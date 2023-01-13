# flicks

Smart glasses project made for VinHack '23

Primary Tech Stack: Native for Android app 

IoT Stack: HC-05 bluetooth module, Arduino Pro Mini , FTDI Module , 0.96 Oled Display , Retrowatch Operating System.


# HOW THE IOT DEVICES ARE CONNECTED AND FUNCTIONING

All elements of the IOT stack are connected to each other using bread board and jumper wires which are soldered together with precision for strong conectivity between the elements.

The Arduino pro mini which has a Atmega 328P chip works as the brain of the IOT system, HC-05 Module is connecting the app to the phone using Bluetooth, which helps in sending over call and text notifications to the Arduino which in turns display it using the Oled display. The FTDI module is used to connect the Arduino to the Main system/PC, we also use FTDI to send data over from the Arduino IDE to Arduino.




