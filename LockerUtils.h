/*
 * LockerUtils.h
 *
 *  Created on: 14 θών. 2018 γ.
 *      Author: Soldat
 */

#ifndef LOCKERUTILS_H_
#define LOCKERUTILS_H_

#include "ESP32_Servo.h"

Servo servo1;

int minUs = 500;
int maxUs = 2400;

int servo1Pin = 26;
int pos = 70; // position in degrees

void initLocker(unsigned long curr_time);
void checkLockerState(unsigned long curr_time, void success_callback(), void fail_callback());
void open_lock();

#endif /* LOCKERUTILS_H_ */
