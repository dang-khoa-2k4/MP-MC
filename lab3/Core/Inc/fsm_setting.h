/*
 * fsm_automatic.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_SETTING_H_
#define INC_FSM_SETTING_H_

#define NO_MODE 4
typedef enum {
    INIT_SETTING,
    WAIT_SETTING,
    MODIFY_SETTING,
    NORMAL_SETTING
} settingLight_t;

typedef enum {
    NORMAL_MODE,
    RED_MODIFY,
    GREEN_MODIFY,
    AMBER_MODIFY
} MODE;

#define TRAFFIC_LIGHT_1_TIMER 0
#define TRAFFIC_LIGHT_2_TIMER 1
#define MODIFY_TIMER 2
#define ONE_SECOND_TIMER 3

#define TIME_OUT 10 //s

extern MODE mode;
extern settingLight_t modify;
extern uint8_t modify_time[3];
extern uint8_t flag_mode;

void modify_run(void);
void save_time();
void update_light_time(MODE mode);
void clone_time();

#endif /* INC_FSM_AUTOMATIC_H_ */

