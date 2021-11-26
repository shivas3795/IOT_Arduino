#include <ESP8266WiFi.h>
//#include<LiquidCrystal.h>  //include LCD library
//LiquidCrystal LCD(D4,D5,D6,D7,D8,A0);
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
WiFiServer server(80);  
int pin1 = D0;
int pin2 = D1;
int pin3 = D2;
int pin4 = D3;

void setup() {
  
Serial.begin(9600);
pinMode(pin1,INPUT);
pinMode(pin2,INPUT);
pinMode(pin3,INPUT);
pinMode(pin4,INPUT);
WiFi.begin(ssid, password);
//LCD.begin(16,2);
//LCD.setCursor(0,0); 
//LCD.print("Total Space: 4");
//LCD.setCursor(0,1); 
//LCD.print("Space Left: ");
while (WiFi.status() != WL_CONNECTED)
    {
    delay(500);
    Serial.print(".");
    }
server.begin(); 
Serial.println(WiFi.localIP());
}


void loop() {
int slot1 = digitalRead(pin1);
int slot2 = digitalRead(pin2);
int slot3 = digitalRead(pin3);
int slot4 = digitalRead(pin4);

int num=4;

if(slot1==0) {num--;} 
if(slot2==0) {num--;} 
if(slot3==0) {num--;} 
if(slot4==0) {num--;} 

//Serial.print("Space Available: ");
//String slot;
//slot += num; 
//Serial.println(slot);
Serial.println(String(num));
//LCD.setCursor(11,1); 
//LCD.print(num);
delay(1000);
 
  WiFiClient client = server.available(); //here client means browser, checks if server available
  if (!client)
  {
    return;
  }
  while(!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r'); //reads the first line of request
  client.flush(); //erase other lines 
  

//Web Server
client.println("HTTP/1.1 200 OK"); 
client.println("Content-Type: text/html");
client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.print("Space Available: ");
client.print(num);
client.println("<br><br>");
if(num==0){
  client.print("Parking Full");
  }

  client.println("</html>");
  delay(1);
}
