/*
 * Car_prog.c
 *
 *  Created on: Sep 10, 2019
 *      Author: Administrator
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
#include "KP_config.h"
#include "GLOBAL_INTERRUPT_INT.h"
#include "EXTERNAL_INTERRUPT_INT.h"
#include "SPI_config.h"
#include "SPI_Int.h"
#include "Car_config.h"
#include "Car_int.h"

void car_intialize(void)
{
	DIO_voidClearPin(motorA_b_pin);
	DIO_voidClearPin(motorA_f_pin);
	DIO_voidClearPin(motorB_b_pin);
	DIO_voidClearPin(motorB_f_pin);
	DIO_voidClearPin(8);
	DIO_voidSetPin(13);
	DIO_voidSetPin(14);
	DIO_voidSetPin(15);
}
void car_forward(void)
{


	DIO_voidSetPin(10);
	DIO_voidClearPin(9);

		DIO_voidSetPin(12);
		DIO_voidClearPin(11);
}

void car_backward(void)
{
	DIO_voidSetPin(9);
	DIO_voidClearPin(10);

	DIO_voidSetPin(11);
	DIO_voidClearPin(12);
}


void car_righ(void)
{


					DIO_voidSetPin(9);
							DIO_voidClearPin(10);

							DIO_voidSetPin(12);
								DIO_voidClearPin(11);
}


void car_left(void)
{
	DIO_voidSetPin(10);
	DIO_voidClearPin(9);

		DIO_voidSetPin(11);
		DIO_voidClearPin(12);

}
