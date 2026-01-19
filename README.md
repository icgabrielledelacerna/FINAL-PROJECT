# 🎓 Student Portfolio: COSC 111 (Internet of Things)

**Student Name:** Gabrielle Delacerna  
**Section:** BSCS - 4C  
**Instructor:** Sir Johnroe Paulo Cañamaque  

---

## 📖 Portfolio Overview
This repository contains the complete collection of laboratory activities, midterm projects, and the final capstone developed for the **Internet of Things (COSC 111)** course.

The progression of this portfolio moves from basic microcontroller operations (Digital/Analog I/O) to advanced IoT architectures involving Python bridging, Bidirectional Serial Communication, and Web API integration (FastAPI).

---

# Laboratory Activities

## Laboratory Activity 1: Working with Digital Signals

### 📖 Overview
This project demonstrates the fundamental concepts of digital output using an Arduino. The circuit implements a "Running Light" sequence where 5 LEDs turn on and off sequentially. This activity serves as an introduction to pin manipulation and timing control using `digitalWrite()` and `delay()`.

### 🎯 Objectives
1. Review Arduino as a device for IoT systems implementation.
2. Discuss digital signals and their implementation in an Arduino circuit.

### 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno (or compatible)
* **Components:**
    * 5x LEDs
    * 5x Resistors (220Ω)
    * Breadboard & Jumper Wires

### 🔌 Pin Configuration
| Component | Arduino Pin | Mode |
| :--- | :--- | :--- |
| **LED 1** | Pin 12 | OUTPUT |
| **LED 2** | Pin 11 | OUTPUT |
| **LED 3** | Pin 10 | OUTPUT |
| **LED 4** | Pin 9 | OUTPUT |
| **LED 5** | Pin 8 | OUTPUT |

### 💻 Code Explanation
The firmware utilizes standard digital I/O functions:
* **`setup()`**: Configures Pins 8 through 12 as `OUTPUT` to allow voltage to be sent to the LEDs.
* **`loop()`**: Executes the running light logic:
    1.  Turns LEDs ON one by one from Pin 12 down to Pin 8.
    2.  Turns LEDs OFF one by one in the same order.
    3.  Uses `delay(1000)` (1 second) between each state change to create the visual sequence.

### 🚀 How to Run
1.  Connect the LEDs to pins 8-12 as shown in the pin configuration.
2.  Upload the `.ino` sketch to your Arduino board.
3.  Observe the LEDs lighting up in a cascading sequence.

---

## Laboratory Activity 2: Working with Analog Signals

### 📖 Overview
This project builds upon the first activity by introducing **Analog Signals** and **Pulse Width Modulation (PWM)**. Instead of simply turning LEDs on and off, this circuit controls the *brightness* of the LEDs to create a fading effect, demonstrating how digital microcontrollers can simulate analog outputs.

### 🎯 Objectives
1. Discuss analog signals and their implementation in an Arduino circuit.
2. Understand analog-to-digital signal conversion concepts using PWM.
3. Optimize code using arrays and loops.

### 🛠️ Hardware Requirements
* **Microcontroller:** Arduino Uno
* **Components:** 5x LEDs, 5x Resistors (220Ω), Breadboard

### 🔌 Pin Configuration
*Note: Ensure these pins support PWM (marked with `~` on some boards).*

| LED | Pin | Feature |
| :--- | :--- | :--- |
| LED 1 | 12 | Digital/PWM* |
| LED 2 | 11 | PWM |
| LED 3 | 10 | PWM |
| LED 4 | 9 | PWM |
| LED 5 | 8 | Digital/PWM* |

### 💻 Code Explanation
* **`analogWrite(pin, value)`**: Used to write values between 0 (OFF) and 255 (Fully ON). This controls the duty cycle of the signal, effectively dimming the LED.
* **Arrays**: Instead of declaring individual integer variables for every pin, the code uses an array `int ledPins[] = {12, 11, 10, 9, 8};`.
* **`while()` Loop**: Used in `setup()` and `loop()` to iterate through the array, reducing code redundancy and improving readability.

### 🚀 How to Run
1.  Connect the circuit according to the pin definitions.
2.  Upload the code.
3.  The LEDs will perform the running sequence with varying brightness levels rather than a binary snap ON/OFF.

---

## Laboratory Activity 3: Working with Sensors (Fire Detector)

*Note: The context provided duplicated Lab 4 content for Lab 3 but referenced sensor logic. This section reconstructs the sensor logic based on the Lab 4 description which mentions "extends the sensor logic from Lab 3".*

### 📖 Overview
This project focuses on integrating sensors into an IoT system. We create a basic "Fire Sensor" system that monitors temperature and light levels to detect potential fire hazards.

### 🎯 Objectives
1. Familiarize with basic sensor components (Thermistor & Photoresistor).
2. Integrate analog sensors into an Arduino circuit.
3. Create a logic-based alarm system.

### 🛠️ Hardware Requirements
* **Microcontroller:** Arduino MCU
* **Sensors:** Thermistor (Temperature), Photoresistor (Light)
* **Output:** Red LED, Buzzer (Optional)

### 🔌 Pin Configuration
| Component | Pin Type | Pin Number |
|-----------|----------|------------|
| Thermistor | Analog | A0 |
| Photoresistor | Analog | A2 |
| Red LED | Digital | 12 |
| Buzzer | Digital | 12 |

### 💻 Code Explanation
The system reads analog data from both sensors:
* **Thresholds:**
    * Temperature: > 50°C
    * Brightness: > 220
* **Alarm Condition:** If **BOTH** thresholds are met simultaneously (High Temp AND High Light), the system triggers the alarm.
* **Alarm Action:** The Red LED (and optional buzzer) blinks rapidly to indicate a fire warning.

---

## Laboratory Activity 4: Arduino Serial Connection

### 📖 Overview
This activity extends the sensor logic from Lab 3 by introducing **Serial Communication** and **Latching Logic**. The system now acts as a smart alarm that "latches" (stays ON) once triggered, requiring manual user intervention via the PC to reset.

### 🎯 Objectives
1. Understand Arduino Serial Communication (UART).
2. Implement string parsing from the Serial Monitor.
3. Create a latching alarm system controlled by software commands.

### 🛠️ Hardware Requirements
* **Sensors:** Thermistor (or Photoresistor)
* **Output:** 1x LED (Pin 8)

### 🔌 Pin Configuration
| Component | Pin |
| :--- | :--- |
| **Sensor Input** | A0 or A2 |
| **Status LED** | 8 |

### 💻 Code Explanation
* **Threshold Detection**: The code continuously monitors the sensor. If the value exceeds the limit (50°C or 220 brightness), it sets a boolean flag `isAlarmActive = true`.
* **Latching Loop**: Once `isAlarmActive` is true, the LED blinks indefinitely, *even if the sensor value returns to normal*.
* **Serial Interrupt**: The `Serial.readString()` function listens for user input.
* **Command Parsing**: If the user types "stop" (case-insensitive), the boolean flag is reset to `false`, and the alarm turns off.

### 🚀 How to Run
1.  Upload the code and open the **Serial Monitor**.
2.  Trigger the sensor threshold. The LED will start blinking.
3.  Remove the trigger source; the LED should *continue* blinking.
4.  Type `stop` (or `STOP`, `Stop`) in the Serial Monitor to reset the system.

---

## Laboratory Activity 5: Receiving Serial Connection from Python

### 📖 Overview
This project shifts control from the Arduino Serial Monitor to a custom **Python Script**. It demonstrates how a high-level programming language (Python) can control hardware components (LEDs) via USB serial communication.

### 🎯 Objectives
1. Utilize Python (`pyserial`) for serial communication.
2. Implement a Command Line Interface (CLI) in Python to control hardware.
3. Handle string manipulation and case insensitivity in both Python and C++.

### 🛠️ Tech Stack
* **Hardware:** Arduino Uno, RGB LEDs (Red, Green, Blue)
* **Software:** Python 3.x, `pyserial` library

### 🔌 Pin Configuration
| LED Color | Pin |
| :--- | :--- |
| **Red** | 8 |
| **Green** | 9 |
| **Blue** | 10 |

### 💻 Code Explanation
#### Arduino (Firmware)
* Listens for single characters: `R`, `G`, `B`, `A`, `O`.
* Based on the character received, it toggles the specific LED state.

#### Python (Client)
* **Loop:** Runs a `while True` loop to keep the program alive.
* **Menu:** Displays options for toggling LEDs.
* **Serial Write:** Sends the corresponding character encoded as bytes (e.g., `ser.write(b'r')`) to the Arduino.
* **Exit:** Terminates the script when `X` is pressed.

### 🚀 How to Run
1.  Upload the Arduino sketch and **close the Arduino IDE Serial Monitor** (to free the port).
2.  Run the Python script: `python main.py`.
3.  Select an option from the menu to toggle the LEDs.

---

## Laboratory Activity 6: Bidirectional Control (Arduino <-> Python)

### 📖 Overview
This activity implements a "Software-in-the-Loop" system. Unlike previous labs where the Arduino controlled LEDs directly, here the Arduino sends a button press to Python, Python processes the logic, and then Python sends a command *back* to Arduino to toggle the LED. This simulates a server-client architecture.

### 🎯 Objectives
1. Implement full-duplex (two-way) serial communication.
2. Create a system where logic is offloaded from the microcontroller to the PC.
3. Manage latency to ensure response time is < 1 second.

### 🔌 Pin Configuration
| Component | Pin |
| :--- | :--- |
| **Red LED** | 7 |
| **Green LED** | 6 |
| **Blue LED** | 5 |
| **Button 1** | 12 |
| **Button 2** | 11 |
| **Button 3** | 10 |

### 💻 Code Explanation
#### 1. Outbound (Arduino -> Python)
When a button is pressed, Arduino sends a character (`R`, `G`, or `B`) to the Serial port. It does **not** turn on the LED locally.

#### 2. Processing (Python)
The Python script listens for these characters. When it receives `R`, it decides the action (e.g., "Turn Red LED On") and sends a numeric command (`1`) back to the Arduino.

#### 3. Inbound (Python -> Arduino)
The Arduino waits for the numeric command (`1`, `2`, or `3`) and activates the corresponding LED on pins 7, 6, or 5.

### 🚀 How to Run
1.  Upload the Arduino firmware.
2.  Run the Python script.
3.  Press a physical button on the breadboard.
4.  Observe the signal travel to the PC and back to light up the LED.

---

## Laboratory Activity 7: Controlling Arduino using FastAPI

### 📖 Overview
This project modernizes the control stack by introducing **FastAPI**, a modern web framework. Instead of a command-line interface, the Arduino is controlled via HTTP Requests (Web API). This creates a true IoT architecture where hardware is controlled over a network protocol.

### 🎯 Objectives
1. Implement an HTTP-based solution using `FastAPI`.
2. Bridge REST API endpoints to Serial commands.
3. Control hardware via web URLs (e.g., `localhost:8000/led/red`).

### 🛠️ Tech Stack
* **Python Libraries:** `fastapi`, `uvicorn`, `pyserial`
* **Tooling:** Postman, Web Browser, or cURL

### 💻 Code Explanation
#### API Endpoints
* `GET /led/{color}`: Accepts "red", "green", or "blue". Python converts this to serial commands `1`, `2`, or `3`.
* `GET /led/on`: Sends a command to turn all LEDs on.
* `GET /led/off`: Sends a command to turn all LEDs off.

#### Backend Logic
The FastAPI app initializes the serial connection on startup. When an API route is hit, it writes the corresponding byte to the serial port, which the Arduino interprets to toggle pins 5, 6, or 7.

### 🚀 How to Run
1.  Upload the Arduino sketch.
2.  Start the server: `uvicorn main:app --reload`.
3.  Open your browser and navigate to `http://localhost:8000/led/red`.
4.  The Red LED on the circuit will toggle.

---

# Exams

## Midterm Project: Smart Lighting System

### 📖 Overview
The Midterm project is a comprehensive **Smart Lighting System** that adapts to environmental conditions. It features a state machine with two modes: **Automatic** (adjusts based on preset logic) and **Manual** (user-defined thresholds via Serial). It simulates a real-world street light controller.

### 🎯 Features
* **Mode Switching:** Toggle between `AUTO` and `MANUAL` modes via Serial commands.
* **Dynamic Thresholds:**
    * *Automatic:* Thresholds shift based on simulated weather (Cloudy, Normal, Bright).
    * *Manual:* User sets specific percentage thresholds for Light/Dark.
* **Real-time Monitoring:** Reports light intensity %, active LED, and current mode every second.

### 🔌 Pin Configuration
* **Input:** Photoresistor (Analog A0)
* **Outputs:** Green LED (Low Light), Yellow LED (Med Light), Red LED (High Light).

### 💻 Command Reference
| Command | Description |
| :--- | :--- |
| `MODE AUTO` | Switches system to Automatic logic. |
| `MODE MANUAL` | Switches system to Manual logic. |
| `SET LOW xx` | Sets the low-light threshold percentage (Manual Mode only). |
| `SET HIGH xx` | Sets the high-light threshold percentage (Manual Mode only). |

### 🚀 How to Run
1.  Connect the Photoresistor voltage divider to A0.
2.  Connect LEDs to PWM/Digital pins.
3.  Upload the code.
4.  Use the Serial Monitor to observe data and send commands.

---

## Final Project: Arduino-to-Python API Client

### 📖 Overview
The Capstone project for this course is a **Serial API Bridge**. It demonstrates a decoupled IoT architecture where an Arduino Input (Button) triggers a Remote Action (API Call) via a Python Gateway.

The Arduino acts solely as a trigger device; it does not know about the API or the Internet. The Python script bridges the physical world (Serial) to the digital world (HTTP).

### 🎯 System Architecture
1.  **Hardware Layer:** Arduino detects a button press, debounces the signal (prevents double-clicks), and sends a "Group ID" to the Serial port.
2.  **Gateway Layer:** A Python script listens to the Serial port. Upon receiving the ID, it normalizes the data.
3.  **Network Layer:** Python sends a `POST` or `GET` request to a specific endpoint: `/led/group/<number>/toggle`.

### 🛠️ Requirements & Constraints
* **Software Debouncing:** Implemented in Arduino to ensure one press = one signal.
* **Case Insensitivity:** Python handles input normalization.
* **Non-Blocking:** The Python client runs continuously without terminating.
* **Feedback:** The terminal displays the exact API response (Success/Error) for debugging.

### 💻 Usage
1.  **Arduino:** Upload the sketch. Connect a button to the input pin.
2.  **Python:** Configure the `API_URL` variable in the script and run it.
3.  **Action:** Press the button. The Python terminal will show:
    ```text
    > Signal Received: Group 3
    > Calling Endpoint: [http://api-server.com/led/group/3/toggle](http://api-server.com/led/group/3/toggle)
    > Status: 200 OK
    ```
