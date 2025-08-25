/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    OpenAMP/OpenAMP_TTY_echo/Inc/main.c
  * @author  MCD Application Team
  * @brief   Main program body.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "ssd1306_tests.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MAX_BUFFER_SIZE RPMSG_BUFFER_SIZE
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
I2C_HandleTypeDef hi2c5;

/* USER CODE END PM */
/* Private variables ---------------------------------------------------------*/
IPCC_HandleTypeDef hipcc;
EXTI_HandleTypeDef hexti;
volatile int buttonPressed = 0;
volatile int commandInit = 0;

/* USER CODE BEGIN PV */
VIRT_UART_HandleTypeDef huart0;
VIRT_UART_HandleTypeDef huart1;

__IO FlagStatus VirtUart0RxMsg = RESET;
uint8_t VirtUart0ChannelBuffRx[MAX_BUFFER_SIZE];
uint16_t VirtUart0ChannelRxSize = 0;

__IO FlagStatus VirtUart1RxMsg = RESET;
uint8_t VirtUart1ChannelBuffRx[MAX_BUFFER_SIZE];
uint16_t VirtUart1ChannelRxSize = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_IPCC_Init(void);
static void EXTI14_IRQHandler_Config(void);
static void Exti14FallingCb(void);

void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_I2C5_Init(void);
/* USER CODE BEGIN PFP */
void VIRT_UART0_RxCpltCallback(VIRT_UART_HandleTypeDef *huart);
void VIRT_UART1_RxCpltCallback(VIRT_UART_HandleTypeDef *huart);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  unsigned int counter = 0;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initialize the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
    if(IS_ENGINEERING_BOOT_MODE())
  {
    /* Configure the system clock */
    HAL_RCC_DeInit();
    SystemClock_Config();
  }

  log_info("Cortex-M4 boot successful with STM32Cube FW version: v%ld.%ld.%ld \r\n",
                                            (long)((HAL_GetHalVersion() >> 24) & 0x000000FF),
                                            (long)((HAL_GetHalVersion() >> 16) & 0x000000FF),
                                            (long)((HAL_GetHalVersion() >> 8) & 0x000000FF));
  /*HW semaphore Clock enable*/
  __HAL_RCC_HSEM_CLK_ENABLE();

  BSP_LED_Init(LED7);
  //BSP_LED_On(LED7);
  /* USER CODE END Init */

  /* IPCC initialisation */
   MX_IPCC_Init();
  /* OpenAmp initialisation ---------------------------------*/
  MX_OPENAMP_Init(RPMSG_REMOTE, NULL);


  MX_GPIO_Init();
  MX_I2C5_Init();

  if (ssd1306_Init () != 0){
	  Error_Handler();
  }
  //ssd1306_SetCursor(5, 5);
 // ssd1306_WriteString("CACAAAAA \n", Font_7x10, White);
  //ssd1306_TestAll();
  //ssd1306_UpdateScreen();
  /* USER CODE BEGIN 2 */
  /* Configure LED7 */
  BSP_LED_Init(LED7);
  BSP_LED_Toggle(LED7);


  EXTI14_IRQHandler_Config();
  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */

  /* USER CODE BEGIN 2 */
  /*
   * Create Virtual UART device
   * defined by a rpmsg channel attached to the remote device
   */
  log_info("Virtual UART0 OpenAMP-rpmsg channel creation\r\n");
  if (VIRT_UART_Init(&huart0) != VIRT_UART_OK) {
    log_err("VIRT_UART_Init UART0 failed.\r\n");
    Error_Handler();
  }

  log_info("Virtual UART1 OpenAMP-rpmsg channel creation\r\n");
  if (VIRT_UART_Init(&huart1) != VIRT_UART_OK) {
    log_err("VIRT_UART_Init UART1 failed.\r\n");
    Error_Handler();
  }

  /*Need to register callback for message reception by channels*/
  if(VIRT_UART_RegisterCallback(&huart0, VIRT_UART_RXCPLT_CB_ID, VIRT_UART0_RxCpltCallback) != VIRT_UART_OK)
  {
   Error_Handler();
  }
  if(VIRT_UART_RegisterCallback(&huart1, VIRT_UART_RXCPLT_CB_ID, VIRT_UART1_RxCpltCallback) != VIRT_UART_OK)
  {
    Error_Handler();
  }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    OPENAMP_check_for_message();

    /* USER CODE END WHILE */
    if (buttonPressed)
    {
//        char *msg = "Chungus";
//        VIRT_UART_Transmit(&huart1, (uint8_t *)msg, strlen(msg));
        buttonPressed = 0;
    }

    if (commandInit)
    {
    	VirtUart0RxMsg = RESET;
    	ssd1306_WriteString("0", Font_16x24, White);
    	ssd1306_UpdateScreen();
    	BSP_LED_Toggle(LED7);
    	commandInit = 0;
    }



    if (VirtUart0RxMsg) {
      VirtUart0RxMsg = RESET;
      VIRT_UART_Transmit(&huart0, VirtUart0ChannelBuffRx, VirtUart0ChannelRxSize);
    }

    if (VirtUart1RxMsg) {
      VirtUart1RxMsg = RESET;

      ssd1306_SetCursor(5, 5);
      ssd1306_WriteString(VirtUart1ChannelBuffRx, Font_11x18, White);
      ssd1306_UpdateScreen();
      VIRT_UART_Transmit(&huart1, VirtUart1ChannelBuffRx, VirtUart1ChannelRxSize);
    }

    if(counter++ == 500000) {
        //BSP_LED_Toggle(LED7);
        counter = 0;
    }

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /**Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_MEDIUMHIGH);

  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE
                |RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS_DIG;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.HSIDivValue = RCC_HSI_DIV1;

  /**PLL1 Config
  */
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLL12SOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 3;
  RCC_OscInitStruct.PLL.PLLN = 81;
  RCC_OscInitStruct.PLL.PLLP = 1;
  RCC_OscInitStruct.PLL.PLLQ = 1;
  RCC_OscInitStruct.PLL.PLLR = 1;
  RCC_OscInitStruct.PLL.PLLFRACV = 0x800;
  RCC_OscInitStruct.PLL.PLLMODE = RCC_PLL_FRACTIONAL;
  RCC_OscInitStruct.PLL.RPDFN_DIS = RCC_RPDFN_DIS_DISABLED;
  RCC_OscInitStruct.PLL.TPDFN_DIS = RCC_TPDFN_DIS_DISABLED;

    /**PLL2 Config
    */
  RCC_OscInitStruct.PLL2.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL2.PLLSource = RCC_PLL12SOURCE_HSE;
  RCC_OscInitStruct.PLL2.PLLM = 3;
  RCC_OscInitStruct.PLL2.PLLN = 66;
  RCC_OscInitStruct.PLL2.PLLP = 2;
  RCC_OscInitStruct.PLL2.PLLQ = 1;
  RCC_OscInitStruct.PLL2.PLLR = 1;
  RCC_OscInitStruct.PLL2.PLLFRACV = 0x1400;
  RCC_OscInitStruct.PLL2.PLLMODE = RCC_PLL_FRACTIONAL;
  RCC_OscInitStruct.PLL2.RPDFN_DIS = RCC_RPDFN_DIS_DISABLED;
  RCC_OscInitStruct.PLL2.TPDFN_DIS = RCC_TPDFN_DIS_DISABLED;

    /**PLL3 Config
    */
  RCC_OscInitStruct.PLL3.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL3.PLLSource = RCC_PLL3SOURCE_HSE;
  RCC_OscInitStruct.PLL3.PLLM = 2;
  RCC_OscInitStruct.PLL3.PLLN = 34;
  RCC_OscInitStruct.PLL3.PLLP = 2;
  RCC_OscInitStruct.PLL3.PLLQ = 17;
  RCC_OscInitStruct.PLL3.PLLR = 37;
  RCC_OscInitStruct.PLL3.PLLRGE = RCC_PLL3IFRANGE_1;
  RCC_OscInitStruct.PLL3.PLLFRACV = 0x1A04;
  RCC_OscInitStruct.PLL3.PLLMODE = RCC_PLL_FRACTIONAL;
  RCC_OscInitStruct.PLL3.RPDFN_DIS = RCC_RPDFN_DIS_DISABLED;
  RCC_OscInitStruct.PLL3.TPDFN_DIS = RCC_TPDFN_DIS_DISABLED;

    /**PLL4 Config
    */
  RCC_OscInitStruct.PLL4.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL4.PLLSource = RCC_PLL4SOURCE_HSE;
  RCC_OscInitStruct.PLL4.PLLM = 4;
  RCC_OscInitStruct.PLL4.PLLN = 99;
  RCC_OscInitStruct.PLL4.PLLP = 6;
  RCC_OscInitStruct.PLL4.PLLQ = 8;
  RCC_OscInitStruct.PLL4.PLLR = 8;
  RCC_OscInitStruct.PLL4.PLLRGE = RCC_PLL4IFRANGE_0;
  RCC_OscInitStruct.PLL4.PLLFRACV = 0;
  RCC_OscInitStruct.PLL4.PLLMODE = RCC_PLL_INTEGER;
  RCC_OscInitStruct.PLL4.RPDFN_DIS = RCC_RPDFN_DIS_DISABLED;
  RCC_OscInitStruct.PLL4.TPDFN_DIS = RCC_TPDFN_DIS_DISABLED;

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
  Error_Handler();
  }
  /**RCC Clock Config
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_ACLK
                |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                |RCC_CLOCKTYPE_PCLK3|RCC_CLOCKTYPE_PCLK4
                |RCC_CLOCKTYPE_PCLK5|RCC_CLOCKTYPE_MPU;
  RCC_ClkInitStruct.MPUInit.MPU_Clock = RCC_MPUSOURCE_PLL1;
  RCC_ClkInitStruct.MPUInit.MPU_Div = RCC_MPU_DIV2;
  RCC_ClkInitStruct.AXISSInit.AXI_Clock = RCC_AXISSOURCE_PLL2;
  RCC_ClkInitStruct.AXISSInit.AXI_Div = RCC_AXI_DIV1;
  RCC_ClkInitStruct.MCUInit.MCU_Clock = RCC_MCUSSOURCE_PLL3;
  RCC_ClkInitStruct.MCUInit.MCU_Div = RCC_MCU_DIV1;
  RCC_ClkInitStruct.APB4_Div = RCC_APB4_DIV2;
  RCC_ClkInitStruct.APB5_Div = RCC_APB5_DIV4;
  RCC_ClkInitStruct.APB1_Div = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2_Div = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB3_Div = RCC_APB3_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct) != HAL_OK)
  {
  Error_Handler();
  }

  /**Set the HSE division factor for RTC clock
  */
  __HAL_RCC_RTC_HSEDIV(24);
}

/**
  * @brief IPPC Initialization Function
  * @param None
  * @retval None
  */
static void MX_IPCC_Init(void)
{

  hipcc.Instance = IPCC;
  if (HAL_IPCC_Init(&hipcc) != HAL_OK)
  {
     Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void VIRT_UART0_RxCpltCallback(VIRT_UART_HandleTypeDef *huart)
{
	//uint8_t to;
//	char *comm = "light";
//	if(huart->pRxBuffPtr = (uint8_t *)comm)
//	{
//		commandInit = 1;
//	}

	//commandInit = 1;


    log_info("Msg received on VIRTUAL UART0 channel:  %s \n\r", (char *) huart->pRxBuffPtr);

    /* copy received msg in a variable to sent it back to master processor in main infinite loop*/
    VirtUart0ChannelRxSize = huart->RxXferSize < MAX_BUFFER_SIZE? huart->RxXferSize : MAX_BUFFER_SIZE-1;
    memcpy(VirtUart0ChannelBuffRx, huart->pRxBuffPtr, VirtUart0ChannelRxSize);
    VirtUart0RxMsg = SET;
}

void VIRT_UART1_RxCpltCallback(VIRT_UART_HandleTypeDef *huart)
{
	ssd1306_Clear();
	HAL_Delay(1000);
    log_info("Msg received on VIRTUAL UART1 channel:  %s \n\r", (char *) huart->pRxBuffPtr);

    /* copy received msg in a variable to sent it back to master processor in main infinite loop*/
    VirtUart1ChannelRxSize = huart->RxXferSize < MAX_BUFFER_SIZE? huart->RxXferSize : MAX_BUFFER_SIZE-1;
    memcpy(VirtUart1ChannelBuffRx, huart->pRxBuffPtr, VirtUart1ChannelRxSize);
    VirtUart1RxMsg = SET;
}

static void EXTI14_IRQHandler_Config(void)
{
  GPIO_InitTypeDef   GPIO_InitStruct;
  EXTI_ConfigTypeDef EXTI_ConfigStructure;


  /* Enable GPIOA clock */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* Configure PA.14 pin as input floating */
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;

  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Pin = USER_BUTTON_PIN;
  PERIPH_LOCK(GPIOA);
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  PERIPH_UNLOCK(GPIOA);

  /* Set configuration except Interrupt and Event mask of Exti line 14*/
  EXTI_ConfigStructure.Line = EXTI_LINE_14;
  EXTI_ConfigStructure.Trigger = EXTI_TRIGGER_FALLING;
  EXTI_ConfigStructure.GPIOSel = EXTI_GPIOA;
  EXTI_ConfigStructure.Mode = EXTI_MODE_C2_INTERRUPT;
  PERIPH_LOCK(EXTI);
  HAL_EXTI_SetConfigLine(&hexti, &EXTI_ConfigStructure);
  PERIPH_UNLOCK(EXTI);

  /* Register callback to treat Exti interrupts in user Exti14FallingCb function */
  HAL_EXTI_RegisterCallback(&hexti, HAL_EXTI_FALLING_CB_ID, Exti14FallingCb);

  /* Enable and set line 14 Interrupt to the lowest priority */
  HAL_NVIC_SetPriority(EXTI14_IRQn, (DEFAULT_IRQ_PRIO + 2U), 0);
  HAL_NVIC_EnableIRQ(EXTI14_IRQn);
}

/**
  * @brief EXTI line detection callbacks
  * @param None:
  * @retval None
  */

static void MX_I2C5_Init(void)
{

  hi2c5.Instance = I2C5;
  hi2c5.Init.Timing = 0x00701837;
  hi2c5.Init.OwnAddress1 = 0;
  hi2c5.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c5.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c5.Init.OwnAddress2 = 0;
  hi2c5.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c5.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c5.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c5) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure Analogue filter
    */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c5, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure Digital filter
    */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c5, 0) != HAL_OK)
  {
    Error_Handler();
  }

  /**I2C Fast mode Plus enable
  */
  HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C5);
}


/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
     USB_DM1   ------> USBH_HS1_DM
     USB_DP1   ------> USBH_HS1_DP
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
}

/**
  * @brief  I2C error callbacks.
  * @param  I2cHandle: I2C handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *I2cHandle)
{
  /** Error_Handler() function is called when error occurs.
    * 1- When Slave doesn't acknowledge its address, Master restarts communication.
    * 2- When Master doesn't acknowledge the last data transferred, Slave doesn't care in this example.
    */
  if (HAL_I2C_GetError(I2cHandle) != HAL_I2C_ERROR_AF)
  {
    Error_Handler();
  }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* Error if LED7 is slowly blinking (1 sec. period) */
  while(1)
  {
    BSP_LED_Toggle(LED7);
    HAL_Delay(1000);
  }
  /* USER CODE END Error_Handler_Debug */
}


static void Exti14FallingCb(void)
{
    BSP_LED_Toggle(LED7);
    ssd1306_Clear();
    buttonPressed = 1;   // just set the flag
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */

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
  /* USER CODE BEGIN 6 */
  log_err("OOOps: file %s, line %d\r\n", __FILE__, __LINE__);
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

