#ifndef __ESP8266_WRITER__
#define __ESP8266_WRITER__

// ESP8266 Flash writer
class ESP8266WriterClass
{
public:
    // begin writer if pin_sw is LOW
    void begin(int pin_sw);
    // begin writer unconditionally
    void begin();
};

extern ESP8266WriterClass ESP8266Writer;

#endif
