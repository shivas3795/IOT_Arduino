String data;
void setup() {
  Serial.begin(9600);
 pinMode(3,OUTPUT);
 digitalWrite(3,LOW);
}

void loop() {
  if(Serial.available()>0)
  {
    data=Serial.readString();
    data.trim();
    Serial.print(data);
    
  }
  if (data!="")
  {
    
    if (data=="ABITHA")
    {
     digitalWrite(3,HIGH);
    delay(2000);
    digitalWrite(3,LOW);
    }
    if (data=="PARTHA SARATHY")
    {
     digitalWrite(3,HIGH);
    delay(1000);
    digitalWrite(3,LOW);
    }
    else
    {
     data="un_known";
     digitalWrite(3,LOW);
    }
    data="";
  }
  }
