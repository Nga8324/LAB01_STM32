/*
 * ex3.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */
#include "ex3.h"
// group 1
int green_status1 = 1;
int yellow_status1 = 0;
int red_status1 = 0;

int green_counter1 = 4;
int yellow_counter1 = 3;
int red_counter1 = 6;
void display1(){
	 if (green_status1 == 1){
		HAL_GPIO_WritePin(Green1_GPIO_Port, Green1_Pin, SET);
		green_counter1 --;

		if(green_counter1 == 0){
			green_status1 = 0;
			green_counter1 = 3;
			HAL_GPIO_WritePin(Green1_GPIO_Port, Green1_Pin, RESET);
			yellow_status1 = 1;
		}
	 }
	if (yellow_status1 == 1){
		HAL_GPIO_WritePin(Yellow1_GPIO_Port, Yellow1_Pin, SET);
		yellow_counter1 --;

		if(yellow_counter1 == 0){
			yellow_status1 = 0;
			yellow_counter1 = 3;
			HAL_GPIO_WritePin(Yellow1_GPIO_Port, Yellow1_Pin, RESET);
			red_status1 = 1;
		}
	}
	if (red_status1 == 1){
		HAL_GPIO_WritePin(Red1_GPIO_Port, Red1_Pin, SET);
		red_counter1 --;

		if(red_counter1 == 0){
			red_status1 = 0;
			red_counter1 = 6;
			HAL_GPIO_WritePin(Red1_GPIO_Port, Red1_Pin, RESET);

			HAL_GPIO_WritePin(Green1_GPIO_Port, Green1_Pin, SET);
			green_status1 = 1;
		 }
	 }
}
//group 2
int green_status2 = 0;
int yellow_status2 = 0;
int red_status2 = 1;

int green_counter2 = 4;
int yellow_counter2 = 3;
int red_counter2 = 6;
void display2(){
	  if (red_status2 == 1){
	  	 HAL_GPIO_WritePin(Red2_GPIO_Port, Red2_Pin, SET);
	  	 red_counter2 --;

	  	 if(red_counter2 == 0){
	  	 	red_status2 = 0;
	  	 	red_counter2 = 5;
	  	 	HAL_GPIO_WritePin(Red2_GPIO_Port, Red2_Pin, RESET);

	  	 	green_status2 = 1;
	  	 }
	  }
	  if (green_status2 == 1){
		  HAL_GPIO_WritePin(Green2_GPIO_Port, Green2_Pin, SET);
		  green_counter2 --;

		  if(green_counter2 == 0){
			  green_status2 = 0;
			  green_counter2 = 4;
			  HAL_GPIO_WritePin(Green2_GPIO_Port, Green2_Pin, RESET);
			  yellow_status2 = 1;
		  }
	  }
	  if (yellow_status2 == 1){
	 		  HAL_GPIO_WritePin(Yellow2_GPIO_Port, Yellow2_Pin, SET);
	 		  yellow_counter2 --;

	 		  if(yellow_counter2 == 0){
	 			  yellow_status2 = 0;
	 			  yellow_counter2 = 3;
	 			  HAL_GPIO_WritePin(Yellow2_GPIO_Port, Yellow2_Pin, RESET);

	 			  HAL_GPIO_WritePin(Red2_GPIO_Port, Red2_Pin, SET);
	 			  red_status2 = 1;
	 		  }
	 	}
}


