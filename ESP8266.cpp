#include "Arduino.h"
#include "ESP8266.h"
#include <SoftwareSerial.h>

ESP8266::ESP8266(int RX=10, int TX=11)
{
    //Set up software serial on pins 10 and 11
    esplink = new SoftwareSerial(RX, TX);
    //Set baud rate to 9600
    esplink.begin(9600);
}

void ESP8266::sendCom(char[] com)
{
    esplink.println(com);
}

void ESP8266::setMode(int mode)
{
    //Send AT command to set the mode
    //of the ESP8266
}

void ESP8266::setAccessPoint(String SSID, String password)
{
    //Set the parameters of the ESP8266
    //in access point mode
}

void ESP8266::listAccessPoints()
{
    //Send AT command to list access points
    //Get list of access points as a string
    //Return string
}

