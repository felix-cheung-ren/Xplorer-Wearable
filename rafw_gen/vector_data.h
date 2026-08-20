/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (29)
#endif
/* ISR prototypes */
void KDMA_Handler(void);
void uart_w_isr(void);
void i2c_master_w_gen_isr(void);
void TDES_CBC_Handler(void);
void PSK_SHA1_Handler(void);
void SYSPLL_Lock_Handler(void);
void RTC_IF_EXTWK_Handler(void);
void RTC_IF_BLACK_Handler(void);
void RTC_IF_BROWN_Handler(void);
void RTC_IF_PCNT_Handler(void);
void RTC_IF_BCF_MSR_Handler(void);
void RTC_IF_RTC_ACC_Handler(void);
void RTC_IF_EXP_Handler(void);
void RTC_IF_LMR_Handler(void);
void MRM_Handler(void);
void DCACHE_MRM_Handler(void);
void CC312_Handler(void);
void r_ext_irq_w_isr(void);
void FPLL_Lock_Handler(void);
void hsu_isr(void);
void rxl_mpdu_isr(void);
void txl_transmit_trigger(void);
void txl_prot_trigger(void);
void hal_machw_gen_handler(void);
void hal_machw_bcn_cancellation_handler(void);
void phy_rc_isr(void);
#if defined(BSP_MCU_GROUP_RA6B1) || defined(BSP_MCU_GROUP_RA6U1) //BROMINE-TODO
        /* Vector table allocations */
        #define VECTOR_NUMBER_WIFI_KDMA_IRQ ((IRQn_Type) 0) /* WIFI KDMA IRQ (kDMA interrupt request) */
        #define WIFI_KDMA_IRQ_IRQn          ((IRQn_Type) 0) /* WIFI KDMA IRQ (kDMA interrupt request) */
        #define VECTOR_NUMBER_UARTW1_IRQ ((IRQn_Type) 1) /* UARTW1 IRQ (Generic interrupt) */
        #define UARTW1_IRQ_IRQn          ((IRQn_Type) 1) /* UARTW1 IRQ (Generic interrupt) */
        #define VECTOR_NUMBER_UARTW2_IRQ ((IRQn_Type) 2) /* UARTW2 IRQ (Generic interrupt) */
        #define UARTW2_IRQ_IRQn          ((IRQn_Type) 2) /* UARTW2 IRQ (Generic interrupt) */
        #define VECTOR_NUMBER_I2CW1_IRQ ((IRQn_Type) 3) /* I2CW1 IRQ (Generic interrupt) */
        #define I2CW1_IRQ_IRQn          ((IRQn_Type) 3) /* I2CW1 IRQ (Generic interrupt) */
        #define VECTOR_NUMBER_WIFI_TDES_CBC_IRQ ((IRQn_Type) 4) /* WIFI TDES CBC IRQ (TDES interrupt) */
        #define WIFI_TDES_CBC_IRQ_IRQn          ((IRQn_Type) 4) /* WIFI TDES CBC IRQ (TDES interrupt) */
        #define VECTOR_NUMBER_WIFI_PSK_SHA1_IRQ ((IRQn_Type) 5) /* WIFI PSK SHA1 IRQ (PSK SHA1 interrupt) */
        #define WIFI_PSK_SHA1_IRQ_IRQn          ((IRQn_Type) 5) /* WIFI PSK SHA1 IRQ (PSK SHA1 interrupt) */
        #define VECTOR_NUMBER_WIFI_SYSPLL_LOCK_IRQ ((IRQn_Type) 6) /* WIFI SYSPLL LOCK IRQ (PLL480M lock interrupt) */
        #define WIFI_SYSPLL_LOCK_IRQ_IRQn          ((IRQn_Type) 6) /* WIFI SYSPLL LOCK IRQ (PLL480M lock interrupt) */
        #define VECTOR_NUMBER_WIFI_RTCW_EXTWK_IRQ ((IRQn_Type) 7) /* WIFI RTCW EXTWK IRQ (External wakeup interrupt) */
        #define WIFI_RTCW_EXTWK_IRQ_IRQn          ((IRQn_Type) 7) /* WIFI RTCW EXTWK IRQ (External wakeup interrupt) */
        #define VECTOR_NUMBER_WIFI_RTCW_BLACK_IRQ ((IRQn_Type) 8) /* WIFI RTCW BLACK IRQ (Voltage blackout interrupt) */
        #define WIFI_RTCW_BLACK_IRQ_IRQn          ((IRQn_Type) 8) /* WIFI RTCW BLACK IRQ (Voltage blackout interrupt) */
        #define VECTOR_NUMBER_WIFI_RTCW_BROWN_IRQ ((IRQn_Type) 9) /* WIFI RTCW BROWN IRQ (Voltage brownout interrupt) */
        #define WIFI_RTCW_BROWN_IRQ_IRQn          ((IRQn_Type) 9) /* WIFI RTCW BROWN IRQ (Voltage brownout interrupt) */
        #define VECTOR_NUMBER_WIFI_RTCW_PCNT_IRQ ((IRQn_Type) 10) /* WIFI RTCW PCNT IRQ (Pulse count interrupt) */
        #define WIFI_RTCW_PCNT_IRQ_IRQn          ((IRQn_Type) 10) /* WIFI RTCW PCNT IRQ (Pulse count interrupt) */
        #define VECTOR_NUMBER_WIFI_RTCW_BCF_MSR_IRQ ((IRQn_Type) 11) /* WIFI RTCW BCF MSR IRQ (Bus clock measure interrupt) */
        #define WIFI_RTCW_BCF_MSR_IRQ_IRQn          ((IRQn_Type) 11) /* WIFI RTCW BCF MSR IRQ (Bus clock measure interrupt) */
        #define VECTOR_NUMBER_WIFI_RTCW_RTC_ACC_IRQ ((IRQn_Type) 12) /* WIFI RTCW RTC ACC IRQ (Access to RTC Core interrupt) */
        #define WIFI_RTCW_RTC_ACC_IRQ_IRQn          ((IRQn_Type) 12) /* WIFI RTCW RTC ACC IRQ (Access to RTC Core interrupt) */
        #define VECTOR_NUMBER_WIFI_RTCW_EXP_IRQ ((IRQn_Type) 13) /* WIFI RTCW EXP IRQ (RTC mirror Free running count interrupt) */
        #define WIFI_RTCW_EXP_IRQ_IRQn          ((IRQn_Type) 13) /* WIFI RTCW EXP IRQ (RTC mirror Free running count interrupt) */
        #define VECTOR_NUMBER_WIFI_RTCW_LMR_IRQ ((IRQn_Type) 14) /* WIFI RTCW LMR IRQ (FRC to mirroring loading done interrupt) */
        #define WIFI_RTCW_LMR_IRQ_IRQn          ((IRQn_Type) 14) /* WIFI RTCW LMR IRQ (FRC to mirroring loading done interrupt) */
        #define VECTOR_NUMBER_WIFI_MRM_IRQ ((IRQn_Type) 15) /* WIFI MRM IRQ (Instruction cache Miss Rate Monitor interrupt) */
        #define WIFI_MRM_IRQ_IRQn          ((IRQn_Type) 15) /* WIFI MRM IRQ (Instruction cache Miss Rate Monitor interrupt) */
        #define VECTOR_NUMBER_WIFI_DCACHE_MRM_IRQ ((IRQn_Type) 16) /* WIFI DCACHE MRM IRQ (Data cache Miss Rate Monitor interrupt) */
        #define WIFI_DCACHE_MRM_IRQ_IRQn          ((IRQn_Type) 16) /* WIFI DCACHE MRM IRQ (Data cache Miss Rate Monitor interrupt) */
        #define VECTOR_NUMBER_CC_IRQ ((IRQn_Type) 17) /* CC IRQ (CryptoCell-312 interrupt) */
        #define CC_IRQ_IRQn          ((IRQn_Type) 17) /* CC IRQ (CryptoCell-312 interrupt) */
        #define VECTOR_NUMBER_EXTIRQW_P0_IRQ ((IRQn_Type) 18) /* EXTIRQW P0 IRQ (GPIO port 0 toggle interrupt (External Interrupt)) */
        #define EXTIRQW_P0_IRQ_IRQn          ((IRQn_Type) 18) /* EXTIRQW P0 IRQ (GPIO port 0 toggle interrupt (External Interrupt)) */
        #define VECTOR_NUMBER_EXTIRQW_P1_IRQ ((IRQn_Type) 19) /* EXTIRQW P1 IRQ (GPIO port 1 toggle interrupt (External Interrupt)) */
        #define EXTIRQW_P1_IRQ_IRQn          ((IRQn_Type) 19) /* EXTIRQW P1 IRQ (GPIO port 1 toggle interrupt (External Interrupt)) */
        #define VECTOR_NUMBER_WIFI_FPLL_LOCK_IRQ ((IRQn_Type) 20) /* WIFI FPLL LOCK IRQ (FPLL lock interrupt) */
        #define WIFI_FPLL_LOCK_IRQ_IRQn          ((IRQn_Type) 20) /* WIFI FPLL LOCK IRQ (FPLL lock interrupt) */
        #define VECTOR_NUMBER_WIFI_HSU_IRQ ((IRQn_Type) 21) /* WIFI HSU IRQ (WIFI Hardware Security Unit interrupt) */
        #define WIFI_HSU_IRQ_IRQn          ((IRQn_Type) 21) /* WIFI HSU IRQ (WIFI Hardware Security Unit interrupt) */
        #define VECTOR_NUMBER_WIFI_MACTIMER_IRQ ((IRQn_Type) 22) /* WIFI MACTIMER IRQ (WIFI MAC TX/RX Timer interrupt) */
        #define WIFI_MACTIMER_IRQ_IRQn          ((IRQn_Type) 22) /* WIFI MACTIMER IRQ (WIFI MAC TX/RX Timer interrupt) */
        #define VECTOR_NUMBER_WIFI_MACRX_IRQ ((IRQn_Type) 23) /* WIFI MACRX IRQ (WIFI MAC RX Trigger interrupt) */
        #define WIFI_MACRX_IRQ_IRQn          ((IRQn_Type) 23) /* WIFI MACRX IRQ (WIFI MAC RX Trigger interrupt) */
        #define VECTOR_NUMBER_WIFI_MACTX_IRQ ((IRQn_Type) 24) /* WIFI MACTX IRQ (WIFI MAC TX Trigger interrupt) */
        #define WIFI_MACTX_IRQ_IRQn          ((IRQn_Type) 24) /* WIFI MACTX IRQ (WIFI MAC TX Trigger interrupt) */
        #define VECTOR_NUMBER_WIFI_MACPROT_IRQ ((IRQn_Type) 25) /* WIFI MACPROT IRQ (WIFI MAC Protocol Trigger interrupt) */
        #define WIFI_MACPROT_IRQ_IRQn          ((IRQn_Type) 25) /* WIFI MACPROT IRQ (WIFI MAC Protocol Trigger interrupt) */
        #define VECTOR_NUMBER_WIFI_MACINTGEN_IRQ ((IRQn_Type) 26) /* WIFI MACINTGEN IRQ (WIFI MAC General interrupt) */
        #define WIFI_MACINTGEN_IRQ_IRQn          ((IRQn_Type) 26) /* WIFI MACINTGEN IRQ (WIFI MAC General interrupt) */
        #define VECTOR_NUMBER_WIFI_MACBCN_IRQ ((IRQn_Type) 27) /* WIFI MACBCN IRQ (WIFI MAC Beacon Reception interrupt) */
        #define WIFI_MACBCN_IRQ_IRQn          ((IRQn_Type) 27) /* WIFI MACBCN IRQ (WIFI MAC Beacon Reception interrupt) */
        #define VECTOR_NUMBER_WIFI_RC_IRQ ((IRQn_Type) 28) /* WIFI RC IRQ (WIFI Radio Controller interrupt) */
        #define WIFI_RC_IRQ_IRQn          ((IRQn_Type) 28) /* WIFI RC IRQ (WIFI Radio Controller interrupt) */
#else
/* Vector table allocations */
#define VECTOR_NUMBER_WIFI_KDMA_IRQ ((IRQn_Type) 1) /* WIFI KDMA IRQ (kDMA interrupt request) */
#define WIFI_KDMA_IRQ_IRQn          ((IRQn_Type) 1) /* WIFI KDMA IRQ (kDMA interrupt request) */
#define VECTOR_NUMBER_UARTW1_IRQ ((IRQn_Type) 2) /* UARTW1 IRQ (Generic interrupt) */
#define UARTW1_IRQ_IRQn          ((IRQn_Type) 2) /* UARTW1 IRQ (Generic interrupt) */
#define VECTOR_NUMBER_UARTW2_IRQ ((IRQn_Type) 3) /* UARTW2 IRQ (Generic interrupt) */
#define UARTW2_IRQ_IRQn          ((IRQn_Type) 3) /* UARTW2 IRQ (Generic interrupt) */
#define VECTOR_NUMBER_I2CW1_IRQ ((IRQn_Type) 5) /* I2CW1 IRQ (Generic interrupt) */
#define I2CW1_IRQ_IRQn          ((IRQn_Type) 5) /* I2CW1 IRQ (Generic interrupt) */
#define VECTOR_NUMBER_WIFI_TDES_CBC_IRQ ((IRQn_Type) 15) /* WIFI TDES CBC IRQ (TDES interrupt) */
#define WIFI_TDES_CBC_IRQ_IRQn          ((IRQn_Type) 15) /* WIFI TDES CBC IRQ (TDES interrupt) */
#define VECTOR_NUMBER_WIFI_PSK_SHA1_IRQ ((IRQn_Type) 16) /* WIFI PSK SHA1 IRQ (PSK SHA1 interrupt) */
#define WIFI_PSK_SHA1_IRQ_IRQn          ((IRQn_Type) 16) /* WIFI PSK SHA1 IRQ (PSK SHA1 interrupt) */
#define VECTOR_NUMBER_WIFI_SYSPLL_LOCK_IRQ ((IRQn_Type) 28) /* WIFI SYSPLL LOCK IRQ (PLL480M lock interrupt) */
#define WIFI_SYSPLL_LOCK_IRQ_IRQn          ((IRQn_Type) 28) /* WIFI SYSPLL LOCK IRQ (PLL480M lock interrupt) */
#define VECTOR_NUMBER_WIFI_RTCW_EXTWK_IRQ ((IRQn_Type) 30) /* WIFI RTCW EXTWK IRQ (External wakeup interrupt) */
#define WIFI_RTCW_EXTWK_IRQ_IRQn          ((IRQn_Type) 30) /* WIFI RTCW EXTWK IRQ (External wakeup interrupt) */
#define VECTOR_NUMBER_WIFI_RTCW_BLACK_IRQ ((IRQn_Type) 31) /* WIFI RTCW BLACK IRQ (Voltage blackout interrupt) */
#define WIFI_RTCW_BLACK_IRQ_IRQn          ((IRQn_Type) 31) /* WIFI RTCW BLACK IRQ (Voltage blackout interrupt) */
#define VECTOR_NUMBER_WIFI_RTCW_BROWN_IRQ ((IRQn_Type) 32) /* WIFI RTCW BROWN IRQ (Voltage brownout interrupt) */
#define WIFI_RTCW_BROWN_IRQ_IRQn          ((IRQn_Type) 32) /* WIFI RTCW BROWN IRQ (Voltage brownout interrupt) */
#define VECTOR_NUMBER_WIFI_RTCW_PCNT_IRQ ((IRQn_Type) 33) /* WIFI RTCW PCNT IRQ (Pulse count interrupt) */
#define WIFI_RTCW_PCNT_IRQ_IRQn          ((IRQn_Type) 33) /* WIFI RTCW PCNT IRQ (Pulse count interrupt) */
#define VECTOR_NUMBER_WIFI_RTCW_BCF_MSR_IRQ ((IRQn_Type) 34) /* WIFI RTCW BCF MSR IRQ (Bus clock measure interrupt) */
#define WIFI_RTCW_BCF_MSR_IRQ_IRQn          ((IRQn_Type) 34) /* WIFI RTCW BCF MSR IRQ (Bus clock measure interrupt) */
#define VECTOR_NUMBER_WIFI_RTCW_RTC_ACC_IRQ ((IRQn_Type) 35) /* WIFI RTCW RTC ACC IRQ (Access to RTC Core interrupt) */
#define WIFI_RTCW_RTC_ACC_IRQ_IRQn          ((IRQn_Type) 35) /* WIFI RTCW RTC ACC IRQ (Access to RTC Core interrupt) */
#define VECTOR_NUMBER_WIFI_RTCW_EXP_IRQ ((IRQn_Type) 36) /* WIFI RTCW EXP IRQ (RTC mirror Free running count interrupt) */
#define WIFI_RTCW_EXP_IRQ_IRQn          ((IRQn_Type) 36) /* WIFI RTCW EXP IRQ (RTC mirror Free running count interrupt) */
#define VECTOR_NUMBER_WIFI_RTCW_LMR_IRQ ((IRQn_Type) 37) /* WIFI RTCW LMR IRQ (FRC to mirroring loading done interrupt) */
#define WIFI_RTCW_LMR_IRQ_IRQn          ((IRQn_Type) 37) /* WIFI RTCW LMR IRQ (FRC to mirroring loading done interrupt) */
#define VECTOR_NUMBER_WIFI_MRM_IRQ ((IRQn_Type) 38) /* WIFI MRM IRQ (Instruction cache Miss Rate Monitor interrupt) */
#define WIFI_MRM_IRQ_IRQn          ((IRQn_Type) 38) /* WIFI MRM IRQ (Instruction cache Miss Rate Monitor interrupt) */
#define VECTOR_NUMBER_WIFI_DCACHE_MRM_IRQ ((IRQn_Type) 39) /* WIFI DCACHE MRM IRQ (Data cache Miss Rate Monitor interrupt) */
#define WIFI_DCACHE_MRM_IRQ_IRQn          ((IRQn_Type) 39) /* WIFI DCACHE MRM IRQ (Data cache Miss Rate Monitor interrupt) */
#define VECTOR_NUMBER_CC_IRQ ((IRQn_Type) 40) /* CC IRQ (CryptoCell-312 interrupt) */
#define CC_IRQ_IRQn          ((IRQn_Type) 40) /* CC IRQ (CryptoCell-312 interrupt) */
#define VECTOR_NUMBER_EXTIRQW_P0_IRQ ((IRQn_Type) 41) /* EXTIRQW P0 IRQ (GPIO port 0 toggle interrupt (External Interrupt)) */
#define EXTIRQW_P0_IRQ_IRQn          ((IRQn_Type) 41) /* EXTIRQW P0 IRQ (GPIO port 0 toggle interrupt (External Interrupt)) */
#define VECTOR_NUMBER_EXTIRQW_P1_IRQ ((IRQn_Type) 42) /* EXTIRQW P1 IRQ (GPIO port 1 toggle interrupt (External Interrupt)) */
#define EXTIRQW_P1_IRQ_IRQn          ((IRQn_Type) 42) /* EXTIRQW P1 IRQ (GPIO port 1 toggle interrupt (External Interrupt)) */
#define VECTOR_NUMBER_WIFI_FPLL_LOCK_IRQ ((IRQn_Type) 43) /* WIFI FPLL LOCK IRQ (FPLL lock interrupt) */
#define WIFI_FPLL_LOCK_IRQ_IRQn          ((IRQn_Type) 43) /* WIFI FPLL LOCK IRQ (FPLL lock interrupt) */
#define VECTOR_NUMBER_WIFI_HSU_IRQ ((IRQn_Type) 44) /* WIFI HSU IRQ (WIFI Hardware Security Unit interrupt) */
#define WIFI_HSU_IRQ_IRQn          ((IRQn_Type) 44) /* WIFI HSU IRQ (WIFI Hardware Security Unit interrupt) */
#define VECTOR_NUMBER_WIFI_MACTIMER_IRQ ((IRQn_Type) 46) /* WIFI MACTIMER IRQ (WIFI MAC TX/RX Timer interrupt) */
#define WIFI_MACTIMER_IRQ_IRQn          ((IRQn_Type) 46) /* WIFI MACTIMER IRQ (WIFI MAC TX/RX Timer interrupt) */
#define VECTOR_NUMBER_WIFI_MACRX_IRQ ((IRQn_Type) 48) /* WIFI MACRX IRQ (WIFI MAC RX Trigger interrupt) */
#define WIFI_MACRX_IRQ_IRQn          ((IRQn_Type) 48) /* WIFI MACRX IRQ (WIFI MAC RX Trigger interrupt) */
#define VECTOR_NUMBER_WIFI_MACTX_IRQ ((IRQn_Type) 49) /* WIFI MACTX IRQ (WIFI MAC TX Trigger interrupt) */
#define WIFI_MACTX_IRQ_IRQn          ((IRQn_Type) 49) /* WIFI MACTX IRQ (WIFI MAC TX Trigger interrupt) */
#define VECTOR_NUMBER_WIFI_MACPROT_IRQ ((IRQn_Type) 50) /* WIFI MACPROT IRQ (WIFI MAC Protocol Trigger interrupt) */
#define WIFI_MACPROT_IRQ_IRQn          ((IRQn_Type) 50) /* WIFI MACPROT IRQ (WIFI MAC Protocol Trigger interrupt) */
#define VECTOR_NUMBER_WIFI_MACINTGEN_IRQ ((IRQn_Type) 51) /* WIFI MACINTGEN IRQ (WIFI MAC General interrupt) */
#define WIFI_MACINTGEN_IRQ_IRQn          ((IRQn_Type) 51) /* WIFI MACINTGEN IRQ (WIFI MAC General interrupt) */
#define VECTOR_NUMBER_WIFI_MACBCN_IRQ ((IRQn_Type) 52) /* WIFI MACBCN IRQ (WIFI MAC Beacon Reception interrupt) */
#define WIFI_MACBCN_IRQ_IRQn          ((IRQn_Type) 52) /* WIFI MACBCN IRQ (WIFI MAC Beacon Reception interrupt) */
#define VECTOR_NUMBER_WIFI_RC_IRQ ((IRQn_Type) 53) /* WIFI RC IRQ (WIFI Radio Controller interrupt) */
#define WIFI_RC_IRQ_IRQn          ((IRQn_Type) 53) /* WIFI RC IRQ (WIFI Radio Controller interrupt) */
#endif
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
