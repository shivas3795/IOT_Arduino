#define trigPin 13
#define echoPin 12 

void setup()
{ 
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{ long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
Serial.println(distance);
delay(1000);

if(distance<15) {
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+919865258158\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("Distance less than 15cm");// The SMS text you want to send
  delay(6000);
  }
}
