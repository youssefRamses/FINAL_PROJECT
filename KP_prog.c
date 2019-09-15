/*
 * KP_prog.c
 *
 *  Created on: Aug 28, 2019
 *      Author: li-lo
 */


#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "KP_priv.h"
#include "KP_config.h"
#include "KP_int.h"
#include "SW_int.h"

const u8 key[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};

void KP_voidInitialize(void){}
void KP_voidOutSequence(u8 seq){
	switch(seq){
	case 0:
		DIO_voidSetPin(KP_PIN_1);
		DIO_voidClearPin(KP_PIN_2);
		DIO_voidClearPin(KP_PIN_3);
		DIO_voidClearPin(KP_PIN_4);

		break;
	case 1:
		DIO_voidClearPin(KP_PIN_1);
		DIO_voidSetPin(KP_PIN_2);
		DIO_voidClearPin(KP_PIN_3);
		DIO_voidClearPin(KP_PIN_4);

		break;
	case 2:
		DIO_voidClearPin(KP_PIN_1);
		DIO_voidClearPin(KP_PIN_2);
		DIO_voidSetPin(KP_PIN_3);
		DIO_voidClearPin(KP_PIN_4);
		break;
	case 3:
		DIO_voidClearPin(KP_PIN_1);
		DIO_voidClearPin(KP_PIN_2);
		DIO_voidClearPin(KP_PIN_3);
		DIO_voidSetPin(KP_PIN_4);
		break;
	default:break;


	}
}
u8 KP_voidGetKP(void){
	for(u8 x=0;x<4;x++){
		 KP_voidOutSequence(x);
		 if(IS_SW_PRESSED(KP_PIN_1)){
			 return key[0][x];
		 }
		 if(IS_SW_PRESSED(KP_PIN_2)){
		 			 return key[1][x];
		 		 }
		 if(IS_SW_PRESSED(KP_PIN_3)){
		 			 return key[2][x];
		 		 }
		 if(IS_SW_PRESSED(KP_PIN_4)){
		 			 return key[3][x];
		 		 }
		 }

	}

