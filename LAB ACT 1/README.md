# Laboratory Activity 1: Working with Digital Signals

## 📖 Overview
This project demonstrates the fundamental concepts of digital output using an Arduino. The circuit implements a "Running Light" sequence where 5 LEDs turn on and off sequentially. This activity serves as an introduction to pin manipulation and timing control using `digitalWrite()` and `delay()`.

## 🎯 Objectives
1. Review Arduino as a device for IoT systems implementation.
2. Discuss digital signals and their implementation in an Arduino circuit.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno (or compatible)
* **Components:**
    * 5x LEDs
    * 5x Resistors (220Ω)
    * Breadboard & Jumper Wires

## 🔌 Pin Configuration
| Component | Arduino Pin | Mode |
| :--- | :--- | :--- |
| **LED 1** | Pin 12 | OUTPUT |
| **LED 2** | Pin 11 | OUTPUT |
| **LED 3** | Pin 10 | OUTPUT |
| **LED 4** | Pin 9 | OUTPUT |
| **LED 5** | Pin 8 | OUTPUT |

## 💻 Code Explanation
The firmware utilizes standard digital I/O functions:
* **`setup()`**: Configures Pins 8 through 12 as `OUTPUT` to allow voltage to be sent to the LEDs.
* **`loop()`**: Executes the running light logic:
    1.  Turns LEDs ON one by one from Pin 12 down to Pin 8.
    2.  Turns LEDs OFF one by one in the same order.
    3.  Uses `delay(1000)` (1 second) between each state change to create the visual sequence.

## 🚀 How to Run
1.  Connect the LEDs to pins 8-12 as shown in the pin configuration.
2.  Upload the `.ino` sketch to your Arduino board.
3.  Observe the LEDs lighting up in a cascading sequence.
