/*
 * EXTERNAL_INTERRUPT_PROG.c
 *
 *  Created on: Aug 28, 2019
 *      Author: li-lo
 */


#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "EXTERNAL_INTERRUPT_CONFIG.h"
#include "EXTERNAL_INTERRUPT_INT.h"
#include "EXTERNAL_INTERRUPT_PRIV.h"
#include "DIO_int.h"

static volatile void (*pf) (void);


void EXT_INTERRUPT0_INIT(void){
	EXT_INTERRUPT0_DIS();
	EXT_I_SET_MODE();

}


void EXT_INTERRUPT0_EN(void){
	SET_BIT(GICR,6);


}

void EXT_INTERRUPT0_DIS(void){
	CLEAR_BIT(GICR,6);

}
void EXT_I_SET_MODE(void){
	#if(INTERRUPT0_SENCE_MODE == RISING_EDGE)
	{
		SET_BIT(MCUCR,1);
		SET_BIT(MCUCR,0);
	}
	#elif(INTERRUPT0_SENCE_MODE == FALLING_EDGE){
	SET_BIT(MCUCR,1);
	CLEAR_BIT(MCUCR,0);
	}
	#elif(INTERRUPT0_SENCE_MODE == ON_CHANGE){
	SET_BIT(MCUCR,0);
	CLEAR_BIT(MCUCR,1);
	}
	#elif(INTERRUPT0_SENCE_MODE == LOW_LEVEL){
	CLEAR_BIT(MCUCR,1);
	CLEAR_BIT(MCUCR,0);
	}
	#else{#error "wrong mode"}
#endif
}

void EXT_INTERRUPT0_SetCallBack(void(*p)(void)){
	pf=p;

}

void __vector1(void) __attribute__ ((signal,used));
void __vector1(void)
{
pf();
}
