/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_max30102_interface_template.c
 * @brief     driver max30102 interface template source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2021-11-13
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2021/11/13  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_max30102_interface.h"
#include "MAX30102/driver_max30102.h"
#include "hal_data.h"
#include "i2c_shared.h"
#include "common_utils.h"

/* Change based on MAX30102 needs */
#define MAX30102_MAX_WRITE_LEN  64
#define EXT_IRQ_W_IRQN_PIN_MAX BSP_IO_PORT_00_PIN_11
#define EXT_IRQ_W_IRQN_MAX     0

/* Flag for IRQ handler */
volatile uint8_t g_max30102_irq_fired = 0;

/* External IRQ callback (fires when MAX30102 INT pin goes low) */
void max30102_irq_callback(external_irq_callback_args_t *p_args)
{
    FSP_PARAMETER_NOT_USED (p_args);
    g_max30102_irq_fired = 1;
}

void max30102_interface_init(void) {
    fsp_err_t err;
    uint8_t res;

    /* Open MAX30102 INT pin interrupt */
    ext_irq_w_extended_cfg_t max_irq_extend = { .irq_pin = EXT_IRQ_W_IRQN_PIN_MAX };

    external_irq_cfg_t max_irq_cfg =
    {
        .channel    = EXT_IRQ_W_IRQN_MAX,
        .trigger    = EXTERNAL_IRQ_TRIGGER_FALLING,
        .p_callback = max30102_irq_callback,
        .p_context  = 0,
        .ipl        = 2,
        .p_extend   = &max_irq_extend,
    };


    err = R_EXT_IRQ_W_ExternalIrqOpen(&g_external_irq0_ctrl, &max_irq_cfg);
    if (err != FSP_SUCCESS)
    {
            max30102_interface_debug_print("max30102: external irq open failed.\n");
            while(1) { vTaskDelay(1000); }
    }

    /* Link FSP interface functions to Libdriver handle */
    DRIVER_MAX30102_LINK_INIT(&g_max30102_handle, max30102_handle_t);
    DRIVER_MAX30102_LINK_IIC_INIT(&g_max30102_handle, max30102_interface_iic_init);
    DRIVER_MAX30102_LINK_IIC_DEINIT(&g_max30102_handle, max30102_interface_iic_deinit);
    DRIVER_MAX30102_LINK_IIC_READ(&g_max30102_handle, max30102_interface_iic_read);
    DRIVER_MAX30102_LINK_IIC_WRITE(&g_max30102_handle, max30102_interface_iic_write);
    DRIVER_MAX30102_LINK_DELAY_MS(&g_max30102_handle, max30102_interface_delay_ms);
    DRIVER_MAX30102_LINK_DEBUG_PRINT(&g_max30102_handle, max30102_interface_debug_print);
    DRIVER_MAX30102_LINK_RECEIVE_CALLBACK(&g_max30102_handle, max30102_interface_receive_callback);

    /* Initialize MAX30102 */
    res = max30102_init(&g_max30102_handle);
    if (res != 0)
    {
        max30102_interface_debug_print("max30102: init failed.\n");
        while(1) { vTaskDelay(1000); }
    }

    /* Enable shutdown */
    res = max30102_set_shutdown(&g_max30102_handle, MAX30102_BOOL_TRUE);
    if (res != 0)
    {
        max30102_interface_debug_print("max30102: set shutdown failed.\n");
        while(1) { vTaskDelay(1000); }
    }

    /* Configure sensor */
    max30102_set_fifo_sample_averaging(&g_max30102_handle, MAX30102_SAMPLE_AVERAGING_4);
    max30102_set_fifo_roll(&g_max30102_handle, MAX30102_BOOL_TRUE);
    max30102_set_fifo_almost_full(&g_max30102_handle, 0x0F);
    max30102_set_mode(&g_max30102_handle, MAX30102_MODE_SPO2);
    max30102_set_spo2_adc_range(&g_max30102_handle, MAX30102_SPO2_ADC_RANGE_16384);
    max30102_set_spo2_sample_rate(&g_max30102_handle, MAX30102_SPO2_SAMPLE_RATE_100_HZ);
    max30102_set_adc_resolution(&g_max30102_handle, MAX30102_ADC_RESOLUTION_18_BIT);
    max30102_set_led_red_pulse_amplitude(&g_max30102_handle, 0x0F);
    max30102_set_led_ir_pulse_amplitude(&g_max30102_handle, 0x0F);
    max30102_set_slot(&g_max30102_handle, MAX30102_SLOT_1, MAX30102_LED_RED); // RED
    max30102_set_slot(&g_max30102_handle, MAX30102_SLOT_2, MAX30102_LED_IR); // IR
    max30102_set_slot(&g_max30102_handle, MAX30102_SLOT_3, MAX30102_LED_NONE); // NONE
    max30102_set_slot(&g_max30102_handle, MAX30102_SLOT_4, MAX30102_LED_NONE); // NONE
    max30102_set_interrupt(&g_max30102_handle, MAX30102_INTERRUPT_FIFO_FULL_EN, MAX30102_BOOL_TRUE);
    max30102_set_interrupt(&g_max30102_handle, MAX30102_INTERRUPT_PPG_RDY_EN, MAX30102_BOOL_FALSE);
    max30102_set_interrupt(&g_max30102_handle, MAX30102_INTERRUPT_ALC_OVF_EN, MAX30102_BOOL_FALSE);
    max30102_set_interrupt(&g_max30102_handle, MAX30102_INTERRUPT_DIE_TEMP_RDY_EN, MAX30102_BOOL_FALSE);

    /* Disable shutdown */
    res = max30102_set_shutdown(&g_max30102_handle, MAX30102_BOOL_FALSE);
    if (res != 0)
    {
        max30102_interface_debug_print("max30102: set shutdown failed.\n");
        while(1) { vTaskDelay(1000); }
    }

    /* Clear any pending interrupt before enabling external IRQ */
    max30102_bool_t enable;
    res = max30102_get_interrupt_status(&g_max30102_handle, MAX30102_INTERRUPT_STATUS_FIFO_FULL, &enable);
    if (res != 0)
    {
        max30102_interface_debug_print("max30102: get interrupt status failed\n");
        while(1) { vTaskDelay(1000); }
    }

    /* Enable MAX30102 INT pin interrupt */
    err = R_EXT_IRQ_W_ExternalIrqEnable(&g_external_irq0_ctrl);
    if (err != FSP_SUCCESS)
    {
            max30102_interface_debug_print("max30102: external irq enable failed.\n");
            while(1) { vTaskDelay(1000); }
    }
}

/**
 * @brief  interface iic bus init
 * @return status code
 *         - 0 success
 *         - 1 iic init failed
 * @note   none
 */
uint8_t max30102_interface_iic_init(void)
{
    /* I2C bus opened in hal_warmstart.c */
    return 0;
}

/**
 * @brief  interface iic bus deinit
 * @return status code
 *         - 0 success
 *         - 1 iic deinit failed
 * @note   none
 */
uint8_t max30102_interface_iic_deinit(void)
{
    fsp_err_t err;
    err = R_I2C_MASTER_W_Close(&g_i2c_master0_ctrl);

    return (err == FSP_SUCCESS) ? 0 : 1;
}

/**
 * @brief      interface iic bus read
 * @param[in]  addr iic device write address
 * @param[in]  reg iic register address
 * @param[out] *buf pointer to a data buffer
 * @param[in]  len length of the data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t max30102_interface_iic_read(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len)
{
    xSemaphoreTake(g_i2c_mutex, portMAX_DELAY);

    fsp_err_t err;
    uint32_t timeout_ms;

    /* Set slave address for MAX30102: 0x57 */
    err = R_I2C_MASTER_W_SlaveAddressSet(&g_i2c_master0_ctrl, (addr >> 1), I2C_MASTER_ADDR_MODE_7BIT);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return 1; }

    /* Write register address to read from */
    g_i2c_callback_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms = I2C_TRANSACTION_BUSY_DELAY;

    err = R_I2C_MASTER_W_Write(&g_i2c_master0_ctrl, &reg, 1, true);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return 1; }

    /* Wait/block until write completes */
    while ((I2C_MASTER_EVENT_TX_COMPLETE != g_i2c_callback_event) && timeout_ms) {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == g_i2c_callback_event) { xSemaphoreGive(g_i2c_mutex); return 1; }

    /* Read data */
    g_i2c_callback_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms           = I2C_TRANSACTION_BUSY_DELAY;

    err = R_I2C_MASTER_W_Read(&g_i2c_master0_ctrl, buf, len, false);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return 1; }

    /* Wait/block until read completes */
    while ((I2C_MASTER_EVENT_RX_COMPLETE != g_i2c_callback_event) && timeout_ms)
    {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == g_i2c_callback_event) { xSemaphoreGive(g_i2c_mutex); return 1; }

    xSemaphoreGive(g_i2c_mutex);

    return 0;
}

/**
 * @brief     interface iic bus write
 * @param[in] addr iic device write address
 * @param[in] reg iic register address
 * @param[in] *buf pointer to a data buffer
 * @param[in] len length of the data buffer
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 * @note      none
 */
uint8_t max30102_interface_iic_write(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len)
{
    xSemaphoreTake(g_i2c_mutex, portMAX_DELAY);

    fsp_err_t err;
    uint32_t timeout_ms;
    uint8_t write_buf[MAX30102_MAX_WRITE_LEN + 1];

    if (len > MAX30102_MAX_WRITE_LEN) { xSemaphoreGive(g_i2c_mutex); return 1; }

    /* Set slave address for MAX30102: 0x57 */
    err = R_I2C_MASTER_W_SlaveAddressSet(&g_i2c_master0_ctrl, (addr >> 1), I2C_MASTER_ADDR_MODE_7BIT);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return 1; }

    /* Prepend write register address with the data */
    write_buf[0] = reg;
    memcpy(&write_buf[1], buf, len);

    /* Write register address + data */
    g_i2c_callback_event = I2C_MASTER_EVENT_ABORTED;
    timeout_ms           = I2C_TRANSACTION_BUSY_DELAY;

    err = R_I2C_MASTER_W_Write(&g_i2c_master0_ctrl, write_buf, len + 1, false);
    if (err != FSP_SUCCESS) { xSemaphoreGive(g_i2c_mutex); return 1; }

    /* Wait/block until write completes */
    while ((I2C_MASTER_EVENT_TX_COMPLETE != g_i2c_callback_event) && timeout_ms) {
        R_BSP_SoftwareDelay(1U, BSP_DELAY_UNITS_MILLISECONDS);
        timeout_ms--;
    }
    if (I2C_MASTER_EVENT_ABORTED == g_i2c_callback_event) { xSemaphoreGive(g_i2c_mutex); return 1; }

    xSemaphoreGive(g_i2c_mutex);

    return 0;
}

/**
 * @brief     interface delay ms
 * @param[in] ms time
 * @note      none
 */
void max30102_interface_delay_ms(uint32_t ms)
{
    R_BSP_SoftwareDelay(ms, BSP_DELAY_UNITS_MILLISECONDS);
}

/**
 * @brief     interface print format data
 * @param[in] fmt format data
 * @note      none
 */
void max30102_interface_debug_print(const char *const fmt, ...)
{
    va_list args;
    char buf[256];

    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    APP_PRINT("%s", buf);
}

/* FIFO full flag for MAX30102 thread to poll */
volatile uint8_t g_max30102_fifo_ready = 0;

/**
 * @brief     interface receive callback
 * @param[in] type irq type
 * @note      none
 */
void max30102_interface_receive_callback(uint8_t type)
{
    switch (type)
    {
        case MAX30102_INTERRUPT_STATUS_FIFO_FULL :
        {
            g_max30102_fifo_ready = 1;
//            max30102_interface_debug_print("max30102: irq fifo full.\n");
            break;
        }
        case MAX30102_INTERRUPT_STATUS_PPG_RDY :
        {
            max30102_interface_debug_print("max30102: irq ppg rdy.\n");
            
            break;
        }
        case MAX30102_INTERRUPT_STATUS_ALC_OVF :
        {
            max30102_interface_debug_print("max30102: irq alc ovf.\n");
            
            break;
        }
        case MAX30102_INTERRUPT_STATUS_PWR_RDY :
        {
            max30102_interface_debug_print("max30102: irq pwr rdy.\n");
            
            break;
        }
        case MAX30102_INTERRUPT_STATUS_DIE_TEMP_RDY :
        {
            max30102_interface_debug_print("max30102: irq die temp rdy.\n");
            
            break;
        }
        default :
        {
            max30102_interface_debug_print("max30102: unknown code.\n");
            
            break;
        }
    }
}
