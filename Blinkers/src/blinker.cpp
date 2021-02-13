#include "Arduino.h"
#include "blinker.h"

void init_blinker() {
    Serial.print("Begin LED BLINKER: ");
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LED9, OUTPUT);
    pinMode(LED11, OUTPUT);
}

void led_blinker() {
    Serial.print("LED9: ");
    Serial.println(LED9);

    Serial.print("LED11: ");
    Serial.println(LED11);

    Serial.print("LED_BUILTIN ON: ");
    Serial.print(LED_BUILTIN);
    Serial.print(", ");

    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED11, LOW);
    delay(DELAY_ON);

    Serial.println("LED_BUILTIN OFF: ");

    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED11, HIGH);
    delay(DELAY_OFF);
}
