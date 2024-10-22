/*
 * timer.h
 *
 *  Created on: Oct 3, 2024
 *      Author: ADMIN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define MAX_TIMER 10

void setTimer(uint8_t timerID, uint32_t time);
void updateTimer(void);
uint8_t isTimerExpired(uint8_t timerID);

#endif /* INC_TIMER_H_ */
