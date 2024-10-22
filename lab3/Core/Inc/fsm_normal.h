/*
 * fsm_automatic.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

typedef enum {
    RED,
    GREEN,
    AMBER,
    MODIFY,
    INIT
} trafficLight_t;

extern uint8_t time[3];
extern trafficLight_t light_1;
extern trafficLight_t light_2;

void automatic_run(void);

#endif /* INC_FSM_AUTOMATIC_H_ */

