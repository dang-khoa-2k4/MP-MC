/*
 * lab2.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Nguyen Tran Dang Khoa
 */
#include "lab2.h"

const uint16_t SEG[NUM_OF_SEG_LED] = {EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin};
uint8_t led_buffer[] = {1, 2, 3, 4};
clock_t clock = {15, 8, 50};
uint16_t row_pin[] = {ROW0_Pin, ROW1_Pin, ROW2_Pin, ROW3_Pin, ROW4_Pin, ROW5_Pin, ROW6_Pin, ROW7_Pin};
uint16_t en_pin[] = {ENM0_Pin, ENM1_Pin, ENM2_Pin, ENM3_Pin, ENM4_Pin, ENM5_Pin, ENM6_Pin, ENM7_Pin};

uint8_t charactor_K[] = {   0B01000100,
                            0B01001000,
                            0B01010000,
                            0B01100000,
                            0B01100000,
                            0B01010000,
                            0B01001000,
                            0B01000100   };

uint8_t charactor_H[] = {   0B10000001,
                            0B10000001,
                            0B10000001,
                            0B11111111,
                            0B10000001,
                            0B10000001,
                            0B10000001,
                            0B10000001   };

uint8_t charactor_O[] = {   0B00011000,
                            0B00100100,
                            0B01000010,
                            0B10000001,
                            0B10000001,
                            0B01000010,
                            0B00100100,
                            0B00011000   };

uint8_t charactor_A[] = {   0B00011000,
                            0B00100100,
                            0B01000010,
                            0B10000001,
                            0B11111111,
                            0B10000001,
                            0B10000001,
                            0B10000001   }; 

uint8_t char_A[] =   {
    0x66,
    0x66,
    0x7E,
    0x7E,
    0x46,
    0x66,
    0x3C,
    0x18
};



void display7Seg(uint8_t num)   
{
    HAL_GPIO_WritePin(SEG_0_GPIO_Port, ALL_SEG, SEG_OFF);
    switch (num)
    {
    case 0:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_0, SEG_ON);
        break;
    case 1:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_1, SEG_ON);
        break;
    case 2:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_2, SEG_ON);
        break;
    case 3:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_3, SEG_ON);
        break;
    case 4:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_4, SEG_ON);
        break;
    case 5:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_5, SEG_ON);
        break;
    case 6:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_6, SEG_ON);
        break;
    case 7:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_7, SEG_ON);
        break;
    case 8:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_8, SEG_ON);
        break;
    case 9:
        HAL_GPIO_WritePin(SEG_0_GPIO_Port, NUM_9, SEG_ON);
        break;
    default:
        break;
    }
}

void update7SEG(int index)
{
    // disable all
    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, DISABLE);
    HAL_GPIO_WritePin(EN0_GPIO_Port, SEG[index], ENABLE);
}

void scanning_seg_led(uint8_t * seg, uint8_t * state, uint8_t size)
{
    // disable all
    update7SEG(*seg);
    display7Seg(*(state + *seg));
    *seg = (*seg + 1) % size;
}

void ex_1_handle()
{
    static uint32_t counter = (1000.0 / MY_FREQ) / PERIOD_SYS_TIME;
    static uint8_t seg = 0;
    const uint8_t state[] = {1, 2};
    counter--;
    if (counter <= 0)
    {
        counter = (1000.0 / MY_FREQ) / PERIOD_SYS_TIME;
        scanning_seg_led(&seg, state, sizeof(state) / sizeof(state[0]));
    }
}

void ex_1_handle_2()
{
    static uint8_t seg = 0;
    static uint8_t state[] = {1, 2};
    scanning_seg_led(&seg, state, sizeof(state) / sizeof(state[0]));
}

void ex_2_handle()
{
    static uint32_t counter = (1000.0 / MY_FREQ) / PERIOD_SYS_TIME;
    static uint8_t seg = 0;
    const uint8_t state[] = {1, 2, 3, 0};
    counter--;
    if (counter <= 0)
    {
        counter = (1000.0 / MY_FREQ) / PERIOD_SYS_TIME;
        if (seg % 2 == 0) 
            HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
        scanning_seg_led(&seg, state, sizeof(state) / sizeof(state[0]));
    }
}

void ex_2_handle_1()
{
    static uint8_t seg = 0;
    static uint8_t state[] = {1, 2, 3, 0};
    scanning_seg_led(&seg, state, sizeof(state) / sizeof(state[0]));
}

void dot_toggle()
{
    HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
}

void ex_3_handle()
{
    static uint32_t counter = (1000.0 / MY_FREQ) / PERIOD_SYS_TIME;
    static uint8_t seg = 0;
    const uint8_t state[] = {1, 2, 3, 4};
    counter--;
    if (counter <= 0)
    {
        counter = (1000.0 / MY_FREQ) / PERIOD_SYS_TIME;
        scanning_seg_led(&seg, state, sizeof(state) / sizeof(state[0]));
    }
}

void ex_4_handle()
{
    // #define MY_FREQ 1 // Hz
    static uint32_t counter = (1000.0 / MY_FREQ) / PERIOD_SYS_TIME;

    static uint8_t seg = 0;
    const uint8_t state[] = {1, 2, 3, 4};
    counter--;
    if (counter <= 0)
    {
        counter = (1000.0 / MY_FREQ) / PERIOD_SYS_TIME;
        scanning_seg_led(&seg, state, sizeof(state) / sizeof(state[0]));
    }
}

void generate_led_buffer(uint8_t * led_buffer, uint8_t hour, uint8_t minute)
{
    led_buffer[0] = hour / 10;
    led_buffer[1] = hour % 10;
    led_buffer[2] = minute / 10;
    led_buffer[3] = minute % 10;
}

void ex_5_update_buffer()
{
        // static uint32_t counter = (1000.0 / CLOCK_FREQ) / PERIOD_SYS_TIME;
    if (clock.second >= 60)
    {
        clock.second = 0;
        clock.minute++;
        if (clock.minute >= 60)
        {
            clock.minute = 0;
            clock.hour++;
            if (clock.hour >= 24)
            {
                clock.hour = 0;
            }
        }
    }
    generate_led_buffer(led_buffer, clock.hour, clock.minute);
    clock.second++;
}

void ex_5_scanning(){
    static uint8_t seg = 0;
    scanning_seg_led(&seg, led_buffer, sizeof(led_buffer) / sizeof(led_buffer[0]));
}

void row_on(uint8_t row)
{
    uint16_t row_pin_on = (0xff & char_A[row]) << 8;
    HAL_GPIO_WritePin(ROW0_GPIO_Port, row_pin_on, 1);
}

void shift_row()
{
    for (int i = 0; i < 8; i++)
    {
        uint8_t temp = (char_A[i] & 0x80) ? 1 : 0;
        char_A[i] = (char_A[i] << 1) | temp;
    }
}

void scanning_matrix()
{
    static uint8_t row = 0;
    // diasble all matrix
    HAL_GPIO_WritePin(ROW0_GPIO_Port, ALL_ROW, 0);
    HAL_GPIO_WritePin(ENM0_GPIO_Port, ALL_EN, 0);
    // enable row pins
    row_on(row % 8);
    // enable col pin
    HAL_GPIO_WritePin(ENM0_GPIO_Port, en_pin[row % 8], 1);
    row++;
    //enable col 
}