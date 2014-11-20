/*
 * Sparkfun7SD_SPI.cpp
 *
 *  Created on: Sep 1, 2014
 *      Author: Konstantin Gredeskoul
 *
 *  (c) 2014 All rights reserved.  Please see LICENSE.
 */

#include <Sparkfun7SD.h>
#include "Sparkfun7SD_SPI.h"

#include <SPI.h>

Sparkfun7SD_SPI::Sparkfun7SD_SPI(uint8_t ssPin) {
    _ssPin = ssPin;
}

Sparkfun7SD_SPI::Sparkfun7SD_SPI() {
    _ssPin = SPARKFUN_7SD_DEFAULT_SS_PIN;
}

void Sparkfun7SD_SPI::begin() {
    pinMode(_ssPin, OUTPUT);  // Set the SS pin as an output
    digitalWrite(_ssPin, HIGH);  // Set the SS pin HIGH
    SPI.begin();  // Begin SPI hardware
    SPI.setClockDivider(SPI_CLOCK_DIV64);  //
    clear();
}

void Sparkfun7SD_SPI::write(byte value) {
    SPI.transfer(value);
}

void Sparkfun7SD_SPI::beginWrite() {
    digitalWrite(_ssPin, LOW);
}

void Sparkfun7SD_SPI::endWrite() {
    digitalWrite(_ssPin, HIGH);
}

void Sparkfun7SD_SPI::print(char *message) {
    beginWrite();
    Sparkfun7SD::print(message);
    endWrite();
}

void Sparkfun7SD_SPI::decimals(byte bitmask) {
    beginWrite();
    Sparkfun7SD::decimals(bitmask);
    endWrite();
}

void Sparkfun7SD_SPI::clear() {
    beginWrite();
    Sparkfun7SD::clear();
    endWrite();
}

void Sparkfun7SD_SPI::brightness(byte value) {
    beginWrite();
    Sparkfun7SD::brightness(value);
    endWrite();
}

void Sparkfun7SD_SPI::printUnits(float value, char *type) {
    beginWrite();
    Sparkfun7SD::printUnits(value, type);
    endWrite();
}

void Sparkfun7SD_SPI::printTime(uint8_t hours, uint8_t minutes,
        bool colonShown) {
    beginWrite();
    Sparkfun7SD::printTime(hours, minutes, colonShown);
    endWrite();
}

