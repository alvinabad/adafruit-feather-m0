/*
  Blink
*/

#include <Arduino.h>

#ifndef LED_BUILTIN
    #define LED_BUILTIN 13
#endif

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(115200);

    // only use if there is serial connection
    //while (!Serial);

    delay(2000);

    Serial.println("Begin LED BLINKER");
    pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
}
