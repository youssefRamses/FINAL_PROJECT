/*
 * SPI_int.h
 *
 *  Created on: Sep 9, 2019
 *      Author: li-lo
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_

void SPI_voidInit(void);
void SPI_voidSend(u8 Data);


u8 SPI_voidSlaveReceive(void);
u8 SPI_voidMasterReceive(void);



#endif /* SPI_INT_H_ */
