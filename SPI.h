#ifndef __spi__h
#define __spi__h
#include "stm32f4xx.h"                  // Device header
#include "stdint.h"

void spi_write(unsigned char c);
void spi_print( char *p);
void spi_init(void);
uint16_t spi_read_write(unsigned char c);
#endif