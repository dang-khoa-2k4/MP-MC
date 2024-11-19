/*
 * scheduler.h
 *
 *  Created on: Sep 19, 2024
 *      Author: Nguyen Tran Dang Khoa
 */

#ifndef __SCHEDULER_H
#define __SCHEDULER_H
#include <stdint.h>
#include <stdlib.h>

#define MAX_TASKS 10

#define ADD_TASK_ERROR -1
#define NOT_VALID_TASK_ID 0

#define PERIOD_SYS_TIME 10 // ms
#define ONE_SECOND (1000 / PERIOD_SYS_TIME) // 1000ms = 1s
#define FREQ_TO_TICK(x) (1000 / x / PERIOD_SYS_TIME) // 100Hz -> 0.01s = 10ms / period = 1 tick

#ifdef __cplusplus
 extern "C" {
#endif

typedef struct {
    void (* pTask)(void);            
    struct TaskNode *next; 
    uint32_t delay;
    uint32_t period;
    uint8_t runMe;
    uint32_t TaskID;
} TaskNode;

typedef struct {
    TaskNode *currentTask;
    uint32_t nTasks;
} Tasks_t;


extern Tasks_t tasks;

void Scheduler_Init(void);
void Scheduler_Update(void);
void Scheduler_Dispatch_Tasks();
uint32_t Scheduler_Add_Task(void (* pFunction)(void), const uint32_t DELAY, const uint32_t PERIOD);
uint8_t Scheduler_Remove_Task(uint32_t TaskID);
uint16_t freq_to_tick(uint16_t freq);

#ifdef __cplusplus
}
#endif
#endif /*__PID_CONTROL_H */