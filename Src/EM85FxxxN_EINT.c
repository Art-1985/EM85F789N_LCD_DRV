//===============================================================================
//	FILE:				EM85FxxxN_EINT.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2017/06/12
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 12 Jun 2017 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 |             |       | 
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Include header files used in the main function--------------//
#include "EM85FxxxN_Device.h"
	extern	Uint8		SlaveWriteFinish;
	extern	Uint8		extTrigger;


//=============================================================================
//	Function:			void EINT_Init(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void EINT_Init(int16	EnableCtrl){
	union EIESC1_REG		LocalVar_A;
	union EXEN0_REG			LocalVar_B;
	union EXEN1_REG			LocalVar_C;
	union EIES2_REG			LocalVar_D;
	union EIES3_REG			LocalVar_E;
	union EIES4_REG			LocalVar_F;
	
	if (EnableCtrl){
		//EINT 0~1, Enable Control By IE
		PAGESW			= PAG0;
		TCON				= TCON | 0x01; // Edge Trigger
		//TCON				= TCON & 0xFE; // Level Trigger
		
		//EINT Deglitch
		PAGESW			= PAG0;
		LocalVar_A.all					= EIESC1;
			LocalVar_A.bits.EIEDG	= EINT_DeGlitch_400ns;	
			LocalVar_A.bits.EIES0	= EINT_Edge_Falling;	
			LocalVar_A.bits.EIES1	= EINT_Edge_Falling;	
			EIESC1								= LocalVar_A.all;
		
		//EINT 2~11
		PAGESW			= PAG2;
		LocalVar_B.all					= EXEN0;
			LocalVar_B.bits.EXE2	=	Func_Pin_Disable;	
			LocalVar_B.bits.EXE3	=	Func_Pin_Disable;	
			LocalVar_B.bits.EXE4	=	Func_Pin_Disable;	
			LocalVar_B.bits.EXE5	=	Func_Pin_Disable;	
			LocalVar_B.bits.EXE6	=	Func_Pin_Disable;	
			LocalVar_B.bits.EXE7	=	Func_Pin_Disable;	
			LocalVar_B.bits.EXE8	=	Func_Pin_Disable;	
			LocalVar_B.bits.EXE9	=	Func_Pin_Disable;	
			EXEN0									= LocalVar_B.all;
		LocalVar_C.all					= EXEN1;
			LocalVar_C.bits.EXE10	=	Func_Pin_Disable;	
			LocalVar_C.bits.EXE11	=	Func_Pin_Disable;
			EXEN1									= LocalVar_C.all;		
		LocalVar_D.all					= EIES2;
			LocalVar_D.bits.EI2ES	=	EINT_Edge_Falling;
			LocalVar_D.bits.EI3ES	=	EINT_Edge_Falling;
			LocalVar_D.bits.EI4ES	=	EINT_Edge_Falling;
			LocalVar_D.bits.EI5ES	=	EINT_Edge_Falling;
			EIES2								= LocalVar_D.all;
		LocalVar_E.all					= EIES3;
			LocalVar_E.bits.EI6ES	=	EINT_Edge_Falling;
			LocalVar_E.bits.EI7ES	=	EINT_Edge_Falling;
			LocalVar_E.bits.EI8ES	=	EINT_Edge_Falling;
			LocalVar_E.bits.EI9ES	=	EINT_Edge_Falling;
			EIES3								= LocalVar_E.all;
		LocalVar_F.all					= EIES4;
			LocalVar_F.bits.EI10ES	=	EINT_Edge_Falling;
			LocalVar_F.bits.EI11ES	=	EINT_Edge_Falling;
			EIES4								= LocalVar_F.all;
		}
	else{
		PAGESW				= PAG0;}
	} //  End of function EINT_vInit

//=============================================================================
//	Function:			void EINT(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void EINT0(void) interrupt 0{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	// Flage will clear by HW

	PAGESW		= pageTemp;}

void EINT1(void) interrupt 2{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	// Flage will clear by HW
	PAGESW	= PAG0;
	
	PAGESW		= pageTemp;}

void EINT29(void) interrupt 29{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	// Extreinal Interrupt 2~9
	PAGESW	= PAG2;
	EXSF2		= 0x00;
	EXSF3		= 0x00;
	PAGESW		= pageTemp;}

void EINTAB(void) interrupt 30{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	// Extreinal Interrupt 10~11
	PAGESW	= PAG2;
	EXSF4		= 0x00;
	
	PAGESW		= pageTemp;	}
