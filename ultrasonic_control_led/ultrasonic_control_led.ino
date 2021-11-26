int echo = 3;
int trig = 2;
int buzz = 5;
int LED = 11;
int distance, Time;
void setup() {
  pinMode(echo,INPUT);
  pinMode(trig, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);

  Time = pulseIn(echo,HIGH);
  distance = 0.034*Time/2;
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);

  if(distance<50) {
    int volt = 255-5.1*distance;
    Serial.print("volt: ");
    Serial.println(volt);
    analogWrite(buzz,volt); 
    delay(10); 
  }
  else {
      //analogWrite(LED,0);
      analogWrite(buzz,0);
      }
}
