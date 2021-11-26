int echo = 7;
int trig = 8;
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
  //Serial.print(distance);
  //Serial.println(" cm");
  delay(500);

  if(distance<50) {
  int j=0; 
  while(j<255) {
      Serial.println(distance);
      j = map(distance, 50, 0, 0, 255);
      analogWrite(buzz,j);
      Serial.print("buzz: ");
      Serial.println(j);
      delay(500);
      }
    }
  
  else {
      //analogWrite(LED,0);
      analogWrite(buzz,0);
      }
}
