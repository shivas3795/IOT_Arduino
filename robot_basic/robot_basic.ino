const int inputPin1  = D0;    // Pin 15 of L293D IC
const int inputPin2  = D1;    // Pin 10 of L293D IC
//Motor B
const int inputPin3  = D2;   // Pin  7 of L293D IC
const int inputPin4  = D3;   // Pin  2 of L293D IC
void setup() {
  // put your setup code here, to run once:
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(inputPin1,HIGH); 
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW);  
    delay(2000);

    digitalWrite(inputPin1,LOW); 
    digitalWrite(inputPin2,HIGH);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,HIGH); 
    delay(2000); 

    digitalWrite(inputPin1,HIGH); 
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,LOW);
    digitalWrite(inputPin4,LOW); 
    delay(2000); 

    digitalWrite(inputPin1,LOW); 
    digitalWrite(inputPin2,LOW);
    digitalWrite(inputPin3,HIGH);
    digitalWrite(inputPin4,LOW); 
    delay(2000); 
}
