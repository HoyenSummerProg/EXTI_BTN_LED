/**
  ******************************************************************************
  * @file    /main.c 
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    Oct/03/2018
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2018 HOYEN TECH</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "hw_cfg.h"
#include "stdbool.h"
/** @addtogroup STM32F0xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup GPIO_IOToggle
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

__IO bool IsPressed = false;
__IO uint8_t state = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static void SysTickConfig(void);
static void ProcessBtnPressed(void);
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  SysTickConfig();

  Gpio_Init();
  HW_GPIO_IN_Init();
  
  while (1)
  {
    LED_On(LED1);
    if(IsPressed)
      ProcessBtnPressed();
  }
}

/**
  * @brief  Configure a SysTick Base time to 10 ms.
  * @param  None
  * @retval None
  */
static void SysTickConfig(void)
{
  /* Setup SysTick Timer for 10ms interrupts  */
  if (SysTick_Config(SystemCoreClock / 1000))
  {
    /* Capture error */
    while (1);
  }

  /* Configure the SysTick handler priority */
  NVIC_SetPriority(SysTick_IRQn, 0x0);
}

static void ProcessBtnPressed(void)
{
  uint8_t i = 0;
  state++;
  
  switch(state % 3)
  {
    case 0:
      for(i = 0; i < 5; i++)
      {
        LED_Toggle(LED1);
        delay_msSysTick(200);
      }
      break;
    case 1:
      LED_Off(LED1);
      for(i = 0; i < 5; i++)
      {
        LED_Toggle(LED2);
        delay_msSysTick(400);
      }
      break;
    default:
    case 2:
      LED_Off(LED1);
      LED_On(LED2);
      for(i = 0; i < 5; i++)
      {
        LED_Toggle(LED1);
        LED_Toggle(LED2);
        delay_msSysTick(600);
      }
      break;
  }
  LED_Off(LED1);
  LED_Off(LED2);
  delay_msSysTick(2000);
  IsPressed = false;
}
#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT HOYEN TECH *****END OF FILE****/
