#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:

for(int i=1; i<=10; i++) {
lcd.print("LCD Program:");  
lcd.setCursor(0,1);
lcd.print(i);
delay(1000);
lcd.clear();
delay(100);
}
}
