
#include <ESP8266WiFi.h>;
 
#include <WiFiClient.h>;
 
#include <ThingSpeak.h>;
 
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password


WiFiServer server(80);

 

 
int val;
 
int LDRpin = A0; //LDR Pin Connected at A0 Pin
 
 
 
WiFiClient client;
 
unsigned long myChannelNumber = 873880; //Your Channel Number (Without Brackets)
 
const char * myWriteAPIKey = "DG286EAQ0JS6QGPE"; //Your Write API Key 
 
void setup()
 
{
 
Serial.begin(9600);
 
delay(10);
 
// Connect to WiFi network
 
WiFi.begin(ssid, password);
 
 
 
ThingSpeak.begin(client);
 
}
 
 
 
void loop()
 
{
 
val = analogRead(LDRpin); //Read Analog values and Store in val variable
 
Serial.print(val); //Print on Serial Monitor
 
delay(1000);
 
ThingSpeak.writeField(myChannelNumber, 1,22, myWriteAPIKey); //Update in ThingSpeak
 
 
 
delay(100);
 
}
