#include "Arduino.h"
#include "ESP8266.h"
#include <SoftwareSerial.h>

ESP8266::ESP8266(int RX=10, int TX=11, int mode=0, int baud=9600)
{
    if(mode == SOFTWARE_SERIAL)
    {
	//Set up software serial on pins 10 and 11
	esplink = new SoftwareSerial(RX, TX);
	//Set baud rate to 9600
	esplink.begin(baud);
    }
    else if(mode == HARDWARE_SERIAL)
    {
	Serial.begin(baud);
    }
    _mode = mode;
}

void ESP8266::sendCom(String com)
{
    if(_mode == SOFTWARE_SERIAL) esplink.println(com);
    if(_mode == HARDWARE_SERIAL) Serial.println(com);
}

String ESP8266::getData()
{
    if(_mode == SOFTWARE_SERIAL)
    {
    }
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
    cmd += "=";
    cmd += String(mode);
    sendCom(cmd);
}

void ESP8266::createAccessPoint(String SSID, String password)
{
    //Set the parameters of the ESP8266
    //in access point mode
    cmd = SET_AP_PARAMS;
    cmd += "=\"";
    cmd += SSID;
    cmd += "\",\"";
    //cmd += ",\"";
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

void ESP8266::setConnectionMode(int mode)
{
    //Send the AT command to set the connection mode
    cmd = MODE;
    cmd += "=";
    if(mode == SINGLE) cmd += String(SINGLE);
    else if(mode == MULTIPLE) cmd += String(MULTIPLE);
    sendCom(cmd);
}

void ESP8266::joinAccessPoint(String SSID, String password);
{
    //Send the AT command to join Access point
    cmd = JOIN_AP;
    cmd += "=\"";
    cmd += SSID;
    cmd += "\",\"";
    cmd += password;
    cmd += "\"";

    //If successful return 1
    if(esplink.find("OK")) return 1;
    else return 0;
}
