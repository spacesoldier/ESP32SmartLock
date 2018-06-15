#include "UARTutils.h"

int pin_code_length = secretPassword.length();
unsigned long old_time_checkCommand = 0;
unsigned long old_time_digit_received = 0;
unsigned long old_time_command_received = 0;

String new_code = String('');

void clearPinCode(){
	new_code = '';
}

void readDigits(unsigned long curr_time){
	if (Serial.available() > 0){

		if (curr_time - old_time_digit_received > digitsDelayPeriod){
			clearPinCode();
		}

		while (Serial.available() > 0) {
			char digit = Serial.read();
			new_code.concat(digit);
		}

		// trim received characters string to the password length
		if (new_code.length() > pin_code_length){
			new_code = new_code.substring(new_code.length() - pin_code_length - 1, new_code.length() - 1);
		}

		// check if the code is received
		if (new_code.length() == pin_code_length){
					if (commandStatus == WAIT_FOR_COMMAND){
						commandStatus = COMMAND_IN_PROCESS;
						old_time_command_received = curr_time;
					}
		}
	}
}

void checkPassword(void success_callback(), void fail_callback()){
	if (new_code.equals(secretPassword)){
		success_callback();
	} else {
		fail_callback();
	}
}

void initCommandReceiver(unsigned long curr_time){
	// nothing to perform here at this moment
}


void checkCommand(unsigned long curr_time, void success_callback(), void fail_callback()){
	if (curr_time - old_time_checkCommand > commandCheckPeriod){
		if (commandStatus == WAIT_FOR_COMMAND){
			readDigits(curr_time);
			// if the code is received let's check it is right or wrong
			if (commandStatus == COMMAND_IN_PROCESS){
				checkPassword(success_callback, fail_callback);
			}
		} else if (commandStatus == COMMAND_IN_PROCESS){
			if (curr_time - old_time_command_received > commandResetPeriod){
				commandStatus = WAIT_FOR_COMMAND;
				clearPinCode();
			}
		}
	}
}




