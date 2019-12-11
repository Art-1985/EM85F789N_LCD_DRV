//===============================================================================
//	FILE:				EM85FxxxN_ADC.c
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
//  0.1 | 07 Mar 2017 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 | 
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Project Includes----------------------------------------------------------//
#include "EM85FxxxN_Device.h"

extern 	Uint16	AdcResult;

//=============================================================================
//	Function:			void ADC_Init(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void ADC_Init(Uint8	EnableCtrl,Uint8 SampleHold){
	union ADCR1_REG		LocalVar_A;
	union ADCR2_REG		LocalVar_B;
	union ADER1_REG		LocalVar_C;
	union ADER2_REG		LocalVar_D;
	union ADER3_REG		LocalVar_E;
	union ADER4_REG		LocalVar_F;
	
	if (EnableCtrl){
		PAGESW				= PAG0;
		LocalVar_A.all		= ADCR1;
			LocalVar_A.bits.SHS			= SampleHold;
			LocalVar_A.bits.ADOM		= ADC_Mode_Continous;
			LocalVar_A.bits.ADP			= ADC_PowerDown_Disable;
			LocalVar_A.bits.ADRUN		= ADC_StartConv_Disable;
			LocalVar_A.bits.CKR			= ADC_CK_Fm_Div_4;
		LocalVar_B.all		= ADCR2;
			LocalVar_B.bits.VREFN		= ADC_VREFN_AGND;
			LocalVar_B.bits.VREFP		= ADC_VREFP_IntRef;
			LocalVar_B.bits.VPIS		= ADC_IntRef_2560mV;
			LocalVar_B.bits.ADCMS		= ADC_CMP_Great;
			LocalVar_B.bits.ADIM		= ADC_Int_ADC;
			LocalVar_B.bits.ADSF		= 0;
		LocalVar_C.all		= ADER1;
			LocalVar_C.bits.ADE0		= ADC_Input_Disable;
			LocalVar_C.bits.ADE1		= ADC_Input_Disable;
			LocalVar_C.bits.ADE2		= ADC_Input_Disable;
			LocalVar_C.bits.ADE3		= ADC_Input_Disable;
			LocalVar_C.bits.ADE4		= ADC_Input_Disable;
			LocalVar_C.bits.ADE5		= ADC_Input_Disable;
			LocalVar_C.bits.ADE6		= ADC_Input_Disable;
			LocalVar_C.bits.ADE7		= ADC_Input_Disable;
		LocalVar_D.all		= ADER2;
			LocalVar_D.bits.ADE8		= ADC_Input_Disable;
			LocalVar_D.bits.ADE9		= ADC_Input_Disable;
			LocalVar_D.bits.ADE10		= ADC_Input_Disable;
			LocalVar_D.bits.ADE11		= ADC_Input_Disable;
			LocalVar_D.bits.ADE12		= ADC_Input_Disable;
			LocalVar_D.bits.ADE13		= ADC_Input_Disable;
			LocalVar_D.bits.ADE14		= ADC_Input_Disable;
			LocalVar_D.bits.ADE15		= ADC_Input_Disable;
		LocalVar_E.all		= ADER3;
			LocalVar_E.bits.ADE16		= ADC_Input_Disable;
			LocalVar_E.bits.ADE17		= ADC_Input_Disable;
			LocalVar_E.bits.ADE18		= ADC_Input_Disable;
			LocalVar_E.bits.ADE19		= ADC_Input_Disable;
			LocalVar_E.bits.ADE20		= ADC_Input_Disable;
			LocalVar_E.bits.ADE21		= ADC_Input_Disable;
			LocalVar_E.bits.ADE22		= ADC_Input_Disable;
			LocalVar_E.bits.ADE23		= ADC_Input_Disable;
		LocalVar_F.all		= ADER4;
			LocalVar_F.bits.ADE24		= ADC_Input_Disable;
			LocalVar_F.bits.ADE25		= ADC_Input_Disable;

		// Channel Select
		ADISR		= ADC_Channel_HVDD;

		PAGESW	= PAG0;
		ADCR1		= LocalVar_A.all;
		ADCR2		= LocalVar_B.all;
		ADER1		= LocalVar_C.all;
		ADER2		= LocalVar_D.all;
		ADER3		= LocalVar_E.all;
		ADER4		= LocalVar_F.all;
		}
	else{
		PAGESW				= PAG0;}
	}

//=============================================================================
//	Function:			void vADC(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void vADC(void) interrupt 13{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW		= PAG0;
	AdcResult	= ADDH;
	AdcResult	= AdcResult << 8;
	AdcResult	= AdcResult | ADDL;
	ADCR2			= ADCR2 & ADC_Status_Falg;
	PAGESW		= pageTemp;
}
