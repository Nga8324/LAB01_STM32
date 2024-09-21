/*
 * ex7_8_9_10.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */

#ifndef INC_EX7_8_9_10_H_
#define INC_EX7_8_9_10_H_

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
    int second_pos = second_counter / 5;
    int minute_pos = minute_counter / 5;
    int hour_pos = hour_counter;

    // ----------Hien thi kim giay------------
    if(second_counter >= 60) {
        minute_counter++;
        second_counter = 0;

        // Xu ly led 0
        int prev_second_pos = (second_pos - 1 + 12) % 12;

        if((prev_second_pos != minute_pos) && (prev_second_pos != hour_pos)) {
            clearNumberOnClock(prev_second_pos);
        }
    }
    int prev_second_pos = (second_pos - 1 + 12) % 12;
    if((prev_second_pos != minute_pos) && (prev_second_pos != hour_pos)) {
        clearNumberOnClock(prev_second_pos);
    }
    setNumberOnClock(second_pos);
    second_counter++;

    // ---------Hien thi kim phut----------
    if(minute_counter >= 60) {
        hour_counter++;
        minute_counter = 0;

        // Xu ly led 0
        int prev_minute_pos = (minute_pos - 1 + 12) % 12;

        if((prev_minute_pos != second_pos) && (prev_minute_pos != hour_pos)) {
            clearNumberOnClock(prev_minute_pos);
        }
    }

    int prev_minute_pos = (minute_pos - 1 + 12) % 12;
    if((prev_minute_pos != second_pos) && (prev_minute_pos != hour_pos)) {
        clearNumberOnClock(prev_minute_pos);
    }

    setNumberOnClock(minute_pos);

    // ---------Hien thi kim gio------------
    if(hour_counter >= 12) {
        hour_counter = 0;

        // Xu ly led 0
        int prev_hour_pos = (hour_pos - 1 + 12) % 12;

        if((prev_hour_pos != minute_pos) && (prev_hour_pos != second_pos)) {
            clearNumberOnClock(prev_hour_pos);
        }
    }

    int prev_hour_pos = (hour_pos - 1 + 12) % 12;
    if((prev_hour_pos != minute_pos) && (prev_hour_pos != second_pos)) {
        clearNumberOnClock(prev_hour_pos);
    }

    setNumberOnClock(hour_pos);
}

#endif /* INC_EX7_8_9_10_H_ */
