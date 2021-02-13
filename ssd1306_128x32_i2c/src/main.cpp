/*******************************************************************************
 *
 * Display Text on ssd1306 128x64 i2c OLED
 *
 ******************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void write_to_display(char *);

void setup() {
    Serial.begin(115200);

    // uncomment for serial debugging
    //while (!Serial);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    // Clear buffer
    display.clearDisplay();
    display.display();

    Serial.println("START OLED DISPLAY...");
}

void loop() {
    // 20 characters max
    write_to_display("Hello,    World!   ");

    // ABCDEF won't be displayed
    write_to_display("12345678901234567890ABCDEF");
}

void write_to_display(char *msg) {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);

    //display.println(F(msg));
    for (int i=0; i<strlen(msg); i++) {
        display.printf("%c", F(msg[i]));
        display.display();
        delay(200);
    }

    // display for 2.5s minimum until the next one
    delay(2500);
}
