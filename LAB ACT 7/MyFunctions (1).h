// Header file for Lab 5 Activity
// Defines pin mappings and function prototypes

#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

// LED pins
const int RED_LED_PIN   = 7;
const int GREEN_LED_PIN = 6;
const int BLUE_LED_PIN  = 5;

// Button pins
const int BUTTON1_PIN   = 12;
const int BUTTON2_PIN   = 11;
const int BUTTON3_PIN   = 10;

// Function prototypes
void setupPins();
void handleOutboundButtons();
void handleInboundSerial();

#endif


