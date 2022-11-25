/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DOT_DURATION 200
#define DASH_DURATION 600
#define SAME_LETTER_DURATION 200
#define DIFFERENT_LETTER_DURATION 600
#define DIFFERENT_WORD_DURATION 1400
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static char supported_characters[36] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
    'P','Q','R','S','T','U','V','W','X','Y','Z',
    '1','2','3','4','5','6','7','8','9','0'
};

static char morse_code[36][5] = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---", "-.-",
    ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----",
    "..---","...--","....-",".....","-....","--...","---..","----.","-----"
};

char phrase[2] = "AI";
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
int returnMorseForCharacter(char input_character);
void outputPhrase();
void outputCharacter(char* morse_conversion, int morse_length);
void outputDot();
void outputDash();
void changeLetter();
void changeWord();

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

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  outputPhrase();
	  changeWord();
	  
    /* USER CODE END WHILE */

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
int returnMorseForCharacter(char input_character) {
    for (int array_index = 0; array_index < 36; array_index++) {
        if (supported_characters[array_index] == input_character) return array_index;
    }
    return ERROR;
}


void outputPhrase() {
    char letter;

    int morse_length = 0;

    int phrase_index = 0;
    int morse_index = 0;

    /* Output Morse Conversion Onto STM32. */
    for (phrase_index = 0; phrase_index < strlen(phrase); phrase_index++) {
    	letter = phrase[phrase_index];

		morse_index = returnMorseForCharacter(letter);

		// Output Morse Code Only for Valid Input.
		if (morse_index == ERROR) Error_Handler();

		morse_length = strlen(morse_code[morse_index]);
		outputCharacter(morse_code[morse_index], morse_length);
    }
}


void outputCharacter(char* morse_conversion, int morse_length) {
    for (int morse_index = 0; morse_index < morse_length; morse_index++) {
        if (morse_conversion[morse_index] == '.') outputDot();
        else if (morse_conversion[morse_index] == '-') outputDash();
        else Error_Handler();
    }
	
	changeLetter();
}


void outputDot() {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
    HAL_Delay(DOT_DURATION);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);

    /* Follow With a Short Delay Between Dot/Dash in Same Letter. */
    HAL_Delay(SAME_LETTER_DURATION);
}


void outputDash() {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
    HAL_Delay(DASH_DURATION);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);

    /* Follow With a Short Delay Between Dot/Dash in Same Letter. */
    HAL_Delay(SAME_LETTER_DURATION);
}

void changeLetter() {
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
  HAL_Delay(DIFFERENT_LETTER_DURATION);
}

void changeWord() {
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
  HAL_Delay(DIFFERENT_WORD_DURATION);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
