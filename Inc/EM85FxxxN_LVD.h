//===============================================================================
//	FILE:			EM85FxxxN_LVD.h
//
//	TITLE:		EM85FxxxN_LVD Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2017/03/09
//===============================================================================
#ifndef EM85FxxxN_LVD_H
#define EM85FxxxN_LVD_H

//----------------------------------------------------------------------------
// Defines for the parameter PinName
//----------------------------------------------------------------------------
	#define 	LVD_Status_Falg			0x7F
	#define 	LVD_Ref_Status_Falg	0x40
	
	// High Low Voltage Detector Control Register File:
	struct HLVDCR_BITS	{
		unsigned char		HLVDS:4;		// 3:0
		unsigned char		VDM:1;			// 4
		unsigned char		VDSB:1;			// 5
		unsigned char		IRVSF:1;		// 6
		unsigned char		HLVDEN:1;		// 7
		};
	union HLVDCR_REG	{
		unsigned char					all;
		struct HLVDCR_BITS		bits;
		};
		#define 	LVD_Level_4700mV		0
		#define 	LVD_Level_4500mV		1
		#define 	LVD_Level_4300mV		2
		#define 	LVD_Level_4100mV		3
		#define 	LVD_Level_3900mV		4
		#define 	LVD_Level_3700mV		5
		#define 	LVD_Level_3500mV		6
		#define 	LVD_Level_3300mV		7
		#define 	LVD_Level_3100mV		8
		#define 	LVD_Level_2900mV		9
		#define 	LVD_Level_2800mV		10
		#define 	LVD_Level_2600mV		11
		#define 	LVD_Level_2500mV		12
		#define 	LVD_Level_2400mV		13
		#define 	LVD_Level_2300mV		14
		#define 	LVD_Level_2200mV		15	
		#define 	LVD_Event_Less			0
		#define 	LVD_Event_Great			1
		#define 	LVD_Detect_Disable	0
		#define 	LVD_Detect_Enable		1
		
	struct HLVDCR1_BITS	{
		unsigned char		rsvd1:7;		// 6:0
		unsigned char		HLVDSF:1;		// 7
		};
	union HLVDCR1_REG	{
		unsigned char					all;
		struct HLVDCR1_BITS		bits;
		};	
		
//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void LVD_Init(int);

#endif
