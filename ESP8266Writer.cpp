#include "ESP8266Writer.h"

// Global obcject
ESP8266WriterClass ESP8266Writer;

// GR-ROSE's Serial6 is ESP8266 I/F 
#ifdef GRROSE
static HardwareSerial* s_serial = &Serial6;
static int s_pin_esp_en   = PIN_ESP_EN;
static int s_pin_esp_io0  = PIN_ESP_IO0;
static int s_pin_esp_io15 = PIN_ESP_IO15;
#else
static HardwareSerial* s_serial;
static int s_pin_esp_en;
static int s_pin_esp_io0;
static int s_pin_esp_io15;
#endif

// attach serial port (not for GR-ROSE's onboard ESP8266)
void ESP8266WriterClass::attach(HardwareSerial &serial, int en, int io0, int io15)
{
    s_serial = &serial;
    s_pin_esp_en   = en;
    s_pin_esp_io0  = io0;
    s_pin_esp_io15 = io15;
}

// begin writer mode if mode_pin is LOW
void ESP8266WriterClass::begin(int mode_pin, int baud)
{
    if(mode_pin != NOT_USE_MODE_PIN)
    {
        // check mode pin
        pinMode(mode_pin, INPUT_PULLUP);
        int pin_state = digitalRead(mode_pin);
        if(pin_state != LOW){
            return;
        }
    }
    
    // setup LEDs
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    for(int i=0;i<2;i++){
        digitalWrite(PIN_LED1, HIGH);
        digitalWrite(PIN_LED2, HIGH);
        delay(250);
        digitalWrite(PIN_LED1, LOW);
        digitalWrite(PIN_LED2, LOW);
        delay(250);
    }
    
    // setup serial ports
    Serial.begin(9600);
    s_serial->begin(baud);
    
    // turn ESP8266 to flash program mode
    pinMode(s_pin_esp_en,   OUTPUT);
    pinMode(s_pin_esp_io0,  OUTPUT);
    pinMode(s_pin_esp_io15, OUTPUT);
    
    digitalWrite(s_pin_esp_io0,  LOW); // LOW -> UART Download Mode
    digitalWrite(s_pin_esp_io15, LOW);
    digitalWrite(s_pin_esp_en,   LOW);
    delay(100);
    digitalWrite(s_pin_esp_en,   HIGH);
    
    // serial port bridge
    while(true)
    {
        if(Serial.available()){
            s_serial->write(Serial.read());
            
            digitalWrite(PIN_LED1, HIGH);
        }else{
            digitalWrite(PIN_LED1, LOW);
        }
        if(s_serial->available()){
            Serial.write(s_serial->read());
            
            digitalWrite(PIN_LED2, HIGH);
        }else{
            digitalWrite(PIN_LED2, LOW);
        }
    }
    
    // never return
}

// begin test mode if mode_pin is LOW
void ESP8266WriterClass::beginTest(int mode_pin, int baud)
{
    if(mode_pin != NOT_USE_MODE_PIN)
    {
        // check mode pin
        pinMode(mode_pin, INPUT_PULLUP);
        int pin_state = digitalRead(mode_pin);
        if(pin_state != LOW){
            return;
        }
    }
    
    // setup LEDs
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    for(int i=0;i<4;i++){
        digitalWrite(PIN_LED1, HIGH);
        digitalWrite(PIN_LED2, HIGH);
        delay(250);
        digitalWrite(PIN_LED1, LOW);
        digitalWrite(PIN_LED2, LOW);
        delay(250);
    }
    
    // setup serial ports
    Serial.begin(9600);
    s_serial->begin(baud);
    
    // turn ESP8266 to flash program mode
    pinMode(s_pin_esp_en,   OUTPUT);
    pinMode(s_pin_esp_io0,  OUTPUT);
    pinMode(s_pin_esp_io15, OUTPUT);
    
    digitalWrite(s_pin_esp_io0,  HIGH); // HIGH -> Flash Run Mode
    digitalWrite(s_pin_esp_io15, LOW);
    digitalWrite(s_pin_esp_en, LOW);
    delay(100);
    digitalWrite(s_pin_esp_en, HIGH);
    
    // serial port bridge
    while(true)
    {
        if(Serial.available()){
            s_serial->write(Serial.read());
            
            digitalWrite(PIN_LED1, HIGH);
        }else{
            digitalWrite(PIN_LED1, LOW);
        }
        if(s_serial->available()){
            Serial.write(s_serial->read());
            
            digitalWrite(PIN_LED2, HIGH);
        }else{
            digitalWrite(PIN_LED2, LOW);
        }
    }
    
    // never return
}

