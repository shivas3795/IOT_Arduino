#include<LiquidCrystal.h>  //include LCD library
const int rs = D0, en = D1, d4 = D2, d5 = D3, d6 = D4, d7 = D5;
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);
//LiquidCrystal LCD(2,3,4,5,6,7); //RS, E, D4-D7
//int counter=0; //initialise counter=0
int Time;
void setup() {
  Serial.begin(115200);
  LCD.begin(16,2);
  LCD.setCursor(0,0); 
  LCD.print("Timer:"); //prints timer
  //LCD.clear(); //(clear the space)
}

void loop() { 
  Serial.println("Enter the time:");
  while(Serial.available()==0) {}
  Time= Serial.parseInt(); //Serial.parseFloat, Serial.read
  
  LCD.setCursor(6,0);
  LCD.print(Time);
  LCD.setCursor(9,1); //sets cursor at 10th column, 2nd row
  LCD.print(" ");
  for(int counter=1; counter<=Time; counter++){
    LCD.setCursor(0,1);
    LCD.print(counter);
    Serial.println(counter);
    LCD.print (" seconds");
    delay(1000); //1 second delay
    }
}
