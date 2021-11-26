#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);

void setup()
{
  LCD.begin(16, 2);
  Serial.begin(9600);
  LCD.setCursor(0,0); 
LCD.print("Total Space: 4");
LCD.setCursor(0,1); 
LCD.print("Space Left: ");
}

void loop() {
  String request = Serial.readStringUntil('\n');
  request.trim();
  LCD.setCursor(11,1); 
  LCD.print(request);
}
