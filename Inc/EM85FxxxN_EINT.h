//===============================================================================
//	FILE:			EM85FxxxN_EINT.h
//
//	TITLE:		EM85FxxxN_GPIO Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2017/01/06
//===============================================================================
#ifndef EM85FxxxN_EINT_H
#define EM85FxxxN_EINT_H

//----------------------------------------------------------------------------
// Defines for the parameter PinName
//----------------------------------------------------------------------------
	#define 	Func_Pin_Disable	0
	#define 	Func_Pin_Enable		1

	#define 	EINT_Trigger_NA			0
	#define 	EINT_Trigger_UART0	1
	#define 	EINT_Trigger_UART2	2
	#define 	EINT_Trigger_SPI		3
	#define 	EINT_Trigger_IIC		4
	#define 	EINT_Trigger_LED		5
	#define 	EINT_Trigger_ADC		6
	
	// External Interrupt Pin Enable Register Files:
	struct EXEN0_BITS	{
		unsigned char		EXE2:1;				 	 // 0
		unsigned char		EXE3:1;				 	 // 1
		unsigned char		EXE4:1;				 	 // 2
		unsigned char		EXE5:1;				 	 // 3
		unsigned char		EXE6:1;				 	 // 4
		unsigned char		EXE7:1;				 	 // 5
		unsigned char		EXE8:1;				 	 // 6
		unsigned char		EXE9:1;				 	 // 7
		};
	union EXEN0_REG{
		unsigned char				all;
		struct EXEN0_BITS		bits;};
	
	struct EXEN1_BITS	{
		unsigned char		EXE10:1;				  // 0
		unsigned char		EXE11:1;				 	// 1
		unsigned char		rsvd:6;				 	 	// 7:2
		};
	union EXEN1_REG{
		unsigned char				all;
		struct EXEN1_BITS		bits;};	
	
	// External Interrupt Edge Select Control 1 Register Files:
	struct EIESC1_BITS	{
		unsigned char		EIES0:1;				  // 0
		unsigned char		rsvd1:1;				  // 1
		unsigned char		EIES1:1;				  // 2
		unsigned char		rsvd2:3;				  // 5:3
		unsigned char		EIEDG:2;				  // 7:6
		};
	union EIESC1_REG{
		unsigned char				all;
		struct EIESC1_BITS	bits;
		};
	#define 	EINT_DeGlitch_50ns			0
	#define 	EINT_DeGlitch_200ns			1
	#define 	EINT_DeGlitch_400ns			2
	#define 	EINT_DeGlitch_0ns				3
	#define 	EINT_Edge_Falling				0
	#define 	EINT_Edge_Rising				1

	// External Interrupt Edge Select Control 2 Register Files:
	struct EIES2_BITS	{
		unsigned char		EI2ES:2;				 	 // 1:0
		unsigned char		EI3ES:2;				 	 // 3:2
		unsigned char		EI4ES:2;				 	 // 5:4
		unsigned char		EI5ES:2;				 	 // 7:6
		};
	union EIES2_REG{
		unsigned char				all;
		struct EIES2_BITS	bits;};
	// External Interrupt Edge Select Control 3 Register Files:
	struct EIES3_BITS	{
		unsigned char		EI6ES:2;				 	 // 1:0
		unsigned char		EI7ES:2;				 	 // 3:2
		unsigned char		EI8ES:2;				 	 // 5:4
		unsigned char		EI9ES:2;				 	 // 7:6
		};
	union EIES3_REG{
		unsigned char				all;
		struct EIES3_BITS	bits;};
	// External Interrupt Edge Select Control 4 Register Files:
	struct EIES4_BITS	{
		unsigned char		EI10ES:2;				 	 // 1:0
		unsigned char		EI11ES:2;				 	 // 3:2
		unsigned char		rsvd:4;				 		 // 7:4
		};
	union EIES4_REG{
		unsigned char				all;
		struct EIES4_BITS	bits;};
	#define 	EINT_Edge_Falling		0
	#define 	EINT_Edge_Rising		1
	#define 	EINT_Edge_Both			2
		
//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
	void EINT_Init(int);

#endif
