#include <SoftwareSerial.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Constants
#define RXPIN 10
#define TXPIN 11
#define SCREEN_WIDTH 128 // pixels
#define SCREEN_HEIGHT 64 // pixels

#define MAX_STRING_LEN 40

SoftwareSerial mySerial(RXPIN, TXPIN); //RX, TX
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

char inputString[MAX_STRING_LEN]; // String we will receive
byte strLen = 0; // Current length of string


void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Change 0x3C
    Serial.begin(9600);
    mySerial.begin(9600);
}

void loop() {
    if(processSerial()) {
        // Received a complete string, echo it back.
        Serial.println(inputString);
        drawReceivedText();
        clearInputText();
    }
}

void clearInputText() {
    inputString[0] = '\0';
    strLen = 0;
}

// checks if there is any more data to be processed and gathers it
bool processSerial() {
    while(Serial.isAvailable()) {
        char inputChar = (char)Serial.read();
        if(inputChar == '\n' || inputChar == '\r') // basically, end of line.
            return true;
        // check if we have room to add more characters, and add if so.
        if(strLen < (MAX_STRING_LEN - 1)) {
            inputString[strLen++] = inputChar;
            inputString[strLen] = '\0';
        }
    }
    return false;
}

void drawReceivedText() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(inputString);
    display.display();
    delay(1000); // after displaying the text, whole system waits for 1000 ms.
    display.clearDisplay();
}