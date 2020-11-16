#ifndef __delay__H__
#define __delay__H__
#include "stm32f4xx.h"                  // Device header
#include <stdint.h>

void systick_init(void);
void delay(int ms);
uint32_t millis(void);
void delayuS(int ms);

#endif


