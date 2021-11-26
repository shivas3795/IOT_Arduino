#include <Servo.h>             //Servo library 
Servo myservo;        //initialize a servo object for the connected servo  
String angle;    

//for lid 
const int trigPin = 12;
const int echoPin = 13;
long duration;
int distance;

//for sms
const int trigPin2 = 8;
const int echoPin2 = 9;
long duration2;
int distance2,j=0,pos;

void setup(){
  Serial.begin(9600);  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT);
  myservo.attach(2);
}

void loop(){
  //lid distance
  object();

  //sms distance
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*340*pow(10,-4)/2);
  Serial.print("distance remaining to full: ");
  Serial.println(distance2);
  Serial.println("");
  delay(50); 

 //servo
  while(distance < 10) {
    myservo.write(0);             
    delay(50);
    object();
    }
  

    myservo.write(100);     
  
  
 //sms
  if((distance2 <= 5)&&(j==0)&&(distance2!=0)) {         
      Serial.println("AT+CMGF=1");    
      delay(1000);  
      Serial.println("AT+CMGS=\"+916381625435\"\r"); 
      delay(1000);
      Serial.println("Dustbin Full! RemoveTrash");
      delay(500);
      Serial.println((char)26);
      delay(1000);
      j++;
   }
  }

 void object() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*340*pow(10,-4)/2);
  Serial.print("distance of object: ");
  Serial.println(distance);
  delay(500);  
  }
