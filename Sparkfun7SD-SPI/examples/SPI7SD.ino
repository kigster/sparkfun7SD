/*
 * Example of using Sparkfun SPI 7SD display.
 *
 * Dependency:
 * - Sparkfun7SD
 * - Sparkfun7SD_SPI
 *
 *  Created on: Nov 19 2014
 *      Author: Konstantin Gredeskoul
 *
 *  (c) 2014 All rights reserved.  Please see LICENSE.
 */
/**
 *
 */
#include <Sparkfun7SD.h>
#include <Sparkfun7SD_SPI.h>

// initialize the display using the default SPI address
// defined in SPARKFUN_7SD_DEFAULT_SPI_ADDRESS
Sparkfun7SD_SPI display7s;

// define variables to print
int counter = 0;
char buffer[5];
bool colonIsOn = false;

void setup() {
    display7s.begin();
    display7s.brightness(255);
    delay(2000);
}

void loop() {
    counter++;
    colonIsOn = !colonIsOn;
    display7s.clear();

    sprintf(buffer, "%4.4d", counter);
    display7s.print(buffer);
    delay(1000);

    // not a real time.  Third arguments defines if the colon is turned on between digits.
    display7s.printTime(12, counter % 60, colonIsOn);
    delay(1000);
}
