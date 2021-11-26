//Ping sensors
#define trigPin1 2 //defines ping sensor1 trigger to pinslot 2
#define echoPin1 3 //defines ping sensor1 echo to pinslot 3
#define trigPin2 12 //defines ping sensor2 trigger to pinslot 4
#define echoPin2 11 //defines ping sensor2 echo to pinslot 5

unsigned long time1,time2;
//duration of the traveldistance from ping sensor to object and back to ping sensor
unsigned long duration1=0; //ping sensor1 duration
unsigned long duration2=0; //ping sensor2 duration
//defining attributes for distance
int distance1; //distance, to calculate distance to object from ping sensor1
int distance2; //distance, to calculate distance to object from ping sensor2
float fps, elap,mph;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(8,9);
void setup() 
{
  // put your setup code here, to run once:
Serial.begin(9600);
 mySerial.begin(9600);
 pinMode(4,OUTPUT);
pinMode(trigPin1, OUTPUT); //ping sensor trigger OUTPUT
pinMode(echoPin1, INPUT); //ping sensor echo INPUT
pinMode(trigPin2, OUTPUT); //ping sensor2 trigger OUTPUT
pinMode(echoPin2, INPUT); //ping sensor2 echo INPUT
 Serial.setTimeout(100);
}
//method to measure distance of ping sensor1
void measureDistance1() {
pinMode(trigPin1, OUTPUT); //ping sensor1 trigger OUTPUT
pinMode(echoPin1, INPUT); //ping sensor1 echo INPUT
digitalWrite(trigPin1, HIGH); //ping sensor1 sends ultrasonic wave
delayMicroseconds(10); //waits for 1 second (1000 microseconds)
digitalWrite(trigPin1, LOW); //ping sensor1 trigger is LOW
duration1 = pulseIn(echoPin1, HIGH); //ping sensor1 retrieves the sound
}
void measureDistance2() {
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
}
//method to calculate distance based on information recieved with measure distance -method for ping sensor1
int calculateDistance1() {
measureDistance1(); //calls for measureDistance() method
duration1=duration1/2; //divides duration of the sound from ping sensor1 to object and back to the sensor and divides it by 2 (sound travels 2 times)
distance1 = int(duration1/29); //duration is then divided by 29 (sound travels 29 microseconds per centimeter)
//Serial.print("Ping distance (CM) - "); //prints "Ping distance (CM) - ") to serial monitor
//Serial.println(distance1); //prints the distance number to serial monitor
delay(50); //waits for 0,5 seconds (500 microseconds)
}
 
//method to calculate distance based on information recieved with measure distance -method for ping sensor2
void calculateDistance2() {
measureDistance2();
duration2=duration2/2;
distance2 = int(duration2/29);
//Serial.print("Ping2 distance (CM) - ");
//Serial.println(distance2);
delay(50);
}
String data;
uint8_t dataRead = 0;

void loop() {
  // put your main code here, to run repeatedly:
 
if (mySerial.available() > 0) {
    delay(50);
    String readData = "";
    Serial.print("cmd from bolt:");
    while (mySerial.available() > 0 ) {
      readData = readData + (char)mySerial.read();
    }
    Serial.println(readData);
    if (readData.indexOf("RD") != -1) {
      String data = sensor_data_to_push();
      mySerial.print(data);
      Serial.print("data sent to bolt:");
      Serial.print(data);
    }
  } 
 digitalWrite(4,HIGH);
   Serial.println ("Waiting for projectile");
calculateDistance1(); //calls for calculateDistance() -method
 calculateDistance2(); //calls for calculateDistance2() -method

while (distance1 >15)
 {
  
calculateDistance1();

  }
  while (distance1 <= 15)
  {
    time1 = micros();
 
    calculateDistance1();
   
    }
    while (distance2 > 15)
    {
      calculateDistance2();
      }
      while (distance2 <=15)
      {
        time2 = micros();
        calculateDistance2();       
        }   
        
elap = time2 - time1;
fps = 666666/elap;
 
 mph= 1.097*fps;

 //Serial.print(elap);
Serial.println("Foot per Sec :");
Serial.print(fps);
 if (mph >= 3 )
  {
    digitalWrite(4,LOW);
    delay (5159);
   
  }
}
String sensor_data_to_push() {
  String data;
  float temp = fps;
  data =String(temp);
  Serial.print("data is:");
  Serial.println(data);
  return data;
  loop();
}
