//===============================================================================
//	FILE:				EM85FxxxN_Device.h
//
//	TITLE:			EM85xFxxxN Device definitions
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2017/03/06
//===============================================================================
//
//
#ifndef EM85FxxxN_Device_H
#define EM85FxxxN_Device_H

#define   PeripheralEnable		0x7FFF
#define   FuncEnable					0x7FFF
#define   PeripheralDisable		0x0000
#define   FuncDisable					0x0000

#define   TARGET  			1
//---------------------------------------------------------------------------
// User To Select Target Device:
#define   A85F7016N				0
#define   EM85F765N				0
#define   EM85F789N				TARGET

#if	(EM85F789N)
	#define	FlashRomSize		18432
	#define	FlashPageSize		64
	#define	IntRamSize			256
	#define	ExtRamSize			768
	#define	LcdRamSize			32
#elif	(EM85F765N)
	#define	FlashRomSize		18432
	#define	FlashPageSize		64
	#define	IntRamSize			256
	#define	ExtRamSize			768
	#define	LcdRamSize			8
#else
	#define	FlashRomSize		18432
	#define	FlashPageSize		64
	#define	IntRamSize			256
	#define	ExtRamSize			768
	#define	LcdRamSize			0
#endif


//---------------------------------------------------------------------------
// Common CPU Definitions:
#define		NOP()				_nop_()
#define		RST()				SWRSF = 1
#define		ClrRST()		SWRSF = 0

//#define		NormalMode()		PCON &=  0xFF
//#define		SlowMode()			PCON &=  0xFF
//#define		GreenMode()			PCON &=  0xFF
#define		IdleMode()				PCON &=  0x01
#define		PowerDownMode()		PCON |=  0x02

#define		PAG0		0x00
#define		PAG1		0x01
#define		PAG2		0x02
#define		PAG3		0x03

#define 	BIT0		0x01
#define 	BIT1    0x02
#define 	BIT2    0x04
#define 	BIT3    0x08
#define 	BIT4    0x10
#define 	BIT5    0x20
#define 	BIT6    0x40
#define 	BIT7    0x80

//---------------------------------------------------------------------------
// Definitions For 16-bit and 32-Bit Signed/Unsigned Integers:
#ifndef EM85Fxxx_DATA_TYPES
#define EM85Fxxx_DATA_TYPES
	typedef 	char             		int8;
	typedef 	unsigned char       Uint8;
	typedef 	int             		int16;
	typedef 	unsigned int     		Uint16;
	typedef 	long            		int32;
	typedef 	unsigned long   		Uint32;
	typedef 	float           		float32;
/*	
	//Only For Reminder, do not complier
	unsigned xdata char * data ptrVar1;	//iPtr_xData, 2Byte
	unsigned char data * xdata ptrVar2;	//xPtr_iData, 1Byte
	unsigned char code * xdata ptrVar3;	//xPtr_cData, 2Byte
	unsigned char code * code  ptrVar4;	//cPtr_cData, 2Byte, cPtr is RO, must give initial value
	unsigned char * xdata  ptrVar5;			//xPtr_gData, 3Byte
	unsigned char * ptrVar5;						//?Ptr_gData, 3Byte, by complier model
	char (* data fp)(void);							//iPtr_cFunc
	*/
#endif

//---------------------------------------------------------------------------
// Include All Kernel Header Files:
#include <intrins.h>

// Include All Peripheral Header Files:
#include "EM85F789N.h"
#include "EM85FxxxN_SysCtrl.h"
#include "EM85FxxxN_EINT.h"
#include "EM85FxxxN_GPIO.h"
//#include "EM85FxxxN_TIM.h"
//#include "EM85FxxxN_PWM.h"
//#include "EM85FxxxN_I2C.h"
//#include "EM85FxxxN_SPI.h"
//#include "EM85FxxxN_UART.h"
#include "EM85FxxxN_ADC.h"
#include "EM85FxxxN_CMP.h"
#include "EM85FxxxN_LVD.h"
#include "EM85FxxxN_LCD.h"
#include "EM85FxxxN_IAP.h"

#include "EM85FxxxN_OZ.h" 

//---------------------------------------------------------------------------
// Timer definitions based on System Clock
// 90 MHz devices
#define      mSec0_5          45000           // 0.5 mS
#define      mSec0_75         67500           // 0.75 mS
#define      mSec1            90000           // 1.0 mS
#define      mSec2            180000          // 2.0 mS
#define      mSec5            450000          // 5.0 mS
#define      mSec7_5          675000          // 7.5 mS
#define      mSec10           900000          // 10 mS
#define      mSec20           1800000         // 20 mS
#define      mSec50           4500000         // 50 mS
#define      mSec75           6750000         // 75 mS
#define      mSec100          9000000         // 100 mS
#define      mSec200          18000000        // 200 mS
#define      mSec500          45000000        // 500 mS
#define      mSec750          67500000        // 750 mS
#define      mSec1000         90000000        // 1000 mS
#define      mSec2000         180000000       // 2000 mS
#define      mSec5000         450000000       // 5000 mS

#endif  // end of EM85FxxxN_Device_H definition

//===========================================================================
// End of file.
//===========================================================================
