/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if BSP_FEATURE_BSP_HAS_ICU
        #if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                [0] = KDMA_Handler, /* WIFI KDMA IRQ (kDMA interrupt request) */
                [1] = uart_w_isr, /* UARTW1 IRQ (Generic interrupt) */
                [2] = uart_w_isr, /* UARTW2 IRQ (Generic interrupt) */
                [3] = i2c_master_w_gen_isr, /* I2CW1 IRQ (Generic interrupt) */
                [4] = TDES_CBC_Handler, /* WIFI TDES CBC IRQ (TDES interrupt) */
                [5] = PSK_SHA1_Handler, /* WIFI PSK SHA1 IRQ (PSK SHA1 interrupt) */
                [6] = SYSPLL_Lock_Handler, /* WIFI SYSPLL LOCK IRQ (PLL480M lock interrupt) */
                [7] = RTC_IF_EXTWK_Handler, /* WIFI RTCW EXTWK IRQ (External wakeup interrupt) */
                [8] = RTC_IF_BLACK_Handler, /* WIFI RTCW BLACK IRQ (Voltage blackout interrupt) */
                [9] = RTC_IF_BROWN_Handler, /* WIFI RTCW BROWN IRQ (Voltage brownout interrupt) */
                [10] = RTC_IF_PCNT_Handler, /* WIFI RTCW PCNT IRQ (Pulse count interrupt) */
                [11] = RTC_IF_BCF_MSR_Handler, /* WIFI RTCW BCF MSR IRQ (Bus clock measure interrupt) */
                [12] = RTC_IF_RTC_ACC_Handler, /* WIFI RTCW RTC ACC IRQ (Access to RTC Core interrupt) */
                [13] = RTC_IF_EXP_Handler, /* WIFI RTCW EXP IRQ (RTC mirror Free running count interrupt) */
                [14] = RTC_IF_LMR_Handler, /* WIFI RTCW LMR IRQ (FRC to mirroring loading done interrupt) */
                [15] = MRM_Handler, /* WIFI MRM IRQ (Instruction cache Miss Rate Monitor interrupt) */
                [16] = DCACHE_MRM_Handler, /* WIFI DCACHE MRM IRQ (Data cache Miss Rate Monitor interrupt) */
                [17] = CC312_Handler, /* CC IRQ (CryptoCell-312 interrupt) */
                [18] = r_ext_irq_w_isr, /* EXTIRQW P0 IRQ (GPIO port 0 toggle interrupt (External Interrupt)) */
                [19] = r_ext_irq_w_isr, /* EXTIRQW P1 IRQ (GPIO port 1 toggle interrupt (External Interrupt)) */
                [20] = FPLL_Lock_Handler, /* WIFI FPLL LOCK IRQ (FPLL lock interrupt) */
                [21] = hsu_isr, /* WIFI HSU IRQ (WIFI Hardware Security Unit interrupt) */
                [22] = rxl_mpdu_isr, /* WIFI MACTIMER IRQ (WIFI MAC TX/RX Timer interrupt) */
                [23] = rxl_mpdu_isr, /* WIFI MACRX IRQ (WIFI MAC RX Trigger interrupt) */
                [24] = txl_transmit_trigger, /* WIFI MACTX IRQ (WIFI MAC TX Trigger interrupt) */
                [25] = txl_prot_trigger, /* WIFI MACPROT IRQ (WIFI MAC Protocol Trigger interrupt) */
                [26] = hal_machw_gen_handler, /* WIFI MACINTGEN IRQ (WIFI MAC General interrupt) */
                [27] = hal_machw_bcn_cancellation_handler, /* WIFI MACBCN IRQ (WIFI MAC Beacon Reception interrupt) */
                [28] = phy_rc_isr, /* WIFI RC IRQ (WIFI Radio Controller interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
                [0] = BSP_PRV_IELS_ENUM(EVENT_WIFI_KDMA_IRQ), /* WIFI KDMA IRQ (kDMA interrupt request) */
                [1] = BSP_PRV_IELS_ENUM(EVENT_UARTW1_IRQ), /* UARTW1 IRQ (Generic interrupt) */
                [2] = BSP_PRV_IELS_ENUM(EVENT_UARTW2_IRQ), /* UARTW2 IRQ (Generic interrupt) */
                [3] = BSP_PRV_IELS_ENUM(EVENT_I2CW1_IRQ), /* I2CW1 IRQ (Generic interrupt) */
                [4] = BSP_PRV_IELS_ENUM(EVENT_WIFI_TDES_CBC_IRQ), /* WIFI TDES CBC IRQ (TDES interrupt) */
                [5] = BSP_PRV_IELS_ENUM(EVENT_WIFI_PSK_SHA1_IRQ), /* WIFI PSK SHA1 IRQ (PSK SHA1 interrupt) */
                [6] = BSP_PRV_IELS_ENUM(EVENT_WIFI_SYSPLL_LOCK_IRQ), /* WIFI SYSPLL LOCK IRQ (PLL480M lock interrupt) */
                [7] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RTCW_EXTWK_IRQ), /* WIFI RTCW EXTWK IRQ (External wakeup interrupt) */
                [8] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RTCW_BLACK_IRQ), /* WIFI RTCW BLACK IRQ (Voltage blackout interrupt) */
                [9] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RTCW_BROWN_IRQ), /* WIFI RTCW BROWN IRQ (Voltage brownout interrupt) */
                [10] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RTCW_PCNT_IRQ), /* WIFI RTCW PCNT IRQ (Pulse count interrupt) */
                [11] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RTCW_BCF_MSR_IRQ), /* WIFI RTCW BCF MSR IRQ (Bus clock measure interrupt) */
                [12] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RTCW_RTC_ACC_IRQ), /* WIFI RTCW RTC ACC IRQ (Access to RTC Core interrupt) */
                [13] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RTCW_EXP_IRQ), /* WIFI RTCW EXP IRQ (RTC mirror Free running count interrupt) */
                [14] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RTCW_LMR_IRQ), /* WIFI RTCW LMR IRQ (FRC to mirroring loading done interrupt) */
                [15] = BSP_PRV_IELS_ENUM(EVENT_WIFI_MRM_IRQ), /* WIFI MRM IRQ (Instruction cache Miss Rate Monitor interrupt) */
                [16] = BSP_PRV_IELS_ENUM(EVENT_WIFI_DCACHE_MRM_IRQ), /* WIFI DCACHE MRM IRQ (Data cache Miss Rate Monitor interrupt) */
                [17] = BSP_PRV_IELS_ENUM(EVENT_CC_IRQ), /* CC IRQ (CryptoCell-312 interrupt) */
                [18] = BSP_PRV_IELS_ENUM(EVENT_EXTIRQW_P0_IRQ), /* EXTIRQW P0 IRQ (GPIO port 0 toggle interrupt (External Interrupt)) */
                [19] = BSP_PRV_IELS_ENUM(EVENT_EXTIRQW_P1_IRQ), /* EXTIRQW P1 IRQ (GPIO port 1 toggle interrupt (External Interrupt)) */
                [20] = BSP_PRV_IELS_ENUM(EVENT_WIFI_FPLL_LOCK_IRQ), /* WIFI FPLL LOCK IRQ (FPLL lock interrupt) */
                [21] = BSP_PRV_IELS_ENUM(EVENT_WIFI_HSU_IRQ), /* WIFI HSU IRQ (WIFI Hardware Security Unit interrupt) */
                [22] = BSP_PRV_IELS_ENUM(EVENT_WIFI_MACTIMER_IRQ), /* WIFI MACTIMER IRQ (WIFI MAC TX/RX Timer interrupt) */
                [23] = BSP_PRV_IELS_ENUM(EVENT_WIFI_MACRX_IRQ), /* WIFI MACRX IRQ (WIFI MAC RX Trigger interrupt) */
                [24] = BSP_PRV_IELS_ENUM(EVENT_WIFI_MACTX_IRQ), /* WIFI MACTX IRQ (WIFI MAC TX Trigger interrupt) */
                [25] = BSP_PRV_IELS_ENUM(EVENT_WIFI_MACPROT_IRQ), /* WIFI MACPROT IRQ (WIFI MAC Protocol Trigger interrupt) */
                [26] = BSP_PRV_IELS_ENUM(EVENT_WIFI_MACINTGEN_IRQ), /* WIFI MACINTGEN IRQ (WIFI MAC General interrupt) */
                [27] = BSP_PRV_IELS_ENUM(EVENT_WIFI_MACBCN_IRQ), /* WIFI MACBCN IRQ (WIFI MAC Beacon Reception interrupt) */
                [28] = BSP_PRV_IELS_ENUM(EVENT_WIFI_RC_IRQ), /* WIFI RC IRQ (WIFI Radio Controller interrupt) */
        };
        #endif
        #else
BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_IRQ_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
{
#if VECTOR_DATA_IRQ_COUNT > 0
            [1] = KDMA_Handler, /* WIFI KDMA IRQ (kDMA interrupt request) */
            [2] = uart_w_isr, /* UARTW1 IRQ (Generic interrupt) */
            [3] = uart_w_isr, /* UARTW2 IRQ (Generic interrupt) */
            [5] = i2c_master_w_gen_isr, /* I2CW1 IRQ (Generic interrupt) */
            [15] = TDES_CBC_Handler, /* WIFI TDES CBC IRQ (TDES interrupt) */
            [16] = PSK_SHA1_Handler, /* WIFI PSK SHA1 IRQ (PSK SHA1 interrupt) */
            [28] = SYSPLL_Lock_Handler, /* WIFI SYSPLL LOCK IRQ (PLL480M lock interrupt) */
            [30] = RTC_IF_EXTWK_Handler, /* WIFI RTCW EXTWK IRQ (External wakeup interrupt) */
            [31] = RTC_IF_BLACK_Handler, /* WIFI RTCW BLACK IRQ (Voltage blackout interrupt) */
            [32] = RTC_IF_BROWN_Handler, /* WIFI RTCW BROWN IRQ (Voltage brownout interrupt) */
            [33] = RTC_IF_PCNT_Handler, /* WIFI RTCW PCNT IRQ (Pulse count interrupt) */
            [34] = RTC_IF_BCF_MSR_Handler, /* WIFI RTCW BCF MSR IRQ (Bus clock measure interrupt) */
            [35] = RTC_IF_RTC_ACC_Handler, /* WIFI RTCW RTC ACC IRQ (Access to RTC Core interrupt) */
            [36] = RTC_IF_EXP_Handler, /* WIFI RTCW EXP IRQ (RTC mirror Free running count interrupt) */
            [37] = RTC_IF_LMR_Handler, /* WIFI RTCW LMR IRQ (FRC to mirroring loading done interrupt) */
            [38] = MRM_Handler, /* WIFI MRM IRQ (Instruction cache Miss Rate Monitor interrupt) */
            [39] = DCACHE_MRM_Handler, /* WIFI DCACHE MRM IRQ (Data cache Miss Rate Monitor interrupt) */
            [40] = CC312_Handler, /* CC IRQ (CryptoCell-312 interrupt) */
            [41] = r_ext_irq_w_isr, /* EXTIRQW P0 IRQ (GPIO port 0 toggle interrupt (External Interrupt)) */
            [42] = r_ext_irq_w_isr, /* EXTIRQW P1 IRQ (GPIO port 1 toggle interrupt (External Interrupt)) */
            [43] = FPLL_Lock_Handler, /* WIFI FPLL LOCK IRQ (FPLL lock interrupt) */
            [44] = hsu_isr, /* WIFI HSU IRQ (WIFI Hardware Security Unit interrupt) */
            [46] = rxl_mpdu_isr, /* WIFI MACTIMER IRQ (WIFI MAC TX/RX Timer interrupt) */
            [48] = rxl_mpdu_isr, /* WIFI MACRX IRQ (WIFI MAC RX Trigger interrupt) */
            [49] = txl_transmit_trigger, /* WIFI MACTX IRQ (WIFI MAC TX Trigger interrupt) */
            [50] = txl_prot_trigger, /* WIFI MACPROT IRQ (WIFI MAC Protocol Trigger interrupt) */
            [51] = hal_machw_gen_handler, /* WIFI MACINTGEN IRQ (WIFI MAC General interrupt) */
            [52] = hal_machw_bcn_cancellation_handler, /* WIFI MACBCN IRQ (WIFI MAC Beacon Reception interrupt) */
            [53] = phy_rc_isr, /* WIFI RC IRQ (WIFI Radio Controller interrupt) */
        #endif
};
#endif
