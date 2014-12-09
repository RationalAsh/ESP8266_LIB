/* 
   ESP8266.h - Library for the ESP8266 Wifi
   module.

   Created by Ashwin Narayan, December 9, 2014

   Code is public domain
*/


#ifndef ESP8266_h
#define ESP8266_h

#include "Arduino.h"
#include <SoftwareSerial.h>

#define TEST           "AT"
#define RESET          "AT+RST"
#define LIST_AP        "AT+CWLAP"
#define JOIN_AP        "AT+CWJAP"
#define QUIT_AP        "AT+CWQAP"
#define SET_AP_PARAMS  "AT+CWSAP"
#define START_CON      "AT+CIPSTART"
#define GET_CON_STATUS "AT+CIPSTATUS"
#define CON_SEND       "AT+CIPSEND"
#define CON_CLOSE      "AT+CIPCLOSE"
#define MODE           "AT+CWMODE"
#define FIRMWARE       "AT+GMR"
#define SET_MUL_CON    "AT+CIPUX"
#define SET_SERVER     "AT+CIPSERVER"
#define GET_DATA       "+IPD"

class ESP8266
{
public:
    //RX goes to TX of module
    //TX goes to RX of module
    ESP8266(int RX=10, int TX=11);
    //Send a command to the module
    void sendCom(char[] com);
    //Checks if module is receiving serial data
    int moduleTest();
    //Set the mode in which the module operates
    void setMode(int mode);
    //Set the parameters of the access point created by the module
    void setAccessPoint(String SSID, String password);
    //List all the access points detected by the module
    String listAccessPoints();

private:
    int mode;
    int _RX;
    int _TX;
    SoftwareSerial esplink;
};

#endif
