void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int a= digitalRead(7);
int b= digitalRead(8);
int c= digitalRead(9);
int d= digitalRead(10);
Serial.print("a ");
Serial.println(a);
Serial.print("b ");
Serial.println(b);
Serial.print("c ");
Serial.println(c);
Serial.print("d ");
Serial.println(d);
delay(1000);
}
