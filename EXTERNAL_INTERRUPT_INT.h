/*
 * EXTERNAL_INTERRUPT_INT.h
 *
 *  Created on: Aug 28, 2019
 *      Author: li-lo
 */

#ifndef EXTERNAL_INTERRUPT_INT_H_
#define EXTERNAL_INTERRUPT_INT_H_

void EXT_INTERRUPT0_INIT(void);
void EXT_INTERRUPT0_EN(void);
void EXT_INTERRUPT0_DIS(void);
void EXT_INTERRUPT0_SetCallBack(void(*p) (void));

#endif /* EXTERNAL_INTERRUPT_INT_H_ */
