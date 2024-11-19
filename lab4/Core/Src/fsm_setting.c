/*
 * fsm_automatic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */
#include "main.h"

uint8_t flag_mode = 0;
static uint8_t flag_modify = 0;
settingLight_t modify;
MODE mode;
uint8_t modify_time[3] = {0};
static uint16_t led_modify_pin[3] = { RED_1_Pin | RED_2_Pin, GREEN_1_Pin | GREEN_2_Pin, YELLOW_1_Pin | YELLOW_2_Pin };
void modify_run (void)
{
	update_7seg_buffer(MODE_SEG, mode);
	if (!is_button_pressed(MODE_BTN)) flag_mode = 1;
	switch (modify)
	{
	case INIT_SETTING:
		if (1) // ko dieu kien
		{
			HAL_GPIO_WritePin(RED_1_GPIO_Port, led_modify_pin[0] | led_modify_pin[1] | led_modify_pin[2], LED_OFF);
			if (mode == NORMAL_MODE)
			{
				modify = NORMAL_SETTING;
				light_1 = INIT;
				light_2 = INIT;
			}
			else 
			{
				modify = WAIT_SETTING;
				clone_time();
				update_7seg_buffer(LIGHT_1_SEG, modify_time[mode - 1]);
				update_7seg_buffer(LIGHT_2_SEG, modify_time[mode - 1]);
				seg_buffer[0] = modify_time[mode - 1] / 10;
				seg_buffer[1] = modify_time[mode - 1] % 10;
				seg_buffer[2] = seg_buffer[0];
				seg_buffer[3] = seg_buffer[1];
				// HAL_GPIO_WritePin(RED_1_GPIO_Port, led_modify_pin[mode - 1], LED_ON);
				setTimer(TRAFFIC_LIGHT_1_TIMER, freq_to_tick(2)); // prepare for waiting mode
				setTimer(MODIFY_TIMER, TIME_OUT * ONE_SECOND); // prepare for waiting mode
			}
		}
		break;
	case WAIT_SETTING:
		if (isTimerExpired(MODIFY_TIMER) == 1) // out of 10s not modify
		{
			modify = INIT_SETTING;
			mode = NORMAL_MODE;
		}
		if (isTimerExpired(TRAFFIC_LIGHT_1_TIMER) == 1)
		{
			HAL_GPIO_TogglePin(RED_1_GPIO_Port, led_modify_pin[mode - 1]);
			setTimer(TRAFFIC_LIGHT_1_TIMER, freq_to_tick(2)); // prepare for waiting mode
		}
		if (is_button_pressed(MODIFY_BTN) == 1)
		{
			// update_light_time(mode);
			modify = MODIFY_SETTING;
			setTimer(MODIFY_TIMER, TIME_OUT * ONE_SECOND);
		}
		// else if (is_button_pressed(MODE_BTN))
		// {
		// 	modify = INIT_SETTING;
		// 	mode = (mode + 1) % NO_MODE;
		// }
		else if (is_button_pressed(SAVE_BTN))
		{
			save_time();
			modify = INIT_SETTING;
			mode = NORMAL_MODE;
		}
		break;
	case MODIFY_SETTING: 
		if (isTimerExpired(MODIFY_TIMER) == 1) // out of 10s not modify
		{
			modify = INIT_SETTING;
			mode = NORMAL_MODE;
		}
		if (isTimerExpired(TRAFFIC_LIGHT_1_TIMER) == 1)
		{
			HAL_GPIO_TogglePin(RED_1_GPIO_Port, led_modify_pin[mode - 1]);
			setTimer(TRAFFIC_LIGHT_1_TIMER, freq_to_tick(2)); // prepare for waiting mode
		}
		if (!is_button_pressed(MODIFY_BTN)) flag_modify = 1;
		if (is_button_pressed(SAVE_BTN) == 1)
		{
			save_time();
			modify = INIT_SETTING;
			mode = NORMAL_MODE;
		}
		// else if (is_button_pressed(MODE_BTN) == 1)
		// {
		// 	modify = INIT_SETTING;
		// 	mode = (mode + 1) % NO_MODE;
		// }
		else if (is_button_pressed(MODIFY_BTN) == 1 && flag_modify == 1)
		{
			flag_modify = 0;
			update_light_time(mode);
			setTimer(MODIFY_TIMER, TIME_OUT * ONE_SECOND);
		}
		break;
	default:
		break;
	}
	if (is_button_pressed(MODE_BTN) == 1 && flag_mode == 1)
	{
		flag_mode = 0;
		mode = (mode + 1) % NO_MODE;
		modify = INIT_SETTING;
	}
}

void save_time()
{
    time[RED]   =   modify_time[RED]; 
    time[GREEN] =   modify_time[GREEN]; 
    time[AMBER] =   modify_time[AMBER]; 
}

void update_light_time(MODE mode)
{
    if (mode != NORMAL_MODE)
    {
        modify_time[mode - 1] = (modify_time[mode - 1] + 1) % 100;
        seg_buffer[0] = modify_time[mode - 1] / 10;
        seg_buffer[1] = modify_time[mode - 1] % 10;
        seg_buffer[2] = seg_buffer[0];
        seg_buffer[3] = seg_buffer[1];
    }
}

void clone_time()
{
    modify_time[RED]      = time[RED]; 
    modify_time[GREEN]    = time[GREEN]; 
    modify_time[AMBER]    = time[AMBER]; 
}
