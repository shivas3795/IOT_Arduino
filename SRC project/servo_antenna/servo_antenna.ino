#include <Servo.h>             //Servo library 
Servo servo_test;        //initialize a servo object for the connected servo  
String angle;    
 
void setup() 
{ 
  Serial.begin(9600);
  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
} 
  
void loop() 
{                                  
    if(Serial.available()) {
      angle = Serial.readString();
      Serial.println(angle);
      angle.trim();
      } 
    if(angle=="sun") {
    servo_test.write(30);                 //command to rotate the servo to the specified angle 
    }
    if(angle=="Sun Music") {
    servo_test.write(60);                 //command to rotate the servo to the specified angle 
    }
    if(angle=="KTV") {
    servo_test.write(90);                 //command to rotate the servo to the specified angle 
    }
    if(angle=="star") {
    servo_test.write(120);                 //command to rotate the servo to the specified angle 
    }
    if((angle=="Z")||(angle=="ji")) {
    servo_test.write(150);                 //command to rotate the servo to the specified angle 
    }
    if(angle=="Jaya") {
    servo_test.write(180);                 //command to rotate the servo to the specified angle 
    }
}
