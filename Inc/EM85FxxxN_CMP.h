//===============================================================================
//	FILE:			EM85FxxxN_CMP.h
//
//	TITLE:		EM85FxxxN_CMP Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2017/08/01
//===============================================================================
#ifndef EM85FxxxN_CMP_H
#define EM85FxxxN_CMP_H

//----------------------------------------------------------------------------
// Defines for the parameter PinName
//----------------------------------------------------------------------------
	#define 	CMP1_Status_Falg		0x01
	#define 	CMP2_Status_Falg		0x02
	
	#define 	CMP_VREF_2048				0x00
	#define 	CMP_VREF_1280				0x01
	#define 	CMP_VREF_512				0x02
	#define 	CMP_VREF_256				0x03

	// OPCMP1 Control Register 1 File:
	struct OPCMP1CR1_BITS	{
		unsigned char		rsvd1:1;				// 0
		unsigned char		SC1PWMEG:1;			// 1
		unsigned char		rsvd2:2;				// 3:2
		unsigned char		CMP1OUT:1;			// 4
		unsigned char		CMP1OUTEN:1;		// 5
		unsigned char		OPCMP1SW:1;			// 6
		unsigned char		OPCMP1EN:1;			// 7
		};
	union OPCMP1CR1_REG		{
		unsigned char							all;
		struct OPCMP1CR1_BITS			bits;
		};
	// CMP2 Control Register 1 File:
	struct CMP2CR1_BITS	{
		unsigned char		rsvd1:1;				// 0
		unsigned char		SC2PWMEG:1;			// 1
		unsigned char		rsvd2:2;				// 3:2
		unsigned char		CMP2OUT:1;			// 4
		unsigned char		CMP2OUTEN:1;		// 5
		unsigned char		rsvd3:1;				// 6
		unsigned char		CMP2EN:1;				// 7
		};
	union CMP2CR1_REG		{
		unsigned char							all;
		struct CMP2CR1_BITS			bits;
		};
	#define 	OPCMP_Disable							0
	#define 	OPCMP_Enable							1
	#define 	OPCMP_Mode_CMP						0
	#define 	OPCMP_Mode_OPA						1
	#define 	CMP_PadOut_Disable				0
	#define 	CMP_PadOut_Enable					1
	#define 	CMP_DisPWM_Edge_Rising		0
	#define 	CMP_DisPWM_Edge_Falling		1


	// OPCMP1 Control Register 2 File:
	struct OPCMP1CR2_BITS	{
		unsigned char		OPCMP1NIVS:2;		// 1:0
		unsigned char		OPCMP1PIVS:2;		// 3:2
		unsigned char		OPCMP1PIPS:2;		// 5:4
		unsigned char		rsvd1:2;				// 7:6
		};
	union OPCMP1CR2_REG		{
		unsigned char							all;
		struct OPCMP1CR2_BITS			bits;
		};
	// CMP2 Control Register 2 File:
	struct CMP2CR2_BITS	{
		unsigned char		CMP2NIVS:2;			// 1:0
		unsigned char		CMP2PIVS:2;			// 3:2
		unsigned char		CMP2PIPS:2;			// 5:4
		unsigned char		rsvd1:2;				// 7:6
		};
	union CMP2CR2_REG		{
		unsigned char							all;
		struct CMP2CR2_BITS			bits;
		};
	#define 	CMP_CH_Neg_Pad					0
	#define 	CMP_CH_Neg_Gnd					1
	#define 	CMP_CH_Neg_IntVref			2
	#define 	CMP_CH_Neg_HVDD					3
	#define 	CMP_CH_Pos_Pad					0
	#define 	CMP_CH_Pos_Gnd					1
	#define 	CMP_CH_Pos_IntVref			2
	#define 	CMP_CH_Pos_HVDD					3
	#define 	CMP_CH_Pos_Pad_1				0
	#define 	CMP_CH_Pos_Pad_2				1
	#define 	CMP_CH_Pos_Pad_3				2
	#define 	CMP_CH_Pos_Pad_4				3

	// CMP Noise Rejection Control Register File:
	struct CMPNRCR1_BITS	{
		unsigned char		CMP1NREN:1;			// 0
		unsigned char		CMP2NREN:1;			// 1
		unsigned char		rsvd1:4;				// 5:2
		unsigned char		NRC:2;					// 7:6
		};
	union CMPNRCR1_REG		{
		unsigned char							all;
		struct CMPNRCR1_BITS			bits;
		};
	#define 	CMP_NoiseRejection_Disable		0
	#define 	CMP_NoiseRejection_Enable			1
	#define 	CMP_NoiseRejection_x2					0
	#define 	CMP_NoiseRejection_x4					1
	#define 	CMP_NoiseRejection_x8					2
	#define 	CMP_NoiseRejection_x16				3

		
//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void CMP_Init(Uint8);
void OPCMP1_Init(void);
void CMP2_Init(void);
void OP1_AutoTrim(void);
void CMP1_AutoTrim(void);
void CMP2_AutoTrim(void);

#endif
