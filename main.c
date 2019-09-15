/*
 * main.c
 *
 *  Created on: Aug 26, 2019
 *      Author: li-lo
 */


/*
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
#include "KP_int.h"
#include "TIM0_int.h"
#include "GLOBAL_INTERRUPT_INT.h"
#include "EXTERNAL_INTERRUPT_INT.h"
#include "UART_init.h"
#include"SPI_int.h"
#include"PWM_int.h"
#include "Bluetooth_int.h"

void EXT_IMTO_ISR(void);
void ISR_Timer0(void);
u16 TIMER_COUNTER =0 ;

int main(void){

	DIO_voidInitialize();
	//LED_voidInitialize();
	SW_voidInitialize();
	KP_voidInitialize();
	//Global_INTERRUPT_DIS();
	LCD_voidInitialize();

	//EXT_INTERRUPT0_INIT();
	//EXT_INTERRUPT0_EN();

	//EXT_INTERRUPT0_SetCallBack(EXT_IMTO_ISR);

	//Timer0_Interrupt_Enable_OV();

	//Timer0_setCallBack(ISR_Timer0);
	//Global_INTERRUPT_EN();
	//UART_voidInit();
	//SPI_voidInit();

	u8 data;


	/*DDRB |= (1<<3);
	OCR0=((50*256)/100)-1;
	TCCR0=0x69; //fast pwm non inverted no pre-scallar*/

	/*voidPWMInit();
	voidPWM_OC0_Set_DC(50);
	voidPWM_OC2_Set_DC(85);*/

	//BM_voidInit();


	/*u16 UBRR_Value = 103;
	UBRRL = (u16)UBRR_Value;
	UBRRH = (u16)(UBRR_Value>>8);
	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC |= (3<<UCSZ0);


	while(1){
while(!(UCSRA&(1<<RXC)));
data=UDR;
if(data=='5'){
	DIO_voidSetPin(31);
}
	}
return 0;
}

void EXT_IMTO_ISR(void){
	LED_ON(LED1);
	DIO_voidSetPin(DIO_PIN_3);
	_delay_ms(1000);
	DIO_voidClearPin(DIO_PIN_3);
	LED_OFF(LED2);

}

void ISR_Timer0(void){
	DIO_voidSetPin(LED1);
	TIMER_COUNTER++;
	if(TIMER_COUNTER==66){
		DIO_voidTogglePin(LED1);
		TIMER_COUNTER =0;
	}
}
*/

#include<avr/io.h>
#include<util/delay.h>
#include "std_Types.h"
#include<string.h>
#include<avr/interrupt.h>
#include"DIO_int.h"
#include "SW_int.h"
#include "LED_int.h"
#include"Car_int.h"
#include"LED_MODULE.h"
#include"LCD_int.h"
#include"Bluetooth_int.h"



unsigned char data =0;
int main(void)
{
	DIO_voidInitialize();
	LCD_voidInitialize();
    UART_Init(103);                            //9600 baud rate
    sei();

    /*------------------------*/
    //driver setup

    DIO_voidSetPin(8);
    DIO_voidSetPin(13);
    DIO_voidSetPin(14);
    DIO_voidClearPin(15);




    /*while(1)
    {
    	data=UART_Receive();
    	if(data=='A'){
LED_ON(LED1);
_delay_ms(1000);
LED_OFF(LED1);
    	}
    }*/
  //  LCD_voidPrint("welcome");
    while(1)
    {
    	//data = UART_Receive();

    if(data ==  'F') {
    LCD_voidPrint("f");
    car_forward();
    LED_Headlights();}
    else if(data ==  'R')
    {car_righ();
    //LED_Right();
    LCD_voidPrint("R");
    LCD_voidWriteData(data);
    }
    else if(data ==  'L')
    {car_left();
    //LED_Left();
    LCD_voidPrint("L");
    LCD_voidWriteData(data);}
    else if(data ==  'B')
    {car_backward();
    LED_Breaks();
    LCD_voidPrint("B");}

    {
    	_delay_ms(50);
    	DIO_voidClearPin(9);
    	DIO_voidClearPin(10);

    	DIO_voidClearPin(11);
    	DIO_voidClearPin(12);
    }

}
}
//----------------------------------------------------------------------------------


 ISR(USART_RXC_vect)
 {
	 data=UDR;

 }                           // notify main of receipt of data.
