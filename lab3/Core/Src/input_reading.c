/*
 * input_reading.c
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */

#include "main.h"

const uint16_t btn_pin[3] = {BTN_0_Pin, BTN_1_Pin, BTN_2_Pin};
const GPIO_TypeDef * btn_port = BTN_0_GPIO_Port;

// debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {BUTTON_RELEASED};
// we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS] = {BUTTON_RELEASED};
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS] = {BUTTON_RELEASED};
// we define a flag for a button pressed more than 1 second .
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
// we define counter for automatically increasing the value
// after the button is pressed more than 1 second .
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
void button_reading(void)
{
    for (char i = 0; i < N0_OF_BUTTONS; i++)
    {
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(btn_port, btn_pin[i]);
        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
            buttonBuffer[i] = debounceButtonBuffer1[i];
        if (buttonBuffer[i] == BUTTON_IS_PRESSED)
        {
            // if a button is pressed , we start counting
            if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING)
            {
                counterForButtonPress1s[i]++;
            }
            else
            {
                // the flag is turned on when 1 second has passed
                // since the button is pressed .
                flagForButtonPress1s[i] = 1;
                // todo
            }
        }
        else
        {
            counterForButtonPress1s[i] = 0;
            flagForButtonPress1s[i] = 0;
        }
    }
}

unsigned char is_button_pressed(uint8_t index)
{
    if (index >= N0_OF_BUTTONS)
        return 0;
    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
unsigned char is_button_pressed_1s(uint8_t index)
{
    if (index >= N0_OF_BUTTONS)
        return 0xff;
    return (flagForButtonPress1s[index] == 1);
}
