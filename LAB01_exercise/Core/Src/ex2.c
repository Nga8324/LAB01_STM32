/*
 * ex2.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */
#include "ex2.h"

// Initialize for three leds to the off state
void init(){
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
}

// Initialize for states and counter for each led
// 1 : active
// 0 : inactive
int green_status = 1;
int yellow_status = 0;
int red_status = 0;

int green_counter = 4;
int yellow_counter = 3;
int red_counter = 6;

void display(){
//If green led is active, turn it on and decrement its counter
	if(green_status == 1){
		  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET); // Green led on
		  green_counter --;
		  // If green counter reaches 0
		  if(green_counter == 0){
			  green_status = 0; // Green led becomes inactive
			  green_counter = 3; // Reset green counter
			  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET); // Turn green led off
			  yellow_status = 1; // Activate for yellow led
		  }
	  }
//If yellow led is active, turn it on and decrement its counter
	  if(yellow_status == 1){
	  	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	  	  yellow_counter --;
	  	  // If yellow counter reaches 0
	  	  if(yellow_counter == 0){
	  		  yellow_status = 0; // Yellow led becomes inactive
	  		  yellow_counter = 3; // Reset yellow counter
	  		  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET); // Turn yellow led off
	  		  red_status = 1; // Activate for red led
	  	  }
	   }
// If red led is active, turn it on and decrement its counter
	  if(red_status == 1){
	  	  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	  	  red_counter --;
	  	  // If red counter reaches 0
	  	  if(red_counter == 0){
	  		  red_status = 0; // Red led becomes inactive
	  		  red_counter = 6; // Reset red counter
	  		  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET); // Turn red led off
	  		  // Restart the cycle by activating the green LED
	  		  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET); // Turn green led on
	  		  green_status = 1; // Active for green led
	  	  }
	   }
}


