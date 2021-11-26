#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(2,3);
const int trigPin = 7;
const int echoPin = 6;
// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  ArduinoUno.begin(115200);
 }

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
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
}
