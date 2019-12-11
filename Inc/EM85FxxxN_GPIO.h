//===============================================================================
//	FILE:			EM85FxxxN_GPIO.h
//
//	TITLE:		EM85FxxxN_GPIO Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2017/03/06
//===============================================================================
#ifndef EM85FxxxN_GPIO_H
#define EM85FxxxN_GPIO_H

//----------------------------------------------------------------------------
// Defines for the parameter PinName
//----------------------------------------------------------------------------
#define 	IO_BI_DIRECTION		0x00
#define 	IO_PUSH_PULL			0x01
#define 	IO_HI_IMPEDANCE		0x02
#define 	IO_OPEN_DRAIN			0x03
	
	
	#define 	PULL_HI_DISABLE		0
	#define 	PULL_HI_ENABLE		1
	// Pull High Control Register File:
	struct PHCON0_BITS	{
		unsigned char		P0PH0:1;		// 0
		unsigned char		P0PH1:1;		// 1
		unsigned char		P0PH2:1;		// 2
		unsigned char		P0PH3:1;		// 3
		unsigned char		P0PH4:1;		// 4
		unsigned char		P0PH5:1;		// 5
		unsigned char		P0PH6:1;		// 6
		unsigned char		P0PH7:1;		// 7
		};
	union PHCON0_REG		{
		unsigned char				all;
		struct PHCON0_BITS	bits;
		};
	struct PHCON1_BITS	{
		unsigned char		P1PH0:1;		// 0
		unsigned char		P1PH1:1;		// 1
		unsigned char		P1PH2:1;		// 2
		unsigned char		P1PH3:1;		// 3
		unsigned char		P1PH4:1;		// 4
		unsigned char		P1PH5:1;		// 5
		unsigned char		P1PH6:1;		// 6
		unsigned char		P1PH7:1;		// 7
		};
	union PHCON1_REG		{
		unsigned char				all;
		struct PHCON1_BITS	bits;
		};

	struct PHCON2_BITS	{
		unsigned char		P2PH0:1;		// 0
		unsigned char		P2PH1:1;		// 1
		unsigned char		P3PH0:1;		// 2
		unsigned char		P3PH1:1;		// 3
		unsigned char		P4PH0:1;		// 4
		unsigned char		P4PH1:1;		// 5
		unsigned char		P5PH0:1;		// 6
		unsigned char		P5PH1:1;		// 7
		};
	union PHCON2_REG		{
		unsigned char				all;
		struct PHCON2_BITS	bits;
		};	
	
		
		
		
	#define 	Func_Pin_Disable	0
	#define 	Func_Pin_Enable		1
	// External IO Pin Select for PWMA Control Register File:
	struct EIOPWMA_BITS	{
		unsigned char		PWMA0:1;		// 0
		unsigned char		IPWMA0:1;		// 1
		unsigned char		PWMA1:1;		// 2
		unsigned char		IPWMA1:1;		// 3
		unsigned char		PWMA2:1;		// 4
		unsigned char		IPWMA2:1;		// 5
		unsigned char		PWMA3:1;		// 6
		unsigned char		IPWMA3:1;		// 7
		};
	union EIOPWMA_REG		{
		unsigned char				all;
		struct EIOPWMA_BITS	bits;
		};

	// External IO Pin Select for PWMB Control Register File:
	struct EIOPWMB_BITS	{
		unsigned char		PWMB0:1;		// 0
		unsigned char		IPWMB0:1;		// 1
		unsigned char		PWMB1:1;		// 2
		unsigned char		IPWMB1:1;		// 3
		unsigned char		PWMB2:1;		// 4
		unsigned char		IPWMB2:1;		// 5
		unsigned char		PWMB3:1;		// 6
		unsigned char		IPWMB3:1;		// 7
		};
	union EIOPWMB_REG		{
		unsigned char				all;
		struct EIOPWMB_BITS	bits;
		};

	// External IO Pin Select for PWMC Control Register File:
	struct EIOPWMC_BITS	{
		unsigned char		PWMC0:1;		// 0
		unsigned char		IPWMC0:1;		// 1
		unsigned char		PWMC1:1;		// 2
		unsigned char		IPWMC1:1;		// 3
		unsigned char		PWMC2:1;		// 4
		unsigned char		IPWMC2:1;		// 5
		unsigned char		PWMC3:1;		// 6
		unsigned char		IPWMC3:1;		// 7
		};
	union EIOPWMC_REG		{
		unsigned char				all;
		struct EIOPWMC_BITS	bits;
		};
	
	// External IO Pin Select for Timer3 Control Register File:
	struct EIOT3_BITS	{
		unsigned char		T3_0:1;		// 0
		unsigned char		T3_1:1;		// 1
		unsigned char		T3_2:1;		// 2
		unsigned char		T3_3:1;		// 3
		unsigned char		rsvd1:4;		// 7:4
		};
	union EIOT3_REG		{
		unsigned char				all;
		struct EIOT3_BITS		bits;
		};

	// External IO Pin Select for Timer4 Control Register File:
	struct EIOT4_BITS	{
		unsigned char		T4_0:1;		// 0
		unsigned char		T4_1:1;		// 1
		unsigned char		T4_2:1;		// 2
		unsigned char		T4_3:1;		// 3
		unsigned char		rsvd1:4;		// 7:4
		};
	union EIOT4_REG		{
		unsigned char				all;
		struct EIOT4_BITS		bits;
		};		

	// External IO Pin Select for I2C Control Register File:
	struct EIOI2C0_BITS	{
		unsigned char		SDA00:1;		// 0
		unsigned char		SCL00:1;		// 1
		unsigned char		SDA01:1;		// 2
		unsigned char		SCL01:1;		// 3
		unsigned char		SDA02:1;		// 4
		unsigned char		SCL02:1;		// 5
		unsigned char		SDA03:1;		// 6
		unsigned char		SCL03:1;		// 7
		};
	union EIOI2C0_REG		{
		unsigned char					all;
		struct EIOI2C0_BITS		bits;
		};

	// External IO Pin Select for SPI Control Register File:
	struct EIOSPI0_BITS	{
		unsigned char		SS00:1;			// 0
		unsigned char		MISO00:1;		// 1
		unsigned char		MOSI00:1;		// 2
		unsigned char		SCK00:1;		// 3
		unsigned char		SS01:1;			// 4
		unsigned char		MISO01:1;		// 5
		unsigned char		MOSI01:1;		// 6
		unsigned char		SCK01:1;		// 7		
		};
	union EIOSPI0_REG		{
		unsigned char					all;
		struct EIOSPI0_BITS		bits;
		};	

	struct EIOSPI1_BITS	{
		unsigned char		SS02:1;			// 0
		unsigned char		MISO02:1;		// 1
		unsigned char		MOSI02:1;		// 2
		unsigned char		SCK02:1;		// 3
		unsigned char		SS03:1;			// 4
		unsigned char		MISO03:1;		// 5
		unsigned char		MOSI03:1;		// 6
		unsigned char		SCK03:1;		// 7		
		};
	union EIOSPI1_REG		{
		unsigned char					all;
		struct EIOSPI1_BITS		bits;
		};

	// External IO Pin Select for UART2 Control Register File:
	struct EIOUART2_BITS	{
		unsigned char		RX20:1;		// 0
		unsigned char		TX20:1;		// 1
		unsigned char		RX21:1;		// 2
		unsigned char		TX21:1;		// 3
		unsigned char		RX22:1;		// 4
		unsigned char		TX22:1;		// 5
		unsigned char		RX23:1;		// 6
		unsigned char		TX23:1;		// 7
		};
	union EIOUART2_REG		{
		unsigned char						all;
		struct EIOUART2_BITS		bits;
		};	
	
	// External IO Pin Select for LCD or LED Control Register File:
	struct EIOCOM1_BITS	{
		unsigned char		COM0:1;		// 0
		unsigned char		COM1:1;		// 1
		unsigned char		COM2:1;		// 2
		unsigned char		COM3:1;		// 3
		unsigned char		COM4:1;		// 4
		unsigned char		COM5:1;		// 5
		unsigned char		COM6:1;		// 6
		unsigned char		COM7:1;		// 7		
		};
	union EIOCOM1_REG		{
		unsigned char					all;
		struct EIOCOM1_BITS		bits;
		};	
	struct EIOSEG1_BITS	{
		unsigned char		SEG0:1;		// 0
		unsigned char		SEG1:1;		// 1
		unsigned char		SEG2:1;		// 2
		unsigned char		SEG3:1;		// 3
		unsigned char		SEG4:1;		// 4
		unsigned char		SEG5:1;		// 5
		unsigned char		SEG6:1;		// 6
		unsigned char		SEG7:1;		// 7		
		};
	union EIOSEG1_REG		{
		unsigned char					all;
		struct EIOSEG1_BITS		bits;
		};
	struct EIOSEG2_BITS	{
		unsigned char		SEG8:1;		// 0
		unsigned char		SEG9:1;		// 1
		unsigned char		SEG10:1;		// 2
		unsigned char		SEG11:1;		// 3
		unsigned char		SEG12:1;		// 4
		unsigned char		SEG13:1;		// 5
		unsigned char		SEG14:1;		// 6
		unsigned char		SEG15:1;		// 7		
		};
	union EIOSEG2_REG		{
		unsigned char					all;
		struct EIOSEG2_BITS		bits;
		};
	struct EIOSEG3_BITS	{
		unsigned char		SEG16:1;		// 0
		unsigned char		SEG17:1;		// 1
		unsigned char		SEG18:1;		// 2
		unsigned char		SEG19:1;		// 3
		unsigned char		SEG20:1;		// 4
		unsigned char		SEG21:1;		// 5
		unsigned char		SEG22:1;		// 6
		unsigned char		SEG23:1;		// 7		
		};
	union EIOSEG3_REG		{
		unsigned char					all;
		struct EIOSEG3_BITS		bits;
		};
	struct EIOSEG4_BITS	{
		unsigned char		SEG24:1;		// 0
		unsigned char		SEG25:1;		// 1
		unsigned char		SEG26:1;		// 2
		unsigned char		SEG27:1;		// 3
		unsigned char		SEG28:1;		// 4
		unsigned char		SEG29:1;		// 5
		unsigned char		SEG30:1;		// 6
		unsigned char		SEG31:1;		// 7		
		};
	union EIOSEG4_REG		{
		unsigned char					all;
		struct EIOSEG4_BITS		bits;
		};

	struct EIOSEG11_BITS	{
		unsigned char		SEG0_1:1;		// 0
		unsigned char		SEG1_1:1;		// 1
		unsigned char		SEG2_1:1;		// 2
		unsigned char		SEG3_1:1;		// 3
		unsigned char		SEG4_1:1;		// 4
		unsigned char		SEG5_1:1;		// 5
		unsigned char		SEG6_1:1;		// 6
		unsigned char		SEG7_1:1;		// 7		
		};
	union EIOSEG11_REG		{
		unsigned char					all;
		struct EIOSEG11_BITS		bits;
		};		

/*
#define 	BIIO_P0_0       	0xFE
#define 	OUIO_P0_0 				0xFF
#define 	INIO_P0_0       	0xFF
#define 	ODIO_P0_0 				0xFF
*/
/*
#define		CONTROLIO_P0_0(Mode)       P0_IOCR00 = (P0_IOCR00 & ~0x00F0) | (Mode << 4)
#define		CONTROLIO_P0_1(Mode)       P0_IOCR01 = (P0_IOCR01 & ~0x00F0) | (Mode << 4)
#define		CONTROLIO_P0_2(Mode)       P0_IOCR02 = (P0_IOCR02 & ~0x00F0) | (Mode << 4)
#define		CONTROLIO_P0_3(Mode)       P0_IOCR03 = (P0_IOCR03 & ~0x00F0) | (Mode << 4)
#define		CONTROLIO_P0_4(Mode)       P0_IOCR04 = (P0_IOCR04 & ~0x00F0) | (Mode << 4)
#define		CONTROLIO_P0_5(Mode)       P0_IOCR05 = (P0_IOCR05 & ~0x00F0) | (Mode << 4)
#define		CONTROLIO_P0_6(Mode)       P0_IOCR06 = (P0_IOCR06 & ~0x00F0) | (Mode << 4)
#define		CONTROLIO_P0_7(Mode)       P0_IOCR07 = (P0_IOCR07 & ~0x00F0) | (Mode << 4)
*/

//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void GPIO_Init(void);
void PULLH_Init(void);
void EIOPWM_Init(void);
void EIOTIM_Init(void);
void EIOI2C_Init(void);
void EIOSPI_Init(void);
void EIOUART2_Init(void);
void EIOLCDLED_Init(void);
#endif
