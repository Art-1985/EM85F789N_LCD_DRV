//===============================================================================
//	FILE:				EM85FxxxN_LVD.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2017/03/09
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 09 Mar 2017 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 | 
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Project Includes----------------------------------------------------------//
#include "EM85FxxxN_Device.h"

//=============================================================================
//	Function:			void LVD_Init(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void LVD_Init(int16	EnableCtrl){
	union HLVDCR_REG		LocalVar_A;
	if (EnableCtrl){
		PAGESW				= PAG0;
		LocalVar_A.all		= HLVDCR;
			LocalVar_A.bits.HLVDS			= LVD_Level_3700mV;
			LocalVar_A.bits.VDM				= LVD_Event_Less;
			LocalVar_A.bits.HLVDEN		= LVD_Detect_Enable;
		HLVDCR		= LocalVar_A.all;
		//while (~(HLVDCR & LVD_Ref_Status_Falg)){
		//	HLVDCR1	&= LVD_Status_Falg;}
		}
	else{
		PAGESW				= PAG0;}
	}

//=============================================================================
//	Function:			void vLVD(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void vLVD(void) interrupt 7{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW		= PAG0;
	HLVDCR1		= HLVDCR1 & LVD_Status_Falg;
	PAGESW		= pageTemp;
}
