//===============================================================================
//	FILE:				EM85FxxxN_SysCtrl.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2016/12/02
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 02 Dec 2016 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 |             |       | 
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Include header files used in the main function--------------//
#include "EM85FxxxN_Device.h"

//=============================================================================
//	Function:			void Oscillator_Init(int)
//
//	Description:	NA 
//
//	Returnvalue:	Null
//
//=============================================================================
void Oscillator_Init(int16 EnableCtrl){
	union CKCON0_REG			LocalVar_A;
	union CKCON1_REG			LocalVar_B;
	if (EnableCtrl){
		PAGESW		= PAG0;
		LocalVar_A.all		= CKCON0;
		LocalVar_B.all		= CKCON1;
		CKCON0						= LocalVar_A.all;
		CKCON1						= LocalVar_B.all;
		PAGESW		= PAG2;
		//HIRCTCTR1	= HIRCTCTR1 | VREF_Output_Enable;
		//HIRCTCTR1	= HIRCTCTR1 | CVREF_Output_Enable;
					}
	else{
		PAGESW			= PAG0;}
} //  End of function Oscillator_Init


//=============================================================================
//	Function:			void IntMask_Init(void)
//
//	Description:	NA 
//
//	Returnvalue:	Null
//
//=============================================================================
void IntMask_Init(int16 EnableCtrl){
	union EIE1_REG			LocalVar_A;
	union EIE2_REG			LocalVar_B;
	union EIE3_REG			LocalVar_C;

	if (EnableCtrl){
		PAGESW			= PAG0;
			ICIE				= Int_Mask_Disable;		// Pin Change
			ERTCIE			= Int_Mask_Disable;		// RTC (Timer2)
			ES0					= Int_Mask_Disable;		// Searial Port(UART0)
			ET1					= Int_Mask_Disable;		// Timer1
			EX1					= Int_Mask_Disable;		// Exterinal INT1
			ET0					= Int_Mask_Disable;		// Timer0
			EX0					= Int_Mask_Disable;		// Exterinal INT0	
		LocalVar_A.all	= EIE1;
			LocalVar_A.bits.HLVDIE	= Int_Mask_Disable;
			LocalVar_A.bits.SHIE		= Int_Mask_Disable;
			LocalVar_A.bits.CMP1IE	= Int_Mask_Disable;
			LocalVar_A.bits.SPIIE		= Int_Mask_Disable;
			LocalVar_A.bits.CMP2IE	= Int_Mask_Disable;
			LocalVar_A.bits.ADIE		= Int_Mask_Disable;
			LocalVar_A.bits.TC3IE		= Int_Mask_Disable;
		LocalVar_B.all	= EIE2;
			LocalVar_B.bits.PWMAIE	= Int_Mask_Disable;
			LocalVar_B.bits.PWMBIE	= Int_Mask_Disable;	
			LocalVar_B.bits.TC4IE		= Int_Mask_Disable;	
			LocalVar_B.bits.I2CIE		= Int_Mask_Disable;	
		LocalVar_C.all	= EIE3;
			LocalVar_C.bits.UART2IE	= Int_Mask_Enable;
			LocalVar_C.bits.PWMCIE	= Int_Mask_Disable;
			LocalVar_C.bits.EXEIE1	= Int_Mask_Disable;
			LocalVar_C.bits.EXEIE2	= Int_Mask_Disable;
		EIE1			=  LocalVar_A.all;
		EIE2			=  LocalVar_B.all;
		EIE3			=  LocalVar_C.all;
		}
	else{
		PAGESW			= PAG0;}
	
} //  End of function IntMask_Init


//=============================================================================
//	Function:			void IntPriority_Init(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void IntPriority_Init(int16 EnableCtrl){
	union EIP1_REG			LocalVar_A;
	union EIP2_REG			LocalVar_B;
	union EIP3_REG			LocalVar_C;

	if (EnableCtrl){
		PAGESW		= PAG0;
			PX0				= Int_Priority_Low;	// EINT0
			PT0				= Int_Priority_Low;	// Timer0
			PX1				= Int_Priority_Low;	// EINT1
			PT1				= Int_Priority_Low;	// Timer1	
			PS0				= Int_Priority_Low;	// UART0
			PRTCIE		= Int_Priority_Low;	// RTC
			PICIE			= Int_Priority_Low;	// Pin Change

		LocalVar_A.all	= EIP1;
			LocalVar_A.bits.PHLVD		= Int_Priority_Low;
			LocalVar_A.bits.PSH			= Int_Priority_Low;		
			LocalVar_A.bits.PCMP1		= Int_Priority_Low;
			LocalVar_A.bits.PSPI		= Int_Priority_Hi;
			LocalVar_A.bits.PCMP2		= Int_Priority_Low;
			LocalVar_A.bits.PAD			= Int_Priority_Low;
			LocalVar_A.bits.PTC3		= Int_Priority_Low;
		LocalVar_B.all	= EIP2;
			LocalVar_B.bits.PPWMA		= Int_Priority_Low;
			LocalVar_B.bits.PPWMB		= Int_Priority_Low;
			LocalVar_B.bits.PTC4		= Int_Priority_Low;
			LocalVar_B.bits.PI2C		= Int_Priority_Low;
		LocalVar_C.all	= EIP3;
			LocalVar_C.bits.PUART2	= Int_Priority_Low;
			LocalVar_C.bits.PPWMC		= Int_Priority_Low;
			LocalVar_C.bits.PEX1		= Int_Priority_Low;
			LocalVar_C.bits.PEX2		= Int_Priority_Low;
		EIP1			=  LocalVar_A.all;
		EIP2			=  LocalVar_B.all;
		EIP3			=  LocalVar_C.all;
			}
	else{
		PAGESW			= PAG0;}

} //  End of function IntPriority_Init


//=============================================================================
//	Function:			void DelayFunc(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void DelayFunc(int16 DelayCounter){
	int16		LocalVar_A = 0;
	do{
		LocalVar_A	= LocalVar_A + 1;
		} while (LocalVar_A < DelayCounter );
}
void Delay(Uint16 count){
	Uint16 cnt;
	// T = 21 * count / Fm
	for(cnt=0;cnt<count;cnt++){
		PAGESW			= PAG0;
	}
}


//=============================================================================
//	Function:			void SRAM_Write(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
/*
void SRAM_Write(Uint16 wAddr, Uint16 wLength, Uint8 wData){
	Uint8 xdata		*pRAMAddr;	
	Uint16 				IncCount = 0;
	pRAMAddr		= (Uint8 xdata *)wAddr;	
	do{
		*pRAMAddr = wData;
		pRAMAddr++;
		IncCount++;		}while(IncCount<wLength);	
	}
*/
//=============================================================================
//	Function:			void SRAM_ByteWrite(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
/*
void SRAM_ByteWrite(unsigned int wAddr, unsigned char wData){
	Uint8 idata *pRAMAddr;	
	pRAMAddr		= (Uint8 idata *)wAddr;	
	*pRAMAddr 	= wData;}
*/