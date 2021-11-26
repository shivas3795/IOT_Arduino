String i;
void setup()
{
Serial.begin(9600);
pinMode(8,OUTPUT);
Serial.println("Enter 1/fwd//2/bwd");
}
void loop()
{
 Serial.println("Enter your option");
 if (Serial.available()>0)
 {
  i=Serial.readString();
  i.trim();
  Serial.println(i);
 }
if (i=="forward")
{

 Serial.println("Fwd");

}
if (i=="backward")
{

 Serial.println("Bwd");

}

i="";
}
