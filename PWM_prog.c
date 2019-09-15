/*
 * PWM_prog.c
 *
 *  Created on: Sep 11, 2019
 *      Author: li-lo
 */
#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include"PWM_int.h"

void voidPWMInit(void){
	TCCR0=0x69;

	TCCR2=0x69;



}
void voidPWM_OC0_Set_DC(u8 dc){
	OCR0=((dc*256)/100)-1;


}

void voidPWM_OC2_Set_DC(u8 d1c){
	OCR2=((d1c*256)/100)-1;
}

