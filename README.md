# 🚦 Lab 1: Working with Digital Signals

![Status](https://img.shields.io/badge/Status-Completed-success)
![Hardware](https://img.shields.io/badge/Hardware-Arduino_Uno-blue)
![Focus](https://img.shields.io/badge/Focus-Digital_I%2FO-yellow)

## 📖 Overview
**Welcome to the foundation of IoT.**
This laboratory activity explores the core concept of **Digital Output**—the ability of a microcontroller to send binary signals (HIGH/LOW) to control physical actuators. We implement a sequential "Running Light" circuit, demonstrating precise timing control and pin manipulation.

## 🧠 Skills Unlocked
* **Circuit Prototyping:** Connecting active components (LEDs) with current-limiting resistors.
* **Digital Logic:** Understanding the binary nature of `digitalWrite()`.
* **Timing Control:** Manipulating program flow using `delay()` and loops.

## 🛠️ Hardware Stack
| Component | Quantity | Description |
| :--- | :---: | :--- |
| **Arduino Uno** | 1 | Microcontroller Unit |
| **LEDs** | 5 | Red/Green/Blue (Generic) |
| **Resistors** | 5 | 220Ω (Current Limiting) |
| **Breadboard** | 1 | Prototyping Base |

## 🔌 Circuit Implementation
* **Pins Used:** Digital Pins 8 through 12.
* **Logic:** The firmware iterates through the pins, setting them HIGH one by one to create a cascading light effect.

## 🚀 How to Run
1.  **Assemble:** Wire the 5 LEDs to pins 8-12 with resistors.
2.  **Flash:** Upload the `.ino` file to the Arduino.
3.  **Observe:** The LEDs will sequence from Pin 12 down to Pin 8.

---

# 📉 Lab 2: Working with Analog Signals

![Status](https://img.shields.io/badge/Status-Completed-success)
![Focus](https://img.shields.io/badge/Focus-PWM_%26_Analog-orange)

## 📖 Overview
**Beyond Binary.**
While Lab 1 was strictly ON/OFF, this activity introduces the nuance of **Analog Signal Simulation**. By utilizing **Pulse Width Modulation (PWM)**, we trick the eye into seeing varying brightness levels. This mimics "breathing" LEDs, a common feature in modern smart devices.

## 🧠 Skills Unlocked
* **PWM Mastery:** Using `analogWrite()` to simulate voltages between 0V and 5V.
* **Code Optimization:** replacing repetitive lines with **Arrays** and **While Loops**.
* **Signal Conversion:** Understanding how digital pulses create analog effects.

## 💻 Tech Highlights
```cpp
// We use arrays to manage pins efficiently
int ledPins[] = {12, 11, 10, 9, 8}; 
// PWM creates the fading effect
analogWrite(ledPins[i], brightness);
