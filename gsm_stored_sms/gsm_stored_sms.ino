#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(7,6,5,4,3,2);
char inputArray[31]; 
char notice[16];


void loop() {

  if(Serial.available()>0) {
    char inchar=Serial.read();
    Serial.print(inchar);
     if (inchar=='*') {
       for (int i = 0; i <= 15; i++) 
      {
        notice += inchar(i);
        
      }
     
     Serial.println("Notice: ");
     Serial.println(notice);
    
}

}}
  
//+CMT: "+917845829919","","20/01/10,20:39:26+22"
//jgmj  //notice.toCharArray(inputArray,31); 
    /*LCD.print(inputArray[i]);
        Serial.println(inputArray[i]);
        delay(1000);*/
  
