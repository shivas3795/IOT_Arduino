#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int echo = 8;
int trig = 9;
int buzz = 13;
int led = 11;
int distance, Time;

void setup() {
  pinMode(echo,INPUT);
  pinMode(trig, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(buzz,OUTPUT);
  digitalWrite(led,LOW); 
  digitalWrite(buzz,LOW); 
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Tank Monitoring");
  lcd.setCursor(0,1);
  lcd.print("Dis:");
  lcd.setCursor(9,1);
  lcd.print("S:");
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);

  Time = pulseIn(echo,HIGH);
  distance = 0.034*Time/2;
  Serial.print(distance);
  Serial.println(" cm");
  
  lcd.setCursor(4,1);
  lcd.print(distance);
  delay(1000);
  lcd.setCursor(4,1);
  lcd.print("   ");

  if(distance<50)
  {
    lcd.setCursor(11,1);
    lcd.print("Y");
    digitalWrite(led,HIGH); 
    digitalWrite(buzz,HIGH); 
    delay(500);
    digitalWrite(buzz,LOW); 
    delay(500);  
  }
  else {
     lcd.setCursor(11,1);
    lcd.print("N");
      digitalWrite(led,LOW); 
       digitalWrite(buzz,LOW); 
      }
} 
