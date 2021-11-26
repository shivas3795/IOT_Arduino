int trig = 2;
int echo = 3;
float timer, distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
delayMicroseconds(10);

timer = pulseIn(echo,HIGH);
distance = timer * 340 * pow(10,-4)/2;
Serial.print(distance);
Serial.println(" cm");
delay(500);
}
