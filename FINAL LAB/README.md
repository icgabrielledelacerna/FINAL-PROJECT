# Final Project: Arduino-to-Python API Client

## 📖 Overview
The Capstone project for this course is a **Serial API Bridge**. It demonstrates a decoupled IoT architecture where an Arduino Input (Button) triggers a Remote Action (API Call) via a Python Gateway.

The Arduino acts solely as a trigger device; it does not know about the API or the Internet. The Python script bridges the physical world (Serial) to the digital world (HTTP).

## 🎯 System Architecture
1.  **Hardware Layer:** Arduino detects a button press, debounces the signal (prevents double-clicks), and sends a "Group ID" to the Serial port.
2.  **Gateway Layer:** A Python script listens to the Serial port. Upon receiving the ID, it normalizes the data.
3.  **Network Layer:** Python sends a `POST` or `GET` request to a specific endpoint: `/led/group/<number>/toggle`.

## 🛠️ Requirements & Constraints
* **Software Debouncing:** Implemented in Arduino to ensure one press = one signal.
* **Case Insensitivity:** Python handles input normalization.
* **Non-Blocking:** The Python client runs continuously without terminating.
* **Feedback:** The terminal displays the exact API response (Success/Error) for debugging.

## 💻 Usage
1.  **Arduino:** Upload the sketch. Connect a button to the input pin.
2.  **Python:** Configure the `API_URL` variable in the script and run it.
3.  **Action:** Press the button. The Python terminal will show:
    ```text
    > Signal Received: Group 3
    > Calling Endpoint: [http://api-server.com/led/group/3/toggle](http://api-server.com/led/group/3/toggle)
    > Status: 200 OK
    ```
