## Sparkfun7SD


Set of libraries for using Sparkfun 7-segment displays (4 digit), but using different means of connectivity as subclasses. It is based on the tutorials published @ https://learn.sparkfun.com/tutorials/using-the-serial-7-segment-display

## The hardware

These little displays are very neat and convenient to use, and while not the cheapest, are still [pretty affordable at $12.95](https://www.sparkfun.com/products/11441).

They are mounted on what appears to be a modified Arduino Pro Mini, and support Serial, I2C and SPI interfaces for communications.   There are very nice examples and tutorials online, but I wanted to be able to access the display without having to worry which communication protocol to use.

The top level abstract class ```Sparkfun7SD``` is responsible for the actual commands sent to the display, while the subclasses are responsible for implementing the appropriate communications protocol.

## Protocols currently supported

The library implements:

* Serial
* I2C
* SPI

Whoohoo! :)

## Examples

Probably the simplest is the example in the ```Sparkfun7SD_Serial``` folder:

```c++
#include <Sparkfun7SD_Serial.h>
Sparkfun7SD_Serial display7s(8);  // TX pin 8

void setup() {
    display7s.begin();
    display7s.brightness(255);
}

void loop() {
    display7s.clear();

    display7s.print("1234");
    delay(1000);

    display7s.printTime(12, 30, true);
    delay(1000);
}
```

To switch from using Serial to I2C, simply edit the first lines:

```c++
#include <Sparkfun7SD_I2C.h>
Sparkfun7SD_I2C display7s;
```

And to switch to SPI,

```c++
#include <Sparkfun7SD_SPI.h>
Sparkfun7SD_SPI display7s;
```


## Contributing

* Fork it ( https://github.com/[my-github-username]/sparkfun7SD/fork )
* Create your feature branch (git checkout -b my-new-feature)
* Commit your changes (git commit -am 'Add some feature')
* Push to the branch (git push origin my-new-feature)
* Create a new Pull Request
