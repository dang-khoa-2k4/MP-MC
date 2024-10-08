/*
 * scheduler.c
 *
 *  Created on: Sep 19, 2024
 *      Author: Nguyen Tran Dang Khoa
 */

#include "scheduler.h"

Tasks_t tasks;


void Scheduler_Init(void) {
    tasks.currentTask = NULL;
    tasks.nTasks = 0;
}

static uint32_t Get_New_Task_ID()
{
    static uint32_t TaskID = 0;
    return ++TaskID;
}


void Scheduler_Update(void) {
    if (tasks.currentTask && tasks.currentTask->runMe == 0) {
		if(tasks.currentTask->delay > 0)
			tasks.currentTask->delay--;
		if (tasks.currentTask->delay <= 0) 
			tasks.currentTask->runMe = 1;
	}
}

uint32_t Scheduler_Add_Task(void (* pFunction)(void), const uint32_t DELAY, const uint32_t PERIOD) {
    TaskNode *newTask = (TaskNode *)malloc(sizeof(TaskNode));
    if (newTask == NULL || tasks.nTasks >= MAX_TASKS) {
        return NOT_VALID_TASK_ID;
    }

    if (tasks.currentTask == NULL) {
        tasks.currentTask = newTask;
        tasks.nTasks++;
        newTask->pTask = pFunction;
        newTask->delay = DELAY;
        newTask->period = PERIOD;
        newTask->runMe = 0;
        newTask->TaskID = Get_New_Task_ID();
        newTask->next = NULL;
        return newTask->TaskID;
    }

    TaskNode *temp_task;
    TaskNode *preTask = NULL;
    uint8_t newTaskIndex = 0;
	uint32_t sumDelay = 0;
	uint32_t newDelay = 0;

	for (newTaskIndex = 0, temp_task = tasks.currentTask; 
         newTaskIndex < tasks.nTasks; newTaskIndex++, 
         preTask = temp_task, temp_task = temp_task->next) {

		sumDelay = sumDelay + temp_task->delay;
		//  sumDelay > DELAY -> new task need to be added before current task pointer
		if(sumDelay > DELAY){
			// because new task will be added before current task pointer 
			// so the delay of new task will be calculated
			newDelay = DELAY - (sumDelay - temp_task->delay);
			// and the delay of current task will be reduced
			temp_task->delay = sumDelay - DELAY;
            // move all task after current task pointer to the next index
            newTask->next = temp_task;
            // avoid preTask is empty when add new task at the first index
            if (preTask)
                preTask->next = newTask;
            else 
                tasks.currentTask = newTask;
            // add new task to the current task pointer
            newTask->pTask = pFunction;
            newTask->delay = newDelay;
            newTask->period = PERIOD;
            newTask->runMe = newTask->delay == 0 ? 1 : 0;
            newTask->TaskID = Get_New_Task_ID();
            tasks.nTasks++;
            return newTask->TaskID;
		}
        else {
            if (newTaskIndex == tasks.nTasks - 1)
            {
                newDelay = DELAY - sumDelay;
                temp_task->next = newTask;
                newTask->next = NULL;

                // add new task to the current task pointer
                newTask->pTask = pFunction;
                newTask->delay = newDelay;
                newTask->period = PERIOD;
                newTask->runMe = newTask->delay == 0 ? 1 : 0;
                newTask->TaskID = Get_New_Task_ID();
                tasks.nTasks++;
                return newTask->TaskID;
            }
        }
	}
	return newTask->TaskID;

}

void Scheduler_Dispatch_Tasks() {
	if(tasks.currentTask->runMe > 0) {
		(*(tasks.currentTask->pTask))(); // Run the task
		tasks.currentTask->runMe = 0; // Reset / reduce RunMe flag
		TaskNode temtask = *(tasks.currentTask);
		if (temtask.period != 0 && Scheduler_Remove_Task(temtask.TaskID)) {
			Scheduler_Add_Task(temtask.pTask, temtask.period, temtask.period);
		}
	}
}

uint8_t Scheduler_Remove_Task( uint32_t TaskID) {
    if (TaskID != NOT_VALID_TASK_ID)
    {
        TaskNode *temp_task;
        TaskNode *preTask = NULL;
        uint8_t taskIndex = 0;
        for (taskIndex = 0, temp_task = tasks.currentTask; 
             taskIndex < tasks.nTasks; taskIndex++, 
             preTask = temp_task, temp_task = temp_task->next) {
            if (temp_task->TaskID == TaskID) {
                if (temp_task == tasks.currentTask) {
                    tasks.currentTask = temp_task->next;
                }
                else {
                    preTask->next = temp_task->next;
                }
                free(temp_task);
                tasks.nTasks--;
                return 1;
            }
        }
    }
	return 0; // return status
}

