/*
 * Bluetooth_int.h
 *
 *  Created on: Sep 11, 2019
 *      Author: li-lo
 */

#ifndef BLUETOOTH_INT_H_
#define BLUETOOTH_INT_H_

#define GPRS_UDR UDR
#define TRUE 1
#define FALSE 0


void UART_Init(unsigned int baud);
void UART_Transmit_char( unsigned char data );
unsigned char UART_Receive( void );
void UART_Transmit_string(char *string_ptr);
void UART_RxString(char *);
void UART_TxNumber(unsigned int);


#define RX_BUFFER_IS_FULL() ((UCSRA & (1 << RXC)) == 0)
#define TX_BUFFER_IS_FULL() ((UCSRA & (1 << UDRE)) == 0)

#endif /* BLUETOOTH_INT_H_ */
