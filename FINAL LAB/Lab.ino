const int BUTTON = 4;
const int GROUP = 6;   // change to your group number

bool lastState = HIGH;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool currentState = digitalRead(BUTTON);

  // Detect button press (HIGH → LOW)
  if (lastState == HIGH && currentState == LOW) {
    Serial.println(GROUP);     // send group number once
    delay(200);                // simple debounce
  }

  lastState = currentState;
}
