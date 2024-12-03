/*
 * communication_fsm.h
 *
 *  Created on: Nov 20, 2024
 *      Author: Khoa Nguyen
 */


#ifndef INC_UART_COMMUNIATION_H_
#define INC_UART_COMMUNIATION_H_

#include "main.h"

typedef enum 
{
    RST, 
    ADC,
    OK
} uart_status_t;

void uart_communiation_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2);

#endif /* INC_UART_COMMUNIATION_H_ */
