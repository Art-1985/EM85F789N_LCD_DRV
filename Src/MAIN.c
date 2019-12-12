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
	void clear_lcd_ram(void);
	void update_LCD(Uint8);
	

//--Variable Declarations---------------------------------------//
	Uint16	GlobalVar_A	= 0;
	Uint16	GlobalVar_B	= 0;
	Uint8		dataRam = 0x01;
	
//=============================================================================
//	Main Function
//=============================================================================
void main(void){
	//Initialize System Control:
		ClrRST();
		Oscillator_Init(FuncDisable);
		LVD_Init(FuncDisable);
	//Initialize Parameter:
		paraInit_LCD();
	//Initalize GPIO:
		GPIO_Init();	//Initial IO State
		//P25	= 1;			//SPI chip Select release
			
	//Clear all interrupts and initialize IVT:
		IntMask_Init(FuncEnable);
		IntPriority_Init(FuncDisable);
		EINT_Init(FuncEnable);

	//Initialize all the Device Peripherals:
		//Analog
		LED_Init(FuncDisable);
		LCD_Init(FuncEnable);
		PAGESW		= PAG0;

	//User specific code:
		PAGESW		= PAG0;
		EA				= 1;
		DelayFunc(1);
		
		PAGESW		= PAG0;
	while(1){
		PAGESW				= PAG0;
		delay_sec(30);	//10sec
		clear_lcd_ram();
		delay_sec(30);	//10sec
		update_LCD(dataRam);
		if (dataRam >= 0x0F){
			dataRam = 0x01;}
		else{
			dataRam	 = dataRam << 1;}
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
			LCDADDR		= LoopCounter;
			LCDDATA		= 0xFF;}	}

	void clear_lcd_ram(){
		Uint8			pageTemp, LoopCounter=0;
		pageTemp	= PAGESW;
		PAGESW		= PAG1;
		PAGESW		= PAG1;
		for(LoopCounter=0;LoopCounter < 32;LoopCounter++){
			LCDADDR		= LoopCounter;
			LCDDATA		= 0x00;
			PAGESW		= pageTemp;}	}
	
	void update_LCD(setData){
		Uint8			pageTemp, LoopCounter=0;
		pageTemp	= PAGESW;
		PAGESW		= PAG1;
		for(LoopCounter=0;LoopCounter < 32;LoopCounter++){
			LCDADDR		= LoopCounter;
			LCDDATA		= setData;
		PAGESW		= pageTemp;}	}

