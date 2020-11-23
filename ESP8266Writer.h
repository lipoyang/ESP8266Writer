#ifndef __ESP8266_WRITER__
#define __ESP8266_WRITER__

// ESP8266 Flash writer
class ESP8266WriterClass
{
public:
    // begin writer mode if pin_sw is LOW
    void begin(int pin_sw);
    // begin writer mode unconditionally
    void begin();

    // begin test mode if pin_sw is LOW
    void beginTest(int pin_sw);
    // begin test mode unconditionally
    void beginTest();

};

extern ESP8266WriterClass ESP8266Writer;

#endif
