//===============================================================================
//	FILE:				EM85FxxxN_I2C.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2017/03/16
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 16 Mar 2017 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 | 
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Project Includes---------------------------------------------------------//
#include "EM85FxxxN_Device.h"

//--Project Define-----------------------------------------------------------//
	#define I2C_Device_Address	0x80

//--Variable Declarations----------------------------------------------------//
	extern	struct I2C_MSG_obj		Msg1;


//=============================================================================
//	Function:			void I2C_Init(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void I2C_Init(int16	EnableCtrl){
	union I2CCR1_REG		LocalVar_A;
	union I2CCR2_REG		LocalVar_B;
	union I2CSA_REG			LocalVar_C;
	union I2CDA_REG			LocalVar_D;
	union I2CSF_REG			LocalVar_E;
	union I2CRXAF_REG		LocalVar_F;
	union I2CTXLEN_REG	LocalVar_G;
	
	if (EnableCtrl){
		PAGESW				= PAG1;
		LocalVar_A.all		= I2CCR1;
			LocalVar_A.bits.STOP			= I2C_Stop_Slave_W_Ack;
			LocalVar_A.bits.ISS				= I2C_Clock_Fast;
	#if (I2C_InitMode_Master)
			LocalVar_A.bits.IMS				= I2C_Mode_Master;
			#endif
	#if (I2C_InitMode_Slave)
			LocalVar_A.bits.IMS				= I2C_Mode_Slave;
			#endif
		LocalVar_B.all		= I2CCR2;
			LocalVar_B.bits.I2CEN			= I2C_Func_Enable;
			LocalVar_B.bits.I2CTS			= I2C_SCL_Div_50;
			LocalVar_B.bits.RSTSWN		= I2C_Reset_Disable;
			LocalVar_B.bits.GCEN			= I2C_GeneralCall_Disable;
		LocalVar_C.all		= I2CSA;
			//LocalVar_C.bits.IRW				= I2C_Func_Write;
			//LocalVar_C.bits.SAL				= 0x00;
		LocalVar_D.bytes.I2CDAL	= I2CDAL;
		LocalVar_D.bytes.I2CDAH	= I2CDAH;
		
	#if (I2C_InitMode_Master)
			LocalVar_D.bits.I2CDAL		= I2C_Device_Address;
			#endif
	#if (I2C_InitMode_Slave)
			LocalVar_D.bits.I2CDAL		= 0x50;
			#endif
			
			LocalVar_D.bits.ADDRSYNC	= I2C_Address_ASync;
	#if (I2C_InitMode_Single)
			LocalVar_D.bits.I2CBFEN		= I2C_Buffer_Disable;
			#endif
	#if (I2C_InitMode_Buffer)
			LocalVar_D.bits.I2CBFEN		= I2C_Buffer_Enable;
			#endif
			LocalVar_D.bits.SDADG			= I2C_SCL_DG_400ns;		
			LocalVar_D.bits.SCLDG			= I2C_SDA_DG_400ns;
		LocalVar_E.all		= I2CSF;
				LocalVar_E.bits.I2CSTPIEN		= I2C_Stop_Interrupt_Enable;
		LocalVar_F.all		= I2CRXAF;
				LocalVar_F.bits.I2CRA			= I2C_RX_BufLen_15;
				LocalVar_F.bits.I2CRBAS		= 0;
		LocalVar_G.all		= I2CTXLEN;
			LocalVar_G.bits.I2CTL				= I2C_TX_LENGTH_3;
			LocalVar_G.bits.I2CTCC			= I2C_TX_CNT_Clr_EQTXLEN;
			
		PAGESW				= PAG1;
		I2CSTASU	= 0x00;
		I2CSTAHD	= 0x00;
		I2CCR1		= LocalVar_A.all;
		I2CCR2		= LocalVar_B.all;
		I2CSA			= LocalVar_C.all;
		I2CDAL		= LocalVar_D.bytes.I2CDAL;
		I2CDAH		= LocalVar_D.bytes.I2CDAH;
		I2CSF			= LocalVar_E.all;
		I2CRXAF		= LocalVar_F.all;
		I2CTXLEN	= LocalVar_G.all;
			}
		else{
			PAGESW				= PAG0;}
	}

//=============================================================================
//	Function:			void I2C_Time_Out_Init(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
	void I2C_Time_Out_Init(int16	EnableCtrl){
		union I2CTO1_REG			LocalVar_A;
		union I2CTO2_REG			LocalVar_B;
		union I2CTO3_REG			LocalVar_C;
		if (EnableCtrl){
			PAGESW				= PAG1;
			LocalVar_A.all		= I2CTO1;
				LocalVar_A.bits.TO1TPRE		= I2C_TimeOut_FL_Div_1;
				LocalVar_A.bits.TO1EN			= I2C_TimeOut_Disable;
			LocalVar_B.all		= I2CTO2;
				LocalVar_B.bits.TO2TPRE		= I2C_TimeOut_FL_Div_1;
				LocalVar_B.bits.TO2EN			= I2C_TimeOut_Disable;	
			LocalVar_C.all		= I2CTO3;
				LocalVar_C.bits.TO3TPRE		= I2C_TimeOut_FL_Div_1;
				LocalVar_C.bits.TO3EN			= I2C_TimeOut_Disable;	
			
			PAGESW				= PAG1;
			I2CTO1R		= 0x00;
			I2CTO2R		= 0x10;
			I2CTO3R		= 0x05;
			I2CTO1		= LocalVar_A.all;
			I2CTO2		= LocalVar_B.all;
			I2CTO3		= LocalVar_C.all;
			}
		else{
			PAGESW				= PAG0;}
	}

//=============================================================================
//	Function:			void I2C_Send_Data(int SalveAddress, char ReWrCtr)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void I2C_Send_Data(int SalveAddress, char ReWrCtr){
		union I2CSA_REG			LocalVar_A;
		PAGESW	= PAG1;	
		LocalVar_A.all		= I2CSA;
			LocalVar_A.bits.IRW				= ReWrCtr;
			LocalVar_A.bits.SAL				= SalveAddress;
		PAGESW	= PAG1;
		I2CSA		= LocalVar_A.all;
		I2CCR1	= I2CCR1 | 0x80;
	}
	
//=============================================================================
//	Function:			void I2C(void)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void I2C(void) interrupt 20{
	unsigned char	MsgDataBuffer,MsgCounter;
	//unsigned char	MsgStatus;
	Uint8		pageTemp;
	pageTemp	= PAGESW;
	
	MsgDataBuffer		= 0x00;
	MsgCounter			= 0x00;
	
	PAGESW				= PAG1;
//	if (I2CTO3 & 0x40){
//		P50			= ~P50;
//		I2CTO3	= I2CTO3 & 0xBF;}
	
/*
	PAGESW	= PAG1;
	MsgStatus	= I2CCR1 & 0x0F;
	if (I2CSF & I2C_TXSF){		// Monitor Flag-TX
		MsgStatus	= MsgStatus | 0x10;}
	if (I2CSF & I2C_RXSF){		// Monitor Flag-RX
		MsgStatus	= MsgStatus | 0x20;}
	if (I2CSF & I2C_STPSF){		// Monitor Flag-STP
		MsgStatus	= MsgStatus | 0x40;}
	if (I2CRXAF & I2C_RXAFSF){	// Monitor Flag-RXAFSF
		MsgStatus	= MsgStatus | 0x80;}
	P3	= MsgStatus;	
*/


	#if (I2C_InitMode_Single)
	//------TX-----//
/*
		#if (I2C_InitMode_Master)
		if (Msg1.Frame < (Msg1.DataLen-1)){
			MsgDataBuffer	= Msg1.DataByte[Msg1.Frame];
			I2CDB		= MsgDataBuffer;
			Msg1.Frame = Msg1.Frame + 1;
				I2CCR1		= I2CCR1 | 0x80;}
		else if (Msg1.Frame == (Msg1.DataLen-1)){
			MsgDataBuffer	= Msg1.DataByte[Msg1.Frame];
			I2CDB		= MsgDataBuffer;
			Msg1.Frame = Msg1.Frame + 1;
			I2CCR1		= I2CCR1 | 0x90;}
		else{
			Msg1.Frame = 0;}
			#endif
			
		#if (I2C_InitMode_Slave)			
		if (Msg1.Frame < (Msg1.DataLen-1)){
			MsgDataBuffer	= Msg1.DataByte[Msg1.Frame];
			I2CDB		= MsgDataBuffer;
			Msg1.Frame = Msg1.Frame + 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
						P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			I2CCR1		= I2CCR1 & 0x7F;}
		else if (Msg1.Frame == (Msg1.DataLen-1)){
			MsgDataBuffer	= Msg1.DataByte[Msg1.Frame];
			I2CDB		= MsgDataBuffer;
			Msg1.Frame = Msg1.Frame + 1;
			I2CCR1		= I2CCR1 | 0x10;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
						P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			I2CCR1		= I2CCR1 & 0x7F;}
		else{
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
						P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			P54 = 1;
			Msg1.Frame = 0;
			I2CCR1		= I2CCR1 & 0x7F;
			I2CCR2		= I2CCR2 & 0xDF;
			}
			#endif
*/
	//------RX-----//
	
		#if (I2C_InitMode_Master)
		if (Msg1.Frame ==0){
			Msg1.Frame = Msg1.Frame + 1;
			P54 = 1;
			I2CCR1		= I2CCR1 | 0x80;}
		else if (Msg1.Frame < (Msg1.DataLen-1)){
			Msg1.DataByte[Msg1.Frame-1]	= I2CDB;
			Msg1.Frame = Msg1.Frame + 1;
						P54 = 1;
			I2CCR1		= I2CCR1 | 0x80;}
		else if (Msg1.Frame == (Msg1.DataLen-1)){
			Msg1.DataByte[Msg1.Frame-1]	= I2CDB;
			Msg1.Frame = Msg1.Frame + 1;
						P54 = 1;
			I2CCR1		= I2CCR1 | 0x90;}
		else{
			Msg1.DataByte[Msg1.Frame-1]	= I2CDB;
			Msg1.Frame = 0;}
			#endif
	
	
	//------TX-10Bit-----//
/*
		if (Msg1.Frame == 0 ){
			//I2CDB		= 0x50;
			I2CDB		= 0xF4;
			Msg1.Frame = Msg1.Frame + 1;
			I2CCR1		= I2CCR1 | 0x80;}
		else if (Msg1.Frame < Msg1.DataLen){
			MsgDataBuffer	= Msg1.DataByte[Msg1.Frame-1];
			I2CDB		= MsgDataBuffer;
			Msg1.Frame = Msg1.Frame + 1;
			I2CCR1		= I2CCR1 | 0x80;}
		else if (Msg1.Frame == Msg1.DataLen){
			MsgDataBuffer	= Msg1.DataByte[Msg1.Frame-1];
			I2CDB		= MsgDataBuffer;
			Msg1.Frame = Msg1.Frame + 1;
			I2CCR1		= I2CCR1 | 0x90;}
		else{
			Msg1.Frame = 0;}
*/

	//------Broadcast-----//
	/*
		if (Msg1.Frame < (Msg1.DataLen-1)){
			MsgDataBuffer	= Msg1.DataByte[Msg1.Frame];
			I2CDB		= MsgDataBuffer;
			Msg1.Frame = Msg1.Frame + 1;
			I2CCR1		= I2CCR1 | 0x80;}
		else if (Msg1.Frame == (Msg1.DataLen-1)){
			MsgDataBuffer	= Msg1.DataByte[Msg1.Frame];
			I2CDB		= MsgDataBuffer;
			Msg1.Frame = Msg1.Frame + 1;
			I2CCR1		= I2CCR1 | 0x90;}
		else{
			Msg1.Frame = 0;}
		*/
		#endif

/*
	PAGESW	= PAG1;
	MsgStatus	= I2CCR1 & 0x0F;
	if (I2CSF & I2C_TXSF){		// Monitor Flag-TX
		MsgStatus	= MsgStatus | 0x10;}
	if (I2CSF & I2C_RXSF){		// Monitor Flag-RX
		MsgStatus	= MsgStatus | 0x20;}
	if (I2CSF & I2C_STPSF){		// Monitor Flag-STP
		MsgStatus	= MsgStatus | 0x40;}
	if (I2CRXAF & I2C_RXAFSF){	// Monitor Flag-RXAFSF
		MsgStatus	= MsgStatus | 0x80;}
	P3	= MsgStatus;	
*/

	PAGESW		= PAG1;
	I2CSF			= I2CSF & 0x20;		// Clear All Flag
	P54 = 0;
	PAGESW		= pageTemp;
}