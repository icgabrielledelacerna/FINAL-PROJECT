# Laboratory Activity 7: Controlling Arduino using FastAPI

## 📖 Overview
This project modernizes the control stack by introducing **FastAPI**, a modern web framework. Instead of a command-line interface, the Arduino is controlled via HTTP Requests (Web API). This creates a true IoT architecture where hardware is controlled over a network protocol.

## 🎯 Objectives
1. Implement an HTTP-based solution using `FastAPI`.
2. Bridge REST API endpoints to Serial commands.
3. Control hardware via web URLs (e.g., `localhost:8000/led/red`).

## 🛠️ Tech Stack
* **Python Libraries:** `fastapi`, `uvicorn`, `pyserial`
* **Tooling:** Postman, Web Browser, or cURL

## 💻 Code Explanation
### API Endpoints
* `GET /led/{color}`: Accepts "red", "green", or "blue". Python converts this to serial commands `1`, `2`, or `3`.
* `GET /led/on`: Sends a command to turn all LEDs on.
* `GET /led/off`: Sends a command to turn all LEDs off.

### Backend Logic
The FastAPI app initializes the serial connection on startup. When an API route is hit, it writes the corresponding byte to the serial port, which the Arduino interprets to toggle pins 5, 6, or 7.

## 🚀 How to Run
1.  Upload the Arduino sketch.
2.  Start the server: `uvicorn main:app --reload`.
3.  Open your browser and navigate to `http://localhost:8000/led/red`.
4.  The Red LED on the circuit will toggle.
