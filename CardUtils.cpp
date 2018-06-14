/*
 * CardUtils.cpp
 *
 *  Created on: 14 июн. 2018 г.
 *      Author: Soldat
 */
#include "CardUtils.h"

void initReader(unsigned long curr_time){
	SPI.begin(); // Init SPI bus
	mfrc522.PCD_Init(); // Init MFRC522
	mfrc522.PCD_DumpVersionToSerial(); // Show details of PCD - MFRC522 Card Reader details
}

void readCards(unsigned long curr_time, void success_callback(), void fail_callback()){
		// Поиск новой карточки / Look for new cards.
		if ( ! mfrc522.PICC_IsNewCardPresent()) {
			return;
		}

		// Выбор карточки / Select one of the cards.
		if ( ! mfrc522.PICC_ReadCardSerial()) {
			return;
		}

		uidDec = 0;

		// Выдача серийного номера карточки.
		for (byte i = 0; i < mfrc522.uid.size; i++)
		{
			uidDecTemp = mfrc522.uid.uidByte[i];
			uidDec = uidDec*256+uidDecTemp;
		}
		Serial.println("Serijnyj nomer karty / Card UID: ");
		Serial.println(uidDec);

		// начинаем сравнивать номер прочитанной корты, с записанным номером карты.
		// замените! № "699586603 ", на номер № вашей карты.
		if (uidDec == 178934400)
		{
			// если номер совпал включим светодиод.
			// digitalWrite(ledPins[0], HIGH);
			success_callback();

			// и отправим сообщение.
			Serial.println("Hi Dmitry");
		}

		// также и с другими номерами карт.
		else if (uidDec == 699586603)
		{
			success_callback();
			// digitalWrite(ledPins[1], HIGH);
			Serial.println("Hi Sergey");
		}

		else if (uidDec == 695670870)
		{
			success_callback();
			// digitalWrite(ledPins[2], HIGH);
			Serial.println("Hi Peter");
		}

		else if (uidDec == 695670614)
		{
			success_callback();
			// digitalWrite(ledPins[3], HIGH);
			Serial.println("Hi Vasily");
		}

		else
		{
			// если номер карты не совпал, включим все светодиоды.
			// for(i = 0; i <= 3; i++)digitalWrite(ledPins[i],HIGH);
			Serial.println("Neizvestnaja karta / unknown card");
		}

		Serial.println("=====================================");
}

