# Laboratory Activity 6: Bidirectional Control (Arduino <-> Python)

## 📖 Overview
This activity implements a "Software-in-the-Loop" system. Unlike previous labs where the Arduino controlled LEDs directly, here the Arduino sends a button press to Python, Python processes the logic, and then Python sends a command *back* to Arduino to toggle the LED. This simulates a server-client architecture.

## 🎯 Objectives
1. Implement full-duplex (two-way) serial communication.
2. Create a system where logic is offloaded from the microcontroller to the PC.
3. Manage latency to ensure response time is < 1 second.

## 🔌 Pin Configuration
| Component | Pin |
| :--- | :--- |
| **Red LED** | 7 |
| **Green LED** | 6 |
| **Blue LED** | 5 |
| **Button 1** | 12 |
| **Button 2** | 11 |
| **Button 3** | 10 |

## 💻 Code Explanation
### 1. Outbound (Arduino -> Python)
When a button is pressed, Arduino sends a character (`R`, `G`, or `B`) to the Serial port. It does **not** turn on the LED locally.

### 2. Processing (Python)
The Python script listens for these characters. When it receives `R`, it decides the action (e.g., "Turn Red LED On") and sends a numeric command (`1`) back to the Arduino.

### 3. Inbound (Python -> Arduino)
The Arduino waits for the numeric command (`1`, `2`, or `3`) and activates the corresponding LED on pins 7, 6, or 5.

## 🚀 How to Run
1.  Upload the Arduino firmware.
2.  Run the Python script.
3.  Press a physical button on the breadboard.
4.  Observe the signal travel to the PC and back to light up the LED.
