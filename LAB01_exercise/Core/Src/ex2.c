/*
 * ex2.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */
#include "ex2.h"

void init(){
	HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
}

int green_status = 1;
int yellow_status = 0;
int red_status = 0;

int green_counter = 4;
int yellow_counter = 3;
int red_counter = 6;

void display(){
	if(green_status == 1){
		  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
		  green_counter --;

		  if(green_counter == 0){
			  green_status = 0;
			  green_counter = 3;
			  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			  yellow_status = 1;
		  }
	  }
	  if(yellow_status == 1){
	  	  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	  	  yellow_counter --;

	  	  if(yellow_counter == 0){
	  		  yellow_status = 0;
	  		  yellow_counter = 3;
	  		  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	  		  red_status = 1;
	  	  }
	   }
	  if(red_status == 1){
	  	  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	  	  red_counter --;

	  	  if(red_counter == 0){
	  		  red_status = 0;
	  		  red_counter = 6;
	  		  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);

	  		  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
	  		  green_status = 1;
	  	  }
	   }
}


