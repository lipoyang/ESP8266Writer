#ifndef __ESP8266_WRITER__
#define __ESP8266_WRITER__

#include <Arduino.h>

#define NOT_USE_MODE_PIN	-1

// ESP8266 Flash writer
class ESP8266WriterClass
{
public:
    // attach serial port (not for GR-ROSE's onboard ESP8266)
    void attach(HardwareSerial &serial, int en, int io0, int io15);

    // begin writer mode if mode_pin is LOW
    void begin(int mode_pin = NOT_USE_MODE_PIN, int baud = 115200);

    // begin test mode if mode_pin is LOW
    void beginTest(int mode_pin = NOT_USE_MODE_PIN, int baud = 115200);

};

extern ESP8266WriterClass ESP8266Writer;

#endif
