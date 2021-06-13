int LED = 7;
int flame_sensor = 4;
int flame;

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
}
void loop()
{
  flame = digitalRead(4);
  if(flame == 1)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}
