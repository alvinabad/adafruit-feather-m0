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

void write_text(char *msg) {
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);

    display.println(F(msg));
    display.display();

    delay(2500);
}

void display_message() {
    // 10 characters max per line. 2 lines max. 
    write_text("Hello,    World!");
    write_text("...");
}

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
    display_message();
}
