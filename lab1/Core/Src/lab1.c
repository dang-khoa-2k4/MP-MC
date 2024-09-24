/*
 * lab1.c
 *
 *  Created on: Sep 8, 2024
 *      Author: 2211635 - Nguyen Tran Dang Khoa
 */
#include "lab1.h"

static uint8_t TRAFFIC_LIGHT_TIME[] = {5, 2, 3};
static uint16_t TIME_CLOCK_LED[12] = {   LED_12_Pin, LED_1_Pin, LED_2_Pin , LED_3_Pin, 
                                        LED_4_Pin , LED_5_Pin, LED_6_Pin , LED_7_Pin, 
                                        LED_8_Pin , LED_9_Pin, LED_10_Pin, LED_11_Pin   };
void ex_1_handle()
{
    static uint8_t start = 1;
    static uint32_t count_seconds = 0;
    if (start)
    {
        HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, LED_ON);
        start = 0;
    }
    if (count_seconds % 2 == 0)
    {
        HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
        HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_Pin);
    }
    count_seconds++;
}

static void traffic_light_handle(TrafficLight * light_state, uint16_t *leds, uint32_t * count_seconds)
{   
    HAL_GPIO_WritePin(GPIOB, leds[0] | leds[1] | leds[2], 1);
    switch (*light_state)
    {
    case RED_LIGHT:
        HAL_GPIO_WritePin(GPIOB, leds[*light_state], 0);
        if (*count_seconds >= TRAFFIC_LIGHT_TIME[*light_state])
        {
            *light_state = GREEN_LIGHT;
            *count_seconds = 0;
        }
        break;
    case YELLOW_LIGHT:
        HAL_GPIO_WritePin(GPIOB, leds[*light_state], 0);
        if (*count_seconds >= TRAFFIC_LIGHT_TIME[*light_state])
        {
            *light_state = RED_LIGHT;
            *count_seconds = 0;
        }
        break;
    case GREEN_LIGHT:
        HAL_GPIO_WritePin(GPIOB, leds[*light_state], 0);
        if (*count_seconds >= TRAFFIC_LIGHT_TIME[*light_state])
        {
            *light_state = YELLOW_LIGHT;
            *count_seconds = 0;
        }
        break;
    default:
        break;
    }
}

void ex_2_handle()
{
    static TrafficLight light_state = RED_LIGHT;
    static uint32_t count_seconds = 0;
    static uint16_t leds[3] = {LED_8_Pin, LED_9_Pin, LED_10_Pin};
    traffic_light_handle(&light_state, leds, &count_seconds);
    count_seconds++;
}

void ex_3_handle()
{
    static uint32_t count_seconds_1 = 0;
    static uint32_t count_seconds_2 = 0;
    static uint32_t count_seconds_3 = 0;
    static uint32_t count_seconds_4 = 0;
    static TrafficLight traffic_light_1 = RED_LIGHT;
    static TrafficLight traffic_light_2 = GREEN_LIGHT;
    static TrafficLight traffic_light_3 = RED_LIGHT;
    static TrafficLight traffic_light_4 = GREEN_LIGHT;
    static uint16_t leds_1[3] = {LED_11_Pin, LED_12_Pin, LED_1_Pin};
    static uint16_t leds_2[3] = {LED_2_Pin, LED_3_Pin, LED_4_Pin};
    static uint16_t leds_3[3] = {LED_7_Pin, LED_6_Pin, LED_5_Pin};
    static uint16_t leds_4[3] = {LED_10_Pin, LED_9_Pin, LED_8_Pin};
    
    traffic_light_handle(&traffic_light_1, leds_1, &count_seconds_1);
    traffic_light_handle(&traffic_light_2, leds_2, &count_seconds_2);
    traffic_light_handle(&traffic_light_3, leds_3, &count_seconds_3);
    traffic_light_handle(&traffic_light_4, leds_4, &count_seconds_4);
    count_seconds_1++;
    count_seconds_2++;
    count_seconds_3++;
    count_seconds_4++;
}

void display7Seg(uint8_t num)   
{
    HAL_GPIO_WritePin(GPIOA, ALL_SEG, LED_OFF);
    switch (num)
    {
    case 0:
        HAL_GPIO_WritePin(GPIOA, NUM_0, LED_ON);
        break;
    case 1:
        HAL_GPIO_WritePin(GPIOA, NUM_1, LED_ON);
        break;
    case 2:
        HAL_GPIO_WritePin(GPIOA, NUM_2, LED_ON);
        break;
    case 3:
        HAL_GPIO_WritePin(GPIOA, NUM_3, LED_ON);
        break;
    case 4:
        HAL_GPIO_WritePin(GPIOA, NUM_4, LED_ON);
        break;
    case 5:
        HAL_GPIO_WritePin(GPIOA, NUM_5, LED_ON);
        break;
    case 6:
        HAL_GPIO_WritePin(GPIOA, NUM_6, LED_ON);
        break;
    case 7:
        HAL_GPIO_WritePin(GPIOA, NUM_7, LED_ON);
        break;
    case 8:
        HAL_GPIO_WritePin(GPIOA, NUM_8, LED_ON);
        break;
    case 9:
        HAL_GPIO_WritePin(GPIOA, NUM_9, LED_ON);
        break;
    default:
        break;
    }
}

void ex_4_handle()
{
    static uint32_t counter = 0;
    if (counter >= 10) counter = 0;
    display7Seg(counter++);
}

void ex_5_handle()
{
    static uint32_t count_seconds_1 = 0;
    static uint32_t count_seconds_2 = 0;
    static uint32_t count_seconds_3 = 0;
    static uint32_t count_seconds_4 = 0;
    static TrafficLight traffic_light_1 = RED_LIGHT;
    static TrafficLight traffic_light_2 = GREEN_LIGHT;
    static TrafficLight traffic_light_3 = RED_LIGHT;
    static TrafficLight traffic_light_4 = GREEN_LIGHT;
    static uint16_t leds_1[3] = {LED_11_Pin, LED_12_Pin, LED_1_Pin};
    static uint16_t leds_3[3] = {LED_7_Pin, LED_6_Pin, LED_5_Pin};
    static uint16_t leds_2[3] = {LED_2_Pin, LED_3_Pin, LED_4_Pin};
    static uint16_t leds_4[3] = {LED_10_Pin, LED_9_Pin, LED_8_Pin};
    
     HAL_GPIO_WritePin(GPIOB,   LED_12_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | 
                                LED_4_Pin  | LED_5_Pin | LED_6_Pin | LED_7_Pin | 
                                LED_8_Pin  | LED_9_Pin | LED_10_Pin| LED_11_Pin, 0);
    
    display7Seg((TRAFFIC_LIGHT_TIME[traffic_light_1] - count_seconds_1) % TRAFFIC_LIGHT_TIME[traffic_light_1]);
    traffic_light_handle(&traffic_light_1, leds_1, &count_seconds_1);
    traffic_light_handle(&traffic_light_2, leds_2, &count_seconds_2);
    traffic_light_handle(&traffic_light_3, leds_3, &count_seconds_3);
    traffic_light_handle(&traffic_light_4, leds_4, &count_seconds_4);
    count_seconds_1++;
    count_seconds_2++;
    count_seconds_3++;
    count_seconds_4++;
}

// turn every LED in a sequence
void sequence_leds(uint8_t *index)
{
     HAL_GPIO_WritePin(GPIOB,   LED_12_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | 
                                LED_4_Pin  | LED_5_Pin | LED_6_Pin | LED_7_Pin | 
                                LED_8_Pin  | LED_9_Pin | LED_10_Pin| LED_11_Pin, 0);
    HAL_GPIO_WritePin(GPIOB, TIME_CLOCK_LED[*index], 1);
    *index = (*index + 1) % 12;
}

void ex_6_handle()
{
  // turn every LED in a sequence
    static uint8_t index = 0;
    sequence_leds(&index);
}

void clearAllClock()
{
    HAL_GPIO_WritePin(GPIOB, LED_1_Pin |LED_2_Pin| LED_3_Pin| LED_11_Pin
                            |LED_12_Pin|LED_4_Pin| LED_5_Pin| LED_6_Pin
                            |LED_7_Pin |LED_8_Pin| LED_9_Pin| LED_10_Pin, 1);
}
void ex_7_handle()
{
  // Your code here
  clearAllClock();
}

void setNumberOnClock(int num)
{
    HAL_GPIO_WritePin(GPIOB, TIME_CLOCK_LED[num % 12], 0);
}

void ex_8_handle()
{
    // Your code here
    setNumberOnClock(0);
}

void clearNumberOnClock(int num)
{
    HAL_GPIO_WritePin(GPIOB, TIME_CLOCK_LED[num % 12], 1);
}

void ex_9_handle()
{
  // Your code here
  clearNumberOnClock(0);
}

void ex_10_handle()
{
    static uint8_t hour = 0;
    static uint8_t minute = 0;
    static uint8_t second = 0;
    if (hour == 0 && minute == 0 && second == 0)
        clearAllClock();
   if (second >= 60)
    {
        second = 0;
        clearNumberOnClock(minute);
        minute++;
        if (minute >= 60)
        {
            minute = 0;
            clearNumberOnClock(hour);
            hour++;
            if (hour >= 24)
            {
                hour = 0;
            }
        }
    }
    clearNumberOnClock(second - 1 + 12);

    setNumberOnClock(second);
    setNumberOnClock(minute);
    setNumberOnClock(hour);

    second++;
}
