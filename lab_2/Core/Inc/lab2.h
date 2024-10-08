/*
 * lab2.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Nguyen Tran Dang Khoa
 */

#ifndef INC_LAB2_H_
#define INC_LAB2_H_

#include "main.h"
#include <stdint.h>
#include "scheduler.h"

// Define part 
#define SEG_ON 0
#define SEG_OFF 1
#define PERIOD_SYS_TIME 10 // ms
#define NUM_OF_SEG_LED 4
#define ENABLE 0
#define DISABLE 1
#define DEFAULT_FREQ 2 // Hz
#define MY_FREQ 10 // Hz
#define CLOCK_FREQ 1 // Hz

// define for 7 segment 
#define NUM_0   (SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin)
#define NUM_1   (SEG_1_Pin | SEG_2_Pin)
#define NUM_2   (SEG_0_Pin | SEG_1_Pin | SEG_3_Pin | SEG_4_Pin | SEG_6_Pin)
#define NUM_3   (SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_6_Pin)
#define NUM_4   (SEG_1_Pin | SEG_2_Pin | SEG_5_Pin | SEG_6_Pin)
#define NUM_5   (SEG_0_Pin | SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin)
#define NUM_6   (SEG_0_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin)
#define NUM_7   (SEG_0_Pin | SEG_1_Pin | SEG_2_Pin)
#define NUM_8   (SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin)
#define NUM_9   (SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_5_Pin | SEG_6_Pin)
#define ALL_SEG (SEG_0_Pin | SEG_1_Pin | SEG_2_Pin | SEG_3_Pin | SEG_4_Pin | SEG_5_Pin | SEG_6_Pin)
#define ALL_ROW (ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin)
#define ALL_EN  (ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin | ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin)
// End define part



typedef struct {
    uint8_t hour : 5;
    uint8_t minute : 6;
    uint8_t second : 6;
} clock_t;


// Function prototype part
void display7Seg(uint8_t num);
void ex_1_handle();
void ex_1_handle_2();
void ex_2_handle();
void ex_2_handle_1();
void dot_toggle();
void ex_3_handle();
void ex_4_handle();
void ex_5_update_buffer();
void ex_5_scanning();
void scanning_matrix();
void shift_row();
// End function prototype part

#endif /* INC_LAB2_H_ */
