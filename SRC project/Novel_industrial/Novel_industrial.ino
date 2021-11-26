#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(7,6,5,4,3,2);
int CT=A0;
int mVperAmp = 66;
double VRMS = 0;
double AmpsRMS = 0;
double Voltage = 0;
int readValue;             //value read from the sensor

void setup() {
Serial.begin(9600);
pinMode(11,OUTPUT);
LCD.begin(16,2);
LCD.setCursor(0,0); 
LCD.print("Current: ");
LCD.setCursor(0,1); 
LCD.print("Vibration: ");
}

void loop() {
  int Cout=analogRead(CT);
         Voltage = getVPP();
         VRMS = (Voltage/2.0) *0.707; 
         AmpsRMS = (VRMS * 1000)/mVperAmp;
  
  LCD.setCursor(9,0);
  LCD.print(AmpsRMS);
  Serial.println(AmpsRMS);
  delay(50);
 
  LCD.setCursor(11,1);
  LCD.print(analogRead(A1));
  Serial.println(analogRead(A1));
  delay(1000);
  
  LCD.setCursor(9,0);
  LCD.print("     ");
  LCD.setCursor(11,1);
  LCD.print("   ");
  delay(100);

  if((AmpsRMS>0.20)||(analogRead(A1)>100))
  {
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(11,LOW);
    delay(100);
    }
}

float getVPP()
{
  float result;
  
  int readValue;             //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 1024;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) //sample for 1 Sec
   {
       readValue = analogRead(CT);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the maximum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;
      
   return result;
 }
