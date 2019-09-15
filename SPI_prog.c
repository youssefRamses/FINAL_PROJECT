/*
 * SPI_prog.c
 *
 *  Created on: Sep 9, 2019
 *      Author: li-lo
 */

#include <avr/io.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "SPI_priv.h"
#include "SPI_config.h"
#include "SPI_int.h"
void SPI_voidInit(void){

	SPCR=0b00000000;

#if(SPI_IN_EN==ENABLE)
	SET_BIT(SPCR,7);

#endif


	SET_BIT(SPCR,6);

#if(DATA_ORDER==LSB)
	SET_BIT(SPCR,5);

#endif

#if(MA_SL_MODE==MASTER)
	SET_BIT(SPCR,4);

#endif

#if(CLOCK_PHASE==MODE0)
	CLEAR_BIT(SPCR,2);
	CLEAR_BIT(SPCR,3);

#endif

#if(CLOCK_PHASE==MODE1)
	SET_BIT(SPCR,2);
	CLEAR_BIT(SPCR,3);

#endif

#if(CLOCK_PHASE==MODE2)
	SET_BIT(SPCR,3);
	CLEAR_BIT(SPCR,2);
#endif

#if(CLOCK_PHASE==MODE3)
	SET_BIT(SPCR,3);
	SET_BIT(SPCR,2);


#endif


#if SC_SPEED == SC_SPEED16
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPSR,0);
#elif
#endif
}

u8 SPI_voidMasterReceive(void){
	SPI_voidSend(0xff);
	while(!(CHECK_BIT(SPSR,7)));
	return SPDR;

}

void SPI_voidSend(u8 Data){
	SPDR=Data;
	while(!(CHECK_BIT(SPSR,7)));


}

u8 SPI_voidSlaveReceive(void){
	//while(!(CHECK_BIT(SPSR,7)));
	return SPDR;

}

