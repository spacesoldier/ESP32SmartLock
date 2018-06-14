/*
 * LockerUtils.cpp
 *
 *  Created on: 14 θών. 2018 γ.
 *      Author: Soldat
 */

#include "LockerUtils.h"

#define LOCK_OPENED 0
#define LOCK_CLOSED 1

int lock_state = LOCK_CLOSED;
int old_lock_state = LOCK_CLOSED;

int checkStatePeriod = 100;
unsigned long old_time_checkState = 0;
unsigned long old_time_lock_opened = 0;

void initLocker(unsigned long curr_time){
	servo1.attach(servo1Pin, minUs, maxUs);
	old_time_checkState = curr_time;
}

void checkLockerState(unsigned long curr_time, void open_callback(), void close_callback()){
	if (curr_time - old_time_checkState > checkStatePeriod){
		if (lock_state != old_lock_state){
			if ( lock_state == LOCK_OPENED){
				servo1.write(pos_open);
				old_lock_state = LOCK_OPENED;
				open_callback();
				old_time_lock_opened = curr_time;
			} else if ( lock_state == LOCK_CLOSED ) {
				old_lock_state = LOCK_CLOSED;
				close_callback();
			}
		} else {
			if ( lock_state == LOCK_OPENED ){
				if ( curr_time - old_time_lock_opened > lockOpenStatePeriod ){
					lock_state = LOCK_CLOSED;
					servo1.write(pos_lock);
				}
			}
		}
		old_time_checkState = curr_time;
	}
}

void open_lock(){
	lock_state = LOCK_OPEN;
}
