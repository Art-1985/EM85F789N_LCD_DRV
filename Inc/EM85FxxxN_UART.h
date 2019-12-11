//===============================================================================
//	FILE:			EM85FxxxN_UART.h
//
//	TITLE:		EM85FxxxN_GPIO Device definitions
//
//	Author:		ELAN SRD1 Adolf (Tzung Yuan Yeh)
//
//	Date:			2016/12/13
//===============================================================================
#ifndef EM85FxxxN_UART_H
#define EM85FxxxN_UART_H

//----------------------------------------------------------------------------
// Defines For The Parameter of Control Register
//----------------------------------------------------------------------------
	// Timer (8051 native) Clock Control Register File(CKCON0):
	#define 	Timer1_SCLK_div12							0xAF
	#define 	Timer1_SCLK_div4							0x10
	#define 	Timer1_SCLK_Nodiv							0x40	
	#define 	Timer0_SCLK_div12							0xD7
	#define 	Timer0_SCLK_div4							0x08
	#define 	Timer0_SCLK_Nodiv							0x40	
	// Timer (8051 native) Control Register File(TMOD):
	#define 	Timer1_Counter_mode						0x40	
	#define 	Timer1_Timer_mode							0xBF	

	// Timer (8051 native) Control Register File(TCON):
	#define 	Timer1_Overflow								0x80
	#define 	Timer1_Run										0x40
	#define 	Timer0_Overflow								0x20
	#define 	Timer0_Run										0x10

	// UART (8051 native) Control Register File(SCON0):
	#define 	UART0_TX_Falg									0x02
	#define 	UART0_TX_Falg_Clr							0xFD
	#define 	UART0_RX_Falg									0x01
	#define 	UART0_RX_Falg_Clr							0xFE
	// UART (Elan) Control Register File(UR2CR):
	#define 	UART2_TX_Empty_Falg						0x02
	#define 	UART2_TX_Start								0x01

	// Message Box
	struct UART_MSG_obj	{
		unsigned char DataLen;
		unsigned char Frame;
		unsigned char RxDataByte[8];
		unsigned char TxDataByte[9];
		unsigned char Index;
		unsigned char PackageFinish;
	};

// UART 0 (8051 native) Control Register 1 File:
	struct SCON0_BITS	{
		unsigned char		RI0:1;				 	 	 // 0
		unsigned char		TI0:1;				 	 	 // 1
		unsigned char		RB08:1;		   	 		 // 2
		unsigned char		TB08:1;		     	 	 // 3
		unsigned char		REN0:1;	     	 		 // 4
		unsigned char		MCE0:1;	     	 		 // 5
		unsigned char		SM:2;	     	 		 	 // 6:7
		};
	 union SCON0_REG {
		unsigned char			 all;
		struct SCON0_BITS	bits;
		};
	// UART 0 (8051 native) Control Register Setting (SCON)
	#define 	UART0_Mode_Sync								0			
	#define 	UART0_Mode_0									0		
	#define 	UART0_Mode_8Bit								1
	#define 	UART0_Mode_1									1		
	#define 	UART0_Mode_9Bit_Static				2
	#define 	UART0_Mode_2									2
	#define 	UART0_Mode_9Bit								3
	#define 	UART0_Mode_3									3
	#define   UART0_ModeSel									0xC0
	#define 	UART0_MultiComm_Disable 			1
	#define 	UART0_MultiComm_Enable				0
	#define 	UART0_RB8											0x04
	#define 	UART0_Receive_Enable					1
	#define 	UART0_Receive_Disable					0
	// UART 0 (8051 native) Power Control Register Setting (PCON)
	#define 	UART0_DoubBaud_Enable					0x80		
	#define 	UART0_DoubBaud_Disable				0x7F	

		
	// UART 2 Control Register 1 File:
	struct UR2CR_BITS	{
		unsigned char		U2TXE:1;				 	 // 0
		unsigned char		U2TBE:1;				 	 // 1
		unsigned char		UR2BRSH:3;		   	 // 4:2
		unsigned char		U2MODE:2;		     	 // 6:5
		unsigned char		U2INVEN:1;	     	 // 7
		};
	 union UR2CR_REG {
		unsigned char				all;
		struct UR2CR_BITS		bits;
		};
	#define 	UART2_NormalInHigh					0
	#define 	UART2_NormalInLow						1
	#define 	UART2_Mode_7Bit	  					0
	#define 	UART2_Mode_8Bit		 					1
	#define 	UART2_Mode_9Bit		 					2
	#define 	UART2_Mode				  				0x60	
	#define 	UART2_TX_Disable						0
	#define 	UART2_TX_Enable							1
		//Baud Rate Define-FH
		#define   FH_20M_Baud_H_9600				0
		#define   FH_20M_Baud_L_9600				129
		#define   FH_20M_Baud_H_19200				0
		#define   FH_20M_Baud_L_19200				64
		#define   FH_20M_Baud_H_38400				0
		#define   FH_20M_Baud_L_38400				31
		#define   FH_20M_Baud_H_115200			0
		#define   FH_20M_Baud_L_115200			9
		//Baud Rate Define-FL
		#define   FL_128K_Baud_H_2400				0
		#define   FL_128K_Baud_L_2400				2
		
	// UART 2 Status Register 1 File:
	struct UR2S_BITS	{
		unsigned char		U2RXE:1;				 	 // 0
		unsigned char		U2RBF:1;				 	 // 1
		unsigned char		U2FMERR:1;			 	 // 2
		unsigned char		U2OVERR:1;		   	 // 3
		unsigned char		U2PRERR:1;			 	 // 4
		unsigned char		U2PRE:1;				 	 // 5
		unsigned char		U2EVEN:1;				   // 6
		unsigned char		UR2TD8:1;				 	 // 7
		};
	union UR2S_REG {
		unsigned char				all;
		struct UR2S_BITS		bits;
		};
	//UART2 Status Register Setting 
	#define 	UART2_Parity_Odd							0
	#define 	UART2_Parity_Even							1
	#define 	UART2_Parity_Disable					0
	#define 	UART2_Parity_Enable						1
	#define 	UART2_Parity_Error_Flag				0x10
	#define 	UART2_Over_Run_Flag						0x08
	#define 	UART2_Frame_Error_Flag	 			0x04
	#define 	UART2_RX_Full_Flag			 			0x02	
	#define 	UART2_RX_Disable				 			0
	#define 	UART2_RX_Enable				 				1
		
	// UART 2 Status Register 2 File:
	struct UR2S2_BITS	{
		unsigned char		U2TSF:1;				 	 // 0
		unsigned char		U2RSF:1;				 	 // 1
		unsigned char		U2ERRSF:1;			 	 // 2
		unsigned char   Reserve:1;				 // 3
		unsigned char		BUFMODE:1;			 	 // 4
		unsigned char		UR2CSS:1;		 	   	 // 5
		unsigned char		UR2DG:2;				 	 // 6:7
		};
	union UR2S2_REG {
		unsigned char			 	all;
		struct UR2S2_BITS		bits;
		};
	//UART2 Status Register 2 Setting 
	#define 	UART2_Deglitch_50ns						0
	#define 	UART2_Deglitch_200ns					1
	#define 	UART2_Deglitch_400ns					2
	#define 	UART2_NoDeglitch  						3
	#define 	UART2_Clock_FL								0
	#define 	UART2_Clock_FH								1
	#define 	UART2_Mode_Single			 				0
	#define 	UART2_Mode_Buffer			 				1
	#define 	UART2_BufferModeOn			 			0x10
	#define 	UART2_ErrorFlag					 			0x04
	#define 	UART2_RXStatusFlag			 			0x02
	#define 	UART2_TXStatusFlag			 			0x01
	//#define 	UART2_RX_Enable				 				1 

	//UART2 Buffer mode Tx Status Flag	
	struct UR2BUFTXSF_BITS	{
		unsigned char		TXERR:1;				 	 // 0
		unsigned char		TXEMPTY:1;			 	 // 1
		unsigned char		TXAEMPTY:1;			 	 // 2
		unsigned char		TXAFULL:1;			   // 3
		unsigned char		TXFULL:1;			     // 4
		unsigned char		TXFIFORST:1;		   // 5
		unsigned char   Reserve:1;				 // 6
		unsigned char		TXBUFSTART:1;		 	 // 7
		};
	 typedef union UR2BUFTXSF_DEFINE {
		unsigned char			 all;
		struct UR2BUFTXSF_BITS	bits;
		}UR2BUFTXSF_REG;
	 
	//UART2 Buffer mode Tx Status Setting 
	#define 	UART2_TXBuf_Start							0x80
	#define 	UART2_TXBuf_Reset							1
	#define 	UART2_TXBuf_Ful								0x10
	#define 	UART2_TXBuf_AmstFul						0x08
	#define 	UART2_TXBuf_AmstEmp						0x04		
	#define 	UART2_TXBuf_Emp								0x02
	#define 	UART2_TXBuf_Err								0x01

		//UART2 Buffer mode Rx Status Flag	
	struct UR2BUFRXSF_BITS	{
		unsigned char		RXERR:1;				 	 // 0
		unsigned char		RXEMPTY:1;			 	 // 1
		unsigned char		RXAEMPTY:1;			 	 // 2
		unsigned char		RXAFULL:1;			 	 // 3
		unsigned char		RXFULL:1;				 	 // 4
		unsigned char		RXFIFORST:1;		 	 // 5
		unsigned char   Reserve:2;				 // 6:7
		};
	 typedef union UR2BUFRXSF_DEFINE {
		unsigned char			 all;
		struct UR2BUFRXSF_BITS	bits;
		}UR2BUFRXSF_REG;
	 
	//UART2 Buffer mode Rx Status Setting 
	#define 	UART2_RXBuf_Reset							1
	#define 	UART2_RXBuf_Ful								0x10	
	#define 	UART2_RXBuf_AmstFul						0x08
	#define 	UART2_RXBuf_AmstEmp						0x04	
	#define 	UART2_RXBuf_Emp								0x02
	#define 	UART2_RXBuf_Err								0x01
		
		//UART2 Buffer mode Tx Interrupt Mask Flag	
	struct UR2BUFTXIM_BITS	{
		unsigned char		TXERRIE:1;			   // 0
		unsigned char		TXEMPTYIE:1;		 	 // 1
		unsigned char		TXAEMPTYIE:1;		 	 // 2
		unsigned char		TXAFULLIE:1;		   // 3
		unsigned char		TXFULLIE:1;			 	 // 4
		unsigned char   Reserve:3;				 // 5:7
		};
	 typedef union UR2BUFTXIM_DEFINE {
		unsigned char			 all;
		struct UR2BUFTXIM_BITS	bits;
		}UR2BUFTXIM_REG;
	 
	//UART2 Buffer mode Tx Interrupt Mask Setting 
	#define 	UART2_TXBuf_FulIntMskOn			  1	
	#define 	UART2_TXBuf_FulIntMskOff		  0	
	#define 	UART2_TXBuf_AmstFulIntMskOn		1	
	#define 	UART2_TXBuf_AmstFulIntMskOff	0	
	#define 	UART2_TXBuf_AmstEmpIntMskOn	  1		
	#define 	UART2_TXBuf_AmstEmpIntMskOff  0
	#define 	UART2_TXBuf_EmpIntMskOn			  1
	#define 	UART2_TXBuf_EmpIntMskOff		  0
	#define 	UART2_TXBuf_ErrIntMskOn			  1
	#define 	UART2_TXBuf_ErrIntMskOff		  0
		
		//UART2 Buffer mode Rx Interrupt Mask Flag	
	struct UR2BUFRXIM_BITS	{
		unsigned char		RXERRIE:1;				// 0
		unsigned char		RXEMPTYIE:1;			// 1
		unsigned char		RXAEMPTYIE:1;			// 2
		unsigned char		RXAFULLIE:1;			// 3
		unsigned char		RXFULLIE:1;				// 4
		unsigned char   Reserve:3;				// 5:7
		};
	 typedef union UR2BUFRXIM_DEFINE {
		unsigned char			 all;
		struct UR2BUFRXIM_BITS	bits;
		}UR2BUFRXIM_REG;
	
	//UART2 Buffer mode Rx Interrupt Mask Setting 
	#define 	UART2_RXBuf_FulIntMskOn			  1	
	#define 	UART2_RXBuf_FulIntMskOff		  0	
	#define 	UART2_RXBuf_AmstFulIntMskOn		1	
	#define 	UART2_RXBuf_AmstFulIntMskOff	0	
	#define 	UART2_RXBuf_AmstEmpIntMskOn	  1		
	#define 	UART2_RXBuf_AmstEmpIntMskOff  0
	#define 	UART2_RXBuf_EmpIntMskOn			  1
	#define 	UART2_RXBuf_EmpIntMskOff		  0
	#define 	UART2_RXBuf_ErrIntMskOn			  1
	#define 	UART2_RXBuf_ErrIntMskOff		  0			
	
		
//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void UART0_Init(int);
void UART2_Init(int);
/*
void UART0_BaudRateSetting(Uint16);
void UART2_BaudRateSetting(Uint32,Uint32);
void setUART2_TXlen(Uint16,Uint16);
void putUART0Byte  (Uint8 *,Uint8 *);
void getUART0Byte  (Uint8 *,Uint8 *);
void setUART2_RXlen(Uint16,Uint16);
void putUART2Data  (Uint8 *,Uint8 *);
void putUART2Byte  (Uint8  ,Uint8  );
void getUART2Data  (Uint8 *,Uint8 *);
void getUART2Byte  (Uint8 *,Uint8 *);
*/
#endif