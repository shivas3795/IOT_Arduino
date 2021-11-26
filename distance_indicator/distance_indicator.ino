#define trigPin 6
#define echoPin 7
#define led 11
int x;
void setup()
{ 
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{ 
 long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.println(distance);
delay(1000);
//if (distance < 10)
//{
//  digitalWrite(led,HIGH);
//  x=millis();
//}
//
//else {
//digitalWrite(led,LOW);
//}

}
