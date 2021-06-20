
//gas initializing 
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 6, 5, 9, 3, 2);
#define MQPin A0
#define buzzer 1

//flame initializing 
int LED = 7;
int flame_sensor = 4;
int flame;


void setup(){
  
//flame sensor  
  pinMode(7, OUTPUT);
  pinMode(4, INPUT);
  
//mq4 gas sensor  
  pinMode(MQPin, INPUT_PULLUP);

//buzzer + lcd initialization 
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("GAS & Flame");
  lcd.setCursor(4, 1);
  lcd.print("DETECTOR");
  delay(1000);
  lcd.clear();
}

void loop()
{
//  flame loop
  flame = digitalRead(4);
  if(flame == 1) {
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(6, 0);
    lcd.print("Flame");
     lcd.setCursor(3, 1);
    lcd.print("DETECTED");
    delay(200);
    lcd.clear();
    delay(200);
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW); 
  }

//  gas loop
  int gas_value = digitalRead(MQPin);
  if(gas_value==HIGH) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, HIGH);
    lcd.setCursor(6, 0);
    lcd.print("GAS");
    lcd.setCursor(3, 1);
    lcd.print("DETECTED");
    delay(200);
    lcd.clear();
    delay(200); 
  } else {
    lcd.clear();
    digitalWrite(buzzer, LOW); 
    digitalWrite(LED, LOW);
  }
}
