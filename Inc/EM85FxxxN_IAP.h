//===============================================================================
//	FILE:			EM85FxxxN_IAP.h
//
//	TITLE:		EM85FxxxN_IAP Device definitions
//
//	Author:		ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:			2017/06/27
//===============================================================================
#ifndef EM85FxxxN_IAP_H
#define EM85FxxxN_IAP_H

//----------------------------------------------------------------------------
// Defines FOr The Parameter of Control Register
//----------------------------------------------------------------------------


	// Flash Control Register File:
	struct FLCR_BITS	{
		unsigned char		FLWE:1;			// 0
		unsigned char		FLEE:1;			// 1
		unsigned char		MEMSP:1;		// 2
		unsigned char		rsvd1:4;		// 6:3
		unsigned char		EPEN:1;		// 7
		};
	union FLCR_REG		{
		unsigned char				all;
		struct FLCR_BITS		bits;
		};
	#define Flash_Protect_Disable			0
	#define Flash_Protect_Enable			1
	#define Flash_Space_Program				0
	#define Flash_Space_Infomation		1
	#define Flash_PageErase_Disable		0
	#define Flash_PageErase_Enable		1
	#define Flash_PageWrite_Disable		0
	#define Flash_PageWrite_Enable		1


//----------------------------------------------------------------------------
// Prototypes Of Global Functions
//----------------------------------------------------------------------------
void excuteFlashProgram(int);
void FlashUnlock(int);
void FlashPageRead(int EnableCtrl, bit rom_spce, Uint8 code *data read_index, Uint8 xdata *ptr_destination );
void FlashPageErase(int EnableCtrl, bit rom_spce, Uint8 code *ptr_destination);
void FlashPageWrite(int EnableCtrl, bit rom_spce, Uint8 code *ptr_destination, Uint8 xdata *ptr_source );

#endif