#include <Servo.h>
int pos;
int Position;
Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  }

void loop() {
  Serial.println("enter position 0 to open and 1 to close");
  while(Serial.available()==0) {}
  Position = Serial.parseInt();
   
   if(Position==0) {
    for (pos = 0; pos <= 90; pos += 90) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100); 
    Serial.println("open");// waits 15ms for the servo to reach the position  
   }
  }
  else if(Position==1) {
  for (pos = 90; pos >= 0; pos -= 90) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100); 
    Serial.println("close");// waits 15ms for the servo to reach the position
  }
}
}
