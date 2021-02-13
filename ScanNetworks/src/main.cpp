/**
 *  Scan WiFi Networks
 */

#include "Arduino.h"
#include <SPI.h>
#include <WiFi101.h>

// Declare functions
void printMacAddress();
void listNetworks();
void printMacAddress(byte[]);
void printEncryptionType(int);

#ifndef LED_BUILTIN
    #define LED_BUILTIN 13
#endif

void setup() {
    //Configure pins for Adafruit ATWINC1500 Feather
    WiFi.setPins(8,7,4,2);
  
    //Initialize serial and wait for port to open:
    Serial.begin(115200);

    //while (!Serial); // wait for serial port to connect. Needed for native USB port only

    delay(2000);

    Serial.println("Begin LED BLINKER");
    pinMode(LED_BUILTIN, OUTPUT);

    // check for the presence of the shield:
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        // don't continue:
        while (true);
    }
}

void blink(int N) {
    // blink N times

    for (int i=0; i<N; i++) {
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
    }
}

void loop() {
    // Print WiFi MAC address:
    printMacAddress();

    // scan for existing networks:
    Serial.println("Scanning available networks...");
    listNetworks();

    Serial.println("End of scan");

    // blink 10 times; introduces 10 seconds delay
    blink(10);

    // delay next scan
    delay(5000);
}

void printMacAddress() {
    // the MAC address of your WiFi shield
    byte mac[6];

    // print your MAC address:
    WiFi.macAddress(mac);
    Serial.print("MAC: ");
    printMacAddress(mac);
}

void listNetworks() {
    // scan for nearby networks:
    Serial.println("** Scan Networks **");
    int numSsid = WiFi.scanNetworks();
    if (numSsid == -1)
    {
        Serial.println("Couldn't get a wifi connection");
        while (true);
    }

    // print the list of networks seen:
    Serial.print("number of available networks:");
    Serial.println(numSsid);

    // print the network number and name for each network found:
    for (int thisNet = 0; thisNet < numSsid; thisNet++) {
        Serial.print(thisNet);
        Serial.print(") ");
        Serial.print(WiFi.SSID(thisNet));
        Serial.print("\tSignal: ");
        Serial.print(WiFi.RSSI(thisNet));
        Serial.print(" dBm");
        Serial.print("\tEncryption: ");
        printEncryptionType(WiFi.encryptionType(thisNet));
        Serial.flush();
    }
}

void printEncryptionType(int thisType) {
    // read the encryption type and print out the name:
    switch (thisType) {
        case ENC_TYPE_WEP:
            Serial.println("WEP");
            break;
        case ENC_TYPE_TKIP:
            Serial.println("WPA");
            break;
        case ENC_TYPE_CCMP:
            Serial.println("WPA2");
            break;
        case ENC_TYPE_NONE:
            Serial.println("None");
            break;
        case ENC_TYPE_AUTO:
            Serial.println("Auto");
            break;
    }
}

void printMacAddress(byte mac[]) {
    for (int i = 5; i >= 0; i--) {
        if (mac[i] < 16) {
            Serial.print("0");
        }
        Serial.print(mac[i], HEX);
        if (i > 0) {
            Serial.print(":");
        }
    }
    Serial.println();
}
