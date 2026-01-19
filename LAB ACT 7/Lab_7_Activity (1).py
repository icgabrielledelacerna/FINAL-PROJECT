from fastapi import FastAPI
import serial
import time

# CHANGE THIS to the actual port your Arduino is using (e.g. "COM3", "COM5")
ARDUINO_PORT = "COM3"
BAUD_RATE = 9600  # Must match Serial.begin(9600) on Arduino

app = FastAPI()

# Global serial connection
arduino = None


@app.on_event("startup")
def startup_event():
    global arduino
    try:
        arduino = serial.Serial(ARDUINO_PORT, BAUD_RATE, timeout=1)
        time.sleep(2)  # Allow Arduino to initialize
        print("Serial connection established.")
    except serial.SerialException as e:
        print(f"Error establishing serial connection: {e}")


@app.on_event("shutdown")
def shutdown_event():
    global arduino
    if arduino and arduino.is_open:
        try:
            # Set a very short timeout to prevent hanging
            arduino.timeout = 0.1
            # Try to turn all LEDs off before closing
            arduino.write(b"0\n")
            # Don't flush - just close immediately to prevent hanging
        except Exception:
            pass
        try:
            arduino.close()
        except Exception:
            pass
        print("Serial connection closed.")


@app.get("/")
def root():
    """Root endpoint with API information."""
    return {
        "message": "Arduino LED Control API",
        "endpoints": {
            "/led/{color}": "Turn on a specific LED (red, green, or blue)",
            "/led/on": "Turn on all LEDs",
            "/led/off": "Turn off all LEDs"
        }
    }


@app.get("/led/on")
def turn_all_leds_on():
    """Turn on all LEDs."""
    global arduino
    if arduino and arduino.is_open:
        # Turn all off first to ensure known state, then turn each on
        arduino.write(b"0\n")
        arduino.flush()
        time.sleep(0.01)
        arduino.write(b"1\n")  # Turn on red
        arduino.flush()
        time.sleep(0.01)
        arduino.write(b"2\n")  # Turn on green
        arduino.flush()
        time.sleep(0.01)
        arduino.write(b"3\n")  # Turn on blue
        arduino.flush()
        return {"status": "success", "message": "All LEDs turned on"}
    else:
        return {"status": "error", "message": "Serial connection is not open."}


@app.get("/led/off")
def turn_all_leds_off():
    """Turn off all LEDs."""
    global arduino
    if arduino and arduino.is_open:
        arduino.write(b"0\n")
        arduino.flush()
        return {"status": "success", "message": "All LEDs turned off"}
    else:
        return {"status": "error", "message": "Serial connection is not open."}


@app.get("/led/{color}")
def control_led(color: str):
    """
    Control individual LED by color.
    
    Args:
        color: LED color - "red", "green", or "blue" (case-insensitive)
    """
    global arduino
    if not arduino or not arduino.is_open:
        return {"status": "error", "message": "Serial connection is not open."}
    
    # Validate: check if color is empty or None
    if not color or len(color.strip()) == 0:
        return {"status": "error", "message": "Color parameter cannot be empty."}
    
    # Validate: check length (prevent very long strings)
    if len(color) > 20:
        return {"status": "error", "message": f"Color parameter too long (max 20 characters)."}
    
    # Validate: check for valid characters only (letters, no special chars)
    if not color.replace(" ", "").isalpha():
        return {"status": "error", "message": "Color parameter must contain only letters."}
    
    color_lower = color.lower().strip()
    
    if color_lower == "red":
        arduino.write(b"1\n")
        arduino.flush()
        return {"status": "success", "message": "Red LED turned on", "color": "red"}
    elif color_lower == "green":
        arduino.write(b"2\n")
        arduino.flush()
        return {"status": "success", "message": "Green LED turned on", "color": "green"}
    elif color_lower == "blue":
        arduino.write(b"3\n")
        arduino.flush()
        return {"status": "success", "message": "Blue LED turned on", "color": "blue"}
    else:
        return {"status": "error", "message": f"Invalid color '{color}'. Must be 'red', 'green', or 'blue'"}


if __name__ == "__main__":
    import uvicorn
    print("Starting FastAPI server...")
    print("API will be available at http://localhost:8000")
    print("API documentation at http://localhost:8000/docs")
    uvicorn.run(app, host="0.0.0.0", port=8000, timeout_keep_alive=5)
