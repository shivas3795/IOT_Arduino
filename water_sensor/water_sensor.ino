#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int a;
int motor=8;

void setup() {
Serial.begin(9600);
  lcd.begin(16, 2);
pinMode(motor,OUTPUT);
 digitalWrite(motor,LOW);
}

void loop() {
lcd.setCursor(0, 0); 
lcd.print("Land Cond:"); 
a=digitalRead(A0);
Serial.println(a);
Serial.println(analogRead(A1));
delay(100);
if(a>500) {
  digitalWrite(motor,LOW);
  lcd.setCursor(11, 0); 
  lcd.print("Wet"); 
  delay(1000);
  lcd.clear();
  }
else {
  digitalWrite(motor,HIGH);
  lcd.setCursor(11, 0); 
  lcd.print("Dry"); 
  delay(1000);
  lcd.clear();
  }  
}
/*
int flag=HIGH;  
a=analogRead(A0);
Serial.println(a);
delay(500);
/*if (a!=0)
{
 if (a 
}
digitalWrite(6,HIGH);
delay(500);
digitalWrite(6,LOW);
delay(500);*/
