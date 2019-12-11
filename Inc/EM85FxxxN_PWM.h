//===============================================================================
//	FILE:			EM85FxxxN_PWM.h
//
//	TITLE:			EM85FxxxN_PWM Device definitions
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2016/12/21
//===============================================================================
#ifndef EM85FxxxN_PWM_H
#define EM85FxxxN_PWM_H

//----------------------------------------------------------------------------
// Defines for the parameter PinName
//----------------------------------------------------------------------------
	#define 	PWMx_PM_Falg	0x80
	#define 	PWMx_DM_Falg	0x40

	// PWMENCR Control Register File:
	struct PWMENCR_BITS	{
		unsigned char		TAEN:1;			// 0
		unsigned char		TBEN:1;			// 1
		unsigned char		TCEN:1;			// 2
		unsigned char		rsvd1:1;		// 3
		unsigned char		DEADTP:2;		// 5:4
		unsigned char		rsvd2:2;		// 7:6		
		};
	union PWMENCR_REG		{
		unsigned char					all;
		struct PWMENCR_BITS		bits;
		};
	#define 	PWM_Start_Disable		0
	#define 	PWM_Start_Enable		1
	#define 	PWM_DT_Pre_Div_1		0
	#define 	PWM_DT_Pre_Div_2		1
	#define 	PWM_DT_Pre_Div_4		2
	#define 	PWM_DT_Pre_Div_8		3
		
	// PWMA Control Register 1 File:
	struct PWMACR1_BITS	{
		unsigned char		TAP:3;			// 2:0
		unsigned char		rsvd1:1;		// 3
		unsigned char		IPWMAA:1;		// 4
		unsigned char		PWMAA:1;		// 5
		unsigned char		IPWMAE:1;		// 6
		unsigned char		PWMAE:1;		// 7
		};
	union PWMACR1_REG		{
		unsigned char					all;
		struct PWMACR1_BITS		bits;
		};
	// PWMB Control Register 1 File:
	struct PWMBCR1_BITS	{
		unsigned char		TBP:3;			// 2:0
		unsigned char		rsvd1:1;		// 3
		unsigned char		IPWMBA:1;		// 4
		unsigned char		PWMBA:1;		// 5
		unsigned char		IPWMBE:1;		// 6
		unsigned char		PWMBE:1;		// 7
		};
	union PWMBCR1_REG		{
		unsigned char					all;
		struct PWMBCR1_BITS		bits;
		};
	// PWMC Control Register 1 File:
	struct PWMCCR1_BITS	{
		unsigned char		TCP:3;			// 2:0
		unsigned char		rsvd1:1;		// 3
		unsigned char		IPWMCA:1;		// 4
		unsigned char		PWMCA:1;		// 5
		unsigned char		IPWMCE:1;		// 6
		unsigned char		PWMCE:1;		// 7
		};
	union PWMCCR1_REG		{
		unsigned char					all;
		struct PWMCCR1_BITS		bits;
		};
	#define 	PWM_Pin_Disable		0
	#define 	PWM_Pin_Enable		1
	#define 	PWM_Active_Hi			0
	#define 	PWM_Active_Lo			1
	#define 	PWM_TMR_Pre_Div1		0
	#define 	PWM_TMR_Pre_Div2		1
	#define 	PWM_TMR_Pre_Div4		2
	#define 	PWM_TMR_Pre_Div8		3
	#define 	PWM_TMR_Pre_Div16		4
	#define 	PWM_TMR_Pre_Div64		5
	#define 	PWM_TMR_Pre_Div128	6
	#define 	PWM_TMR_Pre_Div256	7

	// PWMA Control Register 2 File:
	struct PWMACR2_BITS	{
		unsigned char		DEADTAE:1;		// 0
		unsigned char		PWMAS:2;			// 2:1
		unsigned char		PWMAOSM:1;		// 3
		unsigned char		PWMASWAP:1;		// 4
		unsigned char		PWMACMPLC:1;	// 5
		unsigned char		PWMADSF:1;		// 6
		unsigned char		PWMAPSF:1;		// 7
		};
	union PWMACR2_REG	{
		unsigned char					all;
		struct PWMACR2_BITS		bits;
		};
	// PWMB Control Register 2 File:
	struct PWMBCR2_BITS	{
		unsigned char		DEADTBE:1;		// 0
		unsigned char		PWMBS:2;			// 2:1
		unsigned char		PWMBOSM:1;		// 3
		unsigned char		PWMBSWAP:1;		// 4
		unsigned char		PWMBCMPLC:1;	// 5
		unsigned char		PWMBDSF:1;		// 6
		unsigned char		PWMBPSF:1;		// 7
		};
	union PWMBCR2_REG		{
		unsigned char					all;
		struct PWMBCR2_BITS		bits;
		};
	// PWMC Control Register 2 File:
	struct PWMCCR2_BITS	{
		unsigned char		DEADTCE:1;		// 0
		unsigned char		PWMCS:2;			// 2:1
		unsigned char		PWMCOSM:1;		// 3
		unsigned char		PWMCSWAP:1;		// 4
		unsigned char		PWMCCMPLC:1;	// 5
		unsigned char		PWMCDSF:1;		// 6
		unsigned char		PWMCPSF:1;		// 7
		};
	union PWMCCR2_REG		{
		unsigned char					all;
		struct PWMCCR2_BITS		bits;
		};
	#define 	PWM_Sync_CMP_Disable	0
	#define 	PWM_Sync_CMP_Enable		1
	#define 	PWM_Swap_Disable			0
	#define 	PWM_Swap_Enable				1
	#define 	PWM_OneShot_Disable		0
	#define 	PWM_OneShot_Enable		1
	#define 	PWM_Src_FLS						0
	#define 	PWM_Src_FHS						1
	#define 	PWM_Src_PLL						2
	#define 	PWM_DeadTime_Disable	0
	#define 	PWM_DeadTime_Enable		1
		
	// PRDA Control Register File:
	struct PRDA_BITS	{
		unsigned int		PRDAL:8;		// 7:0
		unsigned int		PRDAH:8;		// 16:8
		};
	union PRDA_REG		{
		unsigned int					all;
		struct PRDA_BITS			bits;
		};
	// PRDB Control Register File:
	struct PRDB_BITS	{
		unsigned int		PRDBL:8;		// 7:0
		unsigned int		PRDBH:8;		// 16:8
		};
	union PRDB_REG		{
		unsigned int					all;
		struct PRDB_BITS			bits;
		};
	// PRDC Control Register File:
	struct PRDC_BITS	{
		unsigned int		PRDCL:8;		// 7:0
		unsigned int		PRDCH:8;		// 16:8
		};
	union PRDC_REG		{
		unsigned int					all;
		struct PRDC_BITS			bits;
		};
	// DTA Control Register File:
	struct DTA_BITS	{
		unsigned int		DTAL:8;		// 7:0
		unsigned int		DTAH:8;		// 16:8
		};
	union DTA_REG		{
		unsigned int					all;
		struct DTA_BITS			bits;
		};
	// DTB Control Register File:
	struct DTB_BITS	{
		unsigned int		DTBL:8;		// 7:0
		unsigned int		DTBH:8;		// 16:8
		};
	union DTB_REG		{
		unsigned int					all;
		struct DTB_BITS			bits;
		};
	// DTC Control Register File:
	struct DTC_BITS	{
		unsigned int		DTCL:8;		// 7:0
		unsigned int		DTCH:8;		// 16:8
		};
	union DTC_REG		{
		unsigned int					all;
		struct DTC_BITS			bits;
		};
	// TMRA Control Register File:
	struct TMRA_BITS	{
		unsigned int		TMRAL:8;		// 7:0
		unsigned int		TMRAH:8;		// 16:8
		};
	union TMRA_REG		{
		unsigned int					all;
		struct TMRA_BITS			bits;
		};
	// TMRB Control Register File:
	struct TMRB_BITS	{
		unsigned int		TMRBL:8;		// 7:0
		unsigned int		TMRBH:8;		// 16:8
		};
	union TMRB_REG		{
		unsigned int					all;
		struct TMRB_BITS			bits;
		};
	// TMRC Control Register File:
	struct TMRC_BITS	{
		unsigned int		TMRCL:8;		// 7:0
		unsigned int		TMRCH:8;		// 16:8
		};
	union TMRC_REG		{
		unsigned int					all;
		struct TMRC_BITS			bits;
		};
		
//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void PWM_Init(int);
void PWMA_Init(void);
void PWMB_Init(void);
void PWMC_Init(void);

#endif
