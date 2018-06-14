#ifndef UART_UTILS_H_
#define UART_UTILS_H_


#include "Arduino.h"

int commandCheckPeriod = 1000;
int digitsDelayPeriod = 1000;
int commandResedPeriod = 3000;

#define WAIT_FOR_COMMAND 0
#define COMMAND_IN_PROCESS 1

int commandStatus = WAIT_FOR_COMMAND;

void initCommandReceiver(unsigned long curr_time);
void checkCommand(unsigned long curr_time, void success_callback(), void fail_callback());






#endif /* UART_UTILS_H_ */
