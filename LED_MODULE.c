#include "LED_MODULE.h"

void LED_Headlights(void){

	LED_ON(DIO_PIN_16);


}
void LED_Right(void){
	LED_BLINK(DIO_PIN_17,300);


}
void LED_Left(void){

	LED_BLINK(DIO_PIN_18,300);


}
void LED_Breaks(void){

	LED_ON(DIO_PIN_19);

}
void LED_Flag0(void){

	LED_ON(DIO_PIN_20);

}
void LED_Flag1(void){

	LED_ON(DIO_PIN_21);

}
