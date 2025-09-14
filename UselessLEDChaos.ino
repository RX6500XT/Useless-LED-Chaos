/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org/>
/*
Chaotic LED Blinker
Non-blocking version using millis()
Still proudly useless 😎
*/

int leds[] = {2, 3, 4};
int numLEDs = 3;

unsigned long prevMillis = 0;
unsigned long interval = 0;
int currentLED = 0;
bool ledState = LOW;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < numLEDs; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(13, OUTPUT);
  
  // pick initial random victim LED
  currentLED = random(0, numLEDs);
  interval = random(50, 500);
  prevMillis = millis();
}

void loop() {
  unsigned long now = millis();

  // check if it's time to toggle chaos
  if (now - prevMillis >= interval) {
    prevMillis = now;

    // toggle current LED
    ledState = !ledState;
    digitalWrite(leds[currentLED], ledState);

    // built-in LED flips a coin every cycle
    digitalWrite(13, random(0, 2));

    if (!ledState) {
      // if we just turned it off, pick a new random LED + new chaos timing
      currentLED = random(0, numLEDs);
      interval = random(50, 500);
      Serial.println("Still useless, but async 😎");
    }
  }
}
