#include "SysClockConfig.h"
#include <stdio.h>
#include "GLCD_ST7735.h"
uint64_t cnt_current,cnt_prev=0;;
char data[20];
void encoder_init(void)
{
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
	RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
	GPIOA->MODER|=(1<<1)|(1<<3);
	GPIOA->AFR[0]|=(1<<0)|(1<<4);
	TIM2->ARR = 0xFFFFFFFF;
	TIM2->CCMR1 |= (TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0 ); 
	TIM2->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);  
	TIM2->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;   
	TIM2->CR1 |= TIM_CR1_CEN ;   
}

int  main(void)

{
SysClockConfig();
encoder_init();

ST7735_Init();
LCD_CS0;
ST7735_FillScreen(BLACK);
LCD_CS1;

	
while (1)
{
cnt_current=TIM2->CNT;
if(cnt_current!=cnt_prev)
{
	LCD_CS0;
cnt_prev=cnt_current;

sprintf(data,"%u        ",TIM2->CNT);
ST7735_DrawString(0,0,"Current Counting",WHITE);
ST7735_DrawString(0,1,data,WHITE);
	LCD_CS1;
}


}

}

