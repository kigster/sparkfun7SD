/*
 * Sparkfun7SD_SPI.h
 *
 * Sparkfun 7-Segment Display, controlled via SPI
 * For more info: https://learn.sparkfun.com/tutorials/using-the-serial-7-segment-display
 *
 *  Created on: Sep 25 2014
 *      Author: Konstantin Gredeskoul
 *
 *  (c) 2014 All rights reserved.  Please see LICENSE.
 */

#ifndef SPARKFUN_SPI_7SEGMENT_H_
#define SPARKFUN_SPI_7SEGMENT_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif

#include <SPI.h>
#include <Sparkfun7SD.h>

#define SPARKFUN_7SD_DEFAULT_SS_PIN 8

class Sparkfun7SD_SPI : public Sparkfun7SD {
public:
    Sparkfun7SD_SPI(uint8_t ssPin);
    Sparkfun7SD_SPI();
    virtual ~Sparkfun7SD_SPI();

    virtual void begin();
    virtual void write(byte value);
    virtual void print(char *message);
    virtual void beginWrite();
    virtual void endWrite();
    virtual void decimals(byte bitmask);

    virtual void clear();
    virtual void brightness(byte value);
    virtual void printUnits(float value, char *type);
    virtual void printTime(uint8_t hours, uint8_t minutes, bool colonShown);
private:
    uint8_t _ssPin;
};
inline Sparkfun7SD_SPI::~Sparkfun7SD_SPI() {}

#endif /* SPARKFUN_SPI_7SEGMENT_H_ */
