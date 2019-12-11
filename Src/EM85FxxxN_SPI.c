//===============================================================================
//	FILE:				EM85FxxxN_SPI.c
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
//	0.2 | 28 Aug 2017 | Arthur| Add Buffer Mode.
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Include header files used in the main function--------------//
#include "EM85FxxxN_Device.h"

extern	struct SPI_MSG_obj		Msg2;

//=============================================================================
//	Function:			void SPI_Init(int)
//
//	Description:	
//
//	Returnvalue:	Null
//
//=============================================================================
void SPI_Init(EnableCtrl){
	union SPICON1_REG			LocalVar_A;
	union SPICON2_REG			LocalVar_B;
	union SPISR1_REG			LocalVar_C;
	union SPISR2_REG			LocalVar_D;
	union SPITDBC_REG			LocalVar_E;
	union SPIRDBC_REG			LocalVar_F;
	if (EnableCtrl){
		PAGESW				= PAG0;
		LocalVar_A.all		= SPICON1;
			LocalVar_A.bits.SPR				= SPI_Clock_Fsys_Div_8;
			LocalVar_A.bits.MSTR			= SPI_Mode_Master;
			LocalVar_A.bits.CPOL			= SPI_IdleLevel_Hi;
			LocalVar_A.bits.CPHA			= SPI_SampleEdge_2ed;
			LocalVar_A.bits.SPIEN			= SPI_Module_Enable;
		LocalVar_B.all		= SPICON2;
			LocalVar_B.bits.SCKOD			= SPI_OpenDrain_Disable;
			LocalVar_B.bits.SDOOD			= SPI_OpenDrain_Disable;
			LocalVar_B.bits.SPIHDEN		= SPI_HiDrv_Disable;
			LocalVar_B.bits.DORD			= SPI_TX_LSB;
		LocalVar_C.all		= SPISR1;
			LocalVar_C.bits.SDOC			= SPI_SDO_Default_Hi;
			LocalVar_C.bits.DEGL_SEL	= SPI_SDI_Filter_15ns;
			LocalVar_C.bits.SCK_SEL		= SPI_SCK_Filter_Enable;
			LocalVar_C.bits.MB_START	= SPI_MasterBuf_Stop;
		LocalVar_D.all		= SPISR2;
			LocalVar_D.bits.WKEN			= SPI_WakeUp_Disable;
		
		#if	(	SPI_InitMode_Buffer)
			LocalVar_E.all		= SPITDBC;
				LocalVar_E.bits.TXBLEN		= SPI_TX_BufLen_Lim_16;
				LocalVar_E.bits.TX_INTVAL	= SPI_Master_NextTX_Fsys_5;
			LocalVar_F.all		= SPIRDBC;
				LocalVar_F.bits.RXBLEN		= SPI_RX_BufLen_Lim_16;
				LocalVar_F.bits.BUFMODE		= SPI_BufMode_Enable;
		#else
			LocalVar_E.all		= SPITDBC;
				LocalVar_E.bits.TXBLEN		= SPI_TX_BufLen_Lim_1;
				LocalVar_E.bits.TX_INTVAL	= SPI_Master_NextTX_Fsys_5;
			LocalVar_F.all		= SPIRDBC;
				LocalVar_F.bits.RXBLEN		= SPI_RX_BufLen_Lim_1;
				LocalVar_F.bits.BUFMODE		= SPI_BufMode_Disable;
			#endif	
		SPICON1		= LocalVar_A.all;
		SPICON2		= LocalVar_B.all;
		SPISR1		= LocalVar_C.all;
		SPISR2		= LocalVar_D.all;
		SPITDBC		= LocalVar_E.all;
		SPIRDBC		= LocalVar_F.all;}
	else{
		PAGESW				= PAG0;}
	} //  End of function SPI_Init

	
//=============================================================================
//	Function:			void SPI(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
	void vSPI(void) interrupt 11{
	unsigned int 	MsgCounter;
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	PAGESW		= PAG0;
	#if	(	SPI_InitMode_Buffer)
		P25	= 1;	//Chip Select Release
		SPISR1		= SPISR1 & SPI_MasterBuffer_Stop;
		for (MsgCounter=0;MsgCounter < 16;MsgCounter++){
				Msg2.RxDataByte[MsgCounter]	= SPIRDBR;}	//Get RX Data
		if (Msg2.Index < Msg2.DataLen){
			for (MsgCounter=Msg2.Index;MsgCounter < (Msg2.Index+16);MsgCounter++){
				SPITDBR	=	Msg2.TxDataByte[MsgCounter+1];}	//Load RX Data
			Msg2.Index	= Msg2.Index + 16;
			P25						= 0;	//Chip Select Enable
			SPISR1		= SPISR1 | 0x80;}
		else
			Msg2.PackageFinish	= 0;
		
	#else
		if (Msg2.Frame < Msg2.DataLen){
			Msg2.RxDataByte[Msg2.Frame]	= SPIRDBR;	//Get RX Data
			Msg2.Frame	= Msg2.Frame + 1;
			SPITDBR	=	Msg2.TxDataByte[Msg2.Frame]; 	//Load TX Data
			}
		else{
			Msg2.PackageFinish	= 0;
			MsgCounter					= 0;
			P25	= 1;	//Chip Select Release
			Msg2.Frame	= 0;}
		#endif
	SPISR2	= SPISR2 & 0x7F;	//Clear All Flag
			
	//Only Foe Continue Test
/*
	#if	(	SPI_InitMode_Buffer)
		P25				= 0; //Chip Select Enable
		SPISR1		= SPISR1 | SPI_MasterBuffer_Start;
	#else
		MsgCounter= 0;
		#endif
*/
	PAGESW		= pageTemp;	}