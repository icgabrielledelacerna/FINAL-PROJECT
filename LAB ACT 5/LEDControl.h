#ifndef LEDCONTROL_H
#define LEDCONTROL_H

// LED pin definitions
const int RED_PIN = 8;
const int GREEN_PIN = 9;
const int BLUE_PIN = 10;

// LED state variables
bool redState = false;
bool greenState = false;
bool blueState = false;

// Function to initialize LED pins
void initializeLEDs() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Turn all LEDs off initially
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  
  redState = false;
  greenState = false;
  blueState = false;
}

// Function to toggle red LED
void toggleRedLED() {
  redState = !redState;
  digitalWrite(RED_PIN, redState ? HIGH : LOW);
  Serial.print("Red LED: ");
  Serial.println(redState ? "ON" : "OFF");
}

// Function to toggle green LED
void toggleGreenLED() {
  greenState = !greenState;
  digitalWrite(GREEN_PIN, greenState ? HIGH : LOW);
  Serial.print("Green LED: ");
  Serial.println(greenState ? "ON" : "OFF");
}

// Function to toggle blue LED
void toggleBlueLED() {
  blueState = !blueState;
  digitalWrite(BLUE_PIN, blueState ? HIGH : LOW);
  Serial.print("Blue LED: ");
  Serial.println(blueState ? "ON" : "OFF");
}

void togglePurpleLED(){
  blueState = !blueState;
  digitalWrite(BLUE_PIN, blueState ? HIGH : LOW);
  Serial.print("Blue LED: ");
  Serial.println(blueState ? "ON" : "OFF");
  redState = !redState;
  digitalWrite(RED_PIN, redState ? HIGH : LOW);
  Serial.print("Red LED: ");
  Serial.println(redState ? "ON" : "OFF");
}

// Function to turn all LEDs on
void turnAllLEDsOn() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  redState = true;
  greenState = true;
  blueState = true;
  Serial.println("All LEDs: ON");
}

// Function to turn all LEDs off
void turnAllLEDsOff() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  redState = greenState = blueState = false;
  Serial.println("All LEDs: OFF");
}

// Function to process serial commands
void processCommand(char command) {
  // Convert to uppercase for case-insensitive comparison
  char upperCommand = toupper(command);
  
  switch (upperCommand) {
    case 'R':
      toggleRedLED();
      break;
    case 'G':
      toggleGreenLED();
      break;
    case 'B':
      toggleBlueLED();
      break;
    case 'A':
      turnAllLEDsOn();
      break;
    case 'O':
      turnAllLEDsOff();
      break;
    case 'P':
      togglePurpleLED();
      break;
    default:
      Serial.print("Error: Invalid command '");
      Serial.print(command);
      Serial.println("'");
      Serial.println("Valid commands: R/r, G/g, B/b, A/a, O/o");
      break;
  }
}

#endif

