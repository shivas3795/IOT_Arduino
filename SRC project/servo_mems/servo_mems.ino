#include <Servo.h>             //Servo library 
Servo servo_test;        //initialize a servo object for the connected servo      
int x,y,z;

void setup() 
{ 
  Serial.begin(9600);
  servo_test.attach(8);      // attach the signal pin of servo to pin9 of arduino
} 
  
void loop() 
{                                  
  x = analogRead(A0);
  y = analogRead(A1);
  z = analogRead(A2);

  Serial.print(x); 
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.println(z);
  delay(1000);
     
    if((x>380)&&(x<=400)) {
    servo_test.write(30);                 //command to rotate the servo to the specified angle 
    }
    if((x>360)&&(x<=380)) {
    servo_test.write(60);                 //command to rotate the servo to the specified angle 
    }
    if((x>340)&&(x<=360)) {
    servo_test.write(90);                 //command to rotate the servo to the specified angle 
    }
    if((x>320)&&(x<=340)) {
    servo_test.write(120);                 //command to rotate the servo to the specified angle 
    }
    if((x>300)&&(x<=320)) {
    servo_test.write(150);                 //command to rotate the servo to the specified angle 
    }
    if((x>260)&&(x<=300)) {
    servo_test.write(180);                 //command to rotate the servo to the specified angle 
    }
}
