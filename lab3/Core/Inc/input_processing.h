/*
 * input_processing.h
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

typedef enum 
{
    BUTTON_RELEASED,
    BUTTON_PRESSED,
    BUTTON_PRESSED_MORE_THAN_1_SECOND
}ButtonState;

extern ButtonState buttonState[N0_OF_BUTTONS];

typedef enum {
    MODE_BTN,
    MODIFY_BTN,
    SAVE_BTN
} btn;

#define FREQ_BUTTON 100 // Hz -> 0.01s = 10ms

void fsm_for_input_processing ( void ) ;
void save_time();
void update_light_time(MODE mode);
void clone_time();

#endif /* INC_INPUT_PROCESSING_H_ */
