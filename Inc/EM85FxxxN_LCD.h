//===============================================================================
//	FILE:			EM85FxxxN_LCD.h
//
//	TITLE:		EM85FxxxN_LCD Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2017/06/13
//===============================================================================
#ifndef EM85FxxxN_LCD_H
#define EM85FxxxN_LCD_H


// User To Select Display Driver:
#define   LCD_Display			0
#define   SEG_Display			0
#define   LED_Display			TARGET

#if	(LCD_Display)
	#define	FlashRomSize		18432
#elif	(SEG_Display)
	#define	FlashRomSize		18432
#else
	#define	FlashRomSize		18432
	#define	FlashPageSize		64
#endif


	// LED Data Message Box
	struct LED_BUF_BITS	{
		unsigned char		Bit0:1;			// 0
		unsigned char		Bit1:1;			// 1
		unsigned char		Bit2:1;			// 2
		unsigned char		Bit3:1;			// 3
		unsigned char		Bit4:1;			// 4
		unsigned char		Bit5:1;			// 5
		unsigned char		Bit6:1;			// 6
		unsigned char		Bit7:1;			// 7
		};
	union LED_BUF_REG		{
		unsigned char					all;
		struct LED_BUF_BITS		bits;
		};
	

//----------------------------------------------------------------------------
// Defines FOr The Parameter of Control Register
//----------------------------------------------------------------------------
	// LED Frame Control Register File:
	struct LEDFR_BITS	{
		unsigned char		LEDDT:4;			// 3:0
		unsigned char		LEDPR:3;			// 6:4
		unsigned char		rsvd1:1;			// 7
		};
	union LEDFR_REG		{
		unsigned char					all;
		struct LEDFR_BITS			bits;
		};
	#define 	LED_Period_x1		0
	#define 	LED_Period_x2		1
	#define 	LED_Period_x4		2
	#define 	LED_Period_x6		3
	#define 	LED_Period_x8		4
	#define 	LED_Period_x12	5
	#define 	LED_Period_x14	6
	#define 	LED_Period_x16	7
	#define 	LED_Duty_Fs_x1		0
	#define 	LED_Duty_Fs_x2		1
	#define 	LED_Duty_Fs_x4		2
	#define 	LED_Duty_Fs_x8		3
	#define 	LED_Duty_Fs_x16		4
	#define 	LED_Duty_Fs_x32		5
	#define 	LED_Duty_Fs_x64		6
	#define 	LED_Duty_Fs_x128	7
	#define 	LED_Duty_Fs_x256	8

	// LCD Control Register 1 File:
	struct LCDCR1_BITS	{
		unsigned char		LCDF:2;			// 1:0
		unsigned char		DS:2;				// 3:2
		unsigned char		BS:1;				// 4
		unsigned char		DISTSEL:1;	// 5
		unsigned char		LCDTYPE:1;	// 6
		unsigned char		LCDEN:1;		// 7
		};
	union LCDCR1_REG		{
		unsigned char					all;
		struct LCDCR1_BITS		bits;
		};
	#define 	Display_Mode_Disable	0
	#define 	Display_Mode_Enable		1
	#define 	LCD_Type_A						0
	#define 	LCD_Type_B						1
	#define 	Display_Mode_LCD			0
	#define 	Display_Mode_LED			1
	#define 	LCD_Bias_Div_2				0
	#define 	LCD_Bias_Div_3				1
	#define 	LCD_Duty_Div_2				0
	#define 	LCD_Duty_Div_3				1
	#define 	LCD_Duty_Div_4				2
	#define 	LCD_Duty_Div_8				3
	#define 	LCD_FrameRate_62			0
	#define 	LCD_FrameRate_57			1
	#define 	LCD_FrameRate_52			2
	#define 	LCD_FrameRate_68			3

	// LCD Control Register 2 File:
	struct LCDCR2_BITS	{
		unsigned char		rsvd1:4;		// 3:0
		unsigned char		DYMEN:1;		// 4
		unsigned char		RBS:2;			// 6:5
		unsigned char		rsvd2:1;		// 7
		};
	union LCDCR2_REG		{
		unsigned char					all;
		struct LCDCR2_BITS		bits;
		};
	#define 	LCD_ResBias_180K		0
	#define 	LCD_ResBias_100K		1
	#define 	LCD_ResBias_60K			2
	#define 	LCD_ResBias_20K			3
	#define 	LCD_Dynamic_Disable	0
	#define 	LCD_Dynamic_Enable	1

	// LCD Control Register 3 File:
	struct LCDCR3_BITS	{
		unsigned char		LCDCC:3;		// 2:0
		unsigned char		rsvd1:5;		// 7:3
		};
	union LCDCR3_REG		{
		unsigned char					all;
		struct LCDCR3_BITS		bits;
		};
	#define 	LCD_VolRatio_100		0
	#define 	LCD_VolRatio_96			1
	#define 	LCD_VolRatio_93			2
	#define 	LCD_VolRatio_87			3
	#define 	LCD_VolRatio_82			4
	#define 	LCD_VolRatio_74			5
	#define 	LCD_VolRatio_66			6
	#define 	LCD_VolRatio_60			7

//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void LED_Init(int);
void LCD_Init(int);
void Uint32_To_BCD(Uint32);
void Uint16_To_BCD(Uint16);
void Update_LED(void);

#endif