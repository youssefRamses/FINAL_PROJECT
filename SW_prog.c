/*
 * SW_prog.c
 *
 *  Created on: Aug 26, 2019
 *      Author: li-lo
 */


#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "SW_priv.h"
#include "SW_config.h"
#include "SW_int.h"
#include"avr/delay.h"
void SW_voidInitialize(void){}
u8 IS_SW_PRESSED(u8 sw){
	return DIO_uint8PinState(sw);
}
