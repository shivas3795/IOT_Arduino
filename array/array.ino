//char inputArray[0];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
String x = ("I am making array program");
for(int i=0;i<=x.length();i++)
{
  Serial.print(x[i]);
  delay(100);
}
Serial.println("");
}
