//===============================================================================
//	FILE:				EM85FxxxN_TIM.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2017/03/07
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 21 Nov 2016 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 | 07 Mar 2017 | Arthur| Add EnableCtrl to avoide warning
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Project Includes----------------------------------------------------------//
#include "EM85FxxxN_Device.h"

//--External Prototypes-------------------------------------------------------//
//extern void xxx(void);


//=============================================================================
//	Function:			void TIM_Init(void)
//
//	Description:	123
//
//	Returnvalue:	Null
//
//=============================================================================
void TIM_Init(int16	EnableCtrl){
	if (EnableCtrl){
		TM01_Init();
		TM2_Init();
		TM3_Init();
		TM4_Init();
		PAGESW				= PAG0;
		TH0			=	0xFF;
		TL0			=	0xFF;
		TH1			=	0xFF;
		TL1			= 0xFF;
		TC3DBH	=	0x00;	// Duty
		TC3DBL	=	0x00;	// Duty
		TC3DAH	=	0x2F;	// Period
		TC3DAL	=	0xFF;	// Period
		TC4DBH	=	0x3F;	// Duty
		TC4DBL	=	0xFF;	// Duty
		TC4DAH	=	0x7F;	// Period
		TC4DAL	=	0xFF;	// Period
		
		//TCON		|= Timer0_Start;
		//TCON		|= Timer1_Start;
		//TC3CR1	|=	Time3_Start;
		//TC4CR1	|=	Time4_Start;
	}
	else{
		PAGESW				= PAG0;}
	}

void TM01_Init(void){
	union CKCON0_REG	LocalVar_A;
	union TMOD_REG		LocalVar_B;
	PAGESW			= PAG0;
	LocalVar_A.all		= CKCON0;
		LocalVar_A.bits.T0M			= TMR_SRC_Div_12;
		LocalVar_A.bits.T1M			= TMR_SRC_Div_4;
		LocalVar_A.bits.T0SC		= TMR_SRC_Fsys_Divider;
		LocalVar_A.bits.T1SC		= TMR_SRC_Fsys_Bypass;
	LocalVar_B.all		= TMOD;
		LocalVar_B.bits.T0Mx			= TMR0_Mode_2x8Bit;
		LocalVar_B.bits.CT0				= TMR_SRC_Timer;
		LocalVar_B.bits.GATE0			= TMR_Run_By_SFR;
		LocalVar_B.bits.T1Mx			= TMR_Mode_8Bit;
		LocalVar_B.bits.CT1				= TMR_SRC_Timer;
		LocalVar_B.bits.GATE1			= TMR_Run_By_SFR;
	CKCON0		= LocalVar_A.all;
	TMOD			= LocalVar_B.all;
	}

void TM2_Init(void){
	//ERTCIE		= 1;
	PAGESW			= PAG1;
	/*
	RTCCON		|= 0xA4;
	RTCDATAH	|= 0x00;
	RTCDATAL	|= 0x00;
	ALARM			|= 0x00;
	RTCCAL1		|= 0x00;
	RTCCAL2		|= 0x00;
	*/
	}

void TM3_Init(void){
	union TC3CR1_REG	LocalVar_A;
	union TC3CR2_REG	LocalVar_B;
	union TC3CR3_REG	LocalVar_C;
	PAGESW					= PAG0;
	LocalVar_A.all	= TC3CR1;
		LocalVar_A.bits.TC3ISx	= Timer_PWM_Int_BOTH;
		LocalVar_A.bits.TC3OMS	= Timer_Repeat_Enable;
		LocalVar_A.bits.TC3FF		= Timer_PWM_ActiveHi;
		LocalVar_A.bits.TC3DASF	= 0;
		LocalVar_A.bits.TC3DBSF	= 0;
		LocalVar_A.bits.TC3RC		= Timer_Raed_Disable;
		LocalVar_A.bits.TC3S		= Timer_Start_Disable;
	LocalVar_B.all	= TC3CR2;
		LocalVar_B.bits.TC3CKx	= Timer_Clock_Div_32;
		LocalVar_B.bits.TC3Mx		= Timer_Mode_Counter_Rising;
	LocalVar_C.all	= TC3CR3;
		LocalVar_C.bits.TC3SSx		= Timer_ClockSrc_FHS;
		LocalVar_C.bits.TC3SCSx		= Timer_TriggerBy_TCxS;
	
	TC3CR1		= LocalVar_A.all;
	TC3CR2		= LocalVar_B.all;
	TC3CR3		= LocalVar_C.all;
	}

void TM4_Init(void){
	union TC4CR1_REG	LocalVar_A;
	union TC4CR2_REG	LocalVar_B;
	union TC4CR3_REG	LocalVar_C;
	PAGESW					= PAG0;
	LocalVar_A.all	= TC4CR1;
		LocalVar_A.bits.TC4ISx	= Timer_PWM_Int_BOTH;
		LocalVar_A.bits.TC4OMS	= Timer_Repeat_Enable;
		LocalVar_A.bits.TC4FF		= Timer_PWM_ActiveHi;
		LocalVar_A.bits.TC4DASF	= 0;
		LocalVar_A.bits.TC4DBSF	= 0;
		LocalVar_A.bits.TC4RC		= Timer_Raed_Disable;
		LocalVar_A.bits.TC4S		= Timer_Start_Disable;
	LocalVar_B.all	= TC4CR2;
		LocalVar_B.bits.TC4CKx	= Timer_Clock_Div_32;
		LocalVar_B.bits.TC4Mx		= Timer_Mode_Counter_Rising;
	LocalVar_C.all	= TC4CR3;
		LocalVar_C.bits.TC4SSx		= Timer_ClockSrc_FHS;
		LocalVar_C.bits.TC4SCSx		= Timer_TriggerBy_TCxS;
	
	TC4CR1		= LocalVar_A.all;
	TC4CR2		= LocalVar_B.all;
	TC4CR3		= LocalVar_C.all;
	}

	
//=============================================================================
//	Function:			void Timer0(void),void Timer1(void)
//
//	Description:	123
//
//	Returnvalue:	Null
//
//=============================================================================
void Timer0(void) interrupt 1{
	Uint8		pageTemp;
	pageTemp	= PAGESW;	
	PAGESW				= PAG0;
	
	PAGESW		= pageTemp;
}

void Timer1(void) interrupt 3{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW				= PAG0;

	PAGESW		= pageTemp;
}
	
//=============================================================================
//	Function:			void Timer3(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void Timer3(void) interrupt 14{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW				= PAG0;
	if (TC3CR1 & Time3_DA_Falg){
		TC3CR1	&=	(~Time3_DA_Falg);
	}
	if (TC3CR1 & Time3_DB_Falg){
		TC3CR1	&=	(~Time3_DB_Falg);
	}
	PAGESW		= pageTemp;
}

//=============================================================================
//	Function:			void Timer4(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void vTimer4(void) interrupt 18{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW				= PAG0;
	if (TC4CR1 & Time4_DA_Falg){
		TC4CR1	&=	(~Time4_DA_Falg);
	}
	if (TC4CR1 & Time4_DB_Falg){
		TC4CR1	&=	(~Time4_DB_Falg);
	}
	PAGESW		= pageTemp;
}

	
