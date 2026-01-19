int led[] = {8, 9, 10, 11, 12};

void setup()
{
  for (int i = 5; i>=0; i--)
  {
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 5; i>=0; i--)
  {
    digitalWrite(led[i], HIGH);
  	delay(1000);
  }
  
  for (int i = 5; i>=0; i--)
  {
    digitalWrite(led[i], LOW);
  	delay(1000);
  }
}