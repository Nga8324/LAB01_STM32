/*
 * ex1.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */

#include "ex1.h"

void init(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
}

int counter = 2;
void display(){
	if(counter == 0)
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
		counter = 2;
	}
	counter --;
}

