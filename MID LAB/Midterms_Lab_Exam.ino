const int photoresistorPin = A0;
const int greenLED = 11;
const int yellowLED = 12;
const int redLED = 13;

// Variables
int lightValue = 0;
float lightPercent = 0;

int lowThreshold = 40;  // default for MANUAL mode
int highThreshold = 70;

bool isAuto = false;   // default mode is MANUAL
String environment = "Cloudy";  // default environment

// ======= SETUP =======
void setup() {
  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.println("System Ready.");
  Serial.println("Current Mode: MANUAL");
}

// ======= MAIN LOOP =======
void loop() {

  readLightSensor();
  updateThresholdAutoMode();
  updateLEDStatus();
  displayStatus();
  processSerialCommands();

  delay(1000);
}

// Reads LDR value and converts to percentage
void readLightSensor() {
  lightValue = analogRead(photoresistorPin);
  lightPercent = map(lightValue, 0, 1023, 0, 100);
}

// Automatically adjust thresholds based on MODE AUTO
void updateThresholdAutoMode() {
  if (isAuto) {
    if (lightPercent <= 40) {
      environment = "Cloudy";
      
    } else if (lightPercent > 40 && lightPercent <= 70) {
      environment = "Clear";
      
    } else {
      environment = "Clear";
      
    }
  }
}

// Turns ON only one LED depending on threshold
void updateLEDStatus() {

  if (lightPercent <= lowThreshold) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
  }
  else if (lightPercent > lowThreshold && lightPercent <= highThreshold) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }
}

// Display monitor output every second
void displayStatus() {
  Serial.print("Light Intensity: ");
  Serial.print(lightPercent);
  Serial.println("%");

  Serial.print("Active LED: ");
  if (digitalRead(greenLED)) Serial.println("Green");
  if (digitalRead(yellowLED)) Serial.println("Yellow");
  if (digitalRead(redLED)) Serial.println("Red");

  Serial.print("Current Mode: ");
  Serial.println(isAuto ? "Automatic" : "Manual");

  if (isAuto) {
    Serial.print("Environment: ");
    Serial.println(environment);
  }

  Serial.println("-----------------------------------");
}

// Reads user input commands on Serial Monitor
void processSerialCommands() {
  if (!Serial.available()) return;

  String command = Serial.readStringUntil('\n');
  command.trim();

  // --- MODE selection ---
  if (command.equalsIgnoreCase("MODE AUTO")) {
    isAuto = true;
    Serial.println("Switched to AUTOMATIC mode.");
  }
  else if (command.equalsIgnoreCase("MODE MANUAL")) {
    isAuto = false;
    Serial.println("Switched to MANUAL mode.");
  }

  // --- SET Threshold (Manual Only) ---
  else if (command.startsWith("SET LOW")) {
    if (!isAuto) {
      int value = command.substring(7).toInt();
      lowThreshold = value;
      Serial.print("Low threshold set to: ");
      Serial.println(lowThreshold);
    } else {
      Serial.println("Error: Wrong command (AUTO mode)");
    }
  }

  else if (command.startsWith("SET HIGH")) {
    if (!isAuto) {
      int value = command.substring(8).toInt();
      highThreshold = value;
      Serial.print("High threshold set to: ");
      Serial.println(highThreshold);
    } else {
      Serial.println("Error: Wrong command (AUTO mode)");
    }
  }

  // Invalid command
  else {
    Serial.println("Error: Wrong command");
  }
}