int val=0;

void setup() {
pinMode(11,OUTPUT); //LED
pinMode(8,INPUT); //Switch
}

void loop() {
//val = digitalRead(8); //reads input

if(digitalRead(11)==LOW) {
digitalWrite(5,HIGH);
}
else {
digitalWrite(5,LOW);
}
}
