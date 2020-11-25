#ifndef __ESP8266_WRITER__
#define __ESP8266_WRITER__

#define NOT_USE_MODE_PIN	-1

// ESP8266 Flash writer
class ESP8266WriterClass
{
public:
    // begin writer mode if mode_pin is LOW
    void begin(int mode_pin = NOT_USE_MODE_PIN, int baud = 115200);

    // begin test mode if mode_pin is LOW
    void beginTest(int mode_pin = NOT_USE_MODE_PIN, int baud = 115200);

};

extern ESP8266WriterClass ESP8266Writer;

#endif
