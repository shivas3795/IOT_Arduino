int tempPin = A1;
float temperature;

void setup() {
Serial.begin(9600);
}

void loop() {

int tempValue = analogRead(tempPin);
float voltageOut = (tempValue * 0.488281100);
  
temperature = voltageOut*0.5;
Serial.println(tempValue);
delay(500);
}
