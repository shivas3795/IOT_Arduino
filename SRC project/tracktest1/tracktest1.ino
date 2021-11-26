#define trigPin 13
#define echoPin 12
#define led 11
int detect;
int x,y,z;
long duration, distance;

void setup()
{ 
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{ 
x = analogRead(A0);
y = analogRead(A1);
z = analogRead(A2);
Serial.print("x: ");
Serial.println(x);
delay(500);
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

if ((distance > 20)&&((x>370)||(x<300)))
{
 for(int i=1;i<=10;i++)
  Serial.println("Alert! Please Check");
  digitalWrite(led,HIGH);
  delay(500);
}

else {
  digitalWrite(led,LOW);
  }
Serial.print(distance);
Serial.println(" cm");
delay(100);

}
