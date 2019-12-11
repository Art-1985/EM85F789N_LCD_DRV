//===============================================================================
//	FILE:				EM85FxxxN_LCD.c
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

	//BCD_TABLE={0,1,2,3,4,5,6,7,8,9,A,B,C,D,F}
	Uint8		BCD_TABLE[10]	= {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0x3E,0xE0,0xFE,0xE6};
	union LED_BUF_REG		LCD_TABLE[8]	= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	union LED_BUF_REG		RAM_TABLE[8]	= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

//=============================================================================
//	Function:			void LED_Init(void)
//
//	Description:	123
//
//	Returnvalue:	Null
//
//=============================================================================
void LED_Init(int16	EnableCtrl){
	union LEDFR_REG			LocalVar_A;
	union LCDCR1_REG		LocalVar_B;
	if (EnableCtrl){
		PAGESW				= PAG1;
		LocalVar_A.all					= LEDFR;
			LocalVar_A.bits.LEDDT	= LED_Duty_Fs_x1;
			LocalVar_A.bits.LEDPR	= LED_Period_x1;
		LocalVar_B.all					= LCDCR1;
			LocalVar_B.bits.LCDEN		= Display_Mode_Enable;
			LocalVar_B.bits.DISTSEL	= Display_Mode_LED;
		PAGESW				= PAG1;
		LEDFR		= LocalVar_A.all;
		LCDCR1	= LocalVar_B.all;
		}
	else{
		PAGESW				= PAG0;}
	} //  End of function LCD_vInit

//=============================================================================
//	Function:			void LCD_Init(void)
//
//	Description:	123
//
//	Returnvalue:	Null
//
//=============================================================================
void LCD_Init(int16	EnableCtrl){
	union LEDFR_REG			LocalVar_A;
	union LCDCR1_REG		LocalVar_B;
	union LCDCR2_REG		LocalVar_C;
	union LCDCR3_REG		LocalVar_D;
	if (EnableCtrl){
		PAGESW				= PAG1;
		LocalVar_A.all					= LEDFR;
		LocalVar_B.all					= LCDCR1;
			LocalVar_B.bits.LCDEN		= Display_Mode_Enable;
			LocalVar_B.bits.LCDTYPE	= LCD_Type_A;
			LocalVar_B.bits.DISTSEL	= Display_Mode_LCD;
			LocalVar_B.bits.BS			= LCD_Bias_Div_2;
			LocalVar_B.bits.DS			= LCD_Duty_Div_2;
			LocalVar_B.bits.LCDF		= LCD_FrameRate_62;
		LocalVar_C.all					= LCDCR2;
			LocalVar_C.bits.RBS			= LCD_ResBias_20K;
			LocalVar_C.bits.DYMEN		= LCD_Dynamic_Disable;
		LocalVar_D.all					= LCDCR3;
				LocalVar_D.bits.LCDCC		= LCD_VolRatio_100;
		PAGESW				= PAG1;
		LEDFR		= LocalVar_A.all;
		LCDCR1	= LocalVar_B.all;
		LCDCR2	= LocalVar_C.all;
		LCDCR3	= LocalVar_D.all;
		}
	else{
		PAGESW				= PAG0;}
	} //  End of function LCD_Init

	
	
	
//=============================================================================
//	Function:			void Uint32_To_BCD(Uint32 DecNum)
//
//	Description:	123
//
//	Returnvalue:	Null
//
//=============================================================================
	void Uint32_To_BCD(Uint32 DecNum){
		Uint32		BcdNum;
		BcdNum	= DecNum / 10000000;
		DecNum	= DecNum - (10000000*BcdNum);
		LCD_TABLE[0].all	= BCD_TABLE[BcdNum];
		BcdNum	= DecNum / 1000000;
		DecNum	= DecNum - (1000000*BcdNum);
		LCD_TABLE[1].all	= BCD_TABLE[BcdNum];
		BcdNum	= DecNum / 100000;
		DecNum	= DecNum - (100000*BcdNum);
		LCD_TABLE[2].all	= BCD_TABLE[BcdNum];
		BcdNum	= DecNum / 10000;
		DecNum	= DecNum - (10000*BcdNum);
		LCD_TABLE[3].all	= BCD_TABLE[BcdNum];
		BcdNum	= DecNum / 1000;
		DecNum	= DecNum - (1000*BcdNum);
		LCD_TABLE[4].all	= BCD_TABLE[BcdNum];
		BcdNum	= DecNum / 100;
		DecNum	= DecNum - (100*BcdNum);
		LCD_TABLE[5].all	= BCD_TABLE[BcdNum];
		BcdNum	= DecNum / 10;
		DecNum	= DecNum - (10*BcdNum);
		LCD_TABLE[6].all	= BCD_TABLE[BcdNum];
		LCD_TABLE[7].all	= BCD_TABLE[DecNum];}

		
//=============================================================================
//	Function:			void Uint16_To_BCD(Uint16 DecNum)
//
//	Description:	123
//
//	Returnvalue:	Null
//
//=============================================================================
	void Uint16_To_BCD(Uint16 DecNum){
		Uint16		BcdNum;
		LCD_TABLE[0].all	= 0;
		LCD_TABLE[1].all	= 0;
		LCD_TABLE[2].all	= 0;
		LCD_TABLE[3].all	= 0;
		BcdNum	= DecNum / 1000;
		DecNum	= DecNum - (1000*BcdNum);
		LCD_TABLE[4].all	= BCD_TABLE[BcdNum];
		BcdNum	= DecNum / 100;
		DecNum	= DecNum - (100*BcdNum);
		LCD_TABLE[5].all	= BCD_TABLE[BcdNum];
		BcdNum	= DecNum / 10;
		DecNum	= DecNum - (10*BcdNum);
		LCD_TABLE[6].all	= BCD_TABLE[BcdNum];
		LCD_TABLE[7].all	= BCD_TABLE[DecNum];}

		
//=============================================================================
//	Function:			void Update_LED(Uint16 DecNum)
//
//	Description:	123
//
//	Returnvalue:	Null
//
//=============================================================================
	void Update_LED(void){
		Uint8		LoopCounter,ShiftRegister;
		//RAM_TABLE,LCD_TABLE
		ShiftRegister	= 0x00;
		for(LoopCounter=0;LoopCounter < 7;LoopCounter++){
			ShiftRegister	= ShiftRegister | LCD_TABLE[LoopCounter].bits.Bit7;
			ShiftRegister	= ShiftRegister << 1;}
			ShiftRegister	= ShiftRegister | LCD_TABLE[7].bits.Bit7;
			RAM_TABLE[0].all	= ShiftRegister;
		ShiftRegister	= 0x00;
		for(LoopCounter=0;LoopCounter < 7;LoopCounter++){
			ShiftRegister	= ShiftRegister | LCD_TABLE[LoopCounter].bits.Bit6;
			ShiftRegister	= ShiftRegister << 1;}
			ShiftRegister	= ShiftRegister | LCD_TABLE[7].bits.Bit6;
			RAM_TABLE[1].all	= ShiftRegister;
		ShiftRegister	= 0x00;
		for(LoopCounter=0;LoopCounter < 7;LoopCounter++){
			ShiftRegister	= ShiftRegister | LCD_TABLE[LoopCounter].bits.Bit5;
			ShiftRegister	= ShiftRegister << 1;}
			ShiftRegister	= ShiftRegister | LCD_TABLE[7].bits.Bit5;
			RAM_TABLE[2].all	= ShiftRegister;
		ShiftRegister	= 0x00;
		for(LoopCounter=0;LoopCounter < 7;LoopCounter++){
			ShiftRegister	= ShiftRegister | LCD_TABLE[LoopCounter].bits.Bit4;
			ShiftRegister	= ShiftRegister << 1;}
			ShiftRegister	= ShiftRegister | LCD_TABLE[7].bits.Bit4;
			RAM_TABLE[3].all	= ShiftRegister;
		ShiftRegister	= 0x00;
		for(LoopCounter=0;LoopCounter < 7;LoopCounter++){
			ShiftRegister	= ShiftRegister | LCD_TABLE[LoopCounter].bits.Bit3;
			ShiftRegister	= ShiftRegister << 1;}
			ShiftRegister	= ShiftRegister | LCD_TABLE[7].bits.Bit3;
			RAM_TABLE[4].all	= ShiftRegister;
		ShiftRegister	= 0x00;
		for(LoopCounter=0;LoopCounter < 7;LoopCounter++){
			ShiftRegister	= ShiftRegister | LCD_TABLE[LoopCounter].bits.Bit2;
			ShiftRegister	= ShiftRegister << 1;}
			ShiftRegister	= ShiftRegister | LCD_TABLE[7].bits.Bit2;
			RAM_TABLE[5].all	= ShiftRegister;
		ShiftRegister	= 0x00;
		for(LoopCounter=0;LoopCounter < 7;LoopCounter++){
			ShiftRegister	= ShiftRegister | LCD_TABLE[LoopCounter].bits.Bit1;
			ShiftRegister	= ShiftRegister << 1;}
			ShiftRegister	= ShiftRegister | LCD_TABLE[7].bits.Bit1;
			RAM_TABLE[6].all	= ShiftRegister;
		ShiftRegister	= 0x00;
		for(LoopCounter=0;LoopCounter < 7;LoopCounter++){
			ShiftRegister	= ShiftRegister | LCD_TABLE[LoopCounter].bits.Bit0;
			ShiftRegister	= ShiftRegister << 1;}
			ShiftRegister	= ShiftRegister | LCD_TABLE[7].bits.Bit0;
			RAM_TABLE[7].all	= ShiftRegister;
		PAGESW				= PAG1;
		for(LoopCounter=0;LoopCounter < 8;LoopCounter++){
			LCDADDR		= LoopCounter;
			LCDDATA		= RAM_TABLE[LoopCounter].all;}
		}//End of Update_LCD