#include <Arduino.h>
#include "ESP8266Writer.h"

// Global obcject
ESP8266WriterClass ESP8266Writer;

// GR-ROSE's Serial6 is ESP8266 I/F 
static HardwareSerial* serial = &Serial6;

// begin writer if pin_sw is LOW
void ESP8266WriterClass::begin(int pin_sw)
{
    // check mode pin
    pinMode(pin_sw, INPUT_PULLUP);
    int pin_state = digitalRead(pin_sw);
    if(pin_state != LOW){
        return;
    }
    
    // begin writer
    begin();
}
// begin writer unconditionally
void ESP8266WriterClass::begin()
{
    // setup LEDs
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    delay(250);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    delay(250);
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    delay(250);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
        
    // setup serial ports
    Serial.begin(9600);
    serial->begin(115200);
    
    // turn ESP8266 to flash program mode
    pinMode(PIN_ESP_EN, OUTPUT);
    pinMode(PIN_ESP_IO0, OUTPUT);
    pinMode(PIN_ESP_IO15, OUTPUT);
    
    digitalWrite(PIN_ESP_IO0, LOW); // HIGH -> run mode
    digitalWrite(PIN_ESP_IO15, LOW);
    digitalWrite(PIN_ESP_EN, LOW);
    delay(100);
    digitalWrite(PIN_ESP_EN, HIGH);
    
    // serial port bridge
    while(true)
    {
        if(Serial.available()){
            serial->write(Serial.read());
            
            digitalWrite(PIN_LED1, HIGH);
        }else{
            digitalWrite(PIN_LED1, LOW);
        }
        if(serial->available()){
            Serial.write(serial->read());
            
            digitalWrite(PIN_LED2, HIGH);
        }else{
            digitalWrite(PIN_LED2, LOW);
        }
    }
    
    // never return
}

