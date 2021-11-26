
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;
#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(2,3);
const int trigPin = 9;
const int echoPin = 7;
long duration;
int distance,i=0;
long latd, longt;

TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  Serial.begin(9600);  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
}

void loop(){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*340*pow(10,-4)/2);
  Serial.print("distance: ");
  Serial.println(distance);
  delay(100);  
  
  if((distance <= 5)&&(i==0)) {
      while(Serial.available() > 0){
      gps.encode(Serial.read());
      if(gps.location.isUpdated()){            
      Serial.println("AT+CMGF=1");    
      delay(1000);  
      Serial.println("AT+CMGS=\"+918248424209\"\r"); 
      delay(1000);
      Serial.println("Dustbin Full");delay(500);
      Serial.println("Location is");delay(500);
      Serial.print("https://www.google.com/maps/place/");
      Serial.print(gps.location.lat(), 6);Serial.print(",");Serial.println(gps.location.lng(), 6);
      delay(1000);
      Serial.println((char)26);
      delay(1000);
      i++;
   }
  }
 }
}
