/*
 * lab1.h
 *
 *  Created on: Sep 8, 2024
 *      Author: 2211635 - Nguyen Tran Dang Khoa
 */

#ifndef INC_LAB1_H_
#define INC_LAB1_H_

#include "main.h"
#include "stdint.h"

// Define part 
#define LED_ON 0
#define LED_OFF 1

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
// End define part

// Enum part
typedef enum 
{
    RED_LIGHT = 0,
    YELLOW_LIGHT = 1,
    GREEN_LIGHT = 2 
} TrafficLight;
// End enum part

// Function prototype part
void ex_1_handle();
void ex_2_handle();
void ex_3_handle();
void display7Seg(uint8_t num);
void ex_4_handle();
void ex_5_handle();
void ex_6_handle();
void clearAllClock();
void ex_7_handle();
void setNumberOnClock(int num);
void ex_8_handle();
void clearNumberOnClock(int num);
void ex_9_handle();
void ex_10_handle();
// End function prototype part

#endif /* INC_LAB1_H_ */
