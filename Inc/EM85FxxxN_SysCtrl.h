//===============================================================================
//	FILE:			EM85FxxxN_SysCtrl.h
//
//	TITLE:		EM85FxxxN_SysCtrl Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2016/11/21
//===============================================================================
#ifndef EM85FxxxN_SysCtrl_H
#define EM85FxxxN_SysCtrl_H

//----------------------------------------------------------------------------
// Defines For The Parameter of Control Register
//----------------------------------------------------------------------------
	#define 	VREF_Output_Enable		0x40
	#define 	CVREF_Output_Enable		0x20
	#define		Timer0_Start					0x10
	#define		Timer1_Start					0x40
	
	#define 	EIE1_TC3IE		0x80
	#define 	EIE1_ADIE			0x40
	#define 	EIE1_CMP2IE		0x20
	#define 	EIE1_SPIIE		0x10
	#define 	EIE1_EEXIE		0x08
	#define 	EIE1_CMP1IE		0x04
	#define 	EIE1_SHIE			0x02
	#define 	EIE1_HLVDIE		0x01

	#define 	EIE2_I2CIE		0x20
	#define 	EIE2_TC4IE		0x08
	#define 	EIE2_PWMBIE		0x02
	#define 	EIE2_PWMAIE		0x01

	#define 	EIE3_EXEIE2		0x80	
	#define 	EIE3_EXEIE1		0x40
	#define 	EIE3_PWMCIE		0x10
	#define 	EIE3_UART2IE	0x08

//----------------------------------------------------------------------------
// Oscillator Register File
//----------------------------------------------------------------------------
	// Clock Control 0 Register File:
	struct CKCON0_BITS	{
		unsigned char		HSPD:1;				// 0
		unsigned char		HSSTABLE:1;		// 1
		unsigned char		LSSTABLE:1;		// 2
		unsigned char		T0M:1;				// 3
		unsigned char		T1M:1;				// 4
		unsigned char		T0SC:1;				// 5
		unsigned char		T1SC:1;				// 6
		unsigned char		SCLKPLL:1;		// 7
		};
	union CKCON0_REG		{
		unsigned char					all;
		struct CKCON0_BITS		bits;};
		#define 	FH_HOSC			0
		#define 	FH_PLL			1
		#define 	TMR_SRC_Fsys_Divider		0
		#define 	TMR_SRC_Fsys_Bypass			1
		#define 	TMR_SRC_Div_12					0
		#define 	TMR_SRC_Div_4						1

	// Clock Control 1 Register File:
	struct CKCON1_BITS	{
		unsigned char		SCLKS:1;			// 0
		unsigned char		FOSCPS:3;			// 3:1
		unsigned char		RCXT:3;				// 6:4
		unsigned char		rsvd1:1;			// 7
		};
	union CKCON1_REG		{
		unsigned char					all;
		struct CKCON1_BITS		bits;};
		#define 	HIRC_4M								0
		#define 	SysClock_Pre_Div_20		0
		#define 	SysClock_Pre_Div_16		1
		#define 	SysClock_Pre_Div_12		2
		#define 	SysClock_Pre_Div_10		3
		#define 	SysClock_Pre_Div_8		4
		#define 	SysClock_Pre_Div_4		5
		#define 	SysClock_Pre_Div_2		6
		#define 	SysClock_Pre_Div_1		7
		#define 	FOSC_FL								0
		#define 	FOSC_FH								1
		
	// Timer Mode Register File:
	struct TMOD_BITS	{
		unsigned char		T0Mx:2;				// 1:0
		unsigned char		CT0:1;				// 2
		unsigned char		GATE0:1;			// 3
		unsigned char		T1Mx:2;				// 5:4
		unsigned char		CT1:1;				// 6
		unsigned char		GATE1:1;			// 7
		};
	union TMOD_REG		{
		unsigned char					all;
		struct TMOD_BITS		bits;};
		#define 	TMR_Run_By_SFR			0
		#define 	TMR_Run_By_INT			1	//Level High
		#define 	TMR_SRC_Timer				0
		#define 	TMR_SRC_Counter			1	//Falling Edge
		#define 	TMR_Mode_13Bit			0
		#define 	TMR_Mode_16Bit			1
		#define 	TMR_Mode_8Bit				2
		#define 	TMR1_Mode_Disable		3
		#define 	TMR0_Mode_2x8Bit		3
		
//----------------------------------------------------------------------------
// Interrupt Register File
//----------------------------------------------------------------------------
	// Extended Interrupt Enable Control Register 1 File:
	struct EIE1_BITS	{
		unsigned char		HLVDIE:1;			// 0
		unsigned char		SHIE:1;				// 1
		unsigned char		CMP1IE:1;			// 2
		unsigned char		rsvd1:1;			// 3
		unsigned char		SPIIE:1;			// 4
		unsigned char		CMP2IE:1;			// 5
		unsigned char		ADIE:1;				// 6
		unsigned char		TC3IE:1;			// 7
		};
	union EIE1_REG		{
		unsigned char					all;
		struct EIE1_BITS			bits;
		};
	// Extended Interrupt Enable Control Register 2 File:
	struct EIE2_BITS	{
		unsigned char		PWMAIE:1;			// 0
		unsigned char		PWMBIE:1;			// 1
		unsigned char		rsvd1:1;			// 2
		unsigned char		TC4IE:1;			// 3
		unsigned char		rsvd2:1;			// 4
		unsigned char		I2CIE:1;			// 5
		unsigned char		rsvd3:1;			// 6
		unsigned char		rsvd4:1;			// 7
		};
	union EIE2_REG		{
		unsigned char					all;
		struct EIE2_BITS			bits;
		};
	// Extended Interrupt Enable Control Register 3 File:
	struct EIE3_BITS	{
		unsigned char		rsvd1:1;		// 0
		unsigned char		rsvd2:1;		// 1
		unsigned char		rsvd3:1;		// 2
		unsigned char		UART2IE:1;	// 3
		unsigned char		PWMCIE:1;		// 4
		unsigned char		rsvd4:1;		// 5
		unsigned char		EXEIE1:1;		// 6
		unsigned char		EXEIE2:1;		// 7
		};
	union EIE3_REG		{
		unsigned char					all;
		struct EIE3_BITS			bits;
		};
	#define		Int_Mask_Disable		0
	#define		Int_Mask_Enable			1

	// Extended Interrupt Priority Control Register 1 File:
	struct EIP1_BITS	{
		unsigned char		PHLVD:1;		// 0
		unsigned char		PSH:1;			// 1
		unsigned char		PCMP1:1;		// 2
		unsigned char		rsvd1:1;		// 3
		unsigned char		PSPI:1;			// 4
		unsigned char		PCMP2:1;		// 5
		unsigned char		PAD:1;			// 6
		unsigned char		PTC3:1;			// 7
		};
	union EIP1_REG		{
		unsigned char					all;
		struct EIP1_BITS			bits;
		};
	// Extended Interrupt Priority Control Register 2 File:
	struct EIP2_BITS	{
		unsigned char		PPWMA:1;			// 0
		unsigned char		PPWMB:1;			// 1
		unsigned char		rsvd1:1;			// 2
		unsigned char		PTC4:1;				// 3
		unsigned char		rsvd2:1;			// 4
		unsigned char		PI2C:1;				// 5
		unsigned char		rsvd3:1;			// 6
		unsigned char		rsvd4:1;			// 7
		};
	union EIP2_REG		{
		unsigned char					all;
		struct EIP2_BITS			bits;
		};
	// Extended Interrupt Priority Control Register 3 File:
	struct EIP3_BITS	{
		unsigned char		rsvd1:1;		// 0
		unsigned char		rsvd2:1;		// 1
		unsigned char		rsvd3:1;		// 2
		unsigned char		PUART2:1;		// 3
		unsigned char		PPWMC:1;		// 4
		unsigned char		rsvd4:1;		// 5
		unsigned char		PEX1:1;			// 6
		unsigned char		PEX2:1;			// 7
		};
	union EIP3_REG		{
		unsigned char					all;
		struct EIP3_BITS			bits;
		};
	#define		Int_Priority_Low		0
	#define		Int_Priority_Hi			1

//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void Oscillator_Init(int);
void IntMask_Init(int);
void IntPriority_Init(int);
void DelayFunc(int);
void delay_sec(int);
void Delay(unsigned int);
/*
void SRAM_Write(unsigned int wAddr, unsigned int wLength, unsigned char wData);
void SRAM_ByteWrite(unsigned int wAddr, unsigned char wData);
*/
#endif