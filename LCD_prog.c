/*
 * LCD_prog.c
 *
 *  Created on: Aug 27, 2019
 *      Author: li-lo
 */

#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO_int.h"
#include "LCD_priv.h"
#include "LCD_config.h"
#include "LCD_int.h"


void LCD_voidWriteCommand(u8 command){

	DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(command,7));
	DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(command,6));
	DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(command,5));
	DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(command,4));

	DIO_voidWriteOnPin(LCD_PIN_RW,DIO_LOW);
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
	_delay_ms(4);
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
	_delay_ms(4);

	DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(command,3));
	DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(command,2));
	DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(command,1));
	DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(command,0));

	DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
	_delay_ms(4);
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
	_delay_ms(4);


}

void LCD_voidWriteData(u8 data){
	DIO_voidWriteOnPin(LCD_PIN_RS,DIO_HIGH);

	DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(data,7));
	DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(data,6));
	DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(data,5));
	DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(data,4));

	DIO_voidWriteOnPin(LCD_PIN_RS,DIO_HIGH);
	DIO_voidWriteOnPin(LCD_PIN_RW,DIO_LOW);
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
	_delay_ms(4);
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
	_delay_ms(4);

	DIO_voidWriteOnPin(LCD_PIN_D7,CHECK_BIT(data,3));
	DIO_voidWriteOnPin(LCD_PIN_D6,CHECK_BIT(data,2));
	DIO_voidWriteOnPin(LCD_PIN_D5,CHECK_BIT(data,1));
	DIO_voidWriteOnPin(LCD_PIN_D4,CHECK_BIT(data,0));

	DIO_voidWriteOnPin(LCD_PIN_E,DIO_HIGH);
	_delay_ms(4);
	DIO_voidWriteOnPin(LCD_PIN_E,DIO_LOW);
	_delay_ms(4);

}

void LCD_voidInitialize(void){

	LCD_voidWriteCommand(0x03);
	_delay_ms(4);
	LCD_voidWriteCommand(0x03);
	_delay_ms(22);
	LCD_voidWriteCommand(0x03);
	LCD_voidWriteCommand(0x02);
	LCD_voidWriteCommand(0x08);
	LCD_voidWriteCommand(0x00);
	LCD_voidWriteCommand(0x0C);
	LCD_voidWriteCommand(0x01);
	_delay_ms(4);
	LCD_voidWriteCommand(0x00);
	LCD_voidWriteCommand(0x06);

}

void LCD_voidSetCursor(u8 rows,u8 columns){
	u8 Starting_line_position[]={0x80,0xC0,0x94,0xD4};
	LCD_voidWriteCommand(Starting_line_position[columns-1]+rows-1);
	_delay_us(100);

}

void LCD_voidPrint(u8 * string){
	for(u8 i=0;string[i] !='\0';i++){
		LCD_voidWriteData(string[i]);
	}
}

void LCD_voidClearDisplay(void){

	LCD_voidWriteCommand(0x01);
}

void LCD_voidShiftToLeft(void){}
void LCD_voidShiftToRight(void){}
