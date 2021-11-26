int val=0;
void setup() {
 pinMode(D2,OUTPUT);
 Serial.begin(9600);
  digitalWrite(D2,LOW);
}

void loop()
{
 val=analogRead(A0);
 Serial.println(val);
 int value=HIGH;
 if (val<750)
 {
  value=LOW;
 }
 else
 {
   value=HIGH;
    digitalWrite(D2,LOW);
 }
if(value==LOW)
{
  for(int i=0;i<10;i++)
  {
     digitalWrite(D2,HIGH);
  }
}
}
