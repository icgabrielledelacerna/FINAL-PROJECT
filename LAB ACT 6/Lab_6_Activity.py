import serial
import time

# CHANGE THIS to the actual port your Arduino is using (e.g. "COM3", "COM5")
ARDUINO_PORT = "COM5"
BAUD_RATE = 9600  # Must match Serial.begin(9600) on Arduino


def main():
    # Open serial connection to Arduino
    ser = serial.Serial(ARDUINO_PORT, BAUD_RATE, timeout=1)
    time.sleep(2)  # Allow Arduino to reset

    print(f"Connected to {ARDUINO_PORT} at {BAUD_RATE} baud.")
    print("Non-terminating Python script: waiting for R/G/B, echoing 1/2/3...")

    try:
        while True:
            if ser.in_waiting > 0:
                # Read ONE character from Arduino
                data = ser.read(1).decode("utf-8", errors="ignore")

                if not data:
                    continue

                # Work with a single character
                ch = data[0]
                # Ignore Arduino's newline/CR characters for logging & logic
                if ch in ("\r", "\n"):
                    continue

                print(f"Received from Arduino: {repr(ch)}")

                # Case-insensitive: normalize to upper-case
                if "a" <= ch <= "z":
                    ch = chr(ord(ch) - ord("a") + ord("A"))

                # Map outbound signal to return command
                if ch == "R":
                    ser.write(b"1\n")  # send command + newline
                    print("Sent to Arduino: '1'")
                elif ch == "G":
                    ser.write(b"2\n")
                    print("Sent to Arduino: '2'")
                elif ch == "B":
                    ser.write(b"3\n")
                    print("Sent to Arduino: '3'")
                # Ignore anything else (e.g. newlines)

            # Small sleep to keep CPU usage low but ensure < 1s response
            time.sleep(0.02)

    except KeyboardInterrupt:
        print("\nStopping script...")
    finally:
        if ser.is_open:
            # Tell Arduino to turn ALL LEDs off before closing
            try:
                for _ in range(3):
                    ser.write(b"0\n")
                    ser.flush()
                    time.sleep(0.1)
            except Exception:
                pass
            ser.close()
            print("Serial connection closed.")


if __name__ == "__main__":
    main()


