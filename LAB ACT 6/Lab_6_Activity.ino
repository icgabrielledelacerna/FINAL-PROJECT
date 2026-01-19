#include "MyFunctions.h"

// Track last button states so we only send R/G/B ONCE per press
int lastButton1State = HIGH;
int lastButton2State = HIGH;
int lastButton3State = HIGH;

// Track LED states for toggle behavior on inbound serial
bool redLedOn   = false;
bool greenLedOn = false;
bool blueLedOn  = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Configure pins
  setupPins();
}

// Configure all pins
void setupPins() {
  // LEDs as outputs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

  // Buttons with internal pull‑ups
  // PRESSED  = LOW
  // RELEASED = HIGH
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);

  // Start with all LEDs OFF
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
}

void loop() {
  // 1) OUTBOUND: button presses → send R/G/B ONCE over serial
  handleOutboundButtons();

  // 2) INBOUND: serial monitor / Python sends "1"/"2"/"3" → toggle LEDs
  handleInboundSerial();

  // Small delay keeps response well under 1 second and avoids bouncing spam
  delay(20);
}

// OUTBOUND SIGNALS:
// - Button 1 prints 'R' ONCE when pressed
// - Button 2 prints 'G' ONCE when pressed
// - Button 3 prints 'B' ONCE when pressed
// No LED actions here: ONLY serial output.
void handleOutboundButtons() {
  int button1State = digitalRead(BUTTON1_PIN);
  int button2State = digitalRead(BUTTON2_PIN);
  int button3State = digitalRead(BUTTON3_PIN);

  // Detect press edge: HIGH (released) -> LOW (pressed)
  if (lastButton1State == HIGH && button1State == LOW) {
    Serial.println('R');
  }

  if (lastButton2State == HIGH && button2State == LOW) {
    Serial.println('G');
  }

  if (lastButton3State == HIGH && button3State == LOW) {
    Serial.println('B');
  }

  // Update last states
  lastButton1State = button1State;
  lastButton2State = button2State;
  lastButton3State = button3State;
}

// INBOUND SIGNALS (from Serial Monitor OR from Python):
// - "1" → toggle RED LED
// - "2" → toggle GREEN LED
// - "3" → toggle BLUE LED
// - "0" → turn ALL LEDs OFF (used when Python exits)
// Case‑insensitive: also accept 'r'/'R', 'g'/'G', 'b'/'B', 'o'/'O'.
// Rule: we buffer characters until newline, then:
//   - Count non‑whitespace chars (not ' ', '\r', '\n')
//   - If count != 1 → ignore the whole line
//   - If count == 1 → process that single character as the command
void handleInboundSerial() {
  static char  inputBuf[32];
  static uint8_t idx = 0;

  while (Serial.available() > 0) {
    char c = Serial.read();

    // Immediate "all off" command: handle even if newline never arrives
    if (c == '0' || c == 'O') {
      redLedOn   = false;
      greenLedOn = false;
      blueLedOn  = false;
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, LOW);
      // Reset buffer because this command consumed the whole intent
      idx        = 0;
      inputBuf[0] = '\0';
      continue;
    }

    // On newline/CR: process the buffered line
    if (c == '\n' || c == '\r') {
      int  nonWhitespaceCount = 0;
      char command            = '\0';

      for (uint8_t i = 0; i < idx; i++) {
        char ch = inputBuf[i];
        if (ch != ' ' && ch != '\n' && ch != '\r') {
          nonWhitespaceCount++;
          command = ch;  // remember last non‑whitespace character
        }
      }

      // Reset buffer for next line
      idx        = 0;
      inputBuf[0] = '\0';

      // Invalid if zero or more than one non‑whitespace characters
      if (nonWhitespaceCount != 1) {
        return;
      }

      // Exactly one non‑whitespace character → process it
      char cmd = command;

      // Normalize letters to upper‑case for easier matching
      if (cmd >= 'a' && cmd <= 'z') {
        cmd = cmd - 'a' + 'A';
      }

      // ALL OFF: "0" or 'O'
      if (cmd == '0' || cmd == 'O') {
        redLedOn   = false;
        greenLedOn = false;
        blueLedOn  = false;
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
      }
      // RED: "1" or 'R'
      else if (cmd == '1' || cmd == 'R') {
        redLedOn = !redLedOn;
        digitalWrite(RED_LED_PIN, redLedOn ? HIGH : LOW);
      }
      // GREEN: "2" or 'G'
      else if (cmd == '2' || cmd == 'G') {
        greenLedOn = !greenLedOn;
        digitalWrite(GREEN_LED_PIN, greenLedOn ? HIGH : LOW);
      }
      // BLUE: "3" or 'B'
      else if (cmd == '3' || cmd == 'B') {
        blueLedOn = !blueLedOn;
        digitalWrite(BLUE_LED_PIN, blueLedOn ? HIGH : LOW);
      }
      // Any other single characters are ignored
    } else {
      // Accumulate into buffer, up to max‑1 to keep space for '\0'
      if (idx < sizeof(inputBuf) - 1) {
        inputBuf[idx++] = c;
        inputBuf[idx]   = '\0';
      }
    }
  }
}


