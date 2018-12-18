#include <stm32f4xx.h>

#define GPIO_Pin_0       ((uint16_t)0x0001)
#define GPIO_Pin_1       ((uint16_t)0x0002)
#define GPIO_Pin_2       ((uint16_t)0x0004)
#define GPIO_Pin_3       ((uint16_t)0x0008)
#define GPIO_Pin_4       ((uint16_t)0x0010)
#define GPIO_Pin_5       ((uint16_t)0x0020)
#define GPIO_Pin_6       ((uint16_t)0x0040)
#define GPIO_Pin_7       ((uint16_t)0x0080)
#define GPIO_Pin_8       ((uint16_t)0x0100)
#define GPIO_Pin_9       ((uint16_t)0x0200)
#define GPIO_Pin_10      ((uint16_t)0x0400)
#define GPIO_Pin_11      ((uint16_t)0x0800)
#define GPIO_Pin_12      ((uint16_t)0x1000)
#define GPIO_Pin_13      ((uint16_t)0x2000)
#define GPIO_Pin_14      ((uint16_t)0x4000)
#define GPIO_Pin_15      ((uint16_t)0x8000)
#define GPIO_Pin_ALL     ((uint16_t)0xffff)

//³õÊ¼»¯GPIO
/*
typedef struct
{
	uint32_t    GPIO_Pin;    //GPIO Òý½Å
	uint8_t     GPIO_Mode;   //GPIO Òý½Å¹¤×÷Ä£Ê½
	uint8_t     GPIO_Speed;  //GPIO Òý½ÅËÙÂÊ
	uint8_t     GPIO_OType;  //GPIO Òý½ÅÊä³öÀàÐÍ
	uint8_t     GPIO_PuPd;   //GPIO Òý½ÅÉÏ/ÏÂÀ­
}GPIO_InitTypeDef;
*/

//-----------------------------------------------------------
//GPIO ¶Ë¿ÚÅäÖÃÄ£Ê½µÄÃ¶¾Ù¶¨Òå
typedef enum
{
	GPIO_Mode_IN  = 0X00,   //ÊäÈë
	GPIO_Mode_OUT = 0X01,   //Êä³ö
	GPIO_Mode_AF  = 0X02,   //¸´ÓÃ
	GPIO_Mode_AN  = 0X03    //Ä£Äâ
}GPIOMode_TypeDef;

//GPIO ¶Ë¿ÚÊä³öÀàÐÍÃ¶¾Ù¶¨Òå
typedef enum
{
	GPIO_OType_PP   = 0x00,  //ÍÆÍì
	GPIO_OType_OD   = 0x01   //¿ªÂ©
}GPIOOType_TypeDef;

//GPIO ¶Ë¿ÚËÙ¶ÈµÄÃ¶¾Ù¶¨Òå
typedef enum
{
	GPIO_Speed_2MHz    = 0x00,  //2MHz
	GPIO_Speed_25MHz   = 0x01,  //25MHz
	GPIO_Speed_50MHz   = 0x10,  //50MHz
	GPIO_Speed_100MHz  = 0x11   //100MHz
}GPIOSpeed_TypeDef;

//GPIO ¶Ë¿ÚÉÏ/ÏÂÀ­Ã¶¾Ù¶¨Òå
typedef enum
{
	GPIO_PuPd_NOPULL = 0X00,//¸¡¿Õ
	GPIO_PuPd_UP     = 0X01,//ÉÏÀ­
	GPIO_PuPd_DOWN   = 0X02 //ÏÂÀ­
}GPIOPuPd_TypeDef;
//-----------------------------------------------------------

typedef struct
{
	uint32_t           GPIO_Pin;     //GPIO Òý½Å
	GPIOMode_TypeDef   GPIO_Mode;    //GPIO Òý½Å¹¤×÷Ä£Ê½
	GPIOOType_TypeDef  GPIO_OType;   //GPIO Òý½ÅÊä³öÀàÐÍ
	GPIOSpeed_TypeDef  GPIO_Speed;   //GPIO Òý½ÅËÙÂÊ
	GPIOPuPd_TypeDef   GPIO_PuPd;    //GPIO Òý½ÅÉÏ/ÏÂÀ­
}GPIO_InitTypeDef;


void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);


