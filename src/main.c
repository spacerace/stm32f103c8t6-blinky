#include "stm32f10x.h"

#define LED_ON()	GPIO_SetBits(GPIOC , GPIO_Pin_13)
#define LED_OFF()	GPIO_ResetBits(GPIOC , GPIO_Pin_13)

void init_led();

void delay(unsigned int j) {
	unsigned int i;

	for(i = 0; i < j; i++) {
		asm("nop");
	}
	return;
}

int main(void){
	SystemInit();
	init_led();
	for(;;) {
		LED_ON();
		delay(750000);
		LED_OFF();
		delay(750000);
	}

	return 0;
}

void init_led() {
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);

	// LED=PC13
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	return;
}

