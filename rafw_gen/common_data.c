/* generated common source file - do not edit */
#include "common_data.h"

ext_irq_w_extended_cfg_t g_external_irq3_ext_cfg = {
#ifdef EXT_INTR3_PIN
    .irq_pin = EXT_INTR3_PIN,
#endif
		};

ext_irq_w_instance_ctrl_t g_external_irq3_ctrl;
const external_irq_cfg_t g_external_irq3_cfg = { .channel = 3, .trigger =
		EXTERNAL_IRQ_TRIG_RISING, .p_callback = lsm_irq_callback, .p_context =
		NULL, .p_extend = &g_external_irq3_ext_cfg, .ipl = (12), .irq =
		FSP_INVALID_VECTOR, };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq3 = { .p_ctrl =
		&g_external_irq3_ctrl, .p_cfg = &g_external_irq3_cfg, .p_api =
		&g_external_irq_on_ext_irq_w };
ext_irq_w_extended_cfg_t g_external_irq0_ext_cfg = {
#ifdef EXT_INTR0_PIN
    .irq_pin = EXT_INTR0_PIN,
#endif
		};

ext_irq_w_instance_ctrl_t g_external_irq0_ctrl;
const external_irq_cfg_t g_external_irq0_cfg = { .channel = 0, .trigger =
		EXTERNAL_IRQ_TRIG_FALLING, .p_callback = max30102_irq_callback,
		.p_context = NULL, .p_extend = &g_external_irq0_ext_cfg, .ipl = (12),
		.irq = FSP_INVALID_VECTOR, };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq0 = { .p_ctrl =
		&g_external_irq0_ctrl, .p_cfg = &g_external_irq0_cfg, .p_api =
		&g_external_irq_on_ext_irq_w };
#define g_at_gpt_TIMER_MODE_PERIODIC
tim_w_instance_ctrl_t g_at_gpt_ctrl;

#if defined(g_at_gpt_TIMER_MODE_PERIODIC)
#if (0 > 0)
tim_w_operation_channel_cfg g_at_gpt_channel_cfg[0] =
{
    {
#if BSP_FEATURE_TIM_W_SUPPORTS_COMPARE_MATCH
        TIM_W_CCM_OPERATION_CAPTURE,
        (uint32_t)0x0U,
#endif
        0,
        TIM_W_GPIO_TRIGGER_DISABLED,
        (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_CCMA_IRQ)
        VECTOR_NUMBER_TIMW1_CCMA_IRQ,
#else
        FSP_INVALID_VECTOR,
#endif
    },
#if (0 > 1)
    {
#if BSP_FEATURE_TIM_W_SUPPORTS_COMPARE_MATCH
        TIM_W_CCM_OPERATION_CAPTURE,
        (uint32_t) 0x0,
#endif
        0,
        TIM_W_GPIO_TRIGGER_DISABLED,
        (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_CCMB_IRQ)
        VECTOR_NUMBER_TIMW1_CCMB_IRQ,
#else
        FSP_INVALID_VECTOR,
#endif
    },
#endif
#if (0 > 2)
{
#if BSP_FEATURE_TIM_W_SUPPORTS_COMPARE_MATCH
        TIM_W_CCM_OPERATION_CAPTURE,
        (uint32_t) 0x0,
#endif
        0,
        TIM_W_GPIO_TRIGGER_DISABLED,
        (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_CCMC_IRQ)
        VECTOR_NUMBER_TIMW1_CCMC_IRQ,
#else
        FSP_INVALID_VECTOR,
#endif
    },
#endif
#if (0 > 3)
{
#if BSP_FEATURE_TIM_W_SUPPORTS_COMPARE_MATCH
        TIM_W_CCM_OPERATION_CAPTURE,
        (uint32_t) 0x0,
#endif
        0,
        TIM_W_GPIO_TRIGGER_DISABLED,
        (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_CCMD_IRQ)
        VECTOR_NUMBER_TIMW1_CCMD_IRQ,
#else
        FSP_INVALID_VECTOR,
#endif
    },
#endif
#if (0 > 4)
{
#if BSP_FEATURE_TIM_W_SUPPORTS_COMPARE_MATCH
        TIM_W_CCM_OPERATION_CAPTURE,
        (uint32_t) 0x0,
#endif
        0,
        TIM_W_GPIO_TRIGGER_DISABLED,
        (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_CCME_IRQ)
        VECTOR_NUMBER_TIMW1_CCME_IRQ,
#else
        FSP_INVALID_VECTOR,
#endif
    },
#endif
#if (0 > 5)
{
#if BSP_FEATURE_TIM_W_SUPPORTS_COMPARE_MATCH
        TIM_W_CCM_OPERATION_CAPTURE,
        (uint32_t) 0x0,
#endif
        0,
        TIM_W_GPIO_TRIGGER_DISABLED,
        (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_CCMF_IRQ)
        VECTOR_NUMBER_TIMW1_CCMF_IRQ,
#else
        FSP_INVALID_VECTOR,
#endif
    },
#endif
#if (0 > 6)
{
#if BSP_FEATURE_TIM_W_SUPPORTS_COMPARE_MATCH
        TIM_W_CCM_OPERATION_CAPTURE,
        (uint32_t) 0x0,
#endif
        0,
        TIM_W_GPIO_TRIGGER_DISABLED,
        (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_CCMG_IRQ)
        VECTOR_NUMBER_TIMW1_CCMG_IRQ,
#else
        FSP_INVALID_VECTOR,
#endif
    },
#endif
#if (0 > 7)
{
#if BSP_FEATURE_TIM_W_SUPPORTS_COMPARE_MATCH
        TIM_W_CCM_OPERATION_CAPTURE,
        (uint32_t) 0x0,
#endif
        0,
        TIM_W_GPIO_TRIGGER_DISABLED,
        (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_CCMH_IRQ)
        VECTOR_NUMBER_TIMW1_CCMH_IRQ,
#else
        FSP_INVALID_VECTOR,
#endif
    },
#endif
};
#endif

tim_w_extended_ccm_cfg g_at_gpt_ccm_cfg = { .single_capture_mode = 0,
#if BSP_FEATURE_TIM_W_SUPPORTS_SEQ_CAPTURES
    .seq_captures           = 0,
#endif
#if !BSP_FEATURE_ELC_MISSING
		.elc_channel = 0,
#endif
		.ccm_channel_size = 0,
#if (0 > 0)
    .p_ccm_channel_cfg      = &g_at_gpt_channel_cfg[0]
#endif
		};
#endif

const tim_w_extended_cfg_t g_at_gpt_extend = { .count_source = TIM_W_CLOCK_DIVN,
		.direction = TIMER_DIRECTION_UP, .free_run = 0,
#if !BSP_FEATURE_ELC_MISSING
		.elc_task = TIM_W_ELC_DISABLED,
#endif
#if defined(g_at_gpt_TIMER_MODE_ONE_SHOT)
    .oneshot_switch_to_periodic = 0,
    .oneshot_delay                  = (uint32_t) 0x1,
#elif defined(g_at_gpt_TIMER_MODE_PERIODIC)
		.p_ccm_cfg = &g_at_gpt_ccm_cfg,
#elif defined(g_at_gpt_TIMER_MODE_PWM)
    .pwm_sync_map   = 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0,
#endif
#if BSP_FEATURE_TIM_W_SUPPORTS_OVERFLOW_UNDERFLOW
    .overflow_ipl       = (BSP_IRQ_DISABLED),
 #if defined(VECTOR_NUMBER_TIMW1_OVF_IRQ)
    .overflow_irq       = VECTOR_NUMBER_TIMW1_OVF_IRQ,
 #else
    .overflow_irq       = FSP_INVALID_VECTOR,
 #endif
    .underflow_ipl       = (BSP_IRQ_DISABLED),
 #if defined(VECTOR_NUMBER_TIMW1_UNF_IRQ)
    .underflow_irq       = VECTOR_NUMBER_TIMW1_UNF_IRQ,
  #else
    .underflow_irq       = FSP_INVALID_VECTOR,
 #endif
#endif
		};

const timer_cfg_t g_at_gpt_cfg = { .mode = TIMER_MODE_PERIODIC,
/* Actual period: 0.0016384 seconds. */.period_counts = (uint32_t) 0x10000,
		.source_div = (timer_source_div_t) 0, .channel = 1
				- TIM_W_CHANNEL_OFFSET, .p_callback = NULL,
		/** If NULL then do not add & */
		.p_context = NULL, .p_extend = &g_at_gpt_extend, .cycle_end_ipl =
				(BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_TIMW1_IRQ)
    .cycle_end_irq       = VECTOR_NUMBER_TIMW1_IRQ,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_at_gpt = { .p_ctrl = &g_at_gpt_ctrl, .p_cfg =
		&g_at_gpt_cfg, .p_api = &g_timer_on_tim_w };
const adc_w_channel_cfg_t g_adc_w_channel_cfg2 = { .interrupt_mode_fifo =
		ADC_W_INTERRUPT_FIFO_NONE, .interrupt_mode_thd =
		ADC_W_INTERRUPT_THD_NONE, .dma_en = ADC_W_DMA_DISABLED,
		.sensorwakeup_en = ADC_W_SENSOR_WAKEUP_DISABLED, .thd_value = 0,
		.threshold_mode = ADC_W_SENSOR_WAKEUP_THD_OVER, };
const adc_w_channel_cfg_t g_adc_w_channel_cfg0 = { .interrupt_mode_fifo =
		ADC_W_INTERRUPT_FIFO_NONE, .interrupt_mode_thd =
		ADC_W_INTERRUPT_THD_NONE, .dma_en = ADC_W_DMA_DISABLED,
		.sensorwakeup_en = ADC_W_SENSOR_WAKEUP_DISABLED, .thd_value = 0,
		.threshold_mode = ADC_W_SENSOR_WAKEUP_THD_OVER, };
adc_w_instance_ctrl_t g_at_adc_ctrl;

const adc_w_extended_cfg_t g_at_adc_cfg_extend = { .conversion_clockdiv = 3,
		.upper_bound_limit = 65535, .lower_bound_limit = 0,
#define FSP_NOT_DEFINED (0xFFFFFFFF)
#if (FSP_NOT_DEFINED == 0)
#define ADC_W_CHANNEL_MASK_0   (0)
    .p_channel_cfgs[0]       = NULL,
#else
#define ADC_W_CHANNEL_MASK_0   (1U << 0)
		.p_channel_cfgs[0] = &g_adc_w_channel_cfg0,
#endif
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define ADC_W_CHANNEL_MASK_1   (0)
		.p_channel_cfgs[1] = NULL,
#else
#define ADC_W_CHANNEL_MASK_1   (1U << 1)
    .p_channel_cfgs[1]       = &g_adc_w_channel_cfg1,
#endif
#if (FSP_NOT_DEFINED == 2)
#define ADC_W_CHANNEL_MASK_2   (0)
    .p_channel_cfgs[2]       = NULL,
#else
#define ADC_W_CHANNEL_MASK_2   (1U << 2)
		.p_channel_cfgs[2] = &g_adc_w_channel_cfg2,
#endif
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
#define ADC_W_CHANNEL_MASK_3   (0)
		.p_channel_cfgs[3] = NULL,
#else
#define ADC_W_CHANNEL_MASK_3   (1U << 3)
    .p_channel_cfgs[3]       = &g_adc_w_channel_cfg3,
#endif
#undef FSP_NOT_DEFINED
		.timer_count_clock_source = ADC_W_TIMER_COUNT_SOURCE_8,
		.timer_value = 1, .sample_average = ADC_W_SAMPLE_AVERAGE_4, };
#define ADC_W_CHANNEL_MASK  (ADC_W_CHANNEL_MASK_0 | ADC_W_CHANNEL_MASK_1 | ADC_W_CHANNEL_MASK_2 | ADC_W_CHANNEL_MASK_3)
const adc_cfg_t g_at_adc_cfg = { .unit = 0, /* Unused */
.mode = ADC_MODE_CONTINUOUS_SCAN, /* Unused */
.resolution = ADC_RESOLUTION_12_BIT, .alignment = ADC_ALIGNMENT_LEFT, /* Unused */
.trigger = ADC_TRIGGER_SOFTWARE, /* Unused */
.p_callback = NULL, .p_context = NULL, .p_extend = &g_at_adc_cfg_extend,
#if defined VECTOR_NUMBER_AUX_ADC_INT
    .scan_end_irq        = VECTOR_NUMBER_AUX_ADC_INT,
#endif
		.scan_end_ipl = (BSP_IRQ_DISABLED),
		.scan_end_b_irq = FSP_INVALID_VECTOR, /* Unused */
		.scan_end_b_ipl = BSP_IRQ_DISABLED, /* Unused */
		.scan_end_c_irq = FSP_INVALID_VECTOR, /* Unused */
		.scan_end_c_ipl = BSP_IRQ_DISABLED, /* Unused */
};
const adc_w_scan_cfg_t g_at_adc_channel_cfg =
		{ .scan_mask = ADC_W_CHANNEL_MASK, };
/* Instance structure to use this module. */
const adc_instance_t g_at_adc = { .p_ctrl = &g_at_adc_ctrl, .p_cfg =
		&g_at_adc_cfg, .p_channel_cfg = &g_at_adc_channel_cfg, .p_api =
		&g_adc_on_adc_w };
#define FSP_NOT_DEFINED (UINT32_MAX)
#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)
/* If the transfer module is DMAC, define a DMAC transfer callback. */
extern void i2c_master_w_tx_dmac_callback(i2c_master_w_instance_ctrl_t * const p_ctrl);

void g_at_i2c_tx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    i2c_master_w_tx_dmac_callback(&g_at_i2c_ctrl);
}
#endif

#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
extern void i2c_master_w_rx_dmac_callback(i2c_master_w_instance_ctrl_t * const p_ctrl);

void g_at_i2c_rx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    i2c_master_w_rx_dmac_callback(&g_at_i2c_ctrl);
}
#endif
#undef FSP_NOT_DEFINED

i2c_master_w_instance_ctrl_t g_at_i2c_ctrl;
const i2c_master_w_extended_cfg_t g_at_i2c_extend =
		{
#if (I2C_MASTER_W_CFG_DMA_ENABLE)
    .enable_dma_bursts_tx    = 1,
    .enable_dma_bursts_rx    = 1,
#endif
				.select_divn = BSP_CFG_I2C1CLK_SOURCE,
#if defined(VECTOR_NUMBER_I2CW1_IRQ)
    .gen_irq             = VECTOR_NUMBER_I2CW1_IRQ,
#else
				.gen_irq = FSP_INVALID_VECTOR,
#endif
				.gen_ipl = (12),
				/* Actual calculated bitrate: 99975. Actual calculated duty cycle: 50%. Frequency of the selected clock source: 80000000. */.clock_settings.scl_lcnt =
						400, .clock_settings.scl_hcnt = 393, };
const i2c_master_cfg_t g_at_i2c_cfg = { .channel = 1
		- I2C_MASTER_W_CHANNEL_OFFSET, .rate = I2C_MASTER_RATE_STANDARD,
		.slave = 0x76, .addr_mode = I2C_MASTER_ADDR_MODE_7BIT,
#define FSP_NOT_DEFINED (1)
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
		.p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &FSP_NOT_DEFINED,
#endif
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
		.p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &FSP_NOT_DEFINED,
#endif
#undef FSP_NOT_DEFINED
		.p_callback = NULL, .p_context = NULL,
#if defined(VECTOR_NUMBER_I2CW1_RX_IRQ)
    .rxi_irq             = VECTOR_NUMBER_I2CW1_RX_IRQ,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_I2CW1_TXE_IRQ)
    .txi_irq             = VECTOR_NUMBER_I2CW1_TXE_IRQ,
#else
		.txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_I2CW1_TXR_IRQ)
    .tei_irq             = VECTOR_NUMBER_I2CW1_TXR_IRQ,
#else
		.tei_irq = FSP_INVALID_VECTOR,
#endif
		.ipl = (BSP_IRQ_DISABLED), .p_extend = &g_at_i2c_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_at_i2c = { .p_ctrl = &g_at_i2c_ctrl, .p_cfg =
		&g_at_i2c_cfg, .p_api = &g_i2c_master_on_i2c_w };
uart_w_instance_ctrl_t g_atcmd_uart_ctrl;
/** UART_W extended configuration for UART HAL driver */
uart_w_baud_setting_t g_atcmd_uart_baud_setting = { .fra_baud = 26, .int_baud =
		43 };

/** UART extended configuration for UART_W HAL driver */
const uart_w_extended_cfg_t g_atcmd_uart_cfg_extend = { .fifo_enable =
		UART_W_FIFO_ENABLE, .rx_fifo_trigger =
		UART_W_RX_FIFO_TRIGGER_SEVEN_EIGHTHS, .tx_fifo_trigger =
		UART_W_TX_FIFO_TRIGGER_EIGHTH, .p_baud_setting =
		&g_atcmd_uart_baud_setting, .flow_control =
		UART_W_AUTO_FLOW_CONTROL_DISABLED, .loop_back_enable =
		UART_W_LOOP_BACK_DISABLE, .rs485_enable = UART_W_RS485_DISABLE, };

/** UART interface configuration */
const uart_cfg_t g_atcmd_uart_cfg = { .channel = 2 - UART_W_CHANNEL_OFFSET,
		.data_bits = UART_W_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits =
				UART_STOP_BITS_1, .p_callback = rm_atcmd_transport_uart_w_cb,
		.p_context = &g_atcmd_transport_ctrl, .p_extend =
				&g_atcmd_uart_cfg_extend,
#define FSP_NOT_DEFINED (1)
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
		.p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &FSP_NOT_DEFINED,
#endif
#if (FSP_NOT_DEFINED == FSP_NOT_DEFINED)
		.p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &FSP_NOT_DEFINED,
#endif
#undef FSP_NOT_DEFINED
		.rxi_ipl = (12),
#if defined(VECTOR_NUMBER_UARTW2_IRQ)
                .rxi_irq             = VECTOR_NUMBER_UARTW2_IRQ,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif

		};

/* Instance structure to use this module. */
const uart_instance_t g_atcmd_uart = { .p_ctrl = &g_atcmd_uart_ctrl, .p_cfg =
		&g_atcmd_uart_cfg, .p_api = &g_uart_on_uart_w };
atcmd_transport_uart_w_instance_ctrl_t g_atcmd_transport_ctrl;
const atcmd_transport_uart_w_extended_cfg_t g_atcmd_transport_cfg_extend = {
		.num_uarts = 1, .uart_instances = { &g_atcmd_uart, } };

atcmd_transport_w_cfg_t g_atcmd_transport_cfg = { .type =
		ATCMD_TRANSPORT_W_TYPE_STREAMING, .p_extend =
		&g_atcmd_transport_cfg_extend, };

atcmd_transport_w_instance_t g_atcmd_transport = { .p_ctrl =
		&g_atcmd_transport_ctrl, .p_cfg = &g_atcmd_transport_cfg, .p_api =
		&g_atcmd_transport_on_uart, };
/* HTTPS control instance. */
https_w_instance_ctrl_t g_https_w0_ctrl;

/* HTTPS configuration. */
const https_cfg_t g_https_w0_cfg = { .p_callback = g_https0_callback,
		.p_context = NULL, .p_extend = NULL, };

/* Instance structure to use HTTPS module. */
const https_instance_t g_https_w0 = { .p_ctrl = &g_https_w0_ctrl, .p_cfg =
		&g_https_w0_cfg, .p_api = &g_https_w, };

ext_irq_w_extended_cfg_t g_external_irq2_ext_cfg = {
#ifdef EXT_INTR2_PIN
    .irq_pin = EXT_INTR2_PIN,
#endif
		};

ext_irq_w_instance_ctrl_t g_external_irq2_ctrl;
const external_irq_cfg_t g_external_irq2_cfg = { .channel = 2, .trigger =
		EXTERNAL_IRQ_TRIG_FALLING, .p_callback = NULL, .p_context = NULL,
		.p_extend = &g_external_irq2_ext_cfg, .ipl = (12), .irq =
				FSP_INVALID_VECTOR, };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq2 = { .p_ctrl =
		&g_external_irq2_ctrl, .p_cfg = &g_external_irq2_cfg, .p_api =
		&g_external_irq_on_ext_irq_w };
ext_irq_w_extended_cfg_t g_external_irq1_ext_cfg = {
#ifdef EXT_INTR1_PIN
    .irq_pin = EXT_INTR1_PIN,
#endif
		};

ext_irq_w_instance_ctrl_t g_external_irq1_ctrl;
const external_irq_cfg_t g_external_irq1_cfg = { .channel = 1, .trigger =
		EXTERNAL_IRQ_TRIG_FALLING,
		.p_callback = srm_wifi_app_gpio_p0_fr_handler, .p_context = NULL,
		.p_extend = &g_external_irq1_ext_cfg, .ipl = (12), .irq =
				FSP_INVALID_VECTOR, };
/* Instance structure to use this module. */
const external_irq_instance_t g_external_irq1 = { .p_ctrl =
		&g_external_irq1_ctrl, .p_cfg = &g_external_irq1_cfg, .p_api =
		&g_external_irq_on_ext_irq_w };
const pmgr_cfg_t g_pmgr_w_cfg;
pmgr_instance_ctrl_t g_pmgr_w_ctrl;

const pmgr_instance_t g_pmgr_w_ins = { .p_ctrl = &g_pmgr_w_ctrl, .p_cfg =
		&g_pmgr_w_cfg, .p_api = &g_pmgr_w_api };
/*
 The following strings are used as parameters when generating the boot image. DO NOT modify or delete them.
 ctrlmode_reg 0xf8000102
 burstcmda_reg 0xa8a500eb
 burstcmdb_reg 0x00010616
 flash_config 0x023102
 */
ospi_w_instance_ctrl_t g_ospi_lfs_ctrl;

static const spi_flash_erase_command_t g_ospi_lfs_erase_command_list[] BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
#if 4096 > 0
	{	.command = 0x20, .size = 4096},
#endif
#if 32768 > 0
	{	.command = 0x52, .size = 32768},
#endif
#if 32768 > 0
	{	.command = 0x52, .size = 32768},
#endif
#if 0xD8 > 0
	{	.command = 0xD8, .size = SPI_FLASH_ERASE_SIZE_CHIP_ERASE},
#endif
};

static const ospi_w_read_instr_cfg_t g_ospi_lfs_read_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.opcode = 0xEB,
	.opcode_wb = 0,
	.opcode_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.addr_bus_mode = OSPI_W_BUS_MODE_QUAD,
	.extra_byte_bus_mode = OSPI_W_BUS_MODE_QUAD,
	.dummy_bus_mode = OSPI_W_BUS_MODE_QUAD,
	.data_bus_mode = OSPI_W_BUS_MODE_QUAD,
	.extra_byte_value = 0xFF,
	.extra_byte_en = OSPI_W_EXTRA_BYTE_ENABLE,
	.extra_byte_half_cfg = 0,
	.dummy_bytes = 1, .dummy_en = true,
	.instr_md = OSPI_W_INSTR_MD_TX_ONLY_IN_FIRST_ACCESS,
	.wrap_md = 0 & 0x01,
	.wrap_blen = 0,
	.wrap_size = 0,
	.wrap_wr_en = 0 & 0x02,
	.cs_high_min_cycles = 1,
	.rd_bend_md = 0,
	.rd_rdb_en = 0,
};

static const ospi_w_erase_instr_cfg_t g_ospi_lfs_erase_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.opcode_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.addr_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.hclk_cycles = 0,
	.opcode = 0x20,
	.cs_idle_delay_cycles = 5,
};

static const ospi_w_suspend_resume_instr_cfg_t g_ospi_lfs_suspend_resume_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.suspend_bus_mode = 0,
	.resume_bus_mode = 0,
	.suspend_opcode = 0,
	.resume_opcode = 0,
	.res_sus_latency_clk_cycles = 0,
	.sussts_dly = 0,
};

static const ospi_w_write_enable_instr_cfg_t g_ospi_lfs_write_enable_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.opcode_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.opcode = 0x06,
};

static const ospi_w_read_status_instr_cfg_t g_ospi_lfs_read_status_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.opcode = 0x05,
	.opcode_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.receive_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.busy_pos = 0,
	.delay_cycles = 0,
	.stsdly_sel = 0,
	.busy_level = OSPI_W_BUSY_LEVEL_HIGH,
	.rstat_dmy_num = 0,
	.dummy_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.dummy_value = 0,
	.rstat_dmy_en = false,
	.rstat_rdb_en = false,
	.rstat_split_en = false,
	.rstat_req = false,
};

static const ospi_w_write_instr_cfg_t g_ospi_lfs_write_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.write_opcode = 0x32,
	.write_opcode_wb = 0,
	.opcode_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.addr_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.data_bus_mode = OSPI_W_BUS_MODE_QUAD,
	.dummy_bus_mode = OSPI_W_BUS_MODE_SINGLE,
	.dummy_bytes = 0, .dummy_en = false,
	.wdex_en = false,
	.cs_hi_min_clk_cycles = 1,
	.send_wen_req = false,
};

static const ospi_w_break_instr_cfg_t g_ospi_lfs_break_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.break_en = 0,
	.break_opcode = 0,
	.break_sec_hf = 0,
	.break_sz = 0,
	.break_tx_md = 0,
};

static const ospi_w_memblen_cfg_t g_ospi_lfs_memblen_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.memblen = 0,
	.tcem_cc = 128,
	.tcem_en = 1,
	.rd_lin_en = 0,
	.keep_active = 0,
	.wcmd_hybrid = 0,
	.dielen = 0,
	.active_thr = 0,
};

static const ospi_w_ctrl_ddr_cfg_t g_ospi_lfs_ddr_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.ctrl_ddra = 0,
	.ctrl_ddrb = 0,
};

static const ospi_w_extra_registers_cfg_t g_ospi_lfs_extra_regs_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.ctrl_mr_reg = 0 ,
	.drst_cmd_reg = 0,
};

static const ospi_w_qpi_instr_cfg_t g_ospi_lfs_qpi_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.opcode_enter = 0x38,
	.opcode_exit = 0xFF,
};

static const ospi_w_flash_cfg_t g_ospi_lfs_flash_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.clk_mode = OSPI_W_CLK_MODE_HIGH,
	.p_read_instr_cfg = &g_ospi_lfs_read_cfg,
	.p_erase_instr_cfg = &g_ospi_lfs_erase_cfg,
	.p_suspend_resume_instr_cfg = &g_ospi_lfs_suspend_resume_cfg,
	.p_write_enable_instr_cfg = &g_ospi_lfs_write_enable_cfg,
	.p_read_status_instr_cfg = &g_ospi_lfs_read_status_cfg,
	.p_write_instr_cfg = &g_ospi_lfs_write_cfg,
	.p_break_instr_cfg = &g_ospi_lfs_break_cfg,
	.p_memblen_cfg = &g_ospi_lfs_memblen_cfg,
	.p_ctrl_ddr = &g_ospi_lfs_ddr_cfg,
	.p_extra_regs = &g_ospi_lfs_extra_regs_cfg,
	.p_qpi_instr_cfg = &g_ospi_lfs_qpi_cfg,
};

static const ospi_w_extended_cfg_t g_ospi_lfs_extended_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.channel = 0,
	.ospi_mode = OSPI_W_MODE_SDR,
	.ospi_clk_div = BSP_CFG_OQSPICLK_DIV,
	.ospi_drive_current = OSPI_W_DRIVE_CURRENT_1,
	.ospi_slew_rate = OSPI_W_SLEW_RATE_0,
	.p_ospi_flash_cfg = &g_ospi_lfs_flash_cfg,
};

const spi_flash_cfg_t g_ospi_lfs_cfg BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.spi_protocol = 0, /* Not used. */
	.read_mode = 0, /* Not used. */
	.address_bytes = SPI_FLASH_ADDRESS_BYTES_3,
	.dummy_clocks = 0, /* Not used. */
	.page_program_address_lines = 0, /* Not used. */
	.write_status_bit = 0, /* Not used. */
	.write_enable_bit = 1,
	.page_size_bytes = 256,
	.page_program_command = 0, /* Not used. */
	.write_enable_command = 0, /* Not used. */
	.status_command = 0, /* Not used. */
	.read_command = 0, /* Not used. */
	.xip_enter_command = 0xA5,
	.xip_exit_command = 0xFF,
	.erase_command_list_length = sizeof(g_ospi_lfs_erase_command_list) / sizeof(g_ospi_lfs_erase_command_list[0]),
	.p_erase_command_list = &g_ospi_lfs_erase_command_list[0],
	.p_extend = &g_ospi_lfs_extended_cfg,
};

/** This structure encompasses everything that is needed to use an instance of this interface. */
const spi_flash_instance_t g_ospi_lfs BSP_PLACE_IN_SECTION(OSPI_W_SECTION_CONST_DATA) =
{
	.p_ctrl = &g_ospi_lfs_ctrl,
	.p_cfg = &g_ospi_lfs_cfg,
	.p_api = &g_ospi_w_on_spi_flash,
};
rm_block_media_spi_w_instance_ctrl_t g_rm_block_media1_ctrl;

#define FSP_NOT_DEFINED 0xFFFFFFFF
static const rm_block_media_spi_w_extended_cfg_t g_rm_block_media1_extended_cfg =
		{
#if (FSP_NOT_DEFINED != FSP_NOT_DEFINED)
                .p_spi             = &FSP_NOT_DEFINED,
                .base_address      = 0x2A770000,
            #elif (FSP_NOT_DEFINED != g_ospi_lfs)
				.p_spi = &g_ospi_lfs, .base_address = 0x2A770000,
#else
                .p_spi             = &g_ospi_lfs,
                .base_address      = 0x2A770000,
            #endif
				.block_count_total = 128, .block_size_bytes = 4096, };
#undef FSP_NOT_DEFINED

const rm_block_media_cfg_t g_rm_block_media1_cfg = { .p_callback = NULL,
		.p_context = NULL, .p_extend = &g_rm_block_media1_extended_cfg };
rm_block_media_instance_t g_rm_block_media1 = { .p_ctrl =
		&g_rm_block_media1_ctrl,

.p_cfg = &g_rm_block_media1_cfg, .p_api = &g_rm_block_media_on_spi };
rm_littlefs_flash_w_instance_ctrl_t g_rm_littlefs0_ctrl;

#ifdef LFS_NO_MALLOC
static uint8_t g_rm_littlefs0_read[512];
static uint8_t g_rm_littlefs0_prog[512];
static uint8_t g_rm_littlefs0_lookahead[32];
#endif

struct lfs g_rm_littlefs0_lfs;

const struct lfs_config g_rm_littlefs0_lfs_cfg = { .context =
		&g_rm_littlefs0_ctrl, .read = &rm_littlefs_flash_w_read, .prog =
		&rm_littlefs_flash_write, .erase = &rm_littlefs_flash_w_erase, .sync =
		&rm_littlefs_flash_w_sync, .read_size = 64, .prog_size = 256,
		.block_size = 4096, .block_count = 128, .block_cycles = 500,
		.cache_size = 512, .lookahead_size = 32,
#ifdef LFS_NO_MALLOC
    .read_buffer = (void *) g_rm_littlefs0_read,
    .prog_buffer = (void *) g_rm_littlefs0_prog,
    .lookahead_buffer = (void *) g_rm_littlefs0_lookahead,
#endif
#if LFS_THREAD_SAFE
    .lock   = &rm_littlefs_flash_w_lock,
    .unlock = &rm_littlefs_flash_w_unlock,
#endif
		};

#define FSP_NOT_DEFINED	(0xFFFFFFFF)
rm_littlefs_flash_w_cfg_t g_rm_littlefs0_ext_cfg = { .p_flash = NULL,
#if (FSP_NOT_DEFINED == g_rm_block_media1)
    .p_media = NULL,
#else
		.p_media = &g_rm_block_media1,
#endif    
		};
#undef FSP_NOT_DEFINED 

const rm_littlefs_cfg_t g_rm_littlefs0_cfg = { .p_lfs_cfg =
		&g_rm_littlefs0_lfs_cfg, .p_extend = &g_rm_littlefs0_ext_cfg, };

/* Instance structure to use this module. */
const rm_littlefs_instance_t g_rm_littlefs0 = { .p_ctrl = &g_rm_littlefs0_ctrl,
		.p_cfg = &g_rm_littlefs0_cfg, .p_api = &g_rm_littlefs_on_flash, };
/* AT configuration. */
atcmd_w_cfg_t g_at0_cfg = { .p_i2c_master = &g_at_i2c, .p_adc = &g_at_adc,
		.p_gpt = &g_at_gpt, .p_transport_instance = &g_atcmd_transport,
		.p_spi_flash = &g_ospi_lfs, };
rm_block_media_spi_w_instance_ctrl_t g_rm_block_media0_ctrl;

#define FSP_NOT_DEFINED 0xFFFFFFFF
static const rm_block_media_spi_w_extended_cfg_t g_rm_block_media0_extended_cfg =
		{
#if (FSP_NOT_DEFINED != FSP_NOT_DEFINED)
                .p_spi             = &FSP_NOT_DEFINED,
                .base_address      = 0x2A300000,
            #elif (FSP_NOT_DEFINED != g_ospi_lfs)
				.p_spi = &g_ospi_lfs, .base_address = 0x2A300000,
#else
                .p_spi             = &g_ospi_lfs,
                .base_address      = 0x2A300000,
            #endif
				.block_count_total = 512, .block_size_bytes = 4096, };
#undef FSP_NOT_DEFINED

const rm_block_media_cfg_t g_rm_block_media0_cfg = { .p_callback =
		rm_vee_media_callback, .p_context = &g_vee0_ctrl, .p_extend =
		&g_rm_block_media0_extended_cfg };
rm_block_media_instance_t g_rm_block_media0 = { .p_ctrl =
		&g_rm_block_media0_ctrl,

.p_cfg = &g_rm_block_media0_cfg, .p_api = &g_rm_block_media_on_spi };
rm_vee_flash_w_instance_ctrl_t g_vee0_ctrl;

#define FSP_NOT_DEFINED	(0xFFFFFFFF)
const rm_vee_flash_w_cfg_t g_vee0_cfg_ext = { .p_flash = NULL,
#if (FSP_NOT_DEFINED == g_rm_block_media0)
    .p_media = NULL,
#else
		.p_media = &g_rm_block_media0,
#endif
		};
#undef FSP_NOT_DEFINED  

static uint16_t g_vee0_record_offset[2048 + 1] = { 0 };

const rm_vee_cfg_t g_vee0_cfg = { .start_addr = 0x2A300000, .num_segments = 2,
		.total_size = 0X4000, .ref_data_size = RM_VEE_FLASH_W_REF_DATA_SIZE,
		.record_max_id = 2048, .rec_offset = &g_vee0_record_offset[0],
		.p_callback = NULL, .p_context = NULL, .p_extend = &g_vee0_cfg_ext };

/* Instance structure to use this module. */
const rm_vee_instance_t g_vee0 = { .p_ctrl = &g_vee0_ctrl, .p_cfg = &g_vee0_cfg,
		.p_api = &g_rm_vee_on_flash };
const map_persistant_w_cfg_t g_map_persistant_w_cfg;
map_persistant_w_instance_ctrl_t g_map_persistant_w_ctrl;

const map_persistant_w_instance_t g_map_persistant_w_instance = { .p_ctrl =
		&g_map_persistant_w_ctrl, .p_cfg = &g_map_persistant_w_cfg, .p_api =
		&g_map_persistant_w_api };
wdog_w_instance_ctrl_t g_wdog_w0_ctrl;
wdog_w_extended_cfg_t g_wdog_w0_cfg_extend = {
#if (BSP_CLOCKS_SOURCE_CLOCK_RCLP == BSP_CFG_WDTSYSCLK_SOURCE)
		.wdt_clk_src = WDOG_W_CLK_SRC_RCLP,
#elif (BSP_CLOCKS_SOURCE_CLOCK_RCX == BSP_CFG_WDTSYSCLK_SOURCE)
    .wdt_clk_src = WDOG_W_CLK_SRC_RCX,
#endif
		};

const wdt_cfg_t g_wdog_w0_cfg = { .timeout = 400, .window_start = 0,
		.window_end = 0, .reset_control = WDT_RESET_CONTROL_NMI, .p_callback =
				wdt_callback_default, .p_extend = &g_wdog_w0_cfg_extend, };

/* Instance structure to use this module. */
const wdt_instance_t g_wdog_w0 = { .p_ctrl = &g_wdog_w0_ctrl, .p_cfg =
		&g_wdog_w0_cfg, .p_api = &g_wdt_on_wdog_w };
#if ((BSP_CFG_LP_CLOCK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_RCX) && (BSP_CFG_WDTSYSCLK_SOURCE == BSP_CLOCKS_SOURCE_CLOCK_RCLP))
#error "RCLP cannot be selected as watchdog clock source, when RCX is lp clock source."
#endif
/* Watchdog Service control instance. */
watchdog_service_w_instance_ctrl_t g_watchdog_service0_ctrl;

/* Watchdog Service configuration. */
const watchdog_service_cfg_t g_watchdog_service0_cfg = { .p_wdt = &g_wdog_w0,
		.p_context = NULL, .p_extend = NULL, };

/* Instance structure to use Watchdog Service module. */
const watchdog_service_instance_t g_watchdog_service0 = { .p_ctrl =
		&g_watchdog_service0_ctrl, .p_cfg = &g_watchdog_service0_cfg, .p_api =
		&g_watchdog_service_on_watchdog_service_w, };

/* WDT default Callback. */
void wdt_callback_default(wdt_callback_args_t *p_args) {
	FSP_PARAMETER_NOT_USED(p_args);
}

/* lwIP configuration. */
const lwip_w_cfg_t g_lwip0_cfg = {
#if LWIP_W_CFG_WATCHDOG_SERVICE_ENABLE
    .p_watchdog_service = &g_watchdog_service0,
#endif
		.p_extend = NULL, };
lwip_w_cfg_t const *gp_lwip_w_cfg = &g_lwip0_cfg;
gpio_w_instance_ctrl_t g_gpio_w_ctrl;
const ioport_instance_t g_gpio_w = { .p_api = &g_ioport_on_gpio_w, .p_ctrl =
		&g_gpio_w_ctrl, .p_cfg = &g_bsp_pin_cfg, };

SemaphoreHandle_t g_i2c_mutex;
#if 1
StaticSemaphore_t g_i2c_mutex_memory;
#endif
void rtos_startup_err_callback(void *p_instance, void *p_data);
void g_common_init(void) {
	g_i2c_mutex =
#if 0
                #if 1
                xSemaphoreCreateRecursiveMutexStatic(&g_i2c_mutex_memory);
                #else
                xSemaphoreCreateRecursiveMutex();
                #endif
                #else
#if 1
			xSemaphoreCreateMutexStatic(&g_i2c_mutex_memory);
#else
                xSemaphoreCreateMutex();
                #endif
#endif
	if (NULL == g_i2c_mutex) {
		rtos_startup_err_callback(g_i2c_mutex, 0);
	}
}
