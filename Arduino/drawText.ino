#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // pixels
#define SCREEN_HEIGHT 64 // pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Change 0x3C
}

void loop() {

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("Hello, World!");
    display.setCursor(40, 40);
    display.print(millis());
    display.display();9
}