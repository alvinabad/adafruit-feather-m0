/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.
  LED_BUILTIN is pin 13
*/

#include "Arduino.h"
#include <SPI.h>
#include <WiFi101.h>

#define DELAY  1000

// the setup function runs once when you press reset or power the board
void setup() {
    //Configure pins for Adafruit ATWINC1500 Feather
    WiFi.setPins(8,7,4,2);
  
    Serial.begin(115200);
    while (!Serial);

    Serial.println();
    Serial.printf("Begin LED LIGHTS: %d\n", LED_BUILTIN);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("LED HIGH:");
  Serial.println(LED_BUILTIN);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(DELAY);
  
  Serial.print("LED LOW:");
  Serial.println(LED_BUILTIN);

  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY);
}
