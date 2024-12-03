/*
 * command_fsm.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Khoa Nguyen
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

// #include "sw_timer.h"
#include "main.h"
#include <stdio.h>

void command_parser_fsm(UART_HandleTypeDef huart2);

typedef enum 
{
    INIT, 
    UNDEFINED,
    END,
    DONE
} parser_status_t;


#endif /* INC_COMMAND_H_ */