#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(2,3,4,5,6,7);
String slot;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
LCD.begin(16,2);
LCD.setCursor(0,0); 
LCD.print("Total Space: 4");
LCD.setCursor(0,1); 
LCD.print("Space Left: ");
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0) {
  slot = Serial.readStringUntil('\n');
  slot.trim();
  Serial.println(slot);
  LCD.setCursor(12,1); 
  LCD.print(slot);
  delay(1000);
  LCD.setCursor(12,1); 
  LCD.print(" ");
  }
}
