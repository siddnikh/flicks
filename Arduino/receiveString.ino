#include <SoftwareSerial.h>

// Constants
#define RXPIN 10
#define TXPIN 11

#define MAX_STRING_LEN 40

SoftwareSerial mySerial(RXPIN, TXPIN); //RX, TX

char inputString[MAX_STRING_LEN]; // String we will receive
byte strLen = 0; // Current length of string


void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

void loop() {

    if(processSerial()) {
        // Received a complete string, echo it back.
        Serial.println(inputString);
        inputString[0] = '\0'; // emptying the array
        strLen = 0;
    }
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