/*
 * command_fsm.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Khoa Nguyen
 */

#include "command_fsm.h"
#include "global.h"


void command_parser_fsm(UART_HandleTypeDef huart2)
{
    switch (parser_status)
    {
    case INIT:
        if (buffer[index_buffer - 1] == '!')
        {
            parser_status = UNDEFINED;
            command_index = 0;
        }
        break;

    case UNDEFINED:
        if (buffer[index_buffer - 1] == '#')
        {
            parser_status = END;
        }
        else if (buffer[index_buffer - 1] == '!')
        {
            command_index = 0;
        }
        else
        {
            command[command_index++] = temp;
            if (command_index >= MAX_BUFFER_SIZE)
            {
                command_index = 0;
            }
        }
        break;

    case END:
        if (1)
        {
            command[command_index] = '\0';
            command_index = 0;
            parser_status = INIT;
            command_flag = 1;
        }
        break;

    default:
        break;
    }
}