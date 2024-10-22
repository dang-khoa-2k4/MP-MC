/*
 * led_display.c
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */
#include "main.h"

uint8_t time_buffer[3] = {0};
uint8_t seg_buffer[NUM_OF_SEG_LED] = {0};
const uint16_t SEG[NUM_OF_SEG_LED] = {EN_0_Pin, EN_1_Pin, EN_2_Pin, EN_3_Pin, EN_4_Pin};

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

void generate_led_buffer(uint8_t * led_buffer, uint8_t * time_buffer)
{
    led_buffer[0] = time_buffer[LIGHT_1_SEG] / 10;
    led_buffer[1] = time_buffer[LIGHT_1_SEG] % 10;
    led_buffer[2] = time_buffer[LIGHT_2_SEG] / 10;
    led_buffer[3] = time_buffer[LIGHT_2_SEG] % 10;
}

void update7SEG(int index)
{
    // disable all
    uint16_t mask;
    for (uint8_t i = 0; i < NUM_OF_SEG_LED; i++) mask |= SEG[i];
    HAL_GPIO_WritePin(EN_0_GPIO_Port, mask, DISABLE);
    HAL_GPIO_WritePin(EN_0_GPIO_Port, SEG[index], ENABLE);
}

void scanning_seg(uint8_t * seg, uint8_t * state, uint8_t size)
{
    // disable all
    update7SEG(*seg);
    display7Seg(*(state + *seg));
    *seg = (*seg + 1) % size;
}

void scanning_seg_led()
{
    static uint8_t seg = 0;
    scanning_seg(&seg, seg_buffer, NUM_OF_SEG_LED);
}

void update_7seg_buffer_time()
{
    if (mode == NORMAL_MODE)
    {
        if (time_buffer[LIGHT_1_SEG] > 0)
            update_7seg_buffer(LIGHT_1_SEG, time_buffer[LIGHT_1_SEG] - 1);
        if (time_buffer[LIGHT_2_SEG] > 0)
            update_7seg_buffer(LIGHT_2_SEG, time_buffer[LIGHT_2_SEG] - 1);
        generate_led_buffer(seg_buffer, time_buffer);
    }
}

void update_7seg_buffer(uint8_t index, uint8_t value)
{
    if (index > 3)
        return;
    time_buffer[index] = value;
    if (index == MODE_SEG) seg_buffer[4] = time_buffer[MODE_SEG];
}
