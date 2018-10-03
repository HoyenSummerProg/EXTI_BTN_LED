/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HE_CFG_H
#define __HE_CFG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"

/* Exported types ------------------------------------------------------------*/
typedef enum 
{
  LED1 = 0,
  LED2 = 1
} Led_TypeDef;


#define LEDn                             2

#define LED1_PIN                         GPIO_Pin_9
#define LED1_GPIO_PORT                   GPIOC
#define LED1_GPIO_CLK                    RCC_AHBPeriph_GPIOC
  
#define LED2_PIN                         GPIO_Pin_8
#define LED2_GPIO_PORT                   GPIOC
#define LED2_GPIO_CLK                    RCC_AHBPeriph_GPIOC

#define USER_BTN                         GPIO_Pin_0
#define UB_GPIO_PORT                     GPIOA
#define UB_CLK                           RCC_AHBPeriph_GPIOA
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Gpio_Init(void);
void LED_On(Led_TypeDef Led);
void LED_Off(Led_TypeDef Led);
void LED_Toggle(Led_TypeDef LED);
void decrement_delay(void);
void delay_msSysTick(uint32_t delay);
void HW_GPIO_IN_Init(void);
#endif /* __HE_CFG_H */
