#include "Arduino.h"

#include "UARTutils.h"
#include "LockerUtils.h"
#include "CardUtils.h"

//#define RST_PIN 9 // Configurable, see typical pin layout above
//#define SS_PIN 10 // Configurable, see typical pin layout above

void do_nothing(){

}


void setup() {
	initLocker(millis());
	Serial.begin(9600); // Initialize serial communications with the PC
	while (!Serial); // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	initCommandReceiver(millis());
	initReader(millis());
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {

	checkCommand(millis(), open_lock, do_nothing);
	readCards(millis(), open_lock, do_nothing);
	checkLockerState(millis(), do_nothing, do_nothing);

}

