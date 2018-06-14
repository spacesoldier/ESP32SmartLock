/*
 * LockerUtils.cpp
 *
 *  Created on: 14 θών. 2018 γ.
 *      Author: Soldat
 */

#include "LockerUtils.h"

void initLocker(unsigned long curr_time){
	servo1.attach(servo1Pin, minUs, maxUs);
}



void checkLockerState(unsigned long curr_time, void success_callback(), void fail_callback()){
	servo1.write(pos);
}

#define LOCK_OPENED 0
#define LOCK_CLOSED 1

int lock_state = LOCK_CLOSED;
int old_lock_state = LOCK_CLOSED;

void open_lock(){
	servo1.write(5);
}
