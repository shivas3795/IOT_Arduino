int count=0;
void setup() {
 Serial.begin(9600);
 pinMode(4,OUTPUT);
 pinMode(2,INPUT);
}

void loop() 
{
 if(digitalRead(2)==0)
 {
  count+=1;
 
  delay(1000);
 }
 if (count>=5)
 {
  Serial.println("Drowsy");
  digitalWrite(4,HIGH);
  delay(3000);
   digitalWrite(4,LOW);
 count=0;
 }
 else 
 {
  Serial.println(count);
 }
}
