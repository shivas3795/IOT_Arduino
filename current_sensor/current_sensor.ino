#include <LiquidCrystal.h>
#include<SoftwareSerial.h>
SoftwareSerial node(8,9);
LiquidCrystal lcd(12,11, 6, 5, 4, 3);

int Temp=A1;
int CT=A0;
int Level=2;
int mVperAmp = 66;
int tempC,ctc,levelc;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;

void setup() 
{
  
  Serial.begin(19200);
  node.begin(19200);
  lcd.begin(16, 2);
  lcd.setCursor(0,0); 
  lcd.print("Temp= "); 
  lcd.setCursor(8,0); 
  lcd.print("Cnt= "); 
  lcd.setCursor(0,1); 
  lcd.print("Lev = ");
  
}

void loop() {
         int Tout=analogRead(Temp);
         int Cout=analogRead(CT);
         int Lout=digitalRead(Level);
         tempC=(Tout*1.8)+32;
         //Tout=(Tout*500)/1023;
        // tempC=(Tout*-1); 
         Voltage = getVPP();
         VRMS = (Voltage/2.0) *0.707; 
         AmpsRMS = (VRMS * 1000)/mVperAmp;
         levelc=Lout;
         lcd.setCursor(5,0);

        lcd.print(tempC);
        lcd.setCursor(12,0);

        Serial.print("AmpsRMS ");
        Serial.println(AmpsRMS);
        lcd.setCursor(8,1); 

        lcd.print(levelc); 
       /* if(tempC>200)
        {
          sms1();
          node.println(tempC);
          
        }
        if( AmpsRMS>300)
        {
          sms2();
          node.println(AmpsRMS);
         
        }
        if(levelc<300)
        {
          sms3();
          node.println(levelc);
          
        }*/
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

         
void sms1()
{                 
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+919994384840\"\r");    
  delay(1000);
  Serial.print("Temperature Exceeds");   
  delay(1000);
  Serial.write((char)26);  
  delay(1000);
}

void sms2()
{
                  
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+919994384840\"\r");    
  delay(1000);
  Serial.print("Over Load");   
  delay(1000);
  Serial.write((char)26);  
  delay(1000);
}

void sms3()
{
                  
  Serial.print("AT+CMGF=1\r");    
  delay(1000);
  Serial.print("AT+CMGS=\"+919994384840\"\r");    
  delay(1000);
  Serial.print("Level High");   
  delay(1000);
  Serial.write((char)26);  
  delay(1000);
}
