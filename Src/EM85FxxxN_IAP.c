//===============================================================================
//	FILE:				EM85FxxxN_IAP.c
//
//  Target:  		EM85FxxxN
//
//  Compiler    Keil
//
//	Author:			ELAN SRD1 Arthur (Lu Hungche)
//
//	Date:				2017/06/27
//-----------------------------------------------------------------------------
//	Description:	Primary system file for the
//					
//-----------------------------------------------------------------------------
// History:
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|================================================
//  0.1 | 27 Jun 2017 | Arthur| Original Release.
// -----|-------------|-------|------------------------------------------------
//	0.2 |             |       | 
// -----|-------------|-------|------------------------------------------------
//  0.3 | 
// -----|-------------|-------|------------------------------------------------
//
//===============================================================================

//--Include header files used in the main function--------------//
#include "EM85FxxxN_Device.h"

data Uint8 code *ReadIndex _at_ 0x7E;	//*ReadIndex_ptr at data[0x40] pointer to code[ReadIndex_ptr]

#define FlashPageSize 64
Uint8 xdata FlashReadData[FlashPageSize];
Uint8 xdata FlashWriteData[FlashPageSize] = {
	0x55, 0x55, 0x55, 0x55, 0x55, 0xAA, 0xAA, 0xAA,
	0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55, 0x55, 0xAA,
	0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	0x55, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x33, 0x33,
	0x33, 0x33, 0x33, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0x33, 0x33, 0x33, 0x33, 0x33, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0x33, 0x33, 0x33, 0x33, 0x33, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc,0x12, 0x34, 0x56, 0x78};

	

//=============================================================================
//	Function:			void excuteFlashProgram(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void excuteFlashProgram(int16	EnableCtrl){
		Uint8 pageNum = 0;
		Uint8 CKCON1_Save = CKCON1;
	if (EnableCtrl){
		CKCON1 = (CKCON1&0x0f) + 0x50;	// switch to IRC 8MHz
		ReadIndex = 0x4780;							// Main page (4096/64 = 64)
		for(pageNum = 0; pageNum < 1	;pageNum++){
			FlashPageRead(PeripheralEnable,Flash_Space_Program, ReadIndex,&FlashReadData);
			FlashPageErase(PeripheralEnable,Flash_Space_Program,ReadIndex);
			FlashPageWrite(PeripheralEnable,Flash_Space_Program,ReadIndex,&FlashWriteData);
			FlashPageRead(PeripheralEnable,Flash_Space_Program, ReadIndex,&FlashReadData);
			ReadIndex += 0x40;}
		CKCON1 = CKCON1_Save;}
	else
		PAGESW		= PAG0;
	}//  End of function FlashUnlock

//=============================================================================
//	Function:			void FlashUnlock(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void FlashUnlock(int16	EnableCtrl){
	if (EnableCtrl){
		PAGESW		= PAG0;
		FLKEY		= 0xA9; //Unlock Key A
		FLKEY		= 0x7F;	//Unlock Key B
		}
	else
		PAGESW		= PAG0;
	PAGESW		= PAG0;
	}//  End of function FlashUnlock

//=============================================================================
//	Function:			void FlashPageRead(int16	EnableCtrl, bit rom_spce, Uint8 code *data ptr_source, Uint8 xdata *ptr_destination )
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void FlashPageRead(int16	EnableCtrl, bit rom_spce, Uint8 code *data ptr_source, Uint8 xdata *ptr_destination ){
	union FLCR_REG		LocalVar_A;	
	Uint8	loop_counter;
	EA = 0;
	if (EnableCtrl){
		PAGESW		= PAG0;
		LocalVar_A.all	= FLCR;
			LocalVar_A.bits.FLWE		= Flash_PageWrite_Disable;
			LocalVar_A.bits.FLEE		= Flash_PageErase_Disable;
			LocalVar_A.bits.MEMSP		= rom_spce;
			LocalVar_A.bits.EPEN		= Flash_Protect_Disable;
			FLCR	= LocalVar_A.all;
		FLKEY		= 0xA9; //Unlock Key A
		FLKEY		= 0x7F;	//Unlock Key B
		for(loop_counter = 0;loop_counter < FlashPageSize ; loop_counter++){
			*ptr_destination = *ptr_source;
			ptr_source++;
			ptr_destination++;}	
		}
	else
		PAGESW		= PAG0;
	EA = 1;
	}//  End of function FlashUnlock


//=============================================================================
//	Function:			void FlashPageErase(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void FlashPageErase(int16	EnableCtrl, bit rom_spce, Uint8 code *ptr_destination ){
	union FLCR_REG		LocalVar_A;	
	int8 xdata *data pwrite;
	EA = 0;
	if (EnableCtrl){
		//*ptr_destination = 0x2000;
		pwrite = (int8 xdata *) ptr_destination;
		*pwrite = 0; 		// initiate page erase
		
		PAGESW		= PAG0;
		FLKEY		= 0xA9; //Unlock Key A
		FLKEY		= 0x7F;	//Unlock Key B
		
		LocalVar_A.all	= FLCR;
			LocalVar_A.bits.FLWE		= Flash_PageWrite_Disable;
			LocalVar_A.bits.FLEE		= Flash_PageErase_Enable;
			LocalVar_A.bits.MEMSP		= rom_spce;
			//LocalVar_A.bits.EPEN		= Flash_Protect_Disable;
			FLCR	= LocalVar_A.all;
		Delay(10);
		}
	else
		PAGESW		= PAG0;
	EA = 1;
	}//  End of function FlashPageErase

	
//=============================================================================
//	Function:			void FlashPageWrite(int)
//
//	Description:	NA
//
//	Returnvalue:	Null
//
//=============================================================================
void FlashPageWrite(int16	EnableCtrl, bit rom_spce, Uint8 code *ptr_destination, Uint8 xdata *ptr_source ){
	union FLCR_REG		LocalVar_A;
	Uint8 cnt;	
	Uint8 xdata *data pwrite; 									// FLASH write pointer
	pwrite = (Uint8 xdata *) ptr_destination; 	// initialize write pointer

	EA = 0;
	if (EnableCtrl){
		PAGESW		= PAG0;
		FLKEY		= 0xA9; //Unlock Key A
		FLKEY		= 0x7F;	//Unlock Key B
		for(cnt=0;cnt<FlashPageSize;cnt++){
			*pwrite = *ptr_source; 	// write the byte
			pwrite++;
			ptr_source++;
			}
		LocalVar_A.all	= FLCR;
			LocalVar_A.bits.FLWE		= Flash_PageWrite_Enable;
			LocalVar_A.bits.FLEE		= Flash_PageErase_Disable;
			LocalVar_A.bits.MEMSP		= rom_spce;
			LocalVar_A.bits.EPEN		= Flash_Protect_Disable;
			FLCR	= LocalVar_A.all;
		Delay(10);
		}
	else
		PAGESW		= PAG0;
	EA = 1;
	}//  End of function FlashPageWrite