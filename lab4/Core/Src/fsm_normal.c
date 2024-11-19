/*
 * fsm_automatic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */
#include "main.h"

trafficLight_t light_1;
trafficLight_t light_2;
uint8_t time[3] = {10, 7, 3}; // R G A

static void off_all_light_1()
{
	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin | GREEN_1_Pin | YELLOW_1_Pin, LED_OFF);
}

static void off_all_light_2()
{
	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin | GREEN_2_Pin | YELLOW_2_Pin, LED_OFF);
}

void automatic_run(void)
{
	update_7seg_buffer(MODE_SEG, mode);
	if (isTimerExpired(ONE_SECOND_TIMER)) 
	{
		update_7seg_buffer_time();
		if (mode == NORMAL_MODE)
			setTimer(ONE_SECOND_TIMER, ONE_SECOND);
	}
	if (!is_button_pressed(MODE_BTN)) flag_mode = 1;
	switch (light_1)
	{
	case INIT:
		if (1) // ko dieu kien
		{
			light_1 = RED;
			update_7seg_buffer(LIGHT_1_SEG, time[RED]);
			off_all_light_1();
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, LED_ON);
			setTimer(TRAFFIC_LIGHT_1_TIMER, time[RED] * ONE_SECOND);
			setTimer(ONE_SECOND_TIMER, ONE_SECOND);
		}
		break;
	case GREEN:
		if (isTimerExpired(TRAFFIC_LIGHT_1_TIMER) == 1)
		{
			light_1 = AMBER;
			update_7seg_buffer(LIGHT_1_SEG, time[AMBER]);
			off_all_light_1();
			HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, LED_ON);
			setTimer(TRAFFIC_LIGHT_1_TIMER, time[AMBER] * ONE_SECOND);
		}
		break;
	case AMBER:
		if (isTimerExpired(TRAFFIC_LIGHT_1_TIMER) == 1)
		{
			light_1 = RED;
			update_7seg_buffer(LIGHT_1_SEG, time[RED]);
			off_all_light_1();
			HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, LED_ON);
			setTimer(TRAFFIC_LIGHT_1_TIMER, time[RED] * ONE_SECOND);
		}
		break;
	case RED:
		if (isTimerExpired(TRAFFIC_LIGHT_1_TIMER) == 1)
		{
			light_1 = GREEN;
			update_7seg_buffer(LIGHT_1_SEG, time[GREEN]);
			off_all_light_1();
			HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, LED_ON);
			setTimer(TRAFFIC_LIGHT_1_TIMER, time[GREEN] * ONE_SECOND);
		}
		break;
	default:
		break;
	}

	switch (light_2)
	{
	case INIT:
		if (1) // ko dieu kien
		{
			light_2 = GREEN;
			update_7seg_buffer(LIGHT_2_SEG, time[GREEN]);
			off_all_light_2();
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, LED_ON);
			setTimer(TRAFFIC_LIGHT_2_TIMER, time[GREEN] * ONE_SECOND);
		}
		break;
	case GREEN:
		if (isTimerExpired(TRAFFIC_LIGHT_2_TIMER) == 1)
		{
			light_2 = AMBER;
			update_7seg_buffer(LIGHT_2_SEG, time[AMBER]);
			off_all_light_2();
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, LED_ON);
			setTimer(TRAFFIC_LIGHT_2_TIMER, time[AMBER] * ONE_SECOND);
		}
		break;
	case AMBER:
		if (isTimerExpired(TRAFFIC_LIGHT_2_TIMER) == 1)
		{
			light_2 = RED;
			update_7seg_buffer(LIGHT_2_SEG, time[RED]);
			off_all_light_2();
			HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, LED_ON);
			setTimer(TRAFFIC_LIGHT_2_TIMER, time[RED] * ONE_SECOND);
		}
		break;
	case RED:
		if (isTimerExpired(TRAFFIC_LIGHT_2_TIMER) == 1)
		{
			light_2 = GREEN;
			update_7seg_buffer(LIGHT_2_SEG, time[GREEN]);
			off_all_light_2();
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, LED_ON);
			setTimer(TRAFFIC_LIGHT_2_TIMER, time[GREEN] * ONE_SECOND);
		}

		break;
	default:
		break;
	}
	if (is_button_pressed(MODE_BTN) == 1 && flag_mode == 1)
	{
		flag_mode = 0;
		mode = (mode + 1) % NO_MODE;
		light_1 = MODIFY;
		light_2 = MODIFY;
		modify = INIT_SETTING;
	}
}
