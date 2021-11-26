int loopcount;

void setup() {
Serial.begin(9600);  

}

void loop() {
  
float starttime = millis();
float endtime = starttime;
while ((endtime - starttime) <=1000) // do this loop for up to 1000mS
{
// code here
loopcount = loopcount+1;
endtime = millis();
}
Serial.print (loopcount,DEC);
}
