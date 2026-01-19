# Laboratory Activity 1: Working with Digital Signals

## 📖 Introduction & Overview
This is the foundational activity for the IoT course. It introduces the concept of **Digital Output**—sending binary signals (HIGH/LOW) from the microcontroller to physical components. We implement a "Sequential Running Light" to demonstrate how to control timing and pin states programmatically.

## 🎯 Objectives
1. Review Arduino as a device for IoT systems implementation.
2. Discuss digital signals and their implementation in an Arduino circuit.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Components:** 5x LEDs (Pins 8-12), 5x Resistors (220Ω), Breadboard

## 💻 Code Logic
* **`digitalWrite()`**: The core function used to switch voltage ON (5V) and OFF (0V).
* **Sequential Loop**: A loop structure turns LED 12 ON, waits 1 second, turns it OFF, and moves to LED 11, creating a "running" visual effect.

## 🚀 How to Run
1. Connect 5 LEDs to pins 8 through 12.
2. Upload the firmware.
3. The LEDs will light up one by one in descending order.

---

# Laboratory Activity 2: Working with Analog Signals

## 📖 Introduction & Overview
While Lab 1 focused on turning things ON or OFF, this activity introduces **Analog Signal Simulation** using Pulse Width Modulation (PWM). By rapidly toggling pins, we simulate varying voltages to create a "breathing" or fading effect on the LEDs, rather than a harsh snap.

## 🎯 Objectives
1. Discuss analog signals and PWM (Pulse Width Modulation).
2. Understand `analogWrite()` vs `digitalWrite()`.
3. Optimize code using **Arrays** and **While Loops**.

## 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Components:** 5x LEDs (Connected to PWM pins: 3, 5, 6, 9, 10, or 11)

## 💻 Code Logic
* **PWM Control**: Uses `analogWrite(pin, value)` where value is between 0 (Off) and 255 (Max Brightness).
* **Arrays**: Defines `int ledPins[] = { ... }` to manage pin numbers efficiently, replacing repetitive code lines from Lab 1.

## 🚀 How to Run
1. Move your LEDs to PWM-supported pins (marked with `~` on the board).
2. Upload the firmware.
3. Observe the smooth fading transition of the lights.

---

# Laboratory Activity 3: Working with Sensors

## 📖 Introduction & Overview
This activity shifts focus from *Output* (LEDs) to *Input* (Sensors). We build a **Fire Sensor Simulation** that reads real-world data—Temperature and Light Intensity. The system makes decisions based on these readings to trigger an alarm, introducing the concept of conditional logic in embedded systems.

## 🎯 Objectives
1. Integrate Thermistors (Temperature) and Photoresistors (Light).
2. Convert Analog Input (0-1023) to readable units (Celsius).
3. Implement compound logic (AND conditions) for safety alarms.

## 🛠️ Hardware Requirements
* **Sensors:** Thermistor (A0), Photoresistor (A2)
* **Output:** Red LED (Pin 12), Optional Buzzer
* **Logic:** Fire triggers if Temp > 50°C **AND** Light > 220.

## 💻 Code Logic
* **`analogRead()`**: Reads voltage changes from the voltage divider circuits.
* **Alert System**: The LED only blinks if *both* sensor thresholds are crossed simultaneously.

## 🚀 How to Run
1. Wire the sensors with 10kΩ pull-down/up resistors.
2. Upload the code.
3. Apply heat and light to the sensors to trigger the alarm.

---

# Laboratory Activity 4: Arduino Serial Connection

## 📖 Introduction & Overview
This project upgrades the "Fire Sensor" from Lab 3 into a **Smart Alarm System**. It introduces **Serial Communication**, allowing the Arduino to talk to a computer. Crucially, it implements "Latching Logic"—once the alarm trips, it stays ON until a human manually types "STOP" in the computer terminal.

## 🎯 Objectives
1. Implement UART Serial Communication.
2. Create "Latching" behavior (Alarm state persists after trigger is gone).
3. Parse String commands from the Serial Monitor (Case-insensitive).

## 🛠️ Hardware Requirements
* Same sensor setup as Lab 3.
* **Pin 8**: Status LED.

## 💻 Code Logic
* **Latching**: A boolean `isAlarmActive` becomes `true` when thresholds are met. It *remains* true even if the fire stops.
* **Serial Command**: The loop listens for the string "stop" (or "STOP") to reset `isAlarmActive` to `false`.

## 🚀 How to Run
1. Trigger the sensor. The LED will start blinking indefinitely.
2. Open Serial Monitor.
3. Type `stop` to silence the alarm.

---

# Midterm Project: Smart Lighting System

## 📖 Introduction & Overview
The Midterm project combines all previous concepts into a **Dual-Mode Control System**. It simulates a smart street light that can operate automatically based on environment (Cloudy/Sunny) or be manually overridden by a user via Serial commands. It tests the ability to manage complex state machines.

## 🎯 Features
* **Automatic Mode**: Adjusts thresholds dynamically based on preset "Weather" profiles.
* **Manual Mode**: Allows the user to set specific percentage thresholds via command line.
* **Feedback Loop**: Continuously reports status (Light %, Active Mode) to the Serial Monitor.

## 💻 Command Reference
| Command | Action |
| :--- | :--- |
| `MODE AUTO` | Switch to automatic environmental sensing. |
| `MODE MANUAL` | Switch to user-defined thresholds. |
| `SET LOW 20` | Set low-light trigger to 20% (Manual only). |

## 🚀 How to Run
1. Upload the code and open Serial Monitor.
2. Watch the system react to light changes on the Photoresistor.
3. Type `MODE MANUAL` to take control and set your own limits.

---

# Laboratory Activity 5: Receiving Serial Connection from Python

## 📖 Introduction & Overview
This marks the transition to **Hybrid IoT**. Instead of using the Arduino's built-in Serial Monitor, we write a custom **Python Script** to act as the controller. This demonstrates how high-level software (running on a PC) can control low-level hardware (LEDs) via USB.

## 🎯 Objectives
1. Use the Python `pyserial` library.
2. Create a Python CLI (Command Line Interface) menu.
3. Control RGB LEDs via keyboard inputs.

## 🛠️ Tech Stack
* **Arduino:** Listens for characters 'R', 'G', 'B', 'A', 'O'.
* **Python:** Displays a menu and sends bytes to the COM port.

## 🚀 How to Run
1. Close Arduino IDE (to free the port).
2. Run `python main.py`.
3. Press 'R' on your keyboard to toggle the Red LED on the breadboard.

---

# Laboratory Activity 6: Bidirectional Control (Arduino <-> Python)

## 📖 Introduction & Overview
In this "Software-in-the-Loop" activity, the Arduino loses its autonomy. When you press a button, the Arduino *cannot* turn on the LED directly. It must send a signal to Python, which processes the request and sends a *return command* back to Arduino to light the LED. This simulates a server-client architecture.

## 🎯 Objectives
1. Implement Full-Duplex (Two-way) communication.
2. Ensure low latency (< 1 second response).
3. Handle input/output logic exclusively on the Python side.

## 💻 Data Flow
1. **Button Press** (Arduino) → Sends 'R' to PC.
2. **Logic Processing** (Python) → Receives 'R', decides to turn on LED 1.
3. **Command Return** (Python) → Sends '1' to Arduino.
4. **Action** (Arduino) → Receives '1', turns on Red LED.

## 🚀 How to Run
1. Upload firmware to Arduino.
2. Run the Python script.
3. Press a button and watch the signal travel to the PC and back.

---

# Laboratory Activity 7: Controlling Arduino using FastAPI

## 📖 Introduction & Overview
This project replaces the Python command-line interface with a **Web API**. By using **FastAPI**, we create a web server that allows the Arduino to be controlled via HTTP requests (URLs). This is the foundation of modern IoT, where devices are controlled over the network.

## 🎯 Objectives
1. Build a REST API using `FastAPI`.
2. Trigger hardware actions via Web Browser or Postman.
3. Define endpoints like `/led/on` and `/led/red`.

## 🛠️ Tech Stack
* **Framework:** FastAPI + Uvicorn
* **Communication:** HTTP (Frontend) → Serial (Backend)

## 🚀 How to Run
1. Start the server: `uvicorn main:app --reload`.
2. Open a browser to `http://localhost:8000/led/red`.
3. The Red LED on your circuit will light up.

---

# Final Project: Serial API Bridge

## 📖 Introduction & Overview
The Capstone project integrates all course concepts. It requires building a **Physical-to-Digital Bridge**. A physical button press on the Arduino triggers a remote network API call via a Python Gateway. This mimics a real-world "Smart Dash Button" (like an Amazon Dash button).

## 🎯 System Architecture
The system is composed of three distinct layers:
1.  **The Trigger (Arduino):** Detects a physical button press, debounces the signal to prevent errors, and sends a Group ID to the computer.
2.  **The Gateway (Python):** A non-terminating script that listens to the serial port. It captures the Group ID and constructs an HTTP request.
3.  **The Cloud (API):** The Python script sends a POST request to `/led/group/<id>/toggle` to execute the remote action.

## 🛠️ Requirements
* **Debouncing:** Arduino must ensure one button press equals exactly one signal.
* **Non-Blocking:** Python client runs continuously.
* **Feedback:** Terminal must show the API response code (200 OK / 404 Error).

## 🚀 How to Run
1.  **Config:** Set the `API_URL` in your Python script.
2.  **Launch:** Run the Python gateway.
3.  **Test:** Press the button on the Arduino.
4.  **Verify:** Check the Python terminal to see the HTTP response from the server.
