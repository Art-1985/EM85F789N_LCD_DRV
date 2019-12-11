//===============================================================================
//	FILE:				EM85FxxxN_UART.c
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
//	0.2 | 30 Aug 2018 | Arthur| Modified UART0 Initial(Added TM1 Ctrl) 
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Include header files used in the main function--------------//
#include "EM85FxxxN_Device.h"

extern	struct UART_MSG_obj		Msg3;

//=============================================================================
//	Function:			void UART0_Init(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void UART0_Init(int16	EnableCtrl){
		union SCON0_REG			LocalVar_A;
	if (EnableCtrl){
		//For Mode-1,3
		PAGESW	= PAG0;
		CKCON0	= CKCON0 | 0x40;	//T1=Fsys
		TH1			= 245;
		TL1			= 245;
		TCON		= TCON | Timer1_Start;
		
		PAGESW				= PAG0;
		LocalVar_A.all		= SCON0;
			LocalVar_A.bits.RI0		= 0;
			LocalVar_A.bits.TI0		= 0;
			LocalVar_A.bits.RB08	= 0;
			LocalVar_A.bits.TB08	= 0;
			LocalVar_A.bits.REN0	= UART0_Receive_Enable;
			LocalVar_A.bits.MCE0	= UART0_MultiComm_Disable;
			LocalVar_A.bits.SM		= UART0_Mode_1;
			SCON0		= LocalVar_A.all;
		PCON			= PCON | UART0_DoubBaud_Enable;
	}
	else{
		PAGESW				= PAG0;}
	} //  End of function UART0_vInit

//=============================================================================
//	Function:			void UART2_Init(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void UART2_Init(int16	EnableCtrl){
	union UR2CR_REG			LocalVar_A;
	union	UR2S_REG			LocalVar_B;
	union	UR2S2_REG			LocalVar_C;
	if (EnableCtrl){
		PAGESW				= PAG2;
		LocalVar_A.all		= UR2CR;
			LocalVar_A.bits.U2INVEN	= UART2_NormalInHigh;
			LocalVar_A.bits.U2MODE	= UART2_Mode_8Bit;
			LocalVar_A.bits.UR2BRSH = FH_20M_Baud_H_19200;
			LocalVar_A.bits.U2TXE		= UART2_TX_Enable;
			UR2CR	= LocalVar_A.all;
		LocalVar_B.all		= UR2S;
			LocalVar_B.bits.U2RXE 	= UART2_RX_Enable;
			LocalVar_B.bits.U2PRE 	= UART2_Parity_Disable;
			LocalVar_B.bits.U2EVEN 	= UART2_Parity_Odd;
			UR2S	= LocalVar_B.all;
		LocalVar_C.all		= UR2S2;
			LocalVar_C.bits.BUFMODE	= UART2_Mode_Single;
			LocalVar_C.bits.UR2CSS 	= UART2_Clock_FH;
			LocalVar_C.bits.UR2DG 	= UART2_Deglitch_400ns;
			UR2S2	= LocalVar_C.all;
		UR2BRS	= FH_20M_Baud_L_19200;
		}
	else{
		PAGESW				= PAG0;}
	} //  End of function UART2_Init

	
//=============================================================================
//	Function:			void UART0(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void UART0(void) interrupt 4{
	Uint8		pageTemp;
	Uint8		Local_VarA;
	pageTemp	= PAGESW;
	PAGESW				= PAG0;
	if (SCON0 & UART0_TX_Falg){
		//P00	= 0;
		SCON0				= SCON0 & UART0_TX_Falg_Clr;}
	if (SCON0 & UART0_RX_Falg){
		//P00	= 1;
		Local_VarA	= SBUF0;
		SCON0				= SCON0 & UART0_RX_Falg_Clr;}
	PAGESW		= pageTemp;
	Msg3.RxDataByte[0]	= Local_VarA;
	}

//=============================================================================
//	Function:			void UART2(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void UART2(void) interrupt 26{
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW				= PAG2;
	UR2S2			= UR2S2 & 0xF8;
	if (Msg3.Frame >= 8){
		Msg3.Frame = 0x00;
		Msg3.PackageFinish = 0x00;}
	else{
		Msg3.Frame = Msg3.Frame + 1;
		UR2TD		= Msg3.TxDataByte[Msg3.Frame];}
	PAGESW		= pageTemp;}