//===============================================================================
//	FILE:			EM85FxxxN_I2C.h
//
//	TITLE:		EM85FxxxN_I2C Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2017/03/15
//===============================================================================
#ifndef EM85FxxxN_I2C_H
#define EM85FxxxN_I2C_H

	// User To Select I2C Opeaation Mode:
	#define	I2C_InitMode_Master		TARGET
	#define	I2C_InitMode_Slave		0

	#define	I2C_InitMode_Single		TARGET
	#define	I2C_InitMode_Buffer		0


	// User To Select I2C Interrupt Mode:
	#define	I2C_Slave_7b					0
	#define	I2C_Master_7b_nW			1
	#define	I2C_Master_7b_R				2
	#define	I2C_Slave_10b					3
	#define	I2C_Master_10b_nW			4
	#define	I2C_Master_10b_R			5
	#define	I2C_Master_nW_R				6
	#define	I2C_Slave_7b_Buf_RX		7
	#define	I2C_Slave_7b_Buf_TX		8
	#define	I2C_Else							9

	#define	I2C_MODE		I2C_Master_7b_R
	#ifndef I2C_MODE
		#error	Critical:I2C_MODE must be define !!
	#endif

//----------------------------------------------------------------------------
// Defines FOr The Parameter of Control Register
//----------------------------------------------------------------------------
	#define	I2C_TXSF			0x80
	#define	I2C_RXSF			0x40
	#define	I2C_STPSF			0x10

	#define	I2C_RXAFSF		0x80

	#define I2C_nWrite		0x00
	#define I2C_Read			0x01
	
	// Message Box
	struct I2C_MSG_obj	{			// bits	 description	
		unsigned char DataLen;
		unsigned char Frame;
		unsigned char SlaveAddrH;
		unsigned char SlaveAddrL;
		unsigned char DataByte[24];
	};

	// I2C Status and Control Register 1 File:
	struct I2CCR1_BITS	{
		unsigned char		EMPTY:1;		// 0
		unsigned char		FULL:1;			// 1
		unsigned char		ACK:1;			// 2
		unsigned char		SAREMPTY:1;	// 3
		unsigned char		STOP:1;			// 4
		unsigned char		ISS:1;			// 5
		unsigned char		IMS:1;			// 6
		unsigned char		STROBE:1;		// 7
		};
	union I2CCR1_REG		{
		unsigned char				all;
		struct I2CCR1_BITS	bits;
		};
	#define I2C_SCL_Pend					0
	#define I2C_SCL_Strobe				1
	#define I2C_Mode_Slave				0
	#define I2C_Mode_Master				1	
	#define I2C_Clock_Standard		0
	#define I2C_Clock_Fast				1
	#define I2C_Stop_Master_R_Ack		0
	#define I2C_Stop_Master_R_nAck	1
	#define I2C_Stop_Master_W_nAck	0
	#define I2C_Stop_Master_W_Ack		1
	#define I2C_Stop_Slave_W_Ack		0
	#define I2C_Stop_Slave_W_nAck		1

	// I2C Status and Control Register 2 File:
	struct I2CCR2_BITS	{
		unsigned char		I2CEN:1;		// 0
		unsigned char		I2CTS:3;		// 3:1
		unsigned char		BBF:1;			// 4
		unsigned char		RSTSWN:1;		// 5
		unsigned char		GCEN:1;			// 6
		unsigned char		I2CBF:1;		// 7
		};
	union I2CCR2_REG		{
		unsigned char				all;
		struct I2CCR2_BITS	bits;
		};
	#define I2C_GeneralCall_Disable		0	
	#define I2C_GeneralCall_Enable		1
	#define I2C_Reset_Disable					0
	#define I2C_Reset_Enable					1
	#define I2C_SCL_Div_10						0
	#define I2C_SCL_Div_15						1
	#define I2C_SCL_Div_20						2
	#define I2C_SCL_Div_30						3
	#define I2C_SCL_Div_40						4
	#define I2C_SCL_Div_50						5
	#define I2C_SCL_Div_60						6
	#define I2C_SCL_Div_70						7
	#define I2C_Func_Disable					0
	#define I2C_Func_Enable						1
		
	// I2C Slave Address Register 2 File:
	struct I2CSA_BITS	{
		unsigned char		IRW:1;			// 0
		unsigned char		SAL:7;			// 7:1
		};
	union I2CSA_REG		{
		unsigned char				all;
		struct I2CSA_BITS		bits;
		};
		#define I2C_Func_Write					0
		#define I2C_Func_Read						1
		
	// I2C Device Address Register File:
	struct I2CDA_BITS	{
		unsigned int		I2CDAL:10;		// 9:0
		unsigned int		ADDRSYNC:1;		// 10
		unsigned int		I2CBFEN:1;		// 11
		unsigned int		SDADG:2;			// 13:12
		unsigned int		SCLDG:2;			// 15:14
		};
	struct I2CDA_BYTES	{
		unsigned int		I2CDAL:8;			// 7:0
		unsigned int		I2CDAH:8;			// 15:8
		};
	union I2CDA_REG		{
		unsigned int				all;
		struct I2CDA_BYTES	bytes;
		struct I2CDA_BITS		bits;
		};
		#define I2C_SCL_DG_50ns					0
		#define I2C_SCL_DG_200ns				1		
		#define I2C_SCL_DG_400ns				2	
		#define I2C_SCL_DG_Disable			3
		#define I2C_SDA_DG_50ns					0
		#define I2C_SDA_DG_200ns				1		
		#define I2C_SDA_DG_400ns				2		
		#define I2C_SDA_DG_Disable			3
		#define I2C_Buffer_Disable			0
		#define I2C_Buffer_Enable				1
		#define I2C_Address_ASync				0
		#define I2C_Address_Sync				1
		
	// I2C Slave Status Register File:
	struct I2CSF_BITS	{
		unsigned char		rsvd1:4;			// 3:0
		unsigned char		I2CSTPSF:1;		// 4
		unsigned char		I2CSTPIEN:1;	// 5
		unsigned char		I2CRXSF:1;		// 6
		unsigned char		I2CTXSF:1;		// 7
		};
	union I2CSF_REG		{
		unsigned char				all;
		struct I2CSF_BITS		bits;
		};
		#define I2C_Stop_Interrupt_Disable		0
		#define I2C_Stop_Interrupt_Enable			1

	// I2C RX Almost Full Buffer Control Length Register File:
	struct I2CRXAF_BITS	{
		unsigned char		I2CRA:5;			// 4:0
		unsigned char		I2CRBAS:1;		// 5
		unsigned char		rsvd1:1;			// 6
		unsigned char		I2CRXAFSF:1;	// 7
		};
	union I2CRXAF_REG		{
		unsigned char					all;
		struct I2CRXAF_BITS		bits;
		};
		#define I2C_BufferMode_RX_nACK			0
		#define I2C_BufferMode_RX_ACK				1
		#define I2C_RX_BufLen_0							0
		#define I2C_RX_BufLen_1							1
		#define I2C_RX_BufLen_2							2
		#define I2C_RX_BufLen_3							3
		#define I2C_RX_BufLen_4							4
		#define I2C_RX_BufLen_5							5
		#define I2C_RX_BufLen_6							6
		#define I2C_RX_BufLen_7							7
		#define I2C_RX_BufLen_8							8
		#define I2C_RX_BufLen_9							9
		#define I2C_RX_BufLen_10						10
		#define I2C_RX_BufLen_11						11
		#define I2C_RX_BufLen_12						12
		#define I2C_RX_BufLen_13						13
		#define I2C_RX_BufLen_14						14
		#define I2C_RX_BufLen_15						15
		#define I2C_RX_BufLen_16						16

	// I2C Time-out 1 Register File:
	struct I2CTO1_BITS	{
		unsigned char		TO1TPRE:3;		// 2:0
		unsigned char		rsvd1:3;			// 5:3
		unsigned char		TO1SF:1;			// 6
		unsigned char		TO1EN:1;			// 7
		};
	union I2CTO1_REG		{
		unsigned char					all;
		struct I2CTO1_BITS		bits;
		};
	// I2C Time-out 2 Register File:
	struct I2CTO2_BITS	{
		unsigned char		TO2TPRE:3;		// 2:0
		unsigned char		rsvd1:3;			// 5:3
		unsigned char		TO2SF:1;			// 6
		unsigned char		TO2EN:1;			// 7
		};
	union I2CTO2_REG		{
		unsigned char					all;
		struct I2CTO2_BITS		bits;
		};
	// I2C Time-out 3 Register File:
	struct I2CTO3_BITS	{
		unsigned char		TO3TPRE:3;		// 2:0
		unsigned char		rsvd1:3;			// 5:3
		unsigned char		TO3SF:1;			// 6
		unsigned char		TO3EN:1;			// 7
		};
	union I2CTO3_REG		{
		unsigned char					all;
		struct I2CTO3_BITS		bits;
		};
		#define I2C_TimeOut_FL_Div_1			0
		#define I2C_TimeOut_FL_Div_2			1
		#define I2C_TimeOut_FL_Div_4			2
		#define I2C_TimeOut_FL_Div_8			3
		#define I2C_TimeOut_FL_Div_16			4
		#define I2C_TimeOut_FL_Div_32			5
		#define I2C_TimeOut_FL_Div_64			6
		#define I2C_TimeOut_FL_Div_128		7
		#define I2C_TimeOut_Disable				0
		#define I2C_TimeOut_Enable				1

	// I2C Transmit Buffer Register File:
	struct I2CTXLEN_BITS	{
		unsigned char		I2CTL:5;		// 4:0
		unsigned char		rsvd1:2;		// 6:5
		unsigned char		I2CTCC:1;		// 7
		};
	union I2CTXLEN_REG		{
		unsigned char						all;
		struct I2CTXLEN_BITS		bits;
		};
		#define I2C_TX_CNT_Clr_TXSF				0
		#define I2C_TX_CNT_Clr_EQTXLEN		1

		#define I2C_TX_LENGTH_2						2
		#define I2C_TX_LENGTH_3						3
		#define I2C_TX_LENGTH_4						4
		#define I2C_TX_LENGTH_5						5
		#define I2C_TX_LENGTH_6						6
		#define I2C_TX_LENGTH_7						7
		#define I2C_TX_LENGTH_8						8
		#define I2C_TX_LENGTH_9						9
		#define I2C_TX_LENGTH_10					10
		#define I2C_TX_LENGTH_11					11
		#define I2C_TX_LENGTH_12					12
		#define I2C_TX_LENGTH_13					13
		#define I2C_TX_LENGTH_14					14
		#define I2C_TX_LENGTH_15					15
		#define I2C_TX_LENGTH_16					16

//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void I2C_Init(int);
void I2C_Time_Out_Init(int);
void I2C_Send_Data(int,char);

#endif