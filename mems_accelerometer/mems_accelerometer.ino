int x;
int y;
int z;
//accelerometer/angle sensor
void setup() {
  Serial.begin(9600);
}

void loop() {
 x = analogRead(A0);
 y = analogRead(A1);
 z = analogRead(A2);
Serial.print(x); 
//delay(1000);
Serial.print("\t");
Serial.print(y);
//delay(1000);
Serial.print("\t");
Serial.println(z);
delay(1000);
}
