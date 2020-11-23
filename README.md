# GR-ROSE ESP8266 Firmware Writer

ESP8266Writer is a tool to update the firmware of GR-ROSE's onboard ESP8266. ESP8266Writer controls EN, IO0 and IO15 of the ESP8266 to put it into UART Download Mode. ESP8266Writer also transparently connects the USB serial port to the ESP8266 for downloading the firmware.

In addition, ESP8266Writer provides ESP8266 test mode. ESP8266Writer just connects the USB serial port to the ESP8266 in this mode, and the ESP8266 operates in Flash Run Mode.

## ESP8266Writer.begin(pin)

begins ESP8266 Writer mode if the specified pin is LOW.

## ESP8266Writer.begin()

begins ESP8266 Writer mode unconditionally.

## ESP8266Writer.beginTest(pin)

begins ESP8266 Test mode if the specified pin is LOW.

## ESP8266Writer.beginTest()

begins ESP8266 Test mode unconditionally.
