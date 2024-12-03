/*
 *  global.h
 *
 *  Created on: Nov 2, 2024
 *      Author: Khoa Nguyen
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdint.h>
#include "communication_fsm.h"
#include "command_fsm.h"
#include "sw_timer.h"
#include "main.h"

#define MAX_BUFFER_SIZE 30

extern parser_status_t parser_status;
extern uart_status_t uart_status;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t command_flag;
extern uint8_t command[MAX_BUFFER_SIZE];
extern uint8_t command_index;

extern char str[50];

extern uint32_t ADC_value;


#endif /* INC_GLOBAL_H_ */