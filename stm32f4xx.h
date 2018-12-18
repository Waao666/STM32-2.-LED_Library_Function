#ifndef __STM32F4XX_H
#define __STM32F4XX_H

#define   __IO  volatile

typedef unsigned int    uint32_t;
typedef unsigned short  uint16_t;
typedef unsigned char   uint8_t;

//----------------------基地址赋值------------------------
#define PERIPH_BASE         ((unsigned int)0x40000000)
	
//总线寄存器
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x10000000)
#define AHB3PERIPH_BASE     (PERIPH_BASE + 0X60000000)


//GPIO 寄存器
#define GPIOA_BASE          AHB1PERIPH_BASE
#define GPIOB_BASE          (AHB1PERIPH_BASE + 0x00000400)
#define GPIOC_BASE          (AHB1PERIPH_BASE + 0x00000800)
#define GPIOD_BASE          (AHB1PERIPH_BASE + 0x00000C00)
#define GPIOE_BASE          (AHB1PERIPH_BASE + 0x00001000)
#define GPIOF_BASE          (AHB1PERIPH_BASE + 0x00001400)
#define GPIOG_BASE          (AHB1PERIPH_BASE + 0x00001800)
#define GPIOH_BASE          (AHB1PERIPH_BASE + 0x00001C00)
#define GPIOI_BASE          (AHB1PERIPH_BASE + 0x00002000)
//复位和时钟控制
#define RCC_BASE            (AHB1PERIPH_BASE + 0x00003800)

//外设时钟使能寄存器
#define RCC_AHB1ENR         *((unsigned int *)(RCC_BASE + 0X30))

typedef struct
{
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint16_t BSRRL;
	__IO uint16_t BSRRH;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2];
}GPIO_TypeDef;

typedef struct
{
	__IO uint32_t CR;
	__IO uint32_t PLLCFGR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
	__IO uint32_t AHB3RSTR;
	__IO uint32_t RESERVED0; //此处为适用于其他芯片版本的APB1RSTR
	__IO uint32_t APB1RSTR;
	__IO uint32_t RESERVED1[2]; //此处为适用于其他芯片版本的APB2RSTR
	__IO uint32_t APB2RSTR;
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
	__IO uint32_t AHB3ENR;
	//后面还有很多，省略...
}RCC_TypeDef;

//------------------定义访问外设的结构体指针---------------------
#define GPIOA   ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC   ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD   ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE   ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF   ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG   ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH   ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI   ((GPIO_TypeDef *) GPIOI_BASE)

#define RCC     ((RCC_TypeDef *) RCC_BASE)

#endif /* __STM32F4XX_H */
