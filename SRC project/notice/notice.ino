#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(7,6,5,4,3,2);
char inchar; // variable to store the incoming character 
char notice[16];
int i;

void setup()
{
  LCD.begin(16,2);
  Serial.begin(9600);
  delay(2000); 
  Serial.println("AT+CMGF=1"); // set SMS mode to text
  delay(100);
  Serial.println("AT+CNMI=2,2,0,0,0");
  // just to get a notification when SMS arrives &direct out SMS upon receipt to the GSM serial out
  delay(100);
}

void loop()
{
  //If a character comes in from the GSM...
  if(Serial.available() >0)
  {
    inchar=Serial.read();
    if (inchar=='$')
    { for(i=0;i<=15;i++)
      {
      inchar=Serial.read();
      LCD.print(inchar);
      notice[i] += inchar;
      delay(100);
       }
  Serial.println("AT+CMGD=1,4"); // delete all SMS
  }
  
  Serial.print(notice);
 
}
}
