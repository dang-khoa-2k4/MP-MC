/*
 * led.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_
// Define part 
#define SEG_ON 0
#define SEG_OFF 1
#define LED_ON 1
#define LED_OFF 0
#define NUM_OF_SEG_LED 5
#define ENABLE 0
#define DISABLE 1

#define LIGHT_1_SEG     0
#define LIGHT_2_SEG     1
#define MODE_SEG        2

#define FREQ_SCANNING 50 // Hz

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

extern uint8_t seg_buffer[NUM_OF_SEG_LED];
extern uint8_t time_buffer[3];

void display7Seg(uint8_t num);
void update7SEG(int index);
void scanning_seg(uint8_t * seg, uint8_t * state, uint8_t size);
void scanning_seg_led();
void update_7seg_buffer_time();
void update_7seg_buffer(uint8_t index, uint8_t value);
void generate_led_buffer(uint8_t * led_buffer, uint8_t * time_buffer);
#endif /* INC_LED_DISPLAY_H_ */
