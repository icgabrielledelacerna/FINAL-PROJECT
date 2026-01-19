# Laboratory Activity 5: Receiving Serial Connection from Python

## 📖 Overview
This project shifts control from the Arduino Serial Monitor to a custom **Python Script**. It demonstrates how a high-level programming language (Python) can control hardware components (LEDs) via USB serial communication.

## 🎯 Objectives
1. Utilize Python (`pyserial`) for serial communication.
2. Implement a Command Line Interface (CLI) in Python to control hardware.
3. Handle string manipulation and case insensitivity in both Python and C++.

## 🛠️ Tech Stack
* **Hardware:** Arduino Uno, RGB LEDs (Red, Green, Blue)
* **Software:** Python 3.x, `pyserial` library

## 🔌 Pin Configuration
| LED Color | Pin |
| :--- | :--- |
| **Red** | 8 |
| **Green** | 9 |
| **Blue** | 10 |

## 💻 Code Explanation
### Arduino (Firmware)
* Listens for single characters: `R`, `G`, `B`, `A`, `O`.
* Based on the character received, it toggles the specific LED state.

### Python (Client)
* **Loop:** Runs a `while True` loop to keep the program alive.
* **Menu:** Displays options for toggling LEDs.
* **Serial Write:** Sends the corresponding character encoded as bytes (e.g., `ser.write(b'r')`) to the Arduino.
* **Exit:** Terminates the script when `X` is pressed.

## 🚀 How to Run
1.  Upload the Arduino sketch and **close the Arduino IDE Serial Monitor** (to free the port).
2.  Run the Python script: `python main.py`.
3.  Select an option from the menu to toggle the LEDs.
