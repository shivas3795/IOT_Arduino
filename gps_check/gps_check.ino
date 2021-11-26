
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;
#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(2,3);
const int trigPin = 7;
const int echoPin = 6;
long duration;
int distance,i=0;
long latd, longt;
// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  Serial.begin(9600);  
  ss.begin(GPSBaud);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
}

void loop(){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration*340*pow(10,-4)/2;
  Serial.print("distance: ");
  Serial.println(distance);
  delay(50);  
  //gps_send();

  if(distance <= 5)
  {
    
      while(Serial.available() > 0){
      gps.encode(Serial.read());
      if(gps.location.isUpdated()){            
      Serial.println("AT+CMGF=1");    
      delay(1000);  
      Serial.println("AT+CMGS=\"+919600615359\"\r"); 
      delay(1000);
      Serial.println("Dustbin Full");delay(500);
      Serial.println("Location is");delay(500);
      Serial.print("https://www.google.com/maps/place/");
      Serial.print(gps.location.lat(), 6);Serial.print(",");Serial.println(gps.location.lng(), 6);
      delay(1000);
      Serial.println((char)26);
      delay(1000);
   
   Serial.print("Message Sent: distance: ");
  }}}
}

   
   /*Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
   delay(10);  // Delay of 1000 milli seconds or 1 second
   Serial.println("AT+CMGS=\"+917053637667\"\r"); // Replace x with mobile number
   delay(10);
   Serial.println("DUSTBIN FULL");// The SMS text you want to send
   delay(10);
   Serial.println(data);
   //Serial.print("Latitude= "); 
   //Serial.println(latd);
   //Serial.print("Longitude= "); 
   //Serial.println(longt);
   delay(10);
  }
  }*/

/* void check()
{
Serial.print("this my fun");
delay(100);
}
  if (distance < 5)
{
   
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+917053637667\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("DUSTBIN FULL");// The SMS text you want to send
  delay(100);
 
Serial.println("Location is");delay(500);
Serial.print("https://www.google.com/maps/place/");
Serial.print(gps.location.lat(), 6);Serial.print(",");Serial.println(gps.location.lng(), 6);delay(500);
 
  }
}
   /*digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration*340*pow(10,-4)/2;
  //Serial.println(distance);
  String data;
  data +=distance;
  Serial.println(data);
  ArduinoUno.println(data);
  delay(1000);

  if (distance < 5)
{
   
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+917053637667\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("DUSTBIN FULL");// The SMS text you want to send
  delay(100);
 
Serial.println("Location is");delay(500);
Serial.print("https://www.google.com/maps/place/");
Serial.print(gps.location.lat(), 6);Serial.print(",");Serial.println(gps.location.lng(), 6);delay(500);
 
  }
}*/

void gps_send(){
  while(Serial.available() > 0){
    gps.encode(Serial.read());
      if(gps.location.isUpdated()){            
      Serial.println("AT+CMGF=1");    
      delay(100);  
      Serial.println("AT+CMGS=\"+919600615359\"\r"); 
      delay(100);
      Serial.println("Dustbin Full");delay(500);
      Serial.println("Location is");delay(500);
      Serial.print("https://www.google.com/maps/place/");
      Serial.print(gps.location.lat(), 6);Serial.print(",");Serial.println(gps.location.lng(), 6);
      delay(100);
      Serial.println((char)26);
      delay(1000);

    }
  }
}

void send_sms()
{
   Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
   delay(1000);  // Delay of 1000 milli seconds or 1 second
   Serial.println("AT+CMGS=\"+919600615359\"\r"); // Replace x with mobile number
   delay(1000);
   gps_send();
   delay(1000);
   Serial.println((char)26);
   delay(1000);

}
