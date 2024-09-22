/*
 * ex1.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Admin
 */

#include "ex1.h"

//Initialize the GPIO pins for two leds: Red led on, Yellow led off
void init(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET); // Red led on
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET); // Yellow led off
}

int counter = 2;
void display(){
	if(counter == 0)
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin); // Toggle red led
		HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin); // Toggle yellow led
		counter = 2; // Reset the counter back to 2
	}
	counter --; // Decrement the counter
}

