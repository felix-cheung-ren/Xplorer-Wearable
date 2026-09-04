#include "lsm6dsv320x_reg_interface.h"
#include "lsm6dsv320x_reg.h"
#include "MAX30102/driver_max30102_interface.h"
#include "common_data.h"
#include "i2c_shared.h"
#include "sensor_events.h"
#include "common_utils.h"

#define ENABLE_LSM_DEBUG_PRINTS 0

#if ENABLE_LSM_DEBUG_PRINTS
    #define LSM_PRINT(...) APP_PRINT(__VA_ARGS__)
#else
    #define LSM_PRINT(...) ((void)0)
#endif

/* Change based on lsm6dsv320x needs */
#define LSM_MAX_WRITE_LEN  64
#define EXT_IRQ_W_IRQN_PIN_LSM BSP_IO_PORT_00_PIN_06
#define EXT_IRQ_W_IRQN_LSM     3

/* External IRQ callback (fires when LSM INT1 pin goes high) */
void lsm_irq_callback(external_irq_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xTaskNotifyFromISR( g_data_processing_task_handle, SENSOR_NOTIFY_LSM6DSV, eSetBits, &xHigherPriorityTaskWoken );
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

stmdev_ctx_t dev_ctx;
uint8_t whoamI;

void lsm6dsv320x_interface_init(void)
{
    int32_t err;

    /* Link FSP specific functions to ST's platform abstraction struct  */
    dev_ctx.write_reg = platform_write;
    dev_ctx.read_reg  = platform_read;
    dev_ctx.mdelay    = platform_delay;
    dev_ctx.handle    = &g_i2c_master0_ctrl;  // Same I2C bus for everything so kinda irrelevant

    err = lsm6dsv320x_device_id_get(&dev_ctx, &whoamI);

    if (err != 0) { LSM_PRINT("lsm device id get failed \n"); while(1); }

    if (whoamI != LSM6DSV320X_ID)
    {
    	LSM_PRINT("Device ID match failed\n");
        while(1);
    }

    /* Power-on-reset lsm6dsv320x */
    err = lsm6dsv320x_sw_por(&dev_ctx);
    if (err != 0) { LSM_PRINT("power on reset lsm failed\n"); while(1); }
    platform_delay(10);

    /* Block data update (data integrity setting) */
    err = lsm6dsv320x_block_data_update_set(&dev_ctx, PROPERTY_ENABLE);
    if (err != 0) { LSM_PRINT("block data update failed \n"); while(1); }

    /* FS_XL = ±8 g */
    err = lsm6dsv320x_xl_full_scale_set(&dev_ctx, LSM6DSV320X_8g);
    if (err != 0) { LSM_PRINT("xl full scale set failed\n"); while(1); }

    /* Turn on the low-g accelerometer (Data rate: ODR_XL >= 30 Hz for SC and 480 Hz for FF) */
    err = lsm6dsv320x_xl_setup(&dev_ctx, LSM6DSV320X_ODR_AT_480Hz, LSM6DSV320X_XL_HIGH_PERFORMANCE_MD);
    if (err != 0) { LSM_PRINT("turn on low-g accel failed \n"); while(1); }

    /* Turn on the gyroscope for SFLP */
    err = lsm6dsv320x_gy_setup(&dev_ctx, LSM6DSV320X_ODR_AT_120Hz, LSM6DSV320X_GY_HIGH_PERFORMANCE_MD);
    if (err != 0) { LSM_PRINT("turn on gyro failed \n"); while(1); }

    /* Configure step count, free fall, and SFLP */
    lsm6dsv320x_stpcnt_init();
    lsm6dsv320x_free_fall_init();
    lsm6dsv320x_sflp_init();

    /* Enable int1 interrupts */
    lsm6dsv320x_interrupt_mode_t int_mode = {0};
    int_mode.enable = 1;
    int_mode.lir = 0;       // pulsed, not latched
    err = lsm6dsv320x_interrupt_enable_set(&dev_ctx, int_mode);
    if (err != 0) { LSM_PRINT("interrupt enable failed\n"); while(1); }

    /* Open line for lsm6dsv320x INT1 pin interrupt */
    ext_irq_w_extended_cfg_t lsm_irq_extend = { .irq_pin = EXT_IRQ_W_IRQN_PIN_LSM };

    external_irq_cfg_t lsm_irq_cfg =
    {
        .channel    = EXT_IRQ_W_IRQN_LSM,
        .trigger    = EXTERNAL_IRQ_TRIGGER_RISING,
        .p_callback = lsm_irq_callback,
        .p_context  = 0,
        .ipl        = 2,
        .p_extend   = &lsm_irq_extend,
    };

    err = R_EXT_IRQ_W_ExternalIrqOpen(&g_external_irq3_ctrl, &lsm_irq_cfg);
    if (err != FSP_SUCCESS) { LSM_PRINT("lsm6dsv320x: external int1 irq open failed.\n"); while(1); }

    /* Enable line for lsm6dsv320x INT1 pin interrupt */
    err = R_EXT_IRQ_W_ExternalIrqEnable(&g_external_irq3_ctrl);
    if (err != FSP_SUCCESS) { LSM_PRINT("lsm6dsv320x: external irq enable failed.\n"); while(1); }
}

int32_t lsm6dsv320x_stpcnt_init(void)
{
    int32_t err;

    /* Step counter specific (Refer to AN6119 pg. 69 and the reg.h file)*/

    /* Set step counter settings and enable */
    lsm6dsv320x_stpcnt_mode_t sc_cfg = { 0 };
    sc_cfg.step_counter_enable = 1;
    sc_cfg.false_step_rej = 0;
    err = lsm6dsv320x_stpcnt_mode_set(&dev_ctx, sc_cfg);
    if (err != 0) { LSM_PRINT("step counter enable failed \n"); while(1); }

    /* Set debounce to minimum for demo (not super practical, but also not very cool to see increments of 10 lol) */
    err = lsm6dsv320x_stpcnt_debounce_set(&dev_ctx, 0);
    if (err != 0) { LSM_PRINT("debounce set failed\n"); while(1); }

    /* Route step detector interrupt to INT1 pin */
    lsm6dsv320x_pin_int_route_t int1_route = {0};
    int1_route.step_detector = 1;
    err = lsm6dsv320x_pin_int1_route_embedded_set(&dev_ctx, &int1_route);
    if (err != 0) { LSM_PRINT("sc int1 route set failed\n"); while(1); }

    /* Reset step counter */
    err = lsm6dsv320x_stpcnt_rst_step_set(&dev_ctx, 1);
    if (err != 0) { LSM_PRINT("step count reset failed \n"); while(1); }

    return 0;
}

int32_t lsm6dsv320x_free_fall_init(void)
{
    int32_t err;

    /* Free fall specific (Refer to AN6119 pg. 51 and the reg.h file)*/

    /* Set free fall time windows */
    err = lsm6dsv320x_ff_time_windows_set(&dev_ctx, 1);
    if (err != 0) { LSM_PRINT("ff time windows set failed\n"); while(1); }

    /* Set free fall thresholds */
    err = lsm6dsv320x_ff_thresholds_set(&dev_ctx, LSM6DSV320X_156_mg);
    if (err != 0) { LSM_PRINT("ff threshold set failed \n"); while(1); }

    /* Route free fall detector interrupt to INT1 pin */
    lsm6dsv320x_pin_int_route_t int1_route = {0};
    int1_route.freefall = 1;
    err = lsm6dsv320x_pin_int1_route_set(&dev_ctx, &int1_route);
    if (err != 0) { LSM_PRINT("ff int1 route set failed\n"); while(1); }

    return 0;
}

int32_t lsm6dsv320x_sflp_init(void)
{
	int32_t err;

	/* SFLP specific (refer to example sensor_fusion example project) */

	/* Enable SFLP game rotation */
	err = lsm6dsv320x_sflp_game_rotation_set(&dev_ctx, PROPERTY_ENABLE);
	if (err != 0) { LSM_PRINT("failed to enable SFLP game rotation\n"); return err; }

	/* Reset SFLP game rotation */
	err = lsm6dsv320x_sflp_game_rotation_reset(&dev_ctx, PROPERTY_ENABLE);
	if (err != 0) { LSM_PRINT("failed to reset SFLP game rotation\n"); return err; }

	/* Set SFLP game rate */
	err = lsm6dsv320x_sflp_data_rate_set(&dev_ctx, LSM6DSV320X_SFLP_30Hz);
	if (err != 0) { LSM_PRINT("failed to set SFLP game rate\n"); return err; }

	return 0;
}

static uint16_t quats_lsb[4];
volatile float g_quaternions[4] = {1.0f, 0.0f, 0.0f, 0.0f};

/* This is a helper function used directly and only to respond to webpage requests */
int32_t lsm6dsv320x_sflp_get(void)
{
	int32_t err;
	memset(quats_lsb, 0x00, sizeof(quats_lsb));

	/* Grab quaternions */
    err = lsm6dsv320x_sflp_quaternion_raw_get(&dev_ctx, quats_lsb);
    if (err != 0) {
    	LSM_PRINT("failed to read quaternions\n");
		g_quaternions[0] = 1.0f, g_quaternions[1] = 0.0f, g_quaternions[2] = 0.0f, g_quaternions[3] = 0.0f;
		return err;
	}

    /* Standard W, X, Y, Z conversion */
    g_quaternions[0] = lsm6dsv320x_from_quaternion_lsb_to_float(quats_lsb[0]);
    g_quaternions[1] = lsm6dsv320x_from_quaternion_lsb_to_float(quats_lsb[1]);
    g_quaternions[2] = lsm6dsv320x_from_quaternion_lsb_to_float(quats_lsb[2]);
    g_quaternions[3] = lsm6dsv320x_from_quaternion_lsb_to_float(quats_lsb[3]);

    return 0;
}

/**
 * @brief  Write generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to write
 * @param  bufp      pointer to data to write in register reg
 * @param  len       number of consecutive register to write
 *
 */
int32_t platform_write(void *handle, uint8_t reg, const uint8_t *bufp, uint16_t len)
{
    xSemaphoreTake(g_i2c_mutex, portMAX_DELAY);

    (void)handle;
    fsp_err_t err;
    uint8_t write_buf[LSM_MAX_WRITE_LEN + 1];

    if (len > LSM_MAX_WRITE_LEN) { xSemaphoreGive(g_i2c_mutex); return -1; }

    /* Set slave address for LSM6DSV320X */
    err = R_I2C_MASTER_W_SlaveAddressSet(&g_i2c_master0_ctrl, (LSM6DSV320X_I2C_ADD_L >> 1), I2C_MASTER_ADDR_MODE_7BIT);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return -1; }

    /* Prepend write register address with the data */
    write_buf[0] = reg;
    memcpy(&write_buf[1], bufp, len);

    /* Write register address + data */
    g_i2c_callback_event = I2C_MASTER_EVENT_ABORTED;
    xSemaphoreTake(g_i2c_complete_sem, 0); // clear any leftover semaphore

    err = R_I2C_MASTER_W_Write(&g_i2c_master0_ctrl, write_buf, len + 1, false);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return -1; }

    /* Wait/block until write completes */
    if (xSemaphoreTake(g_i2c_complete_sem, pdMS_TO_TICKS(I2C_TRANSACTION_BUSY_DELAY)) != pdTRUE)
    {
        xSemaphoreGive(g_i2c_mutex);
        return -1;
    }
    if (I2C_MASTER_EVENT_TX_COMPLETE != g_i2c_callback_event)
    {
        xSemaphoreGive(g_i2c_mutex);
        return -1;
    }

    xSemaphoreGive(g_i2c_mutex);

    return 0;
}

/**
 * @brief  Read generic device register (platform dependent)
 *
 * @param  handle    customizable argument. In this examples is used in
 *                   order to select the correct sensor bus handler.
 * @param  reg       register to read
 * @param  bufp      pointer to buffer that store the data read
 * @param  len       number of consecutive register to read
 *
 */
int32_t platform_read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
{
    xSemaphoreTake(g_i2c_mutex, portMAX_DELAY);

    (void)handle;
    fsp_err_t err;

    /* Set slave address for LSM6DSV320X */
    err = R_I2C_MASTER_W_SlaveAddressSet(&g_i2c_master0_ctrl, (LSM6DSV320X_I2C_ADD_L >> 1), I2C_MASTER_ADDR_MODE_7BIT);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return -1; }

    /* Write register address to read from */
    g_i2c_callback_event = I2C_MASTER_EVENT_ABORTED;
    xSemaphoreTake(g_i2c_complete_sem, 0); // clear any leftover semaphore

    err = R_I2C_MASTER_W_Write(&g_i2c_master0_ctrl, &reg, 1, true);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return -1; }

    /* Wait/block until write completes */
    if (xSemaphoreTake(g_i2c_complete_sem, pdMS_TO_TICKS(I2C_TRANSACTION_BUSY_DELAY)) != pdTRUE)
    {
        xSemaphoreGive(g_i2c_mutex);
        return -1;
    }
    if (I2C_MASTER_EVENT_TX_COMPLETE != g_i2c_callback_event)
    {
        xSemaphoreGive(g_i2c_mutex);
        return -1;
    }

    /* Read data */
    g_i2c_callback_event = I2C_MASTER_EVENT_ABORTED;
    xSemaphoreTake(g_i2c_complete_sem, 0); // clear any leftover semaphore

    err = R_I2C_MASTER_W_Read(&g_i2c_master0_ctrl, bufp, len, false);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return -1; }

    /* Wait/block until read completes */
    if (xSemaphoreTake(g_i2c_complete_sem, pdMS_TO_TICKS(I2C_TRANSACTION_BUSY_DELAY)) != pdTRUE)
    {
        xSemaphoreGive(g_i2c_mutex);
        return -1;
    }
    if (I2C_MASTER_EVENT_RX_COMPLETE != g_i2c_callback_event)
    {
        xSemaphoreGive(g_i2c_mutex);
        return -1;
    }

    xSemaphoreGive(g_i2c_mutex);

    return 0;
}

/**
 * @brief  platform specific delay (platform dependent)
 *
 * @param  ms        delay in ms
 */
void platform_delay(uint32_t ms) {
    R_BSP_SoftwareDelay(ms, BSP_DELAY_UNITS_MILLISECONDS);
}
