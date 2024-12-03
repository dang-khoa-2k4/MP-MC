/*
 * global.c
 *
 *  Created on: Nov 2, 2024
 *      Author: Khoa Nguyen
 */

#include "global.h"

parser_status_t parser_status = UNDEFINED;
uart_status_t uart_status = RST;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t command[MAX_BUFFER_SIZE];
uint8_t command_index = 0;
uint8_t command_flag = 0;

char str[50];

uint32_t ADC_value = 0;