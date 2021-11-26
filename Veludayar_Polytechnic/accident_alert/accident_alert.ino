#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(2,3,4,5,6,7);


void setup()
{
  pinMode(8,INPUT);
   pinMode(9,INPUT);
    pinMode(10,INPUT);
     pinMode(11,INPUT);
  LCD.begin(16,2);
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
}

void loop()
{
 Serial.println(digitalRead(8));
 Serial.println(digitalRead(9));
 Serial.println(digitalRead(10));
 Serial.println(digitalRead(11));
  if((digitalRead(8)==0)||(digitalRead(9)==0)||(digitalRead(10)==0)||(digitalRead(11)==0)) {
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+918220862721\"\r"); // Replace x with mobile number
  delay(1000);
  //Serial.println("AT+CMGS=\"+919965239055\"\r"); // Replace x with mobile number
  //delay(1000);
  Serial.println("Alert! Please Help");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(10000);
  
  sms();
  

  LCD.setCursor(0,0); 
   LCD.print("Alert!Need Help"); 
   delay(15000);
   LCD.clear();
  }
}

void sms()
{
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919965239055\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("Alert! Please Help");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  }
