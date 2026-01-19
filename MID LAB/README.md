# Midterm Project: Smart Lighting System

## 📖 Overview
The Midterm project is a comprehensive **Smart Lighting System** that adapts to environmental conditions. It features a state machine with two modes: **Automatic** (adjusts based on preset logic) and **Manual** (user-defined thresholds via Serial). It simulates a real-world street light controller.

## 🎯 Features
* **Mode Switching:** Toggle between `AUTO` and `MANUAL` modes via Serial commands.
* **Dynamic Thresholds:**
    * *Automatic:* Thresholds shift based on simulated weather (Cloudy, Normal, Bright).
    * *Manual:* User sets specific percentage thresholds for Light/Dark.
* **Real-time Monitoring:** Reports light intensity %, active LED, and current mode every second.

## 🔌 Pin Configuration
* **Input:** Photoresistor (Analog A0)
* **Outputs:** Green LED (Low Light), Yellow LED (Med Light), Red LED (High Light).

## 💻 Command Reference
| Command | Description |
| :--- | :--- |
| `MODE AUTO` | Switches system to Automatic logic. |
| `MODE MANUAL` | Switches system to Manual logic. |
| `SET LOW xx` | Sets the low-light threshold percentage (Manual Mode only). |
| `SET HIGH xx` | Sets the high-light threshold percentage (Manual Mode only). |

## 🚀 How to Run
1.  Connect the Photoresistor voltage divider to A0.
2.  Connect LEDs to PWM/Digital pins.
3.  Upload the code.
4.  Use the Serial Monitor to observe data and send commands.
