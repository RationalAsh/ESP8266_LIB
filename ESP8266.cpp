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

int ESP8266::moduleTest()
{
    //Send the test signal
    sendCom(TST);
    //Receive the reply from the module
    //If the reply is "OK" return 1
    //If there is an error return 0
    if(esplink.find("OK")) return 1;
    else return 0;    
}

void ESP8266::setMode(int mode)
{
    //Send AT command to set the mode
    //of the ESP8266
    cmd = MODE;
    cmd += String(mode);
    sendCom(cmd);
}

void ESP8266::createAccessPoint(String SSID, String password)
{
    //Set the parameters of the ESP8266
    //in access point mode
    cmd = SET_AP_PARAMS;
    cmd += "\"";
    cmd += SSID;
    cmd += "\"";
    cmd += ",\"";
    cmd += password;
    cmd += "\"";
    cmd += String(2);
    cmd += String(1);
    sendCom(cmd);
}

String ESP8266::listAccessPoints()
{
    //Send AT command to list access points
    sendCom(LIST_AP);
    //Get list of access points as a string
    
    //Return string
    
}

