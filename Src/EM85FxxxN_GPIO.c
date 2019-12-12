//===============================================================================
//	FILE:				EM85FxxxN_GPIO.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2016/11/21
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 21 Nov 2016 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 | 06 Mar 2017 | Arthur| Added Peripheral Mux Option 
// -----|-------------|-------|------------------------------------------------
//  0.3 | 30 Aug 2018 | Arthur| Added Pull-H/L Ctrl 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Include header files used in the main function--------------//
#include "EM85FxxxN_Device.h"


//=============================================================================
//	Function:			void GPIO_Init(void)
//
//	Description:	Port-0
//									P00(GPO),P01(GPO)
//									P03(PWMA0),P02(PWMA2B)
//									P04(INT0),P06(INT2)
//								Port-1
//									P13(2W_SDA),P14(2W_SCL)
//									P10(SEG0),P11(SEG1),P12(SEG2),P13(SEG3)
//									P14(SEG4),P15(SEG5),P16(SEG6),P17(SEG7)
//								Port-2
//									P21(TX-2),P20(RX-2)
//									P24(SCK),P22(MOSI),P23(MISO),P25(nSS)
//								Port-3
//									P30(COM0),P31(COM1),P32(COM2),P33(COM3)
//									P34(GPO),P35(GPO),P36(GPO),P37(GPO)
//								Port-4
//									P41(OP1O),P42(OP1+),P43(OP1-)
//									P45(CMP2O),P44(CMP2+)
//									P46(GPO),P47(GPO)
//								Port-5
//									P50(TX-0),P51(RX-0)	//Need External Pull-Hi
//									P53(SDA),P52(SCL/Reset)
//									P54(GPO),P55(GPO),P56(GPO),P57(GPO)
//	Returnvalue:	Null
//=============================================================================
void GPIO_Init(void){
	Uint8			LocalVar_A,LocalVar_B;
	// Port-Mode Ctrl
		PAGESW				= PAG0;
		// P0[7:0]
		LocalVar_A		= P0M0;
		LocalVar_B		= P0M1;
		LocalVar_A		= LocalVar_A & 0xFF;
		LocalVar_B		= LocalVar_B | 0x00;
		P0M0					= LocalVar_A;
		P0M1					= LocalVar_B;
		// P1[7:0]
		LocalVar_A		= P1M0;
		LocalVar_B		= P1M1;
		LocalVar_A		= LocalVar_A & 0xFF;
		LocalVar_B		= LocalVar_B | 0x00;
		P1M0					= LocalVar_A;
		P1M1					= LocalVar_B;
		// P2[7:0]
		LocalVar_A		= P2M0;
		LocalVar_B		= P2M1;
		LocalVar_A		= LocalVar_A & 0xFF;
		LocalVar_B		= LocalVar_B | 0x00;
		P2M0					= LocalVar_A;
		P2M1					= LocalVar_B;
		// P3[7:0]
		LocalVar_A		= P3M0;
		LocalVar_B		= P3M1;
		LocalVar_A		= LocalVar_A & 0xFF;
		LocalVar_B		= LocalVar_B | 0x00;
		P3M0					= LocalVar_A;
		P3M1					= LocalVar_B;
		PAGESW				= PAG1;
		// P4[7:0]
		LocalVar_A		= P4M0;
		LocalVar_B		= P4M1;
		LocalVar_A		= LocalVar_A & 0xFF;	
		LocalVar_B		= LocalVar_B | 0x00;
		P4M0					= LocalVar_A;
		P4M1					= LocalVar_B;
		// P5[7:0] as Output
		LocalVar_A		= P5M0;
		LocalVar_B		= P5M1;
		LocalVar_A		= LocalVar_A & 0xF0;
		LocalVar_B		= LocalVar_B | 0x0F;
		P5M0					= LocalVar_A;
		P5M1					= LocalVar_B;

	// IO Pull Hi/Low Configuration
	PULLH_Init();

	// Initial State
		P0	= 0x00;
		P1	= 0x00;
		P2	= 0x00;
		P3	= 0x00;
		P4	= 0x00;
		P5	= 0x00;
	
	// Extend IO Configuration
		EIOPWM_Init();
		EIOTIM_Init();
		EIOI2C_Init();
		EIOSPI_Init();
		EIOUART2_Init();
		EIOLCDLED_Init();
	} //  End of function GPIO_vInit

	
	
//=============================================================================
//	Function:			void PULLH_Init(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================	
void PULLH_Init(void){
	union PHCON0_REG		LocalVar_A;
	union PHCON1_REG		LocalVar_B;
	union PHCON2_REG		LocalVar_C;
	PAGESW				= PAG0;
	LocalVar_A.all		= PHCON0;
			//LocalVar_A.bits.P0PH0		= PULL_HI_ENABLE;
			//LocalVar_A.bits.P0PH1		= PULL_HI_ENABLE;
			//LocalVar_A.bits.P0PH2		= PULL_HI_ENABLE;
			//LocalVar_A.bits.P0PH3		= PULL_HI_ENABLE;
			//LocalVar_A.bits.P0PH4		= PULL_HI_ENABLE;
			//LocalVar_A.bits.P0PH5		= PULL_HI_ENABLE;
			//LocalVar_A.bits.P0PH6		= PULL_HI_ENABLE;
			//LocalVar_A.bits.P0PH7		= PULL_HI_ENABLE;
			PHCON0					= LocalVar_A.all;
	LocalVar_B.all		= PHCON1;
		//LocalVar_B.bits.P1PH0		= PULL_HI_ENABLE;
		//LocalVar_B.bits.P1PH1		= PULL_HI_ENABLE;
		//LocalVar_B.bits.P1PH2		= PULL_HI_ENABLE;
		//LocalVar_B.bits.P1PH3		= PULL_HI_ENABLE;
		//LocalVar_B.bits.P1PH4		= PULL_HI_ENABLE;
		//LocalVar_B.bits.P1PH5		= PULL_HI_ENABLE;
		//LocalVar_B.bits.P1PH6		= PULL_HI_ENABLE;
		//LocalVar_B.bits.P1PH7		= PULL_HI_ENABLE;	
		PHCON1					= LocalVar_B.all;
	PAGESW				= PAG1;
	LocalVar_C.all		= PHCON2;
		//LocalVar_C.bits.P2PH0		= PULL_HI_ENABLE;	//P2 Low Nibble
		//LocalVar_C.bits.P2PH1		= PULL_HI_ENABLE;	//P2 High Nibble
		//LocalVar_C.bits.P3PH0		= PULL_HI_ENABLE;	//P3 Low Nibble
		//LocalVar_C.bits.P3PH1		= PULL_HI_ENABLE;	//P3 High Nibble
		//LocalVar_C.bits.P4PH0		= PULL_HI_ENABLE;	//P4 Low Nibble
		//LocalVar_C.bits.P4PH1		= PULL_HI_ENABLE;	//P4 High Nibble
		//LocalVar_C.bits.P5PH0		= PULL_HI_ENABLE;	//P5 Low Nibble
		//LocalVar_C.bits.P5PH1		= PULL_HI_ENABLE;	//P5 High Nibble
		PHCON2					= LocalVar_C.all;
	} //  End of function PULLH_Init
	
	
//=============================================================================
//	Function:			void EIOPWM_Init(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void EIOPWM_Init(void){
	union EIOPWMA_REG		LocalVar_A;
	union EIOPWMB_REG		LocalVar_B;
	union EIOPWMC_REG		LocalVar_C;
	PAGESW				= PAG2;
	LocalVar_A.all		= EIOPWMA;
	LocalVar_B.all		= EIOPWMB;
	LocalVar_C.all		= EIOPWMC;
		//LocalVar_A.bits.PWMA0		= Func_Pin_Enable; //PWMA0
		//LocalVar_A.bits.IPWMA0	= Func_Pin_Enable; //PWMA0B
		//LocalVar_A.bits.PWMA1		= Func_Pin_Enable; //PWMA1
		//LocalVar_A.bits.IPWMA1	= Func_Pin_Enable; //PWMA1B
		//LocalVar_A.bits.PWMA2		= Func_Pin_Enable; //PWMA2
		//LocalVar_A.bits.IPWMA2	= Func_Pin_Enable; //PWMA2B
		//LocalVar_B.bits.PWMB0		= Func_Pin_Enable;
		//LocalVar_B.bits.IPWMB0	= Func_Pin_Enable;
		//LocalVar_B.bits.PWMB1		= Func_Pin_Enable;
		//LocalVar_B.bits.IPWMB1	= Func_Pin_Enable;
		//LocalVar_B.bits.PWMB2		= Func_Pin_Enable;
		//LocalVar_B.bits.IPWMB2	= Func_Pin_Enable;
		//LocalVar_C.bits.PWMC0		= Func_Pin_Enable;
		//LocalVar_C.bits.IPWMC0	= Func_Pin_Enable;
		//LocalVar_C.bits.PWMC1		= Func_Pin_Enable;
		//LocalVar_C.bits.IPWMC1	= Func_Pin_Enable;
		//LocalVar_C.bits.PWMC2		= Func_Pin_Enable;
		//LocalVar_C.bits.IPWMC2	= Func_Pin_Enable;
	EIOPWMA					= LocalVar_A.all;
	EIOPWMB					= LocalVar_B.all;
	EIOPWMC					= LocalVar_C.all;	
	} //  End of function EIOPWM_vInit

//=============================================================================
//	Function:			void EIOTIM_Init(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void EIOTIM_Init(void){
	union EIOT3_REG		LocalVar_A;
	union EIOT4_REG		LocalVar_B;
	PAGESW				= PAG2;
	LocalVar_A.all		= EIOT3;
	LocalVar_B.all		= EIOT4;
		//LocalVar_A.bits.T3_0		= Func_Pin_Enable;
		//LocalVar_A.bits.T3_1		= Func_Pin_Enable;
		//LocalVar_A.bits.T3_2		= Func_Pin_Enable;
		//LocalVar_A.bits.T3_3		= Func_Pin_Enable;
		//LocalVar_B.bits.T4_0		= Func_Pin_Enable;
		//LocalVar_B.bits.T4_1		= Func_Pin_Enable;
		//LocalVar_B.bits.T4_2		= Func_Pin_Enable;
		//LocalVar_B.bits.T4_3		= Func_Pin_Enable;
	EIOT3					= LocalVar_A.all;
	EIOT4					= LocalVar_B.all;
	} //  End of function EIOTIM_vInit

//=============================================================================
//	Function:			void EIOI2C_Init(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void EIOI2C_Init(void){
	union EIOI2C0_REG		LocalVar_A;
	PAGESW				= PAG2;
	LocalVar_A.all		= EIOI2C0;
		//LocalVar_A.bits.SDA03		= Func_Pin_Enable;
		//LocalVar_A.bits.SCL03		= Func_Pin_Enable;
		//LocalVar_A.bits.SDA02		= Func_Pin_Enable;
		//LocalVar_A.bits.SCL02		= Func_Pin_Enable;
	EIOI2C0						= LocalVar_A.all;
	} //  End of function EIOI2C_vInit

//=============================================================================
//	Function:			void EIOSPI_Init(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void EIOSPI_Init(void){
	union EIOSPI0_REG		LocalVar_A;
	union EIOSPI1_REG		LocalVar_B;
	PAGESW				= PAG2;
		LocalVar_A.all			= EIOSPI0;
		//LocalVar_A.bits.SS00		= Func_Pin_Enable;
		//LocalVar_A.bits.MISO00	= Func_Pin_Enable;
		//LocalVar_A.bits.MOSI00	= Func_Pin_Enable;
		//LocalVar_A.bits.SCK00		= Func_Pin_Enable;
		//LocalVar_A.bits.SS01		= Func_Pin_Enable;
		//LocalVar_A.bits.MISO01	= Func_Pin_Enable;
		//LocalVar_A.bits.MOSI01	= Func_Pin_Enable;
		//LocalVar_A.bits.SCK01		= Func_Pin_Enable;
		LocalVar_B.all			= EIOSPI1;
		//LocalVar_B.bits.SS02		= Func_Pin_Enable;
		//LocalVar_B.bits.MISO02	= Func_Pin_Enable;
		//LocalVar_B.bits.MOSI02	= Func_Pin_Enable;
		//LocalVar_B.bits.SCK02		= Func_Pin_Enable;
	EIOSPI0							= LocalVar_A.all;
	EIOSPI1							= LocalVar_B.all;
	} //  End of function EIOSPI_vInit

	
//=============================================================================
//	Function:			void EIOUART2_Init(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void EIOUART2_Init(void){
	union EIOUART2_REG		LocalVar_A;
	PAGESW				= PAG2;
		LocalVar_A.all			= EIOUART2;
		//LocalVar_A.bits.RX20		= Func_Pin_Enable;
		//LocalVar_A.bits.TX20		= Func_Pin_Enable;
		//LocalVar_A.bits.RX21		= Func_Pin_Enable;
		//LocalVar_A.bits.TX21		= Func_Pin_Enable;
		//LocalVar_A.bits.RX22		= Func_Pin_Enable;
		//LocalVar_A.bits.TX22		= Func_Pin_Enable;
		//LocalVar_A.bits.RX23		= Func_Pin_Enable;
		//LocalVar_A.bits.TX23		= Func_Pin_Enable;
		EIOUART2						= LocalVar_A.all;
	} //  End of function EIOUART2_vInit
	

//=============================================================================
//	Function:			void EIOLCDLED_Init(void)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void EIOLCDLED_Init(void){
	union EIOCOM1_REG		LocalVar_A;
	union EIOSEG1_REG		LocalVar_B;
	union EIOSEG2_REG		LocalVar_C;
	union EIOSEG3_REG		LocalVar_D;
	union EIOSEG4_REG		LocalVar_E;
	union EIOSEG11_REG	LocalVar_F;
	PAGESW				= PAG2;
	LocalVar_A.all			= EIOCOM1;
	LocalVar_B.all			= EIOSEG1;	
	LocalVar_C.all			= EIOSEG2;
	LocalVar_D.all			= EIOSEG3;
	LocalVar_E.all			= EIOSEG4;
	LocalVar_F.all			= EIOSEG11;
		LocalVar_A.bits.COM0	= Func_Pin_Enable;
		LocalVar_A.bits.COM1	= Func_Pin_Enable;	
		LocalVar_A.bits.COM2	= Func_Pin_Enable;
		LocalVar_A.bits.COM3	= Func_Pin_Enable;
		//LocalVar_A.bits.COM4	= Func_Pin_Enable;	//Share with Seg31
		//LocalVar_A.bits.COM5	= Func_Pin_Enable;	//Share with Seg30
		//LocalVar_A.bits.COM6	= Func_Pin_Enable;	//Share with Seg29
		//LocalVar_A.bits.COM7	= Func_Pin_Enable;	//Share with Seg28
	
		LocalVar_B.bits.SEG0	= Func_Pin_Enable;
		LocalVar_B.bits.SEG1	= Func_Pin_Enable;
		LocalVar_B.bits.SEG2	= Func_Pin_Enable;
		//LocalVar_B.bits.SEG3	= Func_Pin_Enable;	//OCDS_SDA
		//LocalVar_B.bits.SEG4	= Func_Pin_Enable;	//OCDS_SCL
		LocalVar_B.bits.SEG5	= Func_Pin_Enable;
		LocalVar_B.bits.SEG6	= Func_Pin_Enable;
		LocalVar_B.bits.SEG7	= Func_Pin_Enable;

		LocalVar_C.bits.SEG8	= Func_Pin_Enable;
		LocalVar_C.bits.SEG9	= Func_Pin_Enable;
		LocalVar_C.bits.SEG10	= Func_Pin_Enable;
		LocalVar_C.bits.SEG11	= Func_Pin_Enable;
		LocalVar_C.bits.SEG12	= Func_Pin_Enable;
		LocalVar_C.bits.SEG13	= Func_Pin_Enable;
		LocalVar_C.bits.SEG14	= Func_Pin_Enable;
		LocalVar_C.bits.SEG15	= Func_Pin_Enable;

		LocalVar_D.bits.SEG16	= Func_Pin_Enable;
		LocalVar_D.bits.SEG17	= Func_Pin_Enable;
		LocalVar_D.bits.SEG18	= Func_Pin_Enable;
		LocalVar_D.bits.SEG19	= Func_Pin_Enable;
		LocalVar_D.bits.SEG20	= Func_Pin_Enable;
		LocalVar_D.bits.SEG21	= Func_Pin_Enable;
		LocalVar_D.bits.SEG22	= Func_Pin_Enable;
		LocalVar_D.bits.SEG23	= Func_Pin_Enable;

		LocalVar_E.bits.SEG24	= Func_Pin_Enable;
		LocalVar_E.bits.SEG25	= Func_Pin_Enable;
		LocalVar_E.bits.SEG26	= Func_Pin_Enable;
		LocalVar_E.bits.SEG27	= Func_Pin_Enable;
		LocalVar_E.bits.SEG28	= Func_Pin_Enable;	//Share with COM7
		LocalVar_E.bits.SEG29	= Func_Pin_Enable;	//Share with COM6
		LocalVar_E.bits.SEG30	= Func_Pin_Enable;	//Share with COM5
		LocalVar_E.bits.SEG31	= Func_Pin_Enable;	//Share with COM4

		//LocalVar_F.bits.SEG0_1	= Func_Pin_Enable;
		//LocalVar_F.bits.SEG1_1	= Func_Pin_Enable;
		//LocalVar_F.bits.SEG2_1	= Func_Pin_Enable;
		//LocalVar_F.bits.SEG3_1	= Func_Pin_Enable;
		//LocalVar_F.bits.SEG4_1	= Func_Pin_Enable;
		//LocalVar_F.bits.SEG5_1	= Func_Pin_Enable;
		//LocalVar_F.bits.SEG6_1	= Func_Pin_Enable;
		//LocalVar_F.bits.SEG7_1	= Func_Pin_Enable;
	EIOCOM1	= LocalVar_A.all;
	EIOSEG1	= LocalVar_B.all;	
	EIOSEG2	= LocalVar_C.all;
	EIOSEG3	= LocalVar_D.all;
	EIOSEG4	= LocalVar_E.all;
	EIOSEG11= LocalVar_F.all;
	} //  End of function EIOLCDLED_Init