/*
 * input_reading.h
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

// we aim to work with more than one buttons
#define N0_OF_BUTTONS 1
// timer interrupt duration is 10ms , so to pass 1 second ,
// we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING 100
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
// the buffer that the final result is stored after

void button_reading ( void ) ;
unsigned char is_button_pressed ( uint8_t index );
unsigned char is_button_pressed_1s ( uint8_t index );

#endif /* INC_INPUT_READING_H_ */

