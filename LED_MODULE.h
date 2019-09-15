
#include "Std_Types.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "DIO_config.h"
#include "LED_int.h"
#include "LED_config.h"

#ifndef LED_MODULE_H
#define LED_MODULE_H

void LED_Headlights(void);
void LED_Right(void);
void LED_Left(void);
void LED_Breaks(void);
void LED_Flag0(void);
void LED_Flag1(void);
#endif
