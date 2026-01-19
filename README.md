# 🎓 Student Portfolio: COSC 111 (Internet of Things)

**Student Name:** Gabrielle Delacerna  
**Section:** BSCS - 4C    
**Instructor:** Johnroe Paulo Cañamaque  

---

## 📖 Portfolio Overview
This repository contains the complete collection of laboratory activities, midterm projects, and the final capstone developed for the **Internet of Things (COSC 111)** course.

The progression of this portfolio moves from basic microcontroller operations (Digital/Analog I/O) to advanced IoT architectures involving Python bridging, Bidirectional Serial Communication, and Web API integration (FastAPI).

---

## 📂 Laboratory Activities

### 1️⃣ Laboratory Activity 1: Working with Digital Signals
> **Focus:** Digital Output, Timing Control, `digitalWrite()`

<details>
<summary><strong>View Project Details</strong></summary>

### 📖 Overview
This project demonstrates the fundamental concepts of digital output using an Arduino. The circuit implements a "Running Light" sequence where 5 LEDs turn on and off sequentially. This activity serves as an introduction to pin manipulation and timing control using `digitalWrite()` and `delay()`.

### 🎯 Objectives
1. Review Arduino as a device for IoT systems implementation.
2. Discuss digital signals and their implementation in an Arduino circuit.

### 🔌 Pin Configuration
| Component | Arduino Pin | Mode |
| :--- | :--- | :--- |
| **LED 1-5** | Pins 12, 11, 10, 9, 8 | OUTPUT |

### 💻 Code Logic
* **`setup()`**: Configures Pins 8-12 as `OUTPUT`.
* **`loop()`**: Executes the running light logic (Sequential ON/OFF) with a 1-second delay.

</details>

---

### 2️⃣ Laboratory Activity 2: Working with Analog Signals
> **Focus:** PWM (Pulse Width Modulation), Fading Effects, `analogWrite()`

<details>
<summary><strong>View Project Details</strong></summary>

### 📖 Overview
This project builds upon the first activity by introducing **Analog Signals** and **Pulse Width Modulation (PWM)**. Instead of simply turning LEDs on and off, this circuit controls the *brightness* of the LEDs to create a fading effect.

### 🎯 Objectives
1. Discuss analog signals and their implementation.
2. Understand analog-to-digital signal conversion concepts using PWM.
3. Optimize code using arrays and loops.

### 🔌 Pin Configuration
* **LEDs:** Pins 12, 11, 10, 9, 8 (Utilizing PWM enabled pins where available).

### 💻 Code Logic
* **`analogWrite(pin, value)`**: Controls duty cycle (brightness) from 0-255.
* **Arrays**: Uses `int ledPins[]` to manage pin numbers efficiently.

</details>

---

### 4️⃣ Laboratory Activity 4: Arduino Serial Connection
> **Focus:** UART, Latching Logic, String Parsing

<details>
<summary><strong>View Project Details</strong></summary>

### 📖 Overview
This activity extends sensor logic by introducing **Serial Communication**. The system acts as a smart alarm that "latches" (stays ON) once triggered, requiring manual user intervention via the PC to reset.

### 🎯 Objectives
1. Understand Arduino Serial Communication (UART).
2. Implement string parsing from the Serial Monitor.
3. Create a latching alarm system controlled by software commands.

### 🔌 Pin Configuration
| Component | Pin |
| :--- | :--- |
| **Sensor (Thermistor/LDR)** | A0 / A2 |
| **Status LED** | 8 |

### 💻 Code Logic
* **Latching:** If threshold is met, `isAlarmActive` becomes true and stays true.
* **Reset:** The system waits for the user to type `"stop"` in the Serial Monitor to reset the alarm.

</details>

---

### 5️⃣ Laboratory Activity 5: Receiving Serial Connection from Python
> **Focus:** Python Integration, `pyserial`, CLI Control

<details>
<summary><strong>View Project Details</strong></summary>

### 📖 Overview
This project shifts control from the Arduino Serial Monitor to a custom **Python Script**. It demonstrates how a high-level programming language can control hardware components via USB serial.

### 🎯 Objectives
1. Utilize Python (`pyserial`) for serial communication.
2. Implement a Command Line Interface (CLI) in Python.

### 🔌 Pin Configuration
* **RGB LED:** Red (8), Green (9), Blue (10)

### 💻 Tech Stack
* **Arduino Firmware:** Listens for characters `R`, `G`, `B`, `A` (All), `O` (Off).
* **Python Client:** Runs a loop displaying a menu; sends byte-encoded characters to the Arduino.

</details>

---

### 6️⃣ Laboratory Activity 6: Bidirectional Control
> **Focus:** Full Duplex Communication, Software-in-the-Loop

<details>
<summary><strong>View Project Details</strong></summary>

### 📖 Overview
This activity implements a "Software-in-the-Loop" system. The Arduino sends a button press to Python, Python processes the logic, and sends a command *back* to Arduino to toggle the LED.

### 🎯 Objectives
1. Implement full-duplex (two-way) serial communication.
2. Manage latency to ensure response time is < 1 second.

### 🔌 Pin Configuration
* **Inputs:** Buttons on Pins 12, 11, 10.
* **Outputs:** LEDs on Pins 7, 6, 5.

### 💻 System Flow
1. **Outbound:** Arduino sends `R`, `G`, or `B` on button press.
2. **Processing:** Python receives signal, determines action, sends back `1`, `2`, or `3`.
3. **Inbound:** Arduino receives number, toggles LED.

</details>

---

### 7️⃣ Laboratory Activity 7: Controlling Arduino using FastAPI
> **Focus:** Web API, HTTP Requests, REST Architecture

<details>
<summary><strong>View Project Details</strong></summary>

### 📖 Overview
This project modernizes the control stack by introducing **FastAPI**. The Arduino is controlled via HTTP Requests (Web API) rather than a CLI, simulating a true IoT network architecture.

### 🎯 Objectives
1. Implement an HTTP-based solution using `FastAPI`.
2. Bridge REST API endpoints to Serial commands.

### 🛠️ Tech Stack
* **Python:** `fastapi`, `uvicorn`, `pyserial`
* **Tools:** Postman / Web Browser

### 💻 API Endpoints
* `GET /led/{color}`: Toggles specific LED.
* `GET /led/on` / `GET /led/off`: Global controls.

</details>

---

## 🏆 Examinations & Capstones

### 📝 Midterm Project: Smart Lighting System
> **Focus:** State Machines, Environmental Simulation, Automation

<details>
<summary><strong>View Project Details</strong></summary>

### 📖 Overview
A comprehensive system featuring **Automatic** and **Manual** modes. It simulates a street light controller that adapts to "weather conditions" (Cloudy, Normal, Bright).

### 🎯 Features
* **Dynamic Thresholds:** Auto-adjusts based on simulated weather.
* **Manual Overrides:** User can set specific thresholds via Serial commands (`SET LOW xx`).
* **Reporting:** Streams status data (Mode, Light %, Active LED) every second.

### 🔌 Hardware
* **Input:** Photoresistor (A0)
* **Output:** Traffic Light LEDs (Green/Yellow/Red)

</details>

---

### 🚀 Final Project: Arduino-to-Python API Client
> **Focus:** Physical API Bridge, Decoupled Architecture

<details>
<summary><strong>View Project Details</strong></summary>

### 📖 Overview
The Capstone project is a **Serial API Bridge**. The Arduino acts solely as a physical trigger (Button) that initiates a remote API call via a Python Gateway.

### 🎯 System Architecture
1. **Hardware:** Arduino detects button press, debounces signal, sends "Group ID".
2. **Gateway:** Python script listens to Serial, normalizes data.
3. **Network:** Python performs a real HTTP Request (`POST /led/group/<id>/toggle`).

### 🛠️ Requirements
* **Software Debouncing:** No hardware noise.
* **Non-Blocking:** Python client runs continuously.
* **Feedback:** Terminal displays HTTP 200/400 status codes.

</details>
