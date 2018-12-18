#include <stm32f4xx.h>
#include <stm32f4xx_gpio.h>

int main(void)
{
	GPIO_InitTypeDef InitStruct;
	
	RCC->AHB1ENR |= (1<<7);
	
	InitStruct.GPIO_Pin = GPIO_Pin_9;
	InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	InitStruct.GPIO_OType = GPIO_OType_PP;
	InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	InitStruct.GPIO_Speed = GPIO_Speed_25MHz;
	
	GPIO_Init(GPIOH, &InitStruct);
	while(1);
}

void SystemInit(void)
{
}
