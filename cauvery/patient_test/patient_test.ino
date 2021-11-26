#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(7,6,5,4,3,2);
int tempPin = A0;
  

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(10,OUTPUT);
LCD.begin(16,2);
LCD.setCursor(0,0); 
LCD.print("Temp: ");
LCD.setCursor(0,1); 
LCD.print("Pulse: ");
}

void loop() {
  String data;
 
  temp = temp * 1.8 + 32;  // convert Celsius to Farenheit
  data = String(temp);
  
 int sensorValue = analogRead(tempPin);
 float temperature = (sensorValue/3.8);
 
 
 if(digitalRead(8)==LOW)
  {
    count =count +1;
  }
if ((count>80)||(temperature>40))
  {
    digitalWrite(10,HIGH);
  }
  else {digitalWrite(10,LOW);}


  LCD.setCursor(5,0);
  LCD.print(temperature);
  
  LCD.setCursor(6,1);
  LCD.print(count);
  Serial.println(count);
  delay(500);

  if (count>72)
  {
     count=68;
  }
}
