#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
#include <SoftwareSerial.h>
SoftwareSerial gps(4, 5); // RX, TX
SoftwareSerial mcu(2, 3); // RX, TX
int i=0;
int  gps_status=0;
float latitude=0; 
float logitude=0;                       
String gpsString="";
char *test="$GPRMC";
//////////////////////////////////////////////////
int Reset1 = A2;
int Reset2 = A1;
int Reset3 = A0;
int Reset4 = A3;
//////////////////////////////////////////////////////////////////////////////////////////
void initModule(String cmd, char *res, int t)
{
while(1)
{
Serial.println(cmd);
delay(100);
while(Serial.available()>0)
{
if(Serial.find(res))
{Serial.println(res);delay(t);return;}
else
{Serial.println("Error");}}
delay(t);
}
}
////////////////////////////////////////////////////////////////////////////////////
void setup()
{
lcd.begin(16, 2);
Serial.begin(9600);
gps.begin(9600);
mcu.begin(9600);
////////////////////////////////////////////////////////////////////////////////
pinMode(Reset1, INPUT);
digitalWrite(Reset1, HIGH);
pinMode(Reset2, INPUT);
digitalWrite(Reset2, HIGH);
pinMode(Reset3, INPUT);
digitalWrite(Reset3, HIGH);
pinMode(Reset4, INPUT);
digitalWrite(Reset4, HIGH);
////Smart Garbage Collecting Truck Using Arduino, GSM, GPS and Internet of Things (IOT)
lcd.print("AUTOMATIC GARBAGE");
lcd.setCursor(0, 1);
lcd.print("COLLECTING VAN");
delay(2000);
lcd.clear();
////////////////////////////////////////////////////////////////////////////////////  
lcd.print("USING GSM AND");
lcd.setCursor(0, 1);
lcd.print("GPS -IOT     ");
delay(2000);
lcd.clear();
////////////////////////////////////////////////////////////////////////////////////  
get_gps();
show_coordinate();
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GPS is OK");
delay(1000);
lcd.clear();
lcd.print("Initializing");
lcd.setCursor(0,1);
lcd.print("GSM MODEM");
delay(1000);
initModule("AT","OK",1000);
initModule("ATE1","OK",1000);
initModule("AT+CPIN?","READY",1000);  
initModule("AT+CMGF=1","OK",1000);     
initModule("AT+CNMI=2,2,0,0,0","OK",1000);  
lcd.clear();
lcd.print("Initialized");
lcd.setCursor(0,1);
lcd.print("Successfully");
delay(2000);
lcd.clear(); 
}
////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
//////////////////////////////////////////////////////////////////////////////////////
delay(1000);
if (!digitalRead(Reset4)){lcd.clear();lcd.print("EMPTY BIN");lcd.println("25");delay(500);}
if (!digitalRead(Reset1)){lcd.clear();lcd.print("LOW LEVEL");lcd.println("17");delay(500);}
if (!digitalRead(Reset2)){lcd.clear();lcd.print("MID LEVEL");lcd.println("9");delay(500);}
if (!digitalRead(Reset3)){lcd.clear();lcd.print("GARBAGE  BOX FULL ");mcu.println("4");delay(500);
get_gps();Send1();delay(500);
get_gps();Send2();delay(500);
st1:lcd.clear();lcd.print("plz collect box");delay(500);goto st1;}
Serial.println("Location is");delay(500);
Serial.print("https://www.google.com/maps/place/");
Serial.print(latitude,6);Serial.print(",");Serial.println(logitude,6);delay(500);
/////////////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////
void gpsEvent()
{
gpsString="";
while(1)
{
while (gps.available()>0)  //Serial incoming data from GPS
{
char inChar = (char)gps.read();
gpsString+= inChar;  //store incoming data from GPS to temparary string str[]
i++;
if (i < 7)                      
{
if(gpsString[i-1] != test[i-1])  //check for right string
{
i=0;
gpsString="";
}
}
if(inChar=='\r')
{
if(i>60)
{
gps_status=1;
break;
}
else
{
i=0;
}
}
}
if(gps_status)
break;
}
}
///////////////////////////////////////////////////////////////////
void get_gps()
{
lcd.clear();
lcd.print("Getting GPS Data");
lcd.setCursor(0,1);
lcd.print("Please Wait.....");
gps_status=0;
int x=0;
while(gps_status==0)
{
gpsEvent();
int str_lenth=i;
coordinate2dec();
i=0;x=0;
str_lenth=0;
}
}
////////////////////////////////////////////////////////////////////////////
void show_coordinate()
{
lcd.clear();
lcd.print("Lat:");
lcd.print(latitude);
lcd.setCursor(0,1);
lcd.print("Log:");
lcd.print(logitude);
delay(2000);
lcd.clear();
}
////////////////////////////////////////////////////////////////////////////
void coordinate2dec()
{
String lat_degree="";
for(i=19;i<=20;i++)         
lat_degree+=gpsString[i];
String lat_minut="";
for(i=21;i<=27;i++)         
lat_minut+=gpsString[i];
String log_degree="";
for(i=32;i<=34;i++)
log_degree+=gpsString[i];
String log_minut="";
for(i=35;i<=41;i++)
log_minut+=gpsString[i];
float minut= lat_minut.toFloat();
minut=minut/60;
float degree=lat_degree.toFloat();
latitude=degree+minut;
minut= log_minut.toFloat();
minut=minut/60;
degree=log_degree.toFloat();
logitude=degree+minut;
}
///////////////////////////////////////////////////////////////////////////////
void init_sms1()
{
Serial.println("AT+CMGF=1");delay(400);
Serial.println("AT+CMGS=\"9080647651\"");   // use your 10 digit cell no. here
delay(400);
}
///////////////////////////////////////////////////////////////////////////////
void init_sms2()
{
Serial.println("AT+CMGF=1");delay(400);
//Serial.println("AT+CMGS=\"8248424209\"");   // use your 10 digit cell no. here
Serial.println("AT+CMGS=\"8148394342\"");
delay(400);
}
////////////////////////////////////////////////////////////////////////////////
void send_data(String message)
{ Serial.print(message);delay(200);}
///////////////////////////////////////////////////////////////////////////////
void send_sms()
{ Serial.write(26);}
////////////////////////////////////////////////////////////////////////////////
void lcd_status()
{lcd.clear();lcd.print("Message Sent");delay(3000);return;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void Send1()
{ 
lcd.clear();
lcd.print("sending sms to");
lcd.setCursor(0, 1);
lcd.print("truck driver1");
delay(2000);
//////////////////////////////////////////////////////////////////////////////////////////  
init_sms1();
Serial.println("GARBAGE BOX NO:01");delay(500);
Serial.println("Location is");delay(500);
Serial.print("https://www.google.com/maps/place/");
Serial.print(latitude,6);Serial.print(",");Serial.println(logitude,6);delay(500);
send_data("PLZ Collect\nThankyou");delay(50);Serial.write(26);delay(2000);lcd.clear();lcd.print("Message Sent1");delay(3000);lcd.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Send2()
{ 
lcd.clear();
lcd.print("sending sms to");
lcd.setCursor(0, 1);
lcd.print("truck driver2");
delay(2000);
//////////////////////////////////////////////////////////////////////////////////////////  
init_sms2();
Serial.println("GARBAGE BOX NO:01");delay(500);
Serial.println("Location is");delay(500);
Serial.print("https://www.google.com/maps/place/");
Serial.print(latitude,6);Serial.print(",");Serial.println(logitude,6);delay(500);
send_data("PLZ Collect\nThankyou");delay(50);Serial.write(26);delay(2000);lcd.clear();lcd.print("Message Sent2");delay(3000);lcd.clear();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
