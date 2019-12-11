
#ifndef EM85F789N_H
#define EM85F789N_H

//-----------------------------------------------------------------------------
// Byte Registers
//-----------------------------------------------------------------------------
/* ----  Page 0  ---- */
sfr  P0           =  0x80;            // Port 0 Latch
sfr  SP           =  0x81;            // Stack Pointer
sfr  DPL          =  0x82;            // Data Pointer Low
sfr  DPH          =  0x83;            // Data Pointer High
sfr	 DPL1					=  0x84;						// Data Pointer1 Low
sfr  DPH1         =  0x85;            // Data Pointer1 High
sfr  PAGESW			  =  0x86;						// SFR Page Switch
sfr  PCON					=	 0x87;						// Power Control
sfr  TCON					=	 0x88;						// Timer Control
sfr  TMOD					=	 0x89;						// Timer Mode 
sfr  TL0					=  0x8A;						// Timer0 Low Byte
sfr  TL1					=  0x8B;					 	// Timer1 Low Byte
sfr  TH0					=  0x8C;						// Timer0 High Byte
sfr  TH1					=  0x8D;						// Timer1 High Byte
sfr  CKCON0				=  0x8E;						// Clock Control 0
sfr  CKCON1				=  0x8F;						// Clock Control 1
sfr	 P1						=	 0x90;						// Port 1 Latch
sfr  ADCR1				=  0x91;						// ADC Control Register 1
sfr  ADCR2				=  0x92;						// ADC Control Register 2
sfr  ADISR				=  0x93;						// ADC Input Channel Selection Register
sfr  ADER1				=  0x94;						// ADC Input Control Register 1
sfr  ADER2				=  0x95;						// ADC Input Control Register 2
sfr  ADDL					=  0x96;						// ADC Data Low Byte
sfr  ADDH					=  0x97;						// ADC Data High Byte
sfr  SCON0				=  0x98;						// Serial Port 0 Control
sfr  SBUF0				=  0x99;						// Serial Port 0 Data Buffer
sfr  ADCVL				=  0x9A;						// ADC Comparison Low Byte
sfr  ADCVH				=  0x9B;						// ADC Comparison High Byte
sfr  ADER3				=  0x9C;						// ADC Input Control Register 3
sfr  ADER4				=  0x9D;						// ADC Input Control Register 4
sfr  HLVDCR				=  0x9E;						// HLVD Control Register
sfr  HLVDCR1			=  0x9F;						// HLVD Control Register 1
sfr	 P2						=  0xA0;						// Port 2 Latch
// Reserved 0xA1~0xA7
sfr  IE           =  0xA8;            // Interrupt Enable
sfr	 XPAGE				=  0xA9;
// Reserved 0xAA~0xAB
sfr	 SPIRDAFBC		=  0xAC;						// SPI buffer almost full control register
// Reserved 0xAD
sfr  PRST					=  0xAE;						// Peripheral Reset
// Reserved 0xAF
sfr  P3					  =  0xB0;						// Port 3 Latch
sfr  EIE1					=  0xB1;
sfr  EIE2					=  0xB2;
sfr  EIE3					=  0xB3;
// Reserved 0xB4~0xB5
sfr  EIESC1				=  0xB6;
// Reserved 0xB7
sfr  IP           =  0xB8;            // Interrupt Priority
sfr  EIP1					=  0xB9;
sfr  EIP2					=  0xBA;
sfr  EIP3					=  0xBB;
// Reserved 0xBC
sfr  SPICON1			=  0xBD;
sfr  SPICON2			=  0xBE;
sfr  SPISR1				=  0xBF;
sfr  RSTSC				=  0xC0;
sfr  SPISR2				=  0xC1;
sfr  SPITDBR			=  0xC2;
sfr  SPIRDBR			=  0xC3;
sfr  SPITDBC			=  0xC4;
sfr  SPIRDBC			=  0xC5;
sfr  SPIBUFPTR1		=  0xC6;
sfr  SPIBUFPTR2		=  0xC7;
// Reserved 0xC8
sfr  FLKEY				=  0xC9;
sfr  FLCR					=  0xCA;
sfr  EPKEY				=  0xCB;
sfr  EPPOINTL			=  0xCC;
sfr  EPPOINTH			=  0xCD;
sfr  WDTKEY				=  0xCE;
sfr  WDTCR				=  0xCF;
sfr  PSW          =  0xD0;            // Program Status Word 0
sfr  TC3CR1				=  0xD1;						// Timer/Counter 3 Control Register 1
sfr  TC3CR2				=  0xD2;						// Timer/Counter 3 Control Register 2
sfr  TC3DAL				=  0xD3;						// Timer/Counter 3 DATA Buffer A Low Byte
sfr  TC3DAH				=  0xD4;						// Timer/Counter 3 DATA Buffer A Hi Byte
sfr  TC3DBL				=  0xD5;						// Timer/Counter 3 DATA Buffer B Low Byte
sfr  TC3DBH				=  0xD6;						// Timer/Counter 3 DATA Buffer B Hi Byte
sfr  TC3CR3				=	 0xD7;						// Timer/Counter 3 Control Register 3
sfr  PSW1         =  0xD8;            // Program Status Word 1
sfr  TC4CR1				=  0xD9;						// Timer/Counter 4 Control Register 1
sfr  TC4CR2				=  0xDA;						// Timer/Counter 4 Control Register 2
sfr  TC4DAL				=  0xDB;						// Timer/Counter 4 DATA Buffer A Low Byte
sfr  TC4DAH				=  0xDC;						// Timer/Counter 4 DATA Buffer A Hi Byte
sfr  TC4DBL				=  0xDD;						// Timer/Counter 4 DATA Buffer B Low Byte
sfr  TC4DBH				=  0xDE;						// Timer/Counter 4 DATA Buffer B Hi Byte
sfr  TC4CR3				=	 0xDF;						// Timer/Counter 4 Control Register 3
sfr  ACC          =  0xE0;            // Accumulator
// Reserved 0xE1~0xE2
sfr  BGREF0       =  0xE3;            // Bandgap Reference 0
// Reserved 0xE4~0xE5
sfr  SDPWMCR1     =  0xE6;            // Shut Down PWM Control Register 1
sfr  CMPNRCR1     =  0xE7;            // CMP Rising/Falling Edge Control Register 1
sfr  P4					  =  0xE8;						// Port 4 Latch
sfr  ICEN					=  0xE9;						// Input-Change Enable
sfr  QBODICEN			=  0xEA;						// Quasi-Bidirectional and Open-Drain Input-Change Enable
sfr  CMP2CR2			=  0xEB;						// CMP 2 Control Register 2
sfr  CMP2CR1			=  0xEC;						// CMP 2 Control Register 1
sfr  OPCMP1CR2		=  0xED;						// OP/CMP 1 Control Register 2
sfr  OPCMP1CR1		=  0xEE;						// OP/CMP 1 Control Register 1
sfr  COSF1				=  0xEF;						// CMP Status Flag Control Register 1
sfr  B            =  0xF0;            // B Register
sfr  P0M0					=  0xF1;						// P0 Mode 0 
sfr  P0M1					=  0xF2;						// P0 Mode 1 
sfr  P1M0					=  0xF3;						// P1 Mode 0 
sfr  P1M1					=  0xF4;						// P1 Mode 1 
sfr  PHCON0				=  0xF5;						// P0 Pull-high Control Register 
sfr  PLCON0				=  0xF6;						// P0 Pull-low Control Register 
sfr  PHDSC0				=  0xF7;						// P0 High Drive/Sink Control Register
sfr	 P5						=  0xF8;						// Port 5 Latch
sfr  P2M0					=  0xF9;						// P2 Mode 0 
sfr  P2M1					=  0xFA;						// P2 Mode 1 
sfr  P3M0					=  0xFB;						// P3 Mode 0 
sfr  P3M1					=  0xFC;						// P3 Mode 1 
sfr  PHCON1				=  0xFD;						// P1 Pull-high Control Register 
sfr  PLCON1				=  0xFE;						// P1 Pull-low Control Register 
sfr  PHDSC1				=  0xFF;						// P1 High Drive/Sink Control Register

/* ----  Page 1  ---- */
sfr	 RTCCON				=  0x91;						// Real Time Clock Control Register
sfr	 RTCDATAH			=  0x92;						// RTC Hight Byte Data
sfr	 RTCDATAL			=  0x93;						// RTC Low Byte Data 
sfr	 ALARM				=  0x94;						// Alarm Control Register
sfr	 RTCCAL1			=  0x95;						// RTC Calibration Register 1
sfr	 RTCCAL2			=  0x96;						// RTC Calibration Register 2 
sfr	 RTCKEY				=  0x97;						// RTC Key
sfr	 CO1TRL				=  0x9A;						// CMP1 Trim Low Register
sfr	 CO1TRH				=  0x9B;						// CMP1 Trim High Register
sfr	 CO2TRL				=  0x9C;						// CMP2 Trim Low Register
sfr	 CO2TRH				=  0x9D;						// CMP2 Trim High Register
// Reserved 0x9E~0x9F
sfr	 LCDADDR			=  0xA1;						// Address of LCD RAM
sfr	 LCDDATA			=  0xA2;						// Data of LCD RAM
// Reserved 0xA3
sfr	 LEDFR				=  0xA4;						// LED Frame Rate Select
// Reserved 0xA5~0xA7
sfr	 LCDCR1				=  0xA9;						// LCD Driver Control Register 1
sfr	 LCDCR2				=  0xAA;						// LCD Driver Control Register 2
sfr	 LCDCR3				=  0xAB;						// LCD Driver Control Register 3
// Reserved 0xAC
sfr	 DEVPD1				=  0xAD;						// Device 1 Power Down
sfr	 DEVPD2				=  0xAE;						// Device 2 Power Down 
sfr	 DEVPD3				=  0xAF;						// Device 3 Power Down 
sfr  I2CCR1				=  0xB1;						// I2C Status And Control Register 1
sfr  I2CCR2				=  0xB2;						// I2C Status And Control Register 2 
sfr  I2CSA				=  0xB3;						// I2C Slave Address Register
sfr  I2CDB				=  0xB4;						// I2C Data Buffer Register
sfr  I2CDAL				=  0xB5;						// I2C Device Address Register Low Byte
sfr  I2CDAH				=  0xB6;						// I2C Device Address Register Hi Byte
sfr  I2CSF				=  0xB7;						// I2C Status Flag
sfr  I2CRXAF 			=  0xB9;						// I2C Receiver Data Almost Full Buffer Control Length
sfr  I2CTO1 			=  0xBA;						// I2C Time Out 1
sfr  I2CTO1R 			=  0xBB;						// I2C Timer Reload 1 Register
sfr  I2CTO2 			=  0xBC;						// I2C Time Out 2
sfr  I2CTO2R 			=  0xBD;						// I2C Timer Reload 2 Register
sfr  I2CTO3 			=  0xBE;						// I2C Time Out 3
sfr  I2CTO3R 			=  0xBF;						// I2C Timer Reload 3 Register
sfr  I2CTXLEN 		=  0xC1;						// I2C Transmit Buffer Length
sfr  I2CRXLEN 		=  0xC2;						// I2C Receiver Buffer Length
sfr  I2CSTASU 		=  0xC3;						// I2CStart/Stop Setup Time Timing Register
sfr  I2CSTAHD 		=  0xC4;						// I2CStart/Stop Hold Time Timing Register
sfr  I2CSCLFIR 		=  0xC5;						// I2C SCK Digital Filter
sfr  I2CSDAFIR 		=  0xC6;						// I2C SDA Digital Filter
sfr  I2CCR4		 		=  0xC7;						// I2C Status And Control Register 4
sfr  DEADTR			  =  0xC9;						// Dead Time Register
sfr	 PWMENCR			=  0xCA;						// PWM Enable Register
sfr  PWMACR2			=  0xCB;						// PWMA Control Register 2
sfr  PWMBCR2			=  0xCC;						// PWMB Control Register 2
sfr  PWMCCR2			=  0xCD;						// PWMC Control Register 2
// Reserved 0xCE~0xCF
sfr  PWMACR1			=  0xD1;						// PWMA Control Register 1
sfr  PRDAL				=  0xD2;						// PWMA Period Low Byte
sfr  PRDAH				=  0xD3;						// PWMA Period Hi Byte
sfr  DTAL					=  0xD4;						// PWMA Duty Low Byte
sfr  DTAH					=  0xD5;						// PWMA Duty Hi Byte
sfr  TMRAL				=  0xD6;						// Timer A Low Byte
sfr  TMRAH				=  0xD7;						// Timer A Hi Byte
sfr  PWMBCR1			=  0xD9;						// PWMB Control Register 1
sfr  PRDBL				=  0xDA;						// PWMB Period Low Byte
sfr  PRDBH				=  0xDB;						// PWMB Period Hi Byte
sfr  DTBL					=  0xDC;						// PWMB Duty Low Byte
sfr  DTBH					=  0xDD;						// PWMB Duty Hi Byte
sfr  TMRBL				=  0xDE;						// Timer B Low Byte
sfr  TMRBH				=  0xDF;						// Timer B Hi Byte
sfr  PWMCCR1			=  0xE1;						// PWMC Control Register 1
sfr  PRDCL				=  0xE2;						// PWMC Period Low Byte
sfr  PRDCH				=  0xE3;						// PWMC Period Hi Byte
sfr  DTCL					=  0xE4;						// PWMC Duty Low Byte
sfr  DTCH					=  0xE5;						// PWMC Duty Hi Byte
sfr  TMRCL				=  0xE6;						// Timer C Low Byte
sfr  TMRCH				=  0xE7;						// Timer C Hi Byte
// Reserved 0xE9~0xEF
sfr  P4M0					=  0xF1;						// P4 Mode 0 
sfr  P4M1					=  0xF2;						// P4 Mode 1 
sfr  P5M0					=  0xF3;						// P5 Mode 0 
sfr  P5M1					=  0xF4;						// P5 Mode 1 
sfr  PHCON2				=  0xF5;						// P2 Pull-high Control Register 
sfr  PLCON2				=  0xF6;						// P2 Pull-low Control Register 
sfr  PHDSC2				=  0xF7;						// P2 High Drive/Sink Control Register 

/* ----  Page 2  ---- */
// Reserved 0x91~0x97
// Reserved 0x9A~0x9F
sfr	 PLL1CR				=  0xA1;						// PLL 1 Control Register
// Reserved 0xA2~0xA7
sfr	 ARITH				=  0xA9;						// Arithmetic Register
sfr	 MA0					=  0xAA;						// Multiplier A0
sfr  MA1					=  0xAB;						// Multiplier A1
sfr  MA2					=  0xAC;						// Multiplier A2
sfr  MA3					=  0xAD;						// Multiplier A3
sfr  MB0					=  0xAE;						// Multiplier B0
sfr  MB1					=  0xAF;						// Multiplier B1
sfr  EIOUART2			=  0xB1;						// External IO Pin Function Select For UART2
sfr  EIOI2C0			=  0xB2;						// External IO Pin Function Select For I2C0
sfr  EIOSPI0			=  0xB3;						// External IO Pin Function Select For SPI0 Control Register 0
sfr  EIOSPI1			=  0xB4;						// External IO Pin Function Select For SPI0 Control Register 1
sfr  EXEN0				=  0xB5;						// External Interrupt Pin Enable Control Register 0
sfr  EXEN1				=  0xB6;						// External Interrupt Pin Enable Control Register 0
// Reserved 0xB7
sfr  EXSF2				=  0xB9;						// Extended External Interrupt Status Flag Register 2
sfr  EXSF3				=  0xBA;						// Extended External Interrupt Status Flag Register 3
sfr  EXSF4				=  0xBB;						// Extended External Interrupt Status Flag Register 4
// Reserved 0xBC
sfr  EIES2				=  0xBD;						// External Interrupt Edge Select Control Register 2
sfr  EIES3				=  0xBE;						// External Interrupt Edge Select Control Register 3
sfr  EIES4				=  0xBF;						// External Interrupt Edge Select Control Register 4
sfr  EIOCOM1			=  0xC1;						// External IO Pins Function Select For LCD/LED COM Control Register 1
sfr  EIOSEG1			=  0xC2;						// External IO Pins Function Select For LCD/LED SEG Control Register 1
sfr  EIOSEG2			=  0xC3;						// External IO Pins Function Select For LCD/LED SEG Control Register 2
sfr  EIOSEG3			=  0xC4;						// External IO Pins Function Select For LCD/LED SEG Control Register 3
sfr  EIOSEG4			=  0xC5;						// External IO Pins Function Select For LCD/LED SEG Control Register 4
sfr  EIOSEG11			=  0xC6;						// External IO Pins Function Select For LCD/LED SEG1 Control Register 1
// Reserved 0xC7
sfr  EIOPWMA			=  0xC9;						// External IO Pin Function Select For PWMA Control Register
sfr  EIOPWMB			=  0xCA;						// External IO Pin Function Select For PWMB Control Register
sfr  EIOPWMC			=  0xCB;						// External IO Pin Function Select For PWMC Control Register
// Reserved 0xCC
sfr  EIOT3				=  0xCD;						// External IO Pin Function Select For Timer 3 Control Register
sfr  EIOT4				=  0xCE;						// External IO Pin Function Select For Timer 4 Control Register
// Reserved 0xCF
// Reserved 0xD1~0xD7
// Reserved 0xD9~DxDF
// Reserved 0xE1~0xE7
sfr	 UR2BUFTXSF		=	 0xE9;						// UART2 Buffer Mode TX Status Flag
sfr	 UR2BUFRXSF		=	 0xEA;						// UART2 Buffer Mode RX Status Flag
sfr	 UR2BUFTXIM		=	 0xEB;						// UART2 Buffer Mode TX Interrupt Mask Flag
sfr	 UR2BUFRXIM		=	 0xEC;						// UART2 Buffer Mode RX Interrupt Mask Flag
sfr	 UR2TXLEN			=	 0xED;						// UART2 TX Length Register
sfr	 UR2RXLEN			=	 0xEE;						// UART2 RX Length Register
// Reserved 0xEF
sfr	 UR2CR				=	 0xF1;						// UART2 Control Register
sfr	 UR2S					=	 0xF2;						// UART2 Status Register
sfr	 UR2TD				=	 0xF3;						// UART2 Transmit Data Buffer Register
sfr	 UR2RDL				=	 0xF4;						// UART2 Receive Data Low Buffer Register
sfr	 UR2RDH				=	 0xF5;						// UART2 Receive Data High Buffer Register
sfr	 UR2S2				=	 0xF6;						// UART2 Status Register 2
sfr	 UR2BRS				=	 0xF7;						// UART2 Baud Rate Setting Register
// Reserved 0xF9~0xFA
sfr	 LIRCTR				=	 0xFB;						// Low Frequency IRC Trim Register
// Reserved 0xFC~0xFF

//-----------------------------------------------------------------------------
// Bit Definitions
//-----------------------------------------------------------------------------

// P0 0x80
sbit P00 = P0^0;
sbit P01 = P0^1;
sbit P02 = P0^2;
sbit P03 = P0^3;
sbit P04 = P0^4;
sbit P05 = P0^5;
sbit P06 = P0^6;
sbit P07 = P0^7;

// P1 0x90
sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;
sbit P14 = P1^4;
sbit P15 = P1^5;
sbit P16 = P1^6;
sbit P17 = P1^7;

// P2 0xA0
sbit P20 = P2^0;
sbit P21 = P2^1;
sbit P22 = P2^2;
sbit P23 = P2^3;
sbit P24 = P2^4;
sbit P25 = P2^5;
sbit P26 = P2^6;
sbit P27 = P2^7;

// P3 0x30
sbit P30 = P3^0;
sbit P31 = P3^1;
sbit P32 = P3^2;
sbit P33 = P3^3;
sbit P34 = P3^4;
sbit P35 = P3^5;
sbit P36 = P3^6;
sbit P37 = P3^7;

// P4 0xE8
sbit P40 = P4^0;
sbit P41 = P4^1;
sbit P42 = P4^2;
sbit P43 = P4^3;
sbit P44 = P4^4;
sbit P45 = P4^5;
sbit P46 = P4^6;
sbit P47 = P4^7;

// P5 0xF8
sbit P50 = P5^0;
sbit P51 = P5^1;
sbit P52 = P5^2;
sbit P53 = P5^3;
sbit P54 = P5^4;
sbit P55 = P5^5;
sbit P56 = P5^6;
sbit P57 = P5^7;

// TCON 0x88
sbit TF1     = 0x8F;                   // Timer1 overflow flag
sbit TR1     = 0x8E;                   // Timer1 on/off control
sbit TF0     = 0x8D;                   // Timer0 overflow flag
sbit TR0     = 0x8C;                   // Timer0 on/off control
sbit IE0     = 0x89;                   // Ext interrupt 0 edge flag
sbit IT0     = 0x88;                   // Ext interrupt 0 type

// SCON0 0x98
sbit SM00		 = 0x9F;                   // Serial port 0 operation mode control bit 0
sbit SM01		 = 0x9E;                   // Serial port 0 operation mode control bit 1
sbit MCE0    = 0x9D;                   // Multiprocessor communication enable
sbit REN0    = 0x9C;                   // Receive enable
sbit TB08    = 0x9B;                   // Transmit bit 8
sbit RB08    = 0x9A;                   // Receive bit 8
sbit TI0     = 0x99;                   // Transmit interrupt flag
sbit RI0     = 0x98;                   // Receive interrupt flag

// IE 0xA8
sbit EA      = 0xAF;                   // Global interrupt enable
sbit ICIE    = 0xAE;                   // Input change interrupt enable
sbit ERTCIE  = 0xAD;                   // RTC interrupt enable
sbit ES0     = 0xAC;                   // UART0 interrupt enable
sbit ET1     = 0xAB;                   // Timer1 interrupt enable
sbit EX1     = 0xAA;                   // External interrupt 1 enable
sbit ET0     = 0xA9;                   // Timer0 interrupt enable
sbit EX0     = 0xA8;                   // External interrupt 0 enable

// IP 0xB8
sbit PICIE   = 0xBE;                   // Input change interrupt priority
sbit PRTCIE  = 0xBD;                   // RTC Interrupt Priority
sbit PS0     = 0xBC;                   // UART0 priority
sbit PT1     = 0xBB;                   // Timer1 priority
sbit PX1     = 0xBA;                   // External interrupt 1 priority
sbit PT0     = 0xB9;                   // Timer0 priority
sbit PX0     = 0xB8;                   // External interrupt 0 priority

// RSTSC 0xC0
sbit SWRSF	 = 0xC7;									 // Software Reset 
sbit LVRSF	 = 0xC3;									 // LVR flag
sbit WTSF		 = 0xC2;									 // WDT reset flag
sbit ERSF		 = 0xC1;									 // External reset flag	
sbit PORSF	 = 0xC0;									 // Power-on flag

// PSW 0xD0
sbit CY      = 0xD7;                   // Carry flag
sbit AC      = 0xD6;                   // Auxiliary carry flag
sbit F0      = 0xD5;                   // User flag 0
sbit RS1     = 0xD4;                   // Register bank select 1
sbit RS0     = 0xD3;                   // Register bank select 0
sbit OV      = 0xD2;                   // Overflow flag
sbit F1      = 0xD1;                   // User flag 1
sbit PARITY  = 0xD0;                   // Accumulator parity flag

// PSW1 0xD8													 // Bit7~1 unused
sbit SHSF	   = 0xD8;                   // System hold status flag



//-----------------------------------------------------------------------------
// Interrupt Priorities
//-----------------------------------------------------------------------------
#define INTERRUPT_EINT0	           0   // External Interrupt 0
#define INTERRUPT_TIMER0           1   // Timer0 Overflow
#define INTERRUPT_EINT1	           2   // External Interrupt 1
#define INTERRUPT_TIMER1           3   // Timer1 Overflow
#define INTERRUPT_UART0            4   // Serial Port 0
#define INTERRUPT_RTC	             5   // RTC 
#define INTERRUPT_PINC             6   // Pin Change
#define INTERRUPT_HLVD             7   // Hi Low Voltage Detect
#define INTERRUPT_SH	             8   // System Hold
#define INTERRUPT_CMP1			       9   // Comparator1
#define INTERRUPT_SPI				       11  // SPI
#define INTERRUPT_CMP2			       12  // Comparator2
#define INTERRUPT_ADC				       13  // ADC End Of Conversion
#define INTERRUPT_TIMER3           14  // Timer3 Overflow
#define INTERRUPT_PWMA				     15  // PWMA
#define INTERRUPT_PWMB			       16  // PWMB
#define INTERRUPT_TIMER4           18  // Timer4 Overflow
#define INTERRUPT_I2C					     20  // I2C
#define INTERRUPT_UART2            26  // Serial Port 2
#define INTERRUPT_PWMC			       27  // PWMC
#define INTERRUPT_INT29            29  // External Interrupt 2~9
#define INTERRUPT_INT1011          30  // External Interrupt 10~11

#endif                                 	
