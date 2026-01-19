# 🎓 Student Portfolio: COSC 111 (Internet of Things)

**Student Name:** Gabrielle Delacerna  
**Section:** BSCS - 4C  
**Instructor:** Sir Johnroe Paulo Cañamaque  

---

## 📖 Portfolio Overview
This repository contains the complete collection of laboratory activities, midterm projects, and the final capstone developed for the **Internet of Things (COSC 111)** course.

The progression of this portfolio moves from basic microcontroller operations (Digital/Analog I/O) to advanced IoT architectures involving Python bridging, Bidirectional Serial Communication, and Web API integration (FastAPI).

---

# 📂 Laboratory Activities

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

---

## Laboratory Activity 3: Working with Sensors (Fire Detector)

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
