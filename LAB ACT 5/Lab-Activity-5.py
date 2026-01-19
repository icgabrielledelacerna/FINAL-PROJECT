import serial
import time
import os

# Configuration
# Replace 'COM5' with your Arduino's port (e.g., 'COM3' for Windows, '/dev/ttyUSB0' for Linux/Mac)
arduino_port = "COM5"  # Example: "/dev/ttyUSB0" for Linux/Mac
baud_rate = 9600

# Global serial connection
arduino = None

def clear_screen():
    """Clear the terminal screen"""
    os.system('cls' if os.name == 'nt' else 'clear')

def print_menu():
    """Print the menu options"""
    print("\n" + "="*40)
    print("    Arduino LED Control Menu")
    print("="*40)
    print("[R] Red ON/OFF")
    print("[G] Green ON/OFF")
    print("[B] Blue ON/OFF")
    print("[P] Purple ON/OFF")
    print("[A] All ON")
    print("[O] All OFF")
    print("[X] Exit")
    print("="*40)

def initialize_serial():
    """Initialize serial connection to Arduino"""
    global arduino
    try:
        arduino = serial.Serial(arduino_port, baud_rate, timeout=1)
        time.sleep(2)  # Allow Arduino to initialize
        print("Serial connection established.")
        return True
    except serial.SerialException as e:
        print(f"Error establishing serial connection: {e}")
        print(f"Please check if Arduino is connected to {arduino_port}")
        return False
    except Exception as ex:
        print(f"Unexpected error: {ex}")
        return False

def send_command(command):
    """Send command to Arduino via serial"""
    global arduino
    if arduino and arduino.is_open:
        try:
            arduino.write(command.encode('utf-8'))
            time.sleep(0.1)  # Small delay to ensure command is processed
            
            # Read response from Arduino
            
        except Exception as e:
            print(f"Error sending command: {e}")
    else:
        print("Serial connection is not open.")

def process_user_input(user_input):
    """Process user input and send corresponding command"""
    # Convert to uppercase for case-insensitive comparison
    command = user_input.upper().strip()
    
    if command == 'R':
        send_command('R')
    elif command == 'G':
        send_command('G')
    elif command == 'B':
        send_command('B')
    elif command == 'A':
        send_command('A')
    elif command == 'O':
        send_command('O')
    elif command == 'P':
        send_command('P')
    elif command == 'X':
        send_command('O')
        return False  # Signal to exit
    else:
        #print(f"Error: Invalid command '{user_input}'")
        #print("Valid commands: R, G, B, A, O, X")
        time.sleep(0)  # Brief pause to show error message
    
    return True  # Continue running

def main():
    """Main program loop"""
    global arduino
    
    # Initialize serial connection
    if not initialize_serial():
        print("Failed to establish serial connection. Exiting...")
        return
    
    try:
        running = True
        while running:
            clear_screen()
            print_menu()
            
            # Get user input
            user_input = input("\nEnter your choice: ").strip()
            
            # Process input
            if user_input:
                running = process_user_input(user_input)
            else:
                #print("Please enter a valid command.")
                time.sleep(1)
    
    except KeyboardInterrupt:
        print("\n\nExiting...")
    except Exception as e:
        print(f"\nUnexpected error: {e}")
    finally:
        # Close serial connection
        if arduino and arduino.is_open:
            arduino.close()
            print("Serial connection closed.")
        print("Program terminated.")

if __name__ == "__main__":
    main()

