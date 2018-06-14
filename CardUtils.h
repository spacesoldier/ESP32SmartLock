/*
 * CardUtils.h
 *
 *  Created on: 14 июн. 2018 г.
 *      Author: Soldat
 */

#ifndef CARDUTILS_H_
#define CARDUTILS_H_

#include "SPI.h"
#include "MFRC522.h"

const int RST_PIN = 22; // Reset pin
const int SS_PIN = 21; // Slave select pin

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

unsigned long uidDec, uidDecTemp; // для отображения номера карточки в десятичном формате

void initReader(unsigned long curr_time);
void readCards(unsigned long curr_time, void success_callback(), void fail_callback());


#endif /* CARDUTILS_H_ */
