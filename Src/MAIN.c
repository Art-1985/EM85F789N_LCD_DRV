//===============================================================================
//	Project:		EM85F789N_Template
//
//	FILE:				main.c
//
//  Target:  		EM85F789N
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2017/06/12
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the EM85F789N_Template project
//								Use EINT0 as test function trigger(Modify EINT0_ISR)
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 12 Jun 2017 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 | 12 Nov 2018 | Arthur| Added NumTran
// -----|-------------|-------|------------------------------------------------
// -----|-------------|-------|------------------------------------------------
//===============================================================================

//--Include header files used in the main function--------------//
#include <stdlib.h>
#include <intrins.h>
#include "EM85FxxxN_Device.h"


//--Sub Function Prototypes-------------------------------------//
	void paraInit_LCD(void);

//--Variable Declarations---------------------------------------//
	Uint16	GlobalVar_A	= 0;
	Uint16	GlobalVar_B	= 0;
	
	Uint8		SlaveWriteFinish	= 0x7F;
	Uint8		uartWriteFinish		= 0x7F;
	Uint16	*ptrInt2Hex;
	Uint8		extTrigger				= 0x7F;
	
//=============================================================================
//	Main Function
//=============================================================================
void main(void){
	// Step 1. Initialize System Control:
		ClrRST();
		Oscillator_Init(FuncDisable);
		LVD_Init(FuncDisable);
	// Step 2. Initialize Parameter:
		paraInit_LCD();
	// Step 3. Initalize GPIO:
		GPIO_Init();	//Initial IO State
		P25	= 1;			//SPI chip Select release
			
	// Step 4. Clear all interrupts and initialize IVT:
		IntMask_Init(FuncEnable);
		IntPriority_Init(FuncDisable);
		EINT_Init(FuncEnable);

	// Step 5. Initialize all the Device Peripherals:
		//Analog
		LED_Init(FuncDisable);
		LCD_Init(FuncDisable);
		PAGESW		= PAG0;
		//Other
		FlashUnlock(FuncDisable);
		excuteFlashProgram(FuncDisable);

	// Step 6. User specific code:
		PAGESW		= PAG0;
		EA				= 1;
		DelayFunc(1);
		
		PAGESW		= PAG0;
	while(1){
		PAGESW				= PAG0;

		
	 //====== End of python_uart_test,20181106 ======//
	}
}

//=============================================================================
//	Sub-Routine
//=============================================================================
//=============================================================================
//	Function:			void paraInit_LCD(void)
//	Description:	NA
//	Returnvalue:	Null
//=============================================================================
	void paraInit_LCD(void){
		Uint8		LoopCounter=0;
		PAGESW				= PAG1;
		for(LoopCounter=0;LoopCounter < 32;LoopCounter++){
			LCDADDR		= 0x00;
			LCDDATA		= 0x01;}	}


