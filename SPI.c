
#include "SPI.h"
void spi_write(unsigned char c){

	while(!(SPI1->SR&SPI_SR_TXE)){;} // wait to transmision buffer to be emplty
		SPI1->DR= c;
		while(!(SPI1->SR&SPI_SR_BSY)){;}
	
}

void spi_print( char *p)
{
	while(*p!='\0')
	{
		spi_write(*p);
		p++;
	}
}

void spi_init(void)
	
{
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN; //enable clock forn gpio a
RCC->APB2ENR|=RCC_APB2ENR_SPI1EN; //enable clock for spi1
//GPIOA->MODER=0;
GPIOA->MODER|=0xA900;
GPIOA->AFR[0]|=0x55500000;
//SPI1->CR1|=(1<<3)|(1<<2)|(1<<14);
SPI1->CR1|=0x31c;
SPI1->CR2=0;
SPI1->CR1|=(0<<3)|(0<<4)|(0<<5);
SPI1->CR1|=SPI_CR1_SPE;

}
uint16_t spi_read_write(unsigned char c)
{
uint16_t x;

while(!(SPI1->SR&SPI_SR_TXE)){;} // wait to transmision buffer to be emplty

		SPI1->DR= c;
	while(!(SPI1->SR&SPI_SR_TXE)){;}
	while(!(SPI1->SR&SPI_SR_RXNE)){;}
x=SPI1->DR;
	while(SPI1->SR&SPI_SR_BSY){;}


return x;
}