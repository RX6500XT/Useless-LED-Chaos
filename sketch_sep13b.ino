/*
This Arduino code is released into the PUBLIC DOMAIN under the Unlicense:
https://unlicense.org/

Anyone can copy, modify, publish, use, compile, sell, or distribute this software,
in source or binary form, for any purpose, commercial or non-commercial.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
*/

int leds[] = {2, 3, 4}; // only 3 pins now
int numLEDs = 3;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < numLEDs; i++){
    pinMode(leds[i], OUTPUT);
  }
  pinMode(13, OUTPUT); // built-in LED
}

void loop() {
  int r = random(0, numLEDs);       // pick a random LED from 2,3,4
  int t = random(50, 500);          // random blink time in ms
  digitalWrite(leds[r], HIGH);
  digitalWrite(13, random(0,2));    // built-in LED doing chaotic stuff
  delay(t);
  digitalWrite(leds[r], LOW);
  Serial.println("I am useless ;)"); // pointless chaos messages
}
