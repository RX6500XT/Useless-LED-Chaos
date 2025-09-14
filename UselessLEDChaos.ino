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
