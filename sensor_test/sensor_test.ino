starttime = 10000;

void setup() {
  // put your setup code here, to run once:
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

if(millis)
for(int i=0;i<=10;i++)


}
