# GR-ROSE ESP8266 Firmware Writer

ESP8266Writer is a tool to update the firmware of GR-ROSE's onboard ESP8266. ESP8266Writer controls EN, IO0 and IO15 of the ESP8266 to put it into UART Download Mode. ESP8266Writer also transparently connects the USB serial port to the ESP8266 for downloading the firmware.

In addition, ESP8266Writer provides ESP8266 test mode. ESP8266Writer just connects the USB serial port to the ESP8266 in this mode, and the ESP8266 operates in Flash Run Mode.

## ESP8266Writer.begin(pin, baud)

begins ESP8266 Writer mode if the specified pin is LOW.  
baud is optional. (The default baud rate is 115200.)

## ESP8266Writer.begin(baud)

begins ESP8266 Writer mode unconditionally.  
baud is optional. (The default baud rate is 115200.)

## ESP8266Writer.beginTest(pin, baud)

begins ESP8266 Test mode if the specified pin is LOW.  
baud is optional. (The default baud rate is 115200.)

## ESP8266Writer.beginTest(baud)

begins ESP8266 Test mode unconditionally.  
baud is optional. (The default baud rate is 115200.)

# For Flash Download Tool and esptool

This library does not support Flash Download Tool and esptool. Please use the special version of ESP8266 Writer for these tools. The binary file of the special version is below.

- [bin/esp8266_writer_special.bin](bin/esp8266_writer_special.bin)
