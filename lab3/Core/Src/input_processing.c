/*
 * input_processing.c
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */

#include "main.h"

ButtonState buttonState[N0_OF_BUTTONS] = { BUTTON_RELEASED };
uint8_t first_time = 1;



void fsm_for_input_processing(void)
{
    button_reading();
    for (btn btn_index = 0; btn_index < N0_OF_BUTTONS; btn_index++)
    {
        switch (buttonState[btn_index])
        {
        case BUTTON_RELEASED:
            if (is_button_pressed(btn_index))
            {
                buttonState[btn_index] = BUTTON_PRESSED;
                // INCREASE VALUE OF PORT A BY ONE UNIT
                 
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(btn_index))
            {
                buttonState[btn_index] = BUTTON_RELEASED;     
                if (btn_index == MODE_BTN && !first_time)
                {
                    mode = (mode + 1) % NO_MODE;
                }
                first_time = 0;
            }
            else
            {
                if (is_button_pressed_1s(btn_index))
                {
                    buttonState[btn_index] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                }
            }
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if (!is_button_pressed(btn_index))
            {
                buttonState[btn_index] = BUTTON_RELEASED;
                // if press 1 s 
                if (btn_index == MODE_BTN)
                    mode = NORMAL_MODE;
            }
            // todo
            break;
        default:
            break;
        }
    }
}

