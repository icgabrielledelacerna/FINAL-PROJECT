const int ledPin = 12;

const int photoresistorPin = A2;
int brightness;
const int photoresistorThreshold = 220;

const int buzzer = 12;

const int thermistorPin = A0;
const int beta = 3950;
const int resistance = 10;
const float tempThreshold = 50.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  brightness = analogRead(photoresistorPin);
  //Serial.println(brightness);

  int analogValue = analogRead(thermistorPin);
  float tempC = beta / (log((1025.0 * resistance / analogValue - resistance) / resistance) + beta / 298.0) - 273.0;
  //float tempF = 1.8 * tempC + 32.0;

  Serial.print("Temp Celsius: ");
  Serial.println(tempC);
  //Serial.print("Temp Farenheit: ");
  //Serial.println(tempF);

  if (brightness>=photoresistorThreshold && tempC >= tempThreshold)
  {
    digitalWrite(ledPin, HIGH);
    delay(10);
    digitalWrite(ledPin, LOW);
    delay(10);

    tone(buzzer, 1000);
    delay(300);
    noTone(buzzer);
    delay(100);
  
    tone(buzzer, 1000);
    delay(300);
    noTone(buzzer);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

}
