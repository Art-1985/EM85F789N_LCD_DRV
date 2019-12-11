//===============================================================================
//	FILE:				EM85FxxxN_PWM.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2016/11/21
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 21 Nov 2016 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 | 06 Mar 2017 | Arthur| Add EnableCtrl to avoide warning
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Project Includes----------------------------------------------------------//
#include "EM85FxxxN_Device.h"

//=============================================================================
//	Function:			void PWM_Init(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void PWM_Init(int16	EnableCtrl){
	union PWMENCR_REG	LocalVar_A;
	if (EnableCtrl){
		PWMA_Init();
		PWMB_Init();
		PWMC_Init();
		PAGESW				= PAG1;
		DEADTR				= 0x0F;		// DeadTime Counter(For All PWM)
		LocalVar_A.all					= PWMENCR;
			LocalVar_A.bits.DEADTP	= PWM_DT_Pre_Div_1;
			PWMENCR									= LocalVar_A.all;
		
		//PWM start must be after deadtime setting
		LocalVar_A.all					= PWMENCR;
			LocalVar_A.bits.TAEN		= PWM_Start_Enable;
			//LocalVar_A.bits.TBEN		= PWM_Start_Enable;
			//LocalVar_A.bits.TCEN		= PWM_Start_Enable;
			PWMENCR									= LocalVar_A.all;
		}
	else{
		PAGESW				= PAG0;}
	}

void PWMA_Init(void){
	union PWMACR1_REG	LocalVar_A;
	union PWMACR2_REG	LocalVar_B;
	PAGESW				= PAG1;
	LocalVar_A.all				= PWMACR1;
	LocalVar_B.all				= PWMACR2;
		LocalVar_A.bits.PWMAE			= PWM_Pin_Enable;
		LocalVar_A.bits.IPWMAE		= PWM_Pin_Enable;
		LocalVar_A.bits.PWMAA			= PWM_Active_Hi;
		LocalVar_A.bits.IPWMAA		= PWM_Active_Hi;
		LocalVar_A.bits.TAP				= PWM_TMR_Pre_Div2;
		LocalVar_B.bits.PWMAPSF		= 0;
		LocalVar_B.bits.PWMADSF		= 0;	
		LocalVar_B.bits.PWMACMPLC	= PWM_Sync_CMP_Disable;
		LocalVar_B.bits.PWMASWAP	= PWM_Swap_Disable;
		LocalVar_B.bits.PWMAOSM		= PWM_OneShot_Disable;
		LocalVar_B.bits.PWMAS			= PWM_Src_PLL;	
		LocalVar_B.bits.DEADTAE		= PWM_DeadTime_Enable;
	PWMACR1		= LocalVar_A.all;
	PWMACR2		= LocalVar_B.all;
	DTAH			= 0x00;
	DTAL			= 0x7F;
	PRDAH			= 0x01;	
	PRDAL			= 0xFF;	
	}
void PWMB_Init(void){
	union PWMBCR1_REG	LocalVar_A;
	union PWMBCR2_REG	LocalVar_B;
	PAGESW				= PAG1;
	LocalVar_A.all				= PWMBCR1;
	LocalVar_B.all				= PWMBCR2;
		LocalVar_A.bits.PWMBE			= PWM_Pin_Enable;
		LocalVar_A.bits.IPWMBE		= PWM_Pin_Enable;
		LocalVar_A.bits.PWMBA			= PWM_Active_Hi;
		LocalVar_A.bits.IPWMBA		= PWM_Active_Hi;
		LocalVar_A.bits.TBP				= PWM_TMR_Pre_Div1;
		LocalVar_B.bits.PWMBPSF		= 0;
		LocalVar_B.bits.PWMBDSF		= 0;	
		LocalVar_B.bits.PWMBCMPLC	= PWM_Sync_CMP_Disable;
		LocalVar_B.bits.PWMBSWAP	= PWM_Swap_Disable;
		LocalVar_B.bits.PWMBOSM		= PWM_OneShot_Disable;
		LocalVar_B.bits.PWMBS			= PWM_Src_PLL;	
		LocalVar_B.bits.DEADTBE		= PWM_DeadTime_Disable;
	PWMBCR1		= LocalVar_A.all;
	PWMBCR2		= LocalVar_B.all;
	DTBH			= 0x00;
	DTBL			= 0x3F;
	PRDBH			= 0x01;	
	PRDBL			= 0xFF;	
	}
void PWMC_Init(void){
	union PWMCCR1_REG	LocalVar_A;
	union PWMCCR2_REG	LocalVar_B;
	PAGESW				= PAG1;
	LocalVar_A.all				= PWMCCR1;
	LocalVar_B.all				= PWMCCR2;
		LocalVar_A.bits.PWMCE			= PWM_Pin_Enable;
		LocalVar_A.bits.IPWMCE		= PWM_Pin_Enable;
		LocalVar_A.bits.PWMCA			= PWM_Active_Hi;
		LocalVar_A.bits.IPWMCA		= PWM_Active_Hi;
		LocalVar_A.bits.TCP				= PWM_TMR_Pre_Div2;
		LocalVar_B.bits.PWMCPSF		= 0;
		LocalVar_B.bits.PWMCDSF		= 0;	
		LocalVar_B.bits.PWMCCMPLC	= PWM_Sync_CMP_Disable;
		LocalVar_B.bits.PWMCSWAP	= PWM_Swap_Disable;
		LocalVar_B.bits.PWMCOSM		= PWM_OneShot_Disable;
		LocalVar_B.bits.PWMCS			= PWM_Src_PLL;	
		LocalVar_B.bits.DEADTCE		= PWM_DeadTime_Disable;
	PWMCCR1		= LocalVar_A.all;
	PWMCCR2		= LocalVar_B.all;
	DTCH			= 0x0B;
	DTCL			= 0xB8;
	PRDCH			= 0x17;	
	PRDCL			= 0x70;	
	}
	
//=============================================================================
//	Function:			void vPWMA(void),void vPWMB(void),void vPWMC(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void vPWMA(void) interrupt 15{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW				= PAG1;
	if (PWMACR2 & PWMx_PM_Falg){
		PWMACR2	&=	(~PWMx_PM_Falg);	// Clear Flag
		}
	if (PWMACR2 & PWMx_DM_Falg){
		PWMACR2	&=	(~PWMx_DM_Falg);	// Clear Flag
		}
	PAGESW		= pageTemp;}
//=============================================================================
//	Function:			void vPWMB(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void vPWMB(void) interrupt 16{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW				= PAG1;
	if (PWMBCR2 & PWMx_PM_Falg){
		PWMBCR2	&=	(~PWMx_PM_Falg);	// Clear Flag
		}
	if (PWMBCR2 & PWMx_DM_Falg){
		PWMBCR2	&=	(~PWMx_DM_Falg);	// Clear Flag
		}
	PAGESW		= pageTemp;}
//=============================================================================
//	Function:			void vPWMC(void
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void vPWMC(void) interrupt 27{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW				= PAG1;
	if (PWMCCR2 & PWMx_PM_Falg){
		PWMCCR2	&=	(~PWMx_PM_Falg);	// Clear Flag
		}
	if (PWMCCR2 & PWMx_DM_Falg){
		PWMCCR2	&=	(~PWMx_DM_Falg);	// Clear Flag
		}
	PAGESW		= pageTemp;}

