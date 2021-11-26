const int inputPin1  = 2;    // Pin 15 of L293D IC
const int inputPin2  = 3;    // Pin 10 of L293D IC
//Motor B
const int inputPin3  = 4;   // Pin  7 of L293D IC
const int inputPin4  = 5;   // Pin  2 of L293D IC
String inst="";

void setup() 
{
    Serial.begin(9600);
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
    Serial.println("Enter forward/back/right/left");
//    while(Serial.available()==0) {}
//    inst = Serial.readString();
//    Serial.println(inst);
}

void loop() 
{
  // 0 0 Stop
  // 0 1 Anti Clockwise
  // 1 0 Clockwise
  // 1 1 Stop
if(Serial.available()>0) {
    inst = Serial.readString();
    inst.trim();
    Serial.println(inst);
    } 
if(inst=="forward") {
    digitalWrite(inputPin1,HIGH); 
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW); 
}
else if(inst=="back") {
    digitalWrite(inputPin1,LOW); 
    digitalWrite(inputPin2,HIGH);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,HIGH);  
}
else if(inst=="left") {
    digitalWrite(inputPin1,LOW); 
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);  
}
else if(inst=="right") {
    digitalWrite(inputPin1,HIGH); 
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,LOW); 
}
else if(inst=="stop") {
    digitalWrite(inputPin1,LOW); 
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,LOW); 
}
}
