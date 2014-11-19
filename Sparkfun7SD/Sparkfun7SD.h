/*
 *
 * Sparkfun7SD.h
 *
 * Sparkfun 7-Segment Display
 *
 * Abstract Top level implementation, subclaases define anything
 * communications specific.
 *
 * For more info: https://learn.sparkfun.com/tutorials/using-the-serial-7-segment-display
 *
 *  Created on: Oct 19 2014
 *      Author: Konstantin Gredeskoul
 *
 *  (c) 2014 All rights reserved.  Please see LICENSE.
 */

#ifndef SPARKFUN_7SEGMENT_H_
#define SPARKFUN_7SEGMENT_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <pins_arduino.h>
#endif

#define APOSTROPHE  0b100000
#define COLON       0b010000
#define DECIMAL4    0b001000
#define DECIMAL3    0b000100
#define DECIMAL2    0b000010
#define DECIMAL1    0b000001

#define DIGITS      4

class Sparkfun7SD {
public:
    virtual ~Sparkfun7SD() = 0;

    virtual void begin() = 0;
    virtual void write(byte value) = 0;

    virtual void print(char *message);
    virtual void decimals(byte bitmask);
    virtual void clear();
    virtual void brightness(byte value);
    virtual void printUnits(float value, char *type);
    virtual void printTime(uint8_t hours, uint8_t minutes, bool colonShown);
protected:
    char _buffer[DIGITS + 1];
private:
};

inline Sparkfun7SD::~Sparkfun7SD() {
}

#endif /* SPARKFUN_7SEGMENT_H_ */
