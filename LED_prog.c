/*
 * LED_prog.c
 *
 *  Created on: Aug 26, 2019
 *      Author: li-lo
 */

#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "LED_int.h"
#include"avr/delay.h"
void LED_voidInitialize(void){}
void LED_ON(u8 led){
	DIO_voidSetPin(led);
}
void LED_OFF(u8 led){
	DIO_voidClearPin(led);
}
void LED_BLINK(u8 led,u16 time){
	while(1){
	DIO_voidSetPin(led);
	_delay_ms(time);
	DIO_voidClearPin(led);
	_delay_ms(time);
	}
}
