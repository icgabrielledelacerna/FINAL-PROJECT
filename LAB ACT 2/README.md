# Laboratory Activity 2: Working with Analog Signals

## 📖 Overview
This project builds upon the first activity by introducing **Analog Signals** and **Pulse Width Modulation (PWM)**. Instead of simply turning LEDs on and off, this circuit controls the *brightness* of the LEDs to create a fading effect, demonstrating how digital microcontrollers can simulate analog outputs.

## 🎯 Objectives
1. Discuss analog signals and their implementation in an Arduino circuit.
2. Understand analog-to-digital signal conversion concepts using PWM.
3. Optimize code using arrays and loops.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Components:** 5x LEDs, 5x Resistors (220Ω), Breadboard

## 🔌 Pin Configuration
*Note: Ensure these pins support PWM (marked with `~` on some boards, though 8 and 12 on Uno are standard digital. If fading is required on non-PWM pins, soft-PWM logic is used, otherwise, standard `analogWrite` requires PWM pins 3, 5, 6, 9, 10, 11).*

| LED | Pin | Feature |
| :--- | :--- | :--- |
| LED 1 | 12 | Digital/PWM* |
| LED 2 | 11 | PWM |
| LED 3 | 10 | PWM |
| LED 4 | 9 | PWM |
| LED 5 | 8 | Digital/PWM* |

## 💻 Code Explanation
* **`analogWrite(pin, value)`**: Used to write values between 0 (OFF) and 255 (Fully ON). This controls the duty cycle of the signal, effectively dimming the LED.
* **Arrays**: Instead of declaring individual integer variables for every pin, the code uses an array `int ledPins[] = {12, 11, 10, 9, 8};`.
* **`while()` Loop**: Used in `setup()` and `loop()` to iterate through the array, reducing code redundancy and improving readability.

## 🚀 How to Run
1.  Connect the circuit according to the pin definitions.
2.  Upload the code.
3.  The LEDs will perform the running sequence with varying brightness levels rather than a binary snap ON/OFF.
