int led[] = {8, 9, 10, 11, 12};
int i = 0;

void setup()
{
  while (i <= 4)
  {
    pinMode(led[i], OUTPUT);
    i++;
  }
}

void loop()
{
  int brightness = 255;
  i = 4;
  while (i>=0)
  { 
    brightness = (i==0 || i==4? 255 : brightness -= 84);
    analogWrite(led[i], brightness);  
    delay(1000);
    i--;
  }
  
  i = 4;
  brightness = 0;
  while (i>=0)
  {
	analogWrite(led[i], brightness);  
    delay(1000);
    i--;
  }
}