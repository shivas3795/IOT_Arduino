#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(7,6,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
LCD.begin(16,2);
LCD.setCursor(0,0); 
LCD.print("Voltage: ");
LCD.setCursor(0,1); 
LCD.print("Vibration: ");
}

void loop() {
  
  LCD.setCursor(9,0);
  LCD.print("lcd print");
  delay(500);
 
  LCD.setCursor(11,1);
//  LCD.print(analogRead(A1));
  delay(500);
  
  LCD.setCursor(9,0);
  LCD.print("   ");
  LCD.setCursor(11,1);
  LCD.print("   ");
  delay(100);
}
