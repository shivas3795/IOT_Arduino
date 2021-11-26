 String ch;
void setup() {
 Serial.begin(9600); //Default Baudrate

}

void loop() {
 if(Serial.available()>0)
 {
  ch=Serial.readString();
  Serial.println(ch);
  delay(1000);
 }
ch="";
}
