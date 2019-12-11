//===============================================================================
//	FILE:			EM85FxxxN_TIM.h
//
//	TITLE:		EM85FxxxN_GPIO Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2016/11/21
//===============================================================================
#ifndef EM85FxxxN_TIM_H
#define EM85FxxxN_TIM_H

//----------------------------------------------------------------------------
// Defines FOr The Parameter of Control Register
//----------------------------------------------------------------------------
	// User To Select I2C Opeaation Mode:
	#define 	Time3_Start		0x80
	#define 	Time3_DA_Falg	0x10
	#define 	Time3_DB_Falg	0x20
	#define 	Time4_Start		0x80
	#define 	Time4_DA_Falg	0x10
	#define 	Time4_DB_Falg	0x20
	
	// Timer 3 Control Register 1 File:
	struct TC3CR1_BITS	{
		unsigned char		TC3ISx:2;		// 1:0
		unsigned char		TC3OMS:1;		// 2
		unsigned char		TC3FF:1;		// 3
		unsigned char		TC3DASF:1;	// 4
		unsigned char		TC3DBSF:1;	// 5
		unsigned char		TC3RC:1;		// 6
		unsigned char		TC3S:1;			// 7 , TC3 IP Ctrl Bit
		};
	union TC3CR1_REG		{
		unsigned char				all;
		struct TC3CR1_BITS	bits;
		};
	// Timer 4 Control Register 1 File:
	struct TC4CR1_BITS	{
		unsigned char		TC4ISx:2;		// 1:0
		unsigned char		TC4OMS:1;		// 2
		unsigned char		TC4FF:1;		// 3
		unsigned char		TC4DASF:1;	// 4
		unsigned char		TC4DBSF:1;	// 5
		unsigned char		TC4RC:1;		// 6
		unsigned char		TC4S:1;			// 7 , TC3 IP Ctrl Bit
		};
	union TC4CR1_REG		{
		unsigned char				all;
		struct TC4CR1_BITS	bits;
		};
	#define 	Timer_Start_Disable		0
	#define 	Timer_Start_Enable		1
	#define 	Timer_Raed_Disable		0
	#define 	Timer_Raed_Enable			1
	#define 	Timer_PWM_ActiveHi		0
	#define 	Timer_PWM_ActiveLo		1
	#define 	Timer_Repeat_Enable		0
	#define 	Timer_Repeat_Disable	1
	#define 	Timer_PWM_Int_PM			0
	#define 	Timer_PWM_Int_DM			1
	#define 	Timer_PWM_Int_BOTH		2
		
	// Timer 3 Control Register 2 File:
	struct TC3CR2_BITS	{
		unsigned char		TC3CKx:4;		// 3:0
		unsigned char		rsvd1:1;		// 4
		unsigned char		TC3Mx:3;		// 7:5
			};
	union TC3CR2_REG		{
		unsigned char				all;
		struct TC3CR2_BITS	bits;
		};
	// Timer 4 Control Register 2 File:
	struct TC4CR2_BITS	{
		unsigned char		TC4CKx:4;		// 3:0
		unsigned char		rsvd1:1;		// 4
		unsigned char		TC4Mx:3;		// 7:5
			};
	union TC4CR2_REG		{
		unsigned char				all;
		struct TC4CR2_BITS	bits;
		};
	#define 	Timer_Mode_Counter_Rising		0	
	#define 	Timer_Mode_Counter_Falling	1	
	#define 	Timer_Mode_Capture_Rising		2				
	#define 	Timer_Mode_Capture_Falling	3
	#define 	Timer_Mode_Window						4			
	#define 	Timer_Mode_PDO							5
	#define 	Timer_Mode_PWM							6
	#define 	Timer_Mode_Buzzer						7
	#define 	Timer_Clock_Div_1						0
	#define 	Timer_Clock_Div_2						1	
	#define 	Timer_Clock_Div_4						2
	#define 	Timer_Clock_Div_8						3
	#define 	Timer_Clock_Div_16					4
	#define 	Timer_Clock_Div_32					5
	#define 	Timer_Clock_Div_64					6
	#define 	Timer_Clock_Div_128					7
	#define 	Timer_Clock_Div_256					8
	#define 	Timer_Clock_Div_512					9
	#define 	Timer_Clock_Div_1024				10
	#define 	Timer_Clock_Div_2048				11
	#define 	Timer_Clock_Div_4096				12
	#define 	Timer_Clock_Div_8192				13
	#define 	Timer_Clock_Div_32768				14
	#define 	Timer_Clock_Div_65536				15

	// Timer 3 Control Register 3 File:
	struct TC3CR3_BITS	{
		unsigned char		TC3SSx:2;		// 1:0
		unsigned char		rsvd1:4;		// 5:2
		unsigned char		TC3SCSx:2;	// 7:6
			};
	union TC3CR3_REG		{
		unsigned char				all;
		struct TC3CR3_BITS	bits;
		};
	// Timer 4 Control Register 3 File:
	struct TC4CR3_BITS	{
		unsigned char		TC4SSx:2;		// 1:0
		unsigned char		rsvd1:4;		// 5:2
		unsigned char		TC4SCSx:2;	// 7:6
			};
	union TC4CR3_REG		{
		unsigned char				all;
		struct TC4CR3_BITS	bits;
		};
	#define 	Timer_TriggerBy_TCxS		0
	#define 	Timer_TriggerBy_SPI			1
	#define 	Timer_TriggerBy_UART		2
	#define 	Timer_TriggerBy_IIC			3
	#define 	Timer_ClockSrc_FLS			0
	#define 	Timer_ClockSrc_FHS			1
	#define 	Timer_ClockSrc_PLL			2
	#define 	Timer_ClockSrc_EXT			3
		
//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void TIM_Init(int);
void TM01_Init(void);	// Original Timer0,Timer1
void TM2_Init(void);	// Real Time Clock
void TM3_Init(void);	// ELAN
void TM4_Init(void);	// ELAN

#endif
