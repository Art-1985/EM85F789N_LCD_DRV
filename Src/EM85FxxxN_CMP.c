//===============================================================================
//	FILE:				EM85FxxxN_CMP.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2017/08/01
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 01 Aug 2017 | Arthur| Original Release.
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
//	Function:			void CMP_Init(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void CMP_Init(Uint8	EnableCtrl){
	if (EnableCtrl){
		PAGESW				= PAG0;
		OP1_AutoTrim();
		CMP1_AutoTrim();
		CMP2_AutoTrim();
		OPCMP1_Init();
		CMP2_Init();}
	else{
		PAGESW				= PAG0;}
	}	

	
//=============================================================================
//	Function:			void OP1_AutoTrim(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void OP1_AutoTrim(void){
	union OPCMP1CR1_REG		LocalVar_A;
	union CMPNRCR1_REG		LocalVar_B;
	Uint8	LowTrimCode,RollingCode,SignCode,StateFlag,LoopCounter;
	PAGESW		= PAG0;
	LocalVar_A.all	= OPCMP1CR1;
		LocalVar_A.bits.OPCMP1EN	= OPCMP_Enable;
		LocalVar_A.bits.OPCMP1SW	= OPCMP_Mode_OPA;
		LocalVar_A.bits.CMP1OUTEN	= CMP_PadOut_Disable;
		OPCMP1CR1	= LocalVar_A.all;
	LocalVar_B.all	= CMPNRCR1;
		LocalVar_B.bits.CMP1NREN	= CMP_NoiseRejection_Disable;
		LocalVar_B.bits.CMP2NREN	= CMP_NoiseRejection_Disable;
		LocalVar_B.bits.NRC				= CMP_NoiseRejection_x2;
		CMPNRCR1	= LocalVar_B.all;
	
	PAGESW		= PAG1;
	CO1TRL		= 0x80;	//Enable Trim Mode
	RollingCode	= 0x00;
	
	PAGESW		= PAG0;
	StateFlag	= (OPCMP1CR1 & 0x10);
	if (StateFlag){
		SignCode	= 0x40;}
	else{
		SignCode	= 0x00;}
	for (LoopCounter=0;LoopCounter<=15;LoopCounter++){
		RollingCode	= RollingCode + 1;
		LowTrimCode	= RollingCode;
		LowTrimCode = LowTrimCode | SignCode;
		LowTrimCode	= LowTrimCode | 0x80;	
		PAGESW		= PAG1;
		CO1TRL		= LowTrimCode;
		PAGESW		= PAG0;
		if((OPCMP1CR1 & 0x10) != StateFlag){
			break;}
		}
		PAGESW	= PAG1;
		CO1TRL	= CO1TRL & 0x7F;
	}
//=============================================================================
//	Function:			void CMP1_AutoTrim(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void CMP1_AutoTrim(void){
	union OPCMP1CR1_REG		LocalVar_A;
	union CMPNRCR1_REG		LocalVar_B;
	Uint8	LowTrimCode,RollingCode,SignCode,StateFlag,LoopCounter;
	PAGESW		= PAG0;
	LocalVar_A.all	= OPCMP1CR1;
		LocalVar_A.bits.OPCMP1EN	= OPCMP_Enable;
		LocalVar_A.bits.OPCMP1SW	= OPCMP_Mode_CMP;
		LocalVar_A.bits.CMP1OUTEN	= CMP_PadOut_Disable;
		OPCMP1CR1	= LocalVar_A.all;
	LocalVar_B.all	= CMPNRCR1;
		LocalVar_B.bits.CMP1NREN	= CMP_NoiseRejection_Disable;
		LocalVar_B.bits.CMP2NREN	= CMP_NoiseRejection_Disable;
		LocalVar_B.bits.NRC				= CMP_NoiseRejection_x2;
		CMPNRCR1	= LocalVar_B.all;
	
	PAGESW		= PAG1;
	CO1TRL		= 0x80;	//Enable Trim Mode
	RollingCode	= 0x00;
	
	PAGESW		= PAG0;
	StateFlag	= (OPCMP1CR1 & 0x10);
	if (StateFlag){
		SignCode	= 0x40;}
	else{
		SignCode	= 0x00;}
	for (LoopCounter=0;LoopCounter<=15;LoopCounter++){
		RollingCode	= RollingCode + 1;
		LowTrimCode	= RollingCode;
		LowTrimCode = LowTrimCode | SignCode;
		LowTrimCode	= LowTrimCode | 0x80;	
		PAGESW		= PAG1;
		CO1TRL		= LowTrimCode;
		PAGESW		= PAG0;
		if((OPCMP1CR1 & 0x10) != StateFlag){
			break;}
		}
		PAGESW	= PAG1;
		CO1TRL	= CO1TRL & 0x7F;
	}
//=============================================================================
//	Function:			void CMP2_AutoTrim(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void CMP2_AutoTrim(void){
	union CMP2CR1_REG			LocalVar_A;
	union CMPNRCR1_REG		LocalVar_B;
	Uint8	LowTrimCode,RollingCode,SignCode,StateFlag,LoopCounter;
	PAGESW		= PAG0;
	LocalVar_A.all	= CMP2CR1;
		LocalVar_A.bits.CMP2EN		= OPCMP_Enable;
		LocalVar_A.bits.CMP2OUTEN	= CMP_PadOut_Disable;
		CMP2CR1	= LocalVar_A.all;
	LocalVar_B.all	= CMPNRCR1;
		LocalVar_B.bits.CMP1NREN	= CMP_NoiseRejection_Disable;
		LocalVar_B.bits.CMP2NREN	= CMP_NoiseRejection_Disable;
		LocalVar_B.bits.NRC				= CMP_NoiseRejection_x2;
		CMPNRCR1	= LocalVar_B.all;
	
	//-----TrimLowSide------//
	PAGESW		= PAG1;
	CO2TRL		= CO2TRL | 0x80;	//Enable Trim Mode,LowSide
	CO2TRH		= CO2TRH | 0x00;	//TrimStep 0.7mV
	RollingCode	= 0x00;
	PAGESW		= PAG0;
	StateFlag	= (CMP2CR1 & 0x10);
	if (StateFlag){
		SignCode	= 0x20;}
	else{
		SignCode	= 0x00;}
	
	for (LoopCounter=0;LoopCounter<=31;LoopCounter++){
		RollingCode	= RollingCode + 1;
		LowTrimCode	= RollingCode;
		LowTrimCode = LowTrimCode | SignCode;
		LowTrimCode	= LowTrimCode | 0x80;	
		PAGESW		= PAG1;
		CO2TRL		= LowTrimCode;
		PAGESW		= PAG0;
		if((CMP2CR1 & 0x10) != StateFlag){
			break;}	}
	
	//-----TrimHighSide------//
	PAGESW		= PAG1;
	CO2TRL		= CO2TRL | 0xC0;	//Enable Trim Mode,HighSide
	CO2TRH		= CO2TRH | 0x00;	//TrimStep 0.7mV
	RollingCode	= 0x00;
	PAGESW		= PAG0;
	StateFlag	= (CMP2CR1 & 0x10);
	if (StateFlag){
		SignCode	= 0x20;}
	else{
		SignCode	= 0x00;}
	
	for (LoopCounter=0;LoopCounter<=31;LoopCounter++){
		RollingCode	= RollingCode + 1;
		LowTrimCode	= RollingCode;
		LowTrimCode = LowTrimCode | SignCode;
		LowTrimCode	= LowTrimCode | 0x00;	
		PAGESW		= PAG1;
		CO2TRH		= LowTrimCode;
		PAGESW		= PAG0;
		if((CMP2CR1 & 0x10) != StateFlag){
			break;}	}
	//-----End of TrimMode------//
	PAGESW	= PAG1;
	CO2TRL	= CO2TRL & 0x7F;
	}
	
	
//=============================================================================
//	Function:			void OPCMP1_Init(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void OPCMP1_Init(void){
	union OPCMP1CR1_REG		LocalVar_A;
	union OPCMP1CR2_REG		LocalVar_B;
	union CMPNRCR1_REG		LocalVar_C;
	PAGESW		= PAG0;
	LocalVar_A.all	= OPCMP1CR1;
		LocalVar_A.bits.OPCMP1EN	= OPCMP_Enable;
		LocalVar_A.bits.OPCMP1SW	= OPCMP_Mode_OPA;
		LocalVar_A.bits.CMP1OUTEN	= CMP_PadOut_Disable;
		LocalVar_A.bits.SC1PWMEG	= CMP_DisPWM_Edge_Rising;
		OPCMP1CR1	= LocalVar_A.all;
	LocalVar_B.all	= OPCMP1CR2;
		LocalVar_B.bits.OPCMP1NIVS	= CMP_CH_Pos_Pad;
		LocalVar_B.bits.OPCMP1PIVS	= CMP_CH_Pos_Pad;
		LocalVar_B.bits.OPCMP1PIPS	= CMP_CH_Pos_Pad_1;	
		OPCMP1CR2	= LocalVar_B.all;
	LocalVar_C.all	= CMPNRCR1;
		LocalVar_C.bits.CMP1NREN	= CMP_NoiseRejection_Disable;
		LocalVar_C.bits.CMP2NREN	= CMP_NoiseRejection_Disable;
		LocalVar_C.bits.NRC				= CMP_NoiseRejection_x2;
		CMPNRCR1	= LocalVar_C.all;
	
	}

//=============================================================================
//	Function:			void CMP2_Init(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void CMP2_Init(void){
	union CMP2CR1_REG		LocalVar_A;
	union CMP2CR2_REG		LocalVar_B;
	union CMPNRCR1_REG		LocalVar_C;
	PAGESW		= PAG0;
	LocalVar_A.all	= CMP2CR1;
		LocalVar_A.bits.CMP2EN	= OPCMP_Enable;
		LocalVar_A.bits.CMP2OUTEN	= CMP_PadOut_Enable;
		LocalVar_A.bits.SC2PWMEG	= CMP_DisPWM_Edge_Rising;
		CMP2CR1	= LocalVar_A.all;
	LocalVar_B.all	= CMP2CR2;
		LocalVar_B.bits.CMP2NIVS	= CMP_CH_Neg_IntVref;
		LocalVar_B.bits.CMP2PIVS	= CMP_CH_Pos_Pad;
		LocalVar_B.bits.CMP2PIPS	= CMP_CH_Pos_Pad_2;	
		CMP2CR2	= LocalVar_B.all;
	LocalVar_C.all	= CMPNRCR1;
		LocalVar_C.bits.CMP1NREN	= CMP_NoiseRejection_Disable;
		LocalVar_C.bits.CMP2NREN	= CMP_NoiseRejection_Disable;
		LocalVar_C.bits.NRC				= CMP_NoiseRejection_x2;
		CMPNRCR1	= LocalVar_C.all;
		BGREF0			= CMP_VREF_512;
	}

//=============================================================================
//	Function:			void vCMP1(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void vCMP1(void) interrupt 9{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW	= PAG0;
	COSF1		= COSF1 & 0xFE;
	
	PAGESW		= pageTemp;}

//=============================================================================
//	Function:			void vCMP2(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void vCMP2(void) interrupt 12{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW	= PAG0;
	COSF1		= COSF1 & 0xFD;

	PAGESW		= pageTemp;}