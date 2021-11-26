String x;
void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
Serial.begin(9600);
Serial.println("Speak any word");
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println("Speak any word");
if (Serial.available()>0) {
  x= Serial.readString();
  x.trim();
  Serial.println(x);
}
}
