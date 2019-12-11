//===============================================================================
//	FILE:			EM85FxxxN_ADC.h
//
//	TITLE:		EM85FxxxN_ADC Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2017/03/06
//===============================================================================
#ifndef EM85FxxxN_ADC_H
#define EM85FxxxN_ADC_H

//----------------------------------------------------------------------------
// Defines for the parameter PinName
//----------------------------------------------------------------------------
	#define 	ADC_Start				0x10
	#define 	ADC_Status_Falg	0x7F
	
	// ADC Control Register 1 File:
	struct ADCR1_BITS	{
		unsigned char		SHS:2;			// 1:0
		unsigned char		ADOM:1;			// 2
		unsigned char		ADP:1;			// 3
		unsigned char		ADRUN:1;		// 4
		unsigned char		CKR:3;			// 7:5		
		};
	union ADCR1_REG		{
		unsigned char					all;
		struct ADCR1_BITS			bits;
		};
	#define 	ADC_CK_Fm_Div_16		0
	#define 	ADC_CK_Fm_Div_8			1
	#define 	ADC_CK_Fm_Div_4			2
	#define 	ADC_CK_Fm_Div_2			3
	#define 	ADC_CK_Fm_Div_64		4
	#define 	ADC_CK_Fm_Div_32		5
	#define 	ADC_CK_Fm_Div_1			6
	#define 	ADC_CK_Fs_Div_1			7
	#define 	ADC_StartConv_Disable	0
	#define 	ADC_StartConv_Enable	1
	#define 	ADC_PowerDown_Enable	0
	#define 	ADC_PowerDown_Disable	1
	#define 	ADC_PowerOff					0
	#define 	ADC_PowerOn						1
	#define 	ADC_Mode_Single			0
	#define 	ADC_Mode_Continous	1
	#define 	ADC_SampleHold_x2			0
	#define 	ADC_SampleHold_x4			1
	#define 	ADC_SampleHold_x8			2
	#define 	ADC_SampleHold_x16		3

	// ADC Control Register 2 File:
	struct ADCR2_BITS	{
		unsigned char		VREFN:1;			// 0
		unsigned char		VREFP:1;			// 1
		unsigned char		VPIS:3;				// 4:2
		unsigned char		ADCMS:1;			// 5
		unsigned char		ADIM:1;				// 6
		unsigned char		ADSF:1;				// 7
		};
	union ADCR2_REG		{
		unsigned char					all;
		struct ADCR2_BITS			bits;
		};
	#define 	ADC_VREFN_AGND			0
	#define 	ADC_VREFN_VREFGND		1
	#define 	ADC_VREFP_IntRef		0
	#define 	ADC_VREFP_ExtRef		1
	#define 	ADC_IntRef_4096mV		0
	#define 	ADC_IntRef_3072mV		1
	#define 	ADC_IntRef_2560mV		2
	#define 	ADC_IntRef_2048mV		3
	#define 	ADC_IntRef_AVDD			4
	#define 	ADC_CMP_Great				0
	#define 	ADC_CMP_Less				1
	#define 	ADC_Int_ADC					0
	#define 	ADC_Int_CMP					1

	#define 	ADC_Channel_AN0			0
	#define 	ADC_Channel_AN1			1
	#define 	ADC_Channel_AN2			2
	#define 	ADC_Channel_AN3			3
	#define 	ADC_Channel_AN4			4
	#define 	ADC_Channel_AN5			5
	#define 	ADC_Channel_AN6			6
	#define 	ADC_Channel_AN7			7
	#define 	ADC_Channel_AN8			8
	#define 	ADC_Channel_AN9			9
	#define 	ADC_Channel_AN10		10
	#define 	ADC_Channel_AN11		11
	#define 	ADC_Channel_AN12		12
	#define 	ADC_Channel_AN13		13
	#define 	ADC_Channel_AN14		14
	#define 	ADC_Channel_AN15		15
	#define 	ADC_Channel_AN16		16
	#define 	ADC_Channel_AN17		17
	#define 	ADC_Channel_AN18		18
	#define 	ADC_Channel_AN19		19
	#define 	ADC_Channel_AN20		20
	#define 	ADC_Channel_AN21		21	
	#define 	ADC_Channel_AN22		22
	#define 	ADC_Channel_AN23		23
	#define 	ADC_Channel_AN24		24
	#define 	ADC_Channel_AN25		25
	#define 	ADC_Channel_OPA			62	
	#define 	ADC_Channel_HVDD		63

	// ADC Input Enable Control Register File:
	struct ADER1_BITS	{
		unsigned char		ADE0:1;			// 0
		unsigned char		ADE1:1;			// 1
		unsigned char		ADE2:1;			// 2
		unsigned char		ADE3:1;			// 3
		unsigned char		ADE4:1;			// 4
		unsigned char		ADE5:1;			// 5
		unsigned char		ADE6:1;			// 6
		unsigned char		ADE7:1;			// 7
		};
	union ADER1_REG		{
		unsigned char					all;
		struct ADER1_BITS			bits;
		};
	struct ADER2_BITS	{
		unsigned char		ADE8:1;				// 0
		unsigned char		ADE9:1;				// 1
		unsigned char		ADE10:1;			// 2
		unsigned char		ADE11:1;			// 3
		unsigned char		ADE12:1;			// 4
		unsigned char		ADE13:1;			// 5
		unsigned char		ADE14:1;			// 6
		unsigned char		ADE15:1;			// 7
		};
	union ADER2_REG		{
		unsigned char					all;
		struct ADER2_BITS			bits;
		};
	struct ADER3_BITS	{
		unsigned char		ADE16:1;			// 0
		unsigned char		ADE17:1;			// 1
		unsigned char		ADE18:1;			// 2
		unsigned char		ADE19:1;			// 3
		unsigned char		ADE20:1;			// 4
		unsigned char		ADE21:1;			// 5
		unsigned char		ADE22:1;			// 6
		unsigned char		ADE23:1;			// 7
		};
	union ADER3_REG		{
		unsigned char					all;
		struct ADER3_BITS			bits;
		};
	struct ADER4_BITS	{
		unsigned char		ADE24:1;			// 0
		unsigned char		ADE25:1;			// 1
		unsigned char		ADE26:1;			// 2
		unsigned char		ADE27:1;			// 3
		unsigned char		ADE28:1;			// 4
		unsigned char		ADE29:1;			// 5
		unsigned char		ADE30:1;			// 6
		unsigned char		ADE31:1;			// 7
		};
	union ADER4_REG		{
		unsigned char					all;
		struct ADER4_BITS			bits;
		};
	#define 	ADC_Input_Disable		0
	#define 	ADC_Input_Enable		1		


//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void ADC_Init(Uint8,Uint8);

#endif
