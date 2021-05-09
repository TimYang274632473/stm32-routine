/**
  ******************************************************************************
  * @file    dma.c
  * @brief   This file provides code for the configuration
  *          of all the requested memory to memory DMA transfers.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "dma.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * Enable DMA controller clock
  */
void MX_DMA_Init(void)
{

  /* Init with LL driver */
  /* DMA controller clock enable */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

  /* DMA interrupt init */
  /* DMA1_Channel4_IRQn interrupt configuration */
  NVIC_SetPriority(DMA1_Channel4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  /* DMA1_Channel5_IRQn interrupt configuration */
  NVIC_SetPriority(DMA1_Channel5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(DMA1_Channel5_IRQn);

}

/* USER CODE BEGIN 2 */
void DMA_UART_Config( void )
{
	LL_DMA_SetDataLength( DMA1, LL_DMA_CHANNEL_5, USART1_RX_LEN );
	LL_DMA_SetDataLength( DMA1, LL_DMA_CHANNEL_4, USART1_TX_LEN );
	LL_DMA_ConfigAddresses( DMA1, LL_DMA_CHANNEL_5, (uint32_t)&USART1->DR, (uint32_t)USART1_RX_BUFFER, LL_DMA_DIRECTION_PERIPH_TO_MEMORY );
	LL_DMA_ConfigAddresses( DMA1, LL_DMA_CHANNEL_4, (uint32_t)USART1_RX_BUFFER, (uint32_t)&USART1->DR, LL_DMA_DIRECTION_MEMORY_TO_PERIPH );
	LL_DMA_EnableIT_TC( DMA1, LL_DMA_CHANNEL_4 );
	LL_DMA_EnableIT_TE( DMA1, LL_DMA_CHANNEL_4 );
	LL_DMA_EnableIT_TE( DMA1, LL_DMA_CHANNEL_5 );
	LL_DMA_EnableChannel( DMA1, LL_DMA_CHANNEL_5 );
}
/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
