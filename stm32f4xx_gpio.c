#include <stm32f4xx_gpio.h>
#include <stm32f4xx.h>

void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)                                //Set bits
{
	GPIOx->BSRRL = GPIO_Pin;
}

void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)                              //Reset bits
{
	GPIOx->BSRRH = GPIO_Pin;
}

void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)                   //Find the pin, and initialize the GPIO
{
	uint32_t pinpos = 0x00, pin = 0x00, currency = 0x00;
	currency = GPIO_InitStruct->GPIO_Pin;
	for(pinpos=0x00; pinpos<16; pinpos++)
	{		
			pin = 0x01<<pinpos;
			if(pin == (pin & currency))
			{
				GPIOx->MODER &= ~(3 << (2*pinpos));
				GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (2*pinpos));
			
				GPIOx->PUPDR &= ~(3 << ((2*pinpos)));
				GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIO_PuPd)) << (2*pinpos);
				
				if((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) ||
					 (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
				{
					GPIOx->OSPEEDR &= ~(3 << (2*pinpos));
					GPIOx->OSPEEDR |= ((uint32_t)(GPIO_InitStruct->GPIO_Speed)<<(2*pinpos));
					
					GPIOx->OTYPER &= ~(1 << (pinpos));
					GPIOx->OTYPER |= (uint16_t)((GPIO_InitStruct->GPIO_OType)<<(pinpos));
				}
			}
	}
}

