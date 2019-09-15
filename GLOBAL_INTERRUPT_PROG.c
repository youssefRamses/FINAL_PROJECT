/*
 * GLOBAL_INTERRUPT_PROG.c
 *
 *  Created on: Aug 28, 2019
 *      Author: li-lo
 */
#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "LED_int.h"
#include "LCD_int.h"
#include "SW_int.h"
#include"avr/delay.h"
#include "LCD_int.h"
#include "KP_int.h"


void Global_INTERRUPT_EN(void){

	SET_BIT(SREG,7);

}

void Global_INTERRUPT_DIS(void){

	CLEAR_BIT(SREG,7);

}
