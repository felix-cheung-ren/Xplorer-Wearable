/* generated HAL source file - do not edit */
#include "hal_data.h"
dmac_instance_ctrl_t g_transfer1_ctrl;
transfer_info_t g_transfer1_info = { .transfer_settings_word_b.dest_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED,
		.transfer_settings_word_b.src_addr_mode = TRANSFER_ADDR_MODE_FIXED,
		.transfer_settings_word_b.size = TRANSFER_SIZE_1_BYTE,
		.transfer_settings_word_b.mode = TRANSFER_MODE_NORMAL,
		.transfer_settings_word_b.burst_mode = TRANSFER_BURST_MODE_DISABLED,
		.p_dest = (void*) NULL, .p_src = (void const*) NULL, .length = 1, };
const dmac_extended_cfg_t g_transfer1_extend = {
#if BSP_FEATURE_DMAC_HAS_SHARED_IRQ
    .irq                 = DMA_IRQn,
#else
#if defined(VECTOR_NUMBER_DMAC_INT)
    .irq                 = VECTOR_NUMBER_DMAC_INT,
 #else
		.irq = FSP_INVALID_VECTOR,
#endif
#endif
		.ipl = (5), .channel = 1, .p_callback = g_spi_w0_rx_transfer_callback,
		.p_context = NULL, .periph_trigger = BSP_DMAC_TRIG_SPI1_RX,
		.irq_num_of_trans = 0, .start_mode = DMAC_START_ON_PERIPHERAL_REQUEST,
		.init_mode = DMAC_INIT_AX_BX_AY_BY,
		.idle_mode = DMAC_IDLE_BLOCKING_MODE, .channel_prio = 0, };
const transfer_cfg_t g_transfer1_cfg = { .p_info = &g_transfer1_info,
		.p_extend = &g_transfer1_extend, };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer1 = { .p_ctrl = &g_transfer1_ctrl, .p_cfg =
		&g_transfer1_cfg, .p_api = &g_transfer_on_dmac_w };
dmac_instance_ctrl_t g_transfer0_ctrl;
transfer_info_t g_transfer0_info = { .transfer_settings_word_b.dest_addr_mode =
		TRANSFER_ADDR_MODE_FIXED, .transfer_settings_word_b.src_addr_mode =
		TRANSFER_ADDR_MODE_INCREMENTED, .transfer_settings_word_b.size =
		TRANSFER_SIZE_1_BYTE, .transfer_settings_word_b.mode =
		TRANSFER_MODE_NORMAL, .transfer_settings_word_b.burst_mode =
		TRANSFER_BURST_MODE_DISABLED, .p_dest = (void*) NULL, .p_src =
		(void const*) NULL, .length = 1, };
const dmac_extended_cfg_t g_transfer0_extend = {
#if BSP_FEATURE_DMAC_HAS_SHARED_IRQ
    .irq                 = DMA_IRQn,
#else
#if defined(VECTOR_NUMBER_DMAC_INT)
    .irq                 = VECTOR_NUMBER_DMAC_INT,
 #else
		.irq = FSP_INVALID_VECTOR,
#endif
#endif
		.ipl = (5), .channel = 0, .p_callback = g_spi_w0_tx_transfer_callback,
		.p_context = NULL, .periph_trigger = BSP_DMAC_TRIG_SPI1_TX,
		.irq_num_of_trans = 0, .start_mode = DMAC_START_ON_PERIPHERAL_REQUEST,
		.init_mode = DMAC_INIT_AX_BX_AY_BY,
		.idle_mode = DMAC_IDLE_BLOCKING_MODE, .channel_prio = 0, };
const transfer_cfg_t g_transfer0_cfg = { .p_info = &g_transfer0_info,
		.p_extend = &g_transfer0_extend, };
/* Instance structure to use this module. */
const transfer_instance_t g_transfer0 = { .p_ctrl = &g_transfer0_ctrl, .p_cfg =
		&g_transfer0_cfg, .p_api = &g_transfer_on_dmac_w };
#define FSP_NOT_DEFINED (UINT32_MAX)
#if (FSP_NOT_DEFINED) != (g_spi_w0_tx_transfer_callback)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
extern void spi_w_tx_dmac_callback(spi_w_instance_ctrl_t const * const p_ctrl);

void g_spi_w0_tx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    spi_w_tx_dmac_callback(&g_spi_w0_ctrl);
}
#endif

#if (FSP_NOT_DEFINED) != (g_spi_w0_rx_transfer_callback)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
extern void spi_w_rx_dmac_callback(spi_w_instance_ctrl_t const * const p_ctrl);

void g_spi_w0_rx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    spi_w_rx_dmac_callback(&g_spi_w0_ctrl);
}
#endif
#undef FSP_NOT_DEFINED

spi_w_instance_ctrl_t g_spi_w0_ctrl;

/** SPI extended configuration for SPI HAL driver */
const spi_w_extended_cfg_t g_spi_w0_ext_cfg = { .spck_div =
		/* Actual calculated bitrate: 5000000. */3, .cs_select =
		SPI_W_CS_SELECT_CS0, .byte_swap = SPI_W_BYTE_SWAP_DISABLE, .cap_edge =
		SPI_W_CAPTURE_CURRENT_EDGE, .gen_ipl = (12),
#if defined(VECTOR_NUMBER_SPIW1_IRQ)
    .gen_irq             = VECTOR_NUMBER_SPIW1_IRQ,
#else
		.gen_irq = FSP_INVALID_VECTOR,
#endif
		.rx_fifo_lvl_thres = 0, .tx_fifo_lvl_thres = 0,
#if SPI_W_CFG_FAST_MODE_ENABLE
    .skip_disable      = (false),
#endif
		.skip_busy_check = (false) };

/** SPI configuration for SPI HAL driver */
const spi_cfg_t g_spi_w0_cfg = { .channel = 1 - SPI_W_CHANNEL_OFFSET,

#if defined(VECTOR_NUMBER_SPIW1_RX_IRQ)
    .rxi_irq             = VECTOR_NUMBER_SPIW1_RX_IRQ,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SPIW1_TX_IRQ)
    .txi_irq             = VECTOR_NUMBER_SPIW1_TX_IRQ,
#else
		.txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SPIW1_II_IRQ)
    .tei_irq             = VECTOR_NUMBER_SPIW1_II_IRQ,
#else
		.tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SPIW1_EI_IRQ)
    .eri_irq             = VECTOR_NUMBER_SPIW1_EI_IRQ,
#else
		.eri_irq = FSP_INVALID_VECTOR,
#endif

		.rxi_ipl = (BSP_IRQ_DISABLED), .txi_ipl = (BSP_IRQ_DISABLED), .tei_ipl =
				(BSP_IRQ_DISABLED), .eri_ipl = (BSP_IRQ_DISABLED),

		.operating_mode = SPI_MODE_MASTER,

		.clk_phase = SPI_CLK_PHASE_EDGE_ODD, .clk_polarity =
				SPI_CLK_POLARITY_LOW,

#define FSP_NOT_DEFINED (1)
#if (FSP_NOT_DEFINED == g_transfer0)
    .p_transfer_tx       = NULL,
#else
		.p_transfer_tx = &g_transfer0,
#endif
#if (FSP_NOT_DEFINED == g_transfer1)
    .p_transfer_rx       = NULL,
#else
		.p_transfer_rx = &g_transfer1,
#endif
#undef FSP_NOT_DEFINED
		.p_callback = spi_callback,

		.p_context = NULL, .p_extend = (void*) &g_spi_w0_ext_cfg, };

/* Instance structure to use this module. */
const spi_instance_t g_spi_w0 = { .p_ctrl = &g_spi_w0_ctrl, .p_cfg =
		&g_spi_w0_cfg, .p_api = &g_spi_on_spi_w };
#define FSP_NOT_DEFINED (UINT32_MAX)
#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)
/* If the transfer module is DMAC, define a DMAC transfer callback. */
extern void i2c_master_w_tx_dmac_callback(i2c_master_w_instance_ctrl_t * const p_ctrl);

void g_i2c_master0_tx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    i2c_master_w_tx_dmac_callback(&g_i2c_master0_ctrl);
}
#endif

#if (FSP_NOT_DEFINED) != (FSP_NOT_DEFINED)

/* If the transfer module is DMAC, define a DMAC transfer callback. */
extern void i2c_master_w_rx_dmac_callback(i2c_master_w_instance_ctrl_t * const p_ctrl);

void g_i2c_master0_rx_transfer_callback (dmac_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    i2c_master_w_rx_dmac_callback(&g_i2c_master0_ctrl);
}
#endif
#undef FSP_NOT_DEFINED

i2c_master_w_instance_ctrl_t g_i2c_master0_ctrl;
const i2c_master_w_extended_cfg_t g_i2c_master0_extend =
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
				.gen_ipl = (4),
				/* Actual calculated bitrate: 99975. Actual calculated duty cycle: 50%. Frequency of the selected clock source: 80000000. */.clock_settings.scl_lcnt =
						400, .clock_settings.scl_hcnt = 393, };
const i2c_master_cfg_t g_i2c_master0_cfg = { .channel = 1
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
		.p_callback = i2c_master0_callback, .p_context = NULL,
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
		.ipl = (BSP_IRQ_DISABLED), .p_extend = &g_i2c_master0_extend, };
/* Instance structure to use this module. */
const i2c_master_instance_t g_i2c_master0 = { .p_ctrl = &g_i2c_master0_ctrl,
		.p_cfg = &g_i2c_master0_cfg, .p_api = &g_i2c_master_on_i2c_w };
uart_w_instance_ctrl_t g_uart0_ctrl;
/** UART_W extended configuration for UART HAL driver */
uart_w_baud_setting_t g_uart0_baud_setting = { .fra_baud = 26, .int_baud = 43 };

/** UART extended configuration for UART_W HAL driver */
const uart_w_extended_cfg_t g_uart0_cfg_extend =
		{ .fifo_enable = UART_W_FIFO_ENABLE, .rx_fifo_trigger =
				UART_W_RX_FIFO_TRIGGER_SEVEN_EIGHTHS, .tx_fifo_trigger =
				UART_W_TX_FIFO_TRIGGER_EIGHTH, .p_baud_setting =
				&g_uart0_baud_setting, .flow_control =
				UART_W_AUTO_FLOW_CONTROL_ENABLED, .loop_back_enable =
				UART_W_LOOP_BACK_DISABLE, .rs485_enable = UART_W_RS485_DISABLE, };

/** UART interface configuration */
const uart_cfg_t g_uart0_cfg = { .channel = 1 - UART_W_CHANNEL_OFFSET,
		.data_bits = UART_W_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits =
				UART_STOP_BITS_1, .p_callback = NULL, .p_context = NULL,
		.p_extend = &g_uart0_cfg_extend,
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
		.rxi_ipl = (4),
#if defined(VECTOR_NUMBER_UARTW1_IRQ)
                .rxi_irq             = VECTOR_NUMBER_UARTW1_IRQ,
#else
		.rxi_irq = FSP_INVALID_VECTOR,
#endif

		};

/* Instance structure to use this module. */
const uart_instance_t g_uart0 = { .p_ctrl = &g_uart0_ctrl,
		.p_cfg = &g_uart0_cfg, .p_api = &g_uart_on_uart_w };
/* UART Communication Device */

rm_comms_uart_w_instance_ctrl_t g_comms_stdio_w_ctrl;

#if BSP_CFG_RTOS == 1 // ThreadX

 #if !defined(g_comms_stdio_w_tx_mutex)
 rm_comms_mutex_t g_comms_stdio_w_tx_mutex =
 {
     .p_name = "g_comms_stdio_w tx mutex",
 };
 #endif

 #if !defined(g_comms_stdio_w_rx_mutex)
 rm_comms_mutex_t g_comms_stdio_w_rx_mutex =
 {
     .p_name = "g_comms_stdio_w rx mutex",
 };
 #endif

 #if !defined(g_comms_stdio_w_tx_semaphore)
 rm_comms_semaphore_t g_comms_stdio_w_tx_semaphore =
 {
     .p_name = "g_comms_stdio_w tx semaphore",
 };
 #endif

  #if !defined(g_comms_stdio_w_rx_semaphore)
 rm_comms_semaphore_t g_comms_stdio_w_rx_semaphore =
 {
     .p_name = "g_comms_stdio_w rx semaphore",
 };
 #endif

#elif BSP_CFG_RTOS == 2 // FreeRTOS

#if !defined(g_comms_stdio_w_tx_mutex)
rm_comms_mutex_t g_comms_stdio_w_tx_mutex;
#endif

#if !defined(g_comms_stdio_w_rx_mutex)
rm_comms_mutex_t g_comms_stdio_w_rx_mutex;
#endif
#if !defined(g_comms_stdio_w_tx_semaphore)
rm_comms_semaphore_t g_comms_stdio_w_tx_semaphore;
#endif

#if !defined(g_comms_stdio_w_rx_semaphore)
rm_comms_semaphore_t g_comms_stdio_w_rx_semaphore;
#endif

#else

#endif

rm_comms_uart_w_extended_cfg_t g_comms_stdio_w_extended_cfg = {
#if BSP_CFG_RTOS

#if !defined(g_comms_stdio_w_tx_mutex)
    .p_tx_mutex = &g_comms_stdio_w_tx_mutex,
#else
    .p_tx_mutex = NULL,
#endif

#if !defined(g_comms_stdio_w_rx_mutex)
    .p_rx_mutex = &g_comms_stdio_w_rx_mutex,
#else
    .p_rx_mutex = NULL,
#endif

#if !defined(g_comms_stdio_w_tx_semaphore)
    .p_tx_semaphore = &g_comms_stdio_w_tx_semaphore,
#else
    .p_tx_semaphore = NULL,
#endif

#if !defined(g_comms_stdio_w_rx_semaphore)
    .p_rx_semaphore = &g_comms_stdio_w_rx_semaphore,
#else
    .p_rx_semaphore = NULL,
#endif
    .mutex_timeout  = 0xFFFFFFFF,
#endif
		.buff_ovrw_prot = 0, .p_uart = &g_uart0, };

rm_comms_cfg_t g_comms_stdio_w_cfg = { .semaphore_timeout = 0xFFFFFFFF,
		.p_lower_level_cfg = NULL, .p_extend =
				(void*) &g_comms_stdio_w_extended_cfg, .p_callback = NULL, };

const rm_comms_instance_t g_comms_stdio_w = { .p_ctrl = &g_comms_stdio_w_ctrl,
		.p_cfg = &g_comms_stdio_w_cfg, .p_api = &g_comms_on_comms_uart_w, };
const rtc_extended_cfg_t rtc_w_cfg_extend = { .reserved = 0, };

static const rtc_cfg_t g_rtc_w_test_cfg = { .p_extend = &rtc_w_cfg_extend, };

static rtc_w_instance_ctrl_t g_rtc_w_test_ctrl;

/* Instance structure to use this module. */
rtc_instance_t g_rtc_w_inst_obj = { .p_api = &g_rtc_on_rtc_w, .p_cfg =
		&g_rtc_w_test_cfg, .p_ctrl = &g_rtc_w_test_ctrl, };
/* Wi-Fi default (weak) handlers */
void Default_WiFi_Handler(void);

void Default_WiFi_Handler(void) {
	CRG_TOP->SYS_CTRL_REG_b.DEBUGGER_ENABLE = 1;

	BSP_CFG_HANDLE_UNRECOVERABLE_ERROR(0);

	while (1) {
		__NOP();
	}

	;
}
#define WEAK_REF_ATTRIBUTE    __attribute__((weak, alias("Default_WiFi_Handler")))

void KDMA_Handler(void) WEAK_REF_ATTRIBUTE;
void TDES_CBC_Handler(void) WEAK_REF_ATTRIBUTE;
void PSK_SHA1_Handler(void) WEAK_REF_ATTRIBUTE;
void CLKCAL_Handler(void) WEAK_REF_ATTRIBUTE;
void SYSPLL_Lock_Handler(void) WEAK_REF_ATTRIBUTE;
void RTC_IF_EXTWK_Handler(void) WEAK_REF_ATTRIBUTE;
void RTC_IF_BLACK_Handler(void) WEAK_REF_ATTRIBUTE;
void RTC_IF_BROWN_Handler(void) WEAK_REF_ATTRIBUTE;
void RTC_IF_PCNT_Handler(void) WEAK_REF_ATTRIBUTE;
void RTC_IF_BCF_MSR_Handler(void) WEAK_REF_ATTRIBUTE;
void RTC_IF_RTC_ACC_Handler(void) WEAK_REF_ATTRIBUTE;
void RTC_IF_EXP_Handler(void) WEAK_REF_ATTRIBUTE;
void RTC_IF_LMR_Handler(void) WEAK_REF_ATTRIBUTE;
void MRM_Handler(void) WEAK_REF_ATTRIBUTE;
void DCACHE_MRM_Handler(void) WEAK_REF_ATTRIBUTE;
void FPLL_Lock_Handler(void) WEAK_REF_ATTRIBUTE;
void hsu_isr(void) WEAK_REF_ATTRIBUTE;
void rxl_mpdu_isr(void) WEAK_REF_ATTRIBUTE;
void txl_transmit_trigger(void) WEAK_REF_ATTRIBUTE;
void txl_prot_trigger(void) WEAK_REF_ATTRIBUTE;
void hal_machw_gen_handler(void) WEAK_REF_ATTRIBUTE;
void hal_machw_bcn_cancellation_handler(void) WEAK_REF_ATTRIBUTE;
void phy_rc_isr(void) WEAK_REF_ATTRIBUTE;

/* Wi-Fi configuration. */
const wifi_cfg_t g_wifi_cfg = { .p_watchdog_service = &g_watchdog_service0,
		.p_vee_service = &g_vee0, .p_rtc_w_service = &g_rtc_w_inst_obj,
		.p_context = NULL, .p_spi_flash = &g_ospi_lfs, .p_extend = NULL,
		.coex_enabled = 0, .coex_cfg = { .coex_asc1_pin =
				(BSP_IO_PORT_00_PIN_07), .coex_asc2_pin =
				(BSP_IO_PORT_00_PIN_06), .coex_bt_act_pin =
				(BSP_IO_PORT_01_PIN_15), .coex_asc1_reset_val = 01,
				.coex_asc2_reset_val = 00, } };
void g_hal_init(void) {
	g_common_init();
}
