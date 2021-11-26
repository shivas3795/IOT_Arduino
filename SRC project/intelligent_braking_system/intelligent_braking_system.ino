#define trigPin 13
#define echoPin 12 
int detect;
int x,y,z;
int led = 6;
int buzz =7;

void setup()
{ 
  Serial.begin (9600);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{ 
x = analogRead(A0);
y = analogRead(A1);
z = analogRead(A2);
Serial.print("x: ");
Serial.println(x);
Serial.print("z: ");
Serial.println(z);
  
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.println(distance);
delay(1000);

if ((distance<60)||((z>370)||(z<280))||((x>380)||(x<300)))
{
  for(int i=1;i<=10;i++)
  Serial.println("Drive Safe");
  digitalWrite(led,HIGH);
  digitalWrite(buzz,HIGH);
  delay(1000);
  }
  
else {
  digitalWrite(led,LOW);
  digitalWrite(buzz,LOW);
  delay(1000);
  }
}
