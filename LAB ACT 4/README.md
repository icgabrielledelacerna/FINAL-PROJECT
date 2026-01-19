# Laboratory Activity 4: Arduino Serial Connection

## 📖 Overview
This activity extends the sensor logic from Lab 3 by introducing **Serial Communication** and **Latching Logic**. The system now acts as a smart alarm that "latches" (stays ON) once triggered, requiring manual user intervention via the PC to reset.

## 🎯 Objectives
1. Understand Arduino Serial Communication (UART).
2. Implement string parsing from the Serial Monitor.
3. Create a latching alarm system controlled by software commands.

## 🛠️ Hardware Requirements
* **Sensors:** Thermistor (or Photoresistor)
* **Output:** 1x LED (Pin 8)

## 🔌 Pin Configuration
| Component | Pin |
| :--- | :--- |
| **Sensor Input** | A0 or A2 |
| **Status LED** | 8 |

## 💻 Code Explanation
* **Threshold Detection**: The code continuously monitors the sensor. If the value exceeds the limit (50°C or 220 brightness), it sets a boolean flag `isAlarmActive = true`.
* **Latching Loop**: Once `isAlarmActive` is true, the LED blinks indefinitely, *even if the sensor value returns to normal*.
* **Serial Interrupt**: The `Serial.readString()` function listens for user input.
* **Command Parsing**: If the user types "stop" (case-insensitive), the boolean flag is reset to `false`, and the alarm turns off.

## 🚀 How to Run
1.  Upload the code and open the **Serial Monitor**.
2.  Trigger the sensor threshold. The LED will start blinking.
3.  Remove the trigger source; the LED should *continue* blinking.
4.  Type `stop` (or `STOP`, `Stop`) in the Serial Monitor to reset the system.
