#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 6, 5, 9, 3, 2);

#define MQPin A0
#define buzzer 1


int LED = 7;
int flame_sensor = 4;
int flame;


void setup()
{
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
  lcd.begin(16, 2);
   pinMode(MQPin, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);
    lcd.setCursor(5, 0);
    lcd.print("GAS");
    lcd.setCursor(3, 1);
    lcd.print("DETECTOR");
    delay(1000);
    lcd.clear();
}
void loop()
{
  flame = digitalRead(4);
  if(flame == 1)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(6, 0);
    lcd.print("GAS");
     lcd.setCursor(3, 1);
    lcd.print("DETECTED");
    delay(200);
    lcd.clear();
    delay(200);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  int gas_value = digitalRead(MQPin);

if(gas_value==HIGH)
{
  digitalWrite(buzzer, HIGH);
  lcd.setCursor(6, 0);
  lcd.print("GAS");
   lcd.setCursor(3, 1);
  lcd.print("DETECTED");
  delay(200);
  lcd.clear();
  delay(200);
  
}
else
{
 lcd.clear();
 digitalWrite(buzzer, LOW); 
}
}
