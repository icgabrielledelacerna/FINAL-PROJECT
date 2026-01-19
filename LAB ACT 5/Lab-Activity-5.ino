#include "LEDControl.h"

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize LED pins
  initializeLEDs();
  
  // Wait for serial connection to be established
  while (!Serial) {
     // Wait for serial port to connect
  }
  
  Serial.println("Arduino LED Control Ready");
  Serial.println("Commands: R/r (Red), G/g (Green), B/b (Blue), A/a (All ON), O/o (All OFF)");
}

void loop() {
  if (Serial.available() > 0) {
    // Small delay to ensure all characters have arrived
    delay(10);
    
    // Variables to track input
    int nonWhitespaceCount = 0;
    char command = '\0';
    
    // Read all characters and count non-whitespace ones
    while (Serial.available() > 0) {
      char c = Serial.read();
      
      // Count non-whitespace characters
      if (c != '\n' && c != '\r' && c != ' ') {
        nonWhitespaceCount++;
        command = c; // Store the last non-whitespace character
      }
    }
    
    // If more than 1 non-whitespace character, it's invalid input
    if (nonWhitespaceCount > 1) {
      // Print error message
      //Serial.println("Error: Invalid command");
      //Serial.println("Valid commands: R/r, G/g, B/b, A/a, O/o");
      return; // Don't process any characters
    }
    
    // If exactly one non-whitespace character, process it
    if (nonWhitespaceCount == 1) {
      processCommand(command);
    }
    // If no non-whitespace characters, just ignore (whitespace only)
  }
}

