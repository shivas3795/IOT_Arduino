#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(7,6,5,4,3,2);
int tempPin = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
LCD.begin(16,2);
LCD.setCursor(0,0); 
LCD.print("Temp: ");
LCD.setCursor(0,1); 
LCD.print("Pulse: ");
pinMode(11,OUTPUT);
}

void loop() {
 
 int sensorValue = analogRead(tempPin);
 float voltageOut = (sensorValue);
 float temperature = voltageOut*0.064;
 Serial.print("Temperature(ºC): ");
 Serial.println(temperature); 
 int pulse = digitalRead(8);
 

 if((temperature>40)||(pulse==1)) {
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  delay(1000);
  }
  
  LCD.setCursor(5,0);
  LCD.print(temperature);
  delay(500);
 
  LCD.setCursor(6,1);
  LCD.print(pulse);
  Serial.println(pulse);
  delay(500);
  
  LCD.setCursor(9,0);
  LCD.print("   ");
  LCD.setCursor(6,1);
  LCD.print("   ");
  delay(100);
}
