/* 
   ESP8266.h - Library for the ESP8266 Wifi
   module.

   Created by Ashwin Narayan, December 9, 2014

   Code is public domain
*/


#ifndef ESP8266_h
#define ESP8266_h

#include "Arduino.h"

class ESP8266
{
public:
    //RX goes to TX of module
    //TX goes to RX of module
    ESP8266(int RX=10, int TX=11);
    void setMode(int mode);
    void setAccessPoint(String SSID, String password);
    String listAccessPoints();

private:
    int mode;
    int _RX;
    int _TX;
};

#endif
