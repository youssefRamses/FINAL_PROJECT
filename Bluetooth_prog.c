
#include<avr/io.h>
#include<util/delay.h>
#include "std_Types.h"
#include<string.h>
#include<avr/interrupt.h>
#include"DIO_int.h"
#include"Bluetooth_int.h"

unsigned char data_in[25];
unsigned char command_in[25];

unsigned char data_count;
volatile unsigned char command_ready;




void UART_Init( unsigned int baud)      //BAUD=103 16MHZ (internal RC Osc.)
{
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	UCSRC = (1<<URSEL)|(0<<USBS)|(3<<UCSZ0);
}



void UART_Transmit_char( unsigned char data )
{
	while ( !( UCSRA & (1<<UDRE)) );
	UDR = data;
}


unsigned char UART_Receive( void )
{
	while ( !(UCSRA & (1<<RXC)) );
	return UDR;
}



void UART_Transmit_string(char string[])
{
	int i=0;
	while ( string[i] > 0)
	UART_Transmit_char(string[i++]);
}

void set_UART_init()
{
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
	sei();
}
