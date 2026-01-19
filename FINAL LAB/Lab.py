import serial
import requests
import time

PORT = "COM6"          # change if needed
BAUD = 9600
BASE_URL = "http://172.20.20.3:8000"

ser = serial.Serial(PORT, BAUD, timeout=0.1)
time.sleep(2)

print("Listening for button presses...\n")

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode().strip()

        # Validate input
        if data.isdigit():
            group = data
            endpoint = f"/led/group/{group}/toggle"
            url = BASE_URL + endpoint

            # Display feedback
            print(f"Received Group Number: {group}")
            print(f"Endpoint Called: {endpoint}")

            try:
                response = requests.get(url)
                if response.status_code == 200:
                    print(f"API Response: Success (Status Code {response.status_code})\n")
                else:
                    print(f"API Response: Failed (Status Code {response.status_code})\n")
            except Exception as e:
                print(f"API Error: {e}\n")
        else:
            print(f"Invalid data received: {data}\n")