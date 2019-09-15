/*#include "std_types.h"
#include "Bit_Math.h"
#include "avr/io.h"
#include "DIO_Int.h"
#include "avr/delay.h"
#include "UART_init.h"
#include "GLOBAL_INTERRUPT_INT.h"

void RX_ISR(void);


u8 data = 0;
int main(void){

	Global_INTERRUPT_DIS();
	UART_voidInit();
	DIO_voidInitialize();
	LCD_voidInitialize();
	UART_RX_SetCallBack(RX_ISR);
	Global_INTERRUPT_EN();

	while(1)
	{
     if(data == 'A')
     { DIO_voidSetPin(1);}
     else { DIO_voidClearPin(1);}
	}

	return 0;
}


void RX_ISR(void)
{
  	data = UDR ;
}*/
