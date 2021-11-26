
void setup() {
 Serial.begin(9600);
}

void loop() 
{
 /*Serial.print("fire "); 
 Serial.println(digitalRead(2));
 Serial.print("sound ");
 Serial.println(digitalRead(3));
 Serial.print("IR ");
 Serial.println(digitalRead(4)); */
int x = analogRead(A0);

 String data;
 data +=x;
data +="\n";
 Serial.println(data);
 delay(100); 

 if((digitalRead(2)==0)||(digitalRead(3)==1)||(digitalRead(4)==1))
 {
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(6,LOW);
  delay(1000);
 }
 
 else 
 {
  digitalWrite(6,LOW);
  delay(1000);
 }
}
