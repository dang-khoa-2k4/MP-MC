/*
 * timer.c
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */

#include "main.h"

uint32_t timer[MAX_TIMER];

void setTimer(uint8_t timerID, uint32_t time)
{
    if (timerID < 0 && timerID >= MAX_TIMER) return;
    timer[timerID] = time;
}

void updateTimer(void)
{
    uint8_t i;
    for (i = 0; i < MAX_TIMER; i++)
    {
        if (timer[i] > 0)
            timer[i]--;
    }
}

uint8_t isTimerExpired(uint8_t timerID)
{
    if (timerID < 0 && timerID >= MAX_TIMER) return 0;
    if (timer[timerID] == 0)
        return 1;
    return 0;
}
