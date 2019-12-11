//===============================================================================
//	FILE:			EM85FxxxN_SPI.h
//
//	TITLE:		EM85FxxxN_SPI Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2016/11/21
//===============================================================================
#ifndef EM85FxxxN_SPI_H
#define EM85FxxxN_SPI_H

	// User To Select I2C Opeaation Mode:
	#define	SPI_InitMode_Slave					0
	#define	SPI_InitMode_Master					TARGET
	#define	SPI_InitMode_Buffer					0						//Buffer Mode(1) Or Not(0)

//----------------------------------------------------------------------------
// Defines FOr The Parameter of Control Register
//----------------------------------------------------------------------------
	#define 	SPI_MasterBuffer_Start		0x80
	#define 	SPI_MasterBuffer_Stop			0x7F

	// Message Box
	struct SPI_MSG_obj	{
		unsigned char DataLen;
		unsigned char Frame;
		unsigned char RxDataByte[128];
		unsigned char TxDataByte[128];
		unsigned char Index;
		unsigned char PackageFinish;
	};

	// SPI Control Register 1 File:
	struct SPICON1_BITS	{
		unsigned char		rsvd1:1;		// 0
		unsigned char		SPR:3;			// 3:1
		unsigned char		MSTR:1;			// 4
		unsigned char		CPOL:1;			// 5
		unsigned char		CPHA:1;			// 6
		unsigned char		SPIEN:1;		// 7
		};
	union SPICON1_REG		{
		unsigned char					all;
		struct SPICON1_BITS		bits;
		};
	#define SPI_Module_Disable			0
	#define SPI_Module_Enable				1
	#define SPI_SampleEdge_2ed			0
	#define SPI_SampleEdge_1st			1
	#define SPI_IdleLevel_Lo				0
	#define SPI_IdleLevel_Hi				1
	#define SPI_Mode_Master					0
	#define SPI_Mode_Slave					1
	#define SPI_Clock_Fsys_Div_2		0
	#define SPI_Clock_Fsys_Div_4		1
	#define SPI_Clock_Fsys_Div_8		2
	#define SPI_Clock_Fsys_Div_16		3
	#define SPI_Clock_Fsys_Div_32		4
	#define SPI_Clock_Fsys_Div_64		5
	#define SPI_Clock_Fsys_Div_128	6

	// SPI Control Register 2 File:
	struct SPICON2_BITS	{
		unsigned char		SCKOD:1;		// 0
		unsigned char		SDOOD:1;		// 1
		unsigned char		SPIHDEN:1;	// 2
		unsigned char		DORD:1;			// 3
		unsigned char		rsvd1:3;		// 7:4
		};
	union SPICON2_REG		{
		unsigned char					all;
		struct SPICON2_BITS		bits;
		};
	#define SPI_TX_MSB						0
	#define SPI_TX_LSB						1
	#define SPI_HiDrv_Disable			0
	#define SPI_HiDrv_Enable			1
	#define SPI_OpenDrain_Disable	0
	#define SPI_OpenDrain_Enable	1

	// SPI Status Register 1 File:
	struct SPISR1_BITS	{
		unsigned char		rsvd1:1;		// 0
		unsigned char		SDOC:1;			// 1
		unsigned char		DEGL_SEL:1;	// 2
		unsigned char		SCK_SEL:1;	// 3
		unsigned char		RXEMY:1;		// 4
		unsigned char		TXE:1;			// 5
		unsigned char		RXF:1;			// 6
		unsigned char		MB_START:1;	// 7
		};
	union SPISR1_REG		{
		unsigned char					all;
		struct SPISR1_BITS		bits;
		};
	#define SPI_MasterBuf_Stop		0
	#define SPI_MasterBuf_Start		1
	
	#define SPI_SCK_Fliter_Diaable	0
	#define SPI_SCK_Filter_Enable		1
	#define SPI_SDI_Filter_15ns			0
	#define SPI_SDI_Filter_30ns			1
	#define SPI_SDO_Default_Hi			0
	#define SPI_SDO_Default_Lo			1

	// SPI Status Register 2 File:
	struct SPISR2_BITS	{
		unsigned char		TCF:1;		// 0
		unsigned char		RBF:1;		// 1
		unsigned char		TXS:1;		// 2
		unsigned char		SRO:1;		// 3
		unsigned char		RCF:1;		// 4
		unsigned char		RXAF:1;		// 5
		unsigned char		WKEN:1;		// 6
		unsigned char		SPIIF:1;	// 7
		};
	union SPISR2_REG		{
		unsigned char					all;
		struct SPISR2_BITS		bits;
		};
	#define SPI_WakeUp_Disable		0
	#define SPI_WakeUp_Enable			1

	// SPI TX Data Control Register File:
	struct SPITDBC_BITS	{
		unsigned char		TXBLEN:5;			// 4:0
		unsigned char		rsvd1:2;			// 6:5
		unsigned char		TX_INTVAL:1;	// 7
		};
	union SPITDBC_REG		{
		unsigned char					all;
		struct SPITDBC_BITS		bits;
		};
	#define SPI_Master_NextTX_Fsys_9		0	
	#define SPI_Master_NextTX_Fsys_5		1
	#define SPI_TX_BufLen_Lim_1					1
	#define SPI_TX_BufLen_Lim_2					2
	#define SPI_TX_BufLen_Lim_3					3
	#define SPI_TX_BufLen_Lim_4					4
	#define SPI_TX_BufLen_Lim_5					5
	#define SPI_TX_BufLen_Lim_6					6
	#define SPI_TX_BufLen_Lim_7					7
	#define SPI_TX_BufLen_Lim_8					8
	#define SPI_TX_BufLen_Lim_9					9
	#define SPI_TX_BufLen_Lim_10				10
	#define SPI_TX_BufLen_Lim_11				11
	#define SPI_TX_BufLen_Lim_12				12
	#define SPI_TX_BufLen_Lim_13				13
	#define SPI_TX_BufLen_Lim_14				14
	#define SPI_TX_BufLen_Lim_15				15
	#define SPI_TX_BufLen_Lim_16				16

	// SPI RX Data Control Register File:
	struct SPIRDBC_BITS	{
		unsigned char		RXBLEN:5;			// 4:0
		unsigned char		rsvd1:2;			// 6:5
		unsigned char		BUFMODE:1;		// 7
		};
	union SPIRDBC_REG		{
		unsigned char					all;
		struct SPIRDBC_BITS		bits;
		};
	#define SPI_BufMode_Disable					0	
	#define SPI_BufMode_Enable					1
	#define SPI_RX_BufLen_Lim_1					1
	#define SPI_RX_BufLen_Lim_2					2
	#define SPI_RX_BufLen_Lim_3					3
	#define SPI_RX_BufLen_Lim_4					4
	#define SPI_RX_BufLen_Lim_5					5
	#define SPI_RX_BufLen_Lim_6					6
	#define SPI_RX_BufLen_Lim_7					7
	#define SPI_RX_BufLen_Lim_8					8
	#define SPI_RX_BufLen_Lim_9					9
	#define SPI_RX_BufLen_Lim_10				10
	#define SPI_RX_BufLen_Lim_11				11
	#define SPI_RX_BufLen_Lim_12				12
	#define SPI_RX_BufLen_Lim_13				13
	#define SPI_RX_BufLen_Lim_14				14
	#define SPI_RX_BufLen_Lim_15				15
	#define SPI_RX_BufLen_Lim_16				16

//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
	void SPI_Init(int);
#endif