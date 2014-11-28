/*
 * Sparkfun7SD_Serial.cpp
 *
 *  Created on: Sep 1, 2014
 *      Author: Konstantin Gredeskoul
 *
 *  (c) 2014 All rights reserved.  Please see LICENSE.
 */

#include "Sparkfun7SD_Serial.h"
#include <Sparkfun7SD.h>
#include <SoftwareSerial.h>

Sparkfun7SD_Serial::Sparkfun7SD_Serial(uint8_t serialPin) {
    _pinTx = serialPin;
    _Serial7Segment = new SoftwareSerial(_pinTx - 1, _pinTx);
}

Sparkfun7SD_Serial::Sparkfun7SD_Serial() {
    _pinTx = 8;
    _Serial7Segment = new SoftwareSerial(_pinTx - 1, _pinTx);
}

void Sparkfun7SD_Serial::begin() {
    _Serial7Segment->begin(9600);
    clear();
}

void Sparkfun7SD_Serial::printTime(uint8_t hours, uint8_t minutes,
        bool colonShown) {
    Sparkfun7SD::printTime(hours, minutes, colonShown);
}

void Sparkfun7SD_Serial::printUnits(float value, char *type) {
    Sparkfun7SD::printUnits(value, type);
}

void Sparkfun7SD_Serial::clear() {
    Sparkfun7SD::clear();
}

void Sparkfun7SD_Serial::brightness(byte value) {
    Sparkfun7SD::brightness(value);

}
void Sparkfun7SD_Serial::print(char * message) {
    clear();
    _Serial7Segment->print(message);
}

void Sparkfun7SD_Serial::write(byte value) {
    _Serial7Segment->write(value);
}

void Sparkfun7SD_Serial::beginWrite() {
}

void Sparkfun7SD_Serial::endWrite() {
}
