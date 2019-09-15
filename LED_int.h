/*
 * LED_int.h
 *
 *  Created on: Aug 26, 2019
 *      Author: li-lo
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#define LED1 DIO_PIN_4
#define LED2 DIO_PIN_5

#endif /* LED_INT_H_ */

void LED_voidInitialize(void);
void LED_ON(u8 led);
void LED_OFF(u8 led);
void LED_BLINK(u8 led,u16 time);
