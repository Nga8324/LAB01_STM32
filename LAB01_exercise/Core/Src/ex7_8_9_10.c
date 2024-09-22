/*
 * ex7_8_9_10.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */
#include "ex7_8_9_10.h"
//Exercise 7
void clearAllClock()
{
	HAL_GPIO_WritePin(GPIOB, LED_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_4_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_5_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_6_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_7_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_8_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_9_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_10_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_11_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, LED_12_Pin, GPIO_PIN_RESET);

}

//Exercise 8
void setNumberOnClock(int num)
{
	switch (num){
	case 0:
		HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_SET);
		break;
	case 5:
		HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_SET);
		break;
	case 6:
		HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_SET);
		break;
	case 7:
		HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_SET);
		break;
	case 8:
		HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_SET);
		break;
	case 9:
		HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_SET);
		break;
	case 10:
		HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_SET);
		break;
	case 11:
		HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_SET);
		break;
	default:
		clearAllClock();
		break;
	}
}

//Exercise 9
void clearNumberOnClock(int num)
{
	switch (num){
		case 0:
			HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, GPIO_PIN_RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, GPIO_PIN_RESET);
			break;
		case 10:
			HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, GPIO_PIN_RESET);
			break;
		case 11:
			HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, GPIO_PIN_RESET);
			break;
		default:
			//clearAllClock();
			break;
		}
}

int second_counter = 0;
int minute_counter = 0;
int hour_counter = 0;
void display(){
	// Calculate positions for the second, minute, and hour
    int second_pos = second_counter / 5;
    int minute_pos = minute_counter / 5;
    int hour_pos = hour_counter;

    // ----------Display the second------------
    // When second_counter reaches 60, increment minute_counter and reset second_counter
    if(second_counter >= 60) {
        minute_counter++;
        second_counter = 0;

        // Handle the previous position of the second (to clear the old positon)
        int prev_second_pos = (second_pos - 1 + 12) % 12;
        // Only clear the previous position of the second on clock if it is not overlapping with the minute and hour
        if((prev_second_pos != minute_pos) && (prev_second_pos != hour_pos)) {
            clearNumberOnClock(prev_second_pos);
        }
    }
    int prev_second_pos = (second_pos - 1 + 12) % 12;
    if((prev_second_pos != minute_pos) && (prev_second_pos != hour_pos)) {
        clearNumberOnClock(prev_second_pos);
    }
    // Set the new position for the second
    setNumberOnClock(second_pos);
    // Increment the second for the next call to the function
    second_counter++;

    // ---------Display the minute----------
    // When minute_counter reaches 60, increment hour_counter and reset minute_counter
    if(minute_counter >= 60) {
        hour_counter++;
        minute_counter = 0;

        // Handle the previous position of the minute (to clear the old positon)
        int prev_minute_pos = (minute_pos - 1 + 12) % 12;
        // Only clear the previous position of the minute on clock if it is not overlapping with the second and hour
        if((prev_minute_pos != second_pos) && (prev_minute_pos != hour_pos)) {
            clearNumberOnClock(prev_minute_pos);
        }
    }

    int prev_minute_pos = (minute_pos - 1 + 12) % 12;
    if((prev_minute_pos != second_pos) && (prev_minute_pos != hour_pos)) {
        clearNumberOnClock(prev_minute_pos);
    }
    // Set the new position for the minute
    setNumberOnClock(minute_pos);

    // ---------Display the hour------------
    // When hour_counter reaches 12 (full roatation of clock), reset hour_counter
    if(hour_counter >= 12) {
        hour_counter = 0;

        // Handle the previous position of the hour (to clear the old positon)
        int prev_hour_pos = (hour_pos - 1 + 12) % 12;
        // Only clear the previous position of the hour on clock if it is not overlapping with the second and minute
        if((prev_hour_pos != minute_pos) && (prev_hour_pos != second_pos)) {
            clearNumberOnClock(prev_hour_pos);
        }
    }

    int prev_hour_pos = (hour_pos - 1 + 12) % 12;
    if((prev_hour_pos != minute_pos) && (prev_hour_pos != second_pos)) {
        clearNumberOnClock(prev_hour_pos);
    }
    // Set the new position for the hour
    setNumberOnClock(hour_pos);
}

