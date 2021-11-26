#include <TinyGPS++.h>
#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(2,3);
void datagps();
const int trigPin = 8;
const int echoPin = 9;

static const int RXPin = 4, TXPin = 5;
static const uint32_t GPSBaud = 9600;
SoftwareSerial ss(RXPin, TXPin);
TinyGPSPlus gps;
long duration;
int distance;
long latitude;
long logitude;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  ArduinoUno.begin(9600);
  ss.begin(GPSBaud);   
 }

void loop()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration*340*pow(10,-4)/2;
  Serial.println(distance);
//  String data;
//  data +=distance;
//  Serial.println(data);
//  ArduinoUno.println(data);
  delay(500);

  datagps();
 /* if (distance < 5)
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
 
  }*/
}
void datagps()
{
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
      return(gps.location.lat(), 6);
      return(gps.location.lng(), 6);
    }
}
}
