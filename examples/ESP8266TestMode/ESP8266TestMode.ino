#include <ESP8266Writer.h>

// ESP8266Writer mode pin
#define TEST_MODE_PIN  21

// setup routine
void setup()
{
    // begin test mode if WRITER_MODE_PIN is LOW
    ESP8266Writer.beginTest(TEST_MODE_PIN);
    
    // normal operation
    Serial.begin(115200);
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
}

// normal operation (blink LEDs)
void loop() {
    Serial.println("Normal Operation Now!");
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    delay(1000);
    digitalWrite(PIN_LED1, LOW);
    digitalWrite(PIN_LED2, LOW);
    delay(1000);
}

