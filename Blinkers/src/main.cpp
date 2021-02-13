/*
  Blink
*/

#include <Arduino.h>

#include "blinker.h"
#include "hello.h"

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(115200);

    // use only if there is serial connection
    //while (!Serial);

    // initialize digital pin LED_BUILTIN as an output.
    init_blinker();
}

// the loop function runs over and over again forever
void loop() {
    // run blinker
    led_blinker();

    Hello h;
    h.println();
    h.println("Hello, World!");
}
