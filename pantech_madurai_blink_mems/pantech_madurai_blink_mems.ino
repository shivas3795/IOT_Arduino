#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
unsigned long myChannelNumber =  984714; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "AEO6JECVORERMWHD"; //Your Write API Key 
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print("Connecting to the Newtork");
  WiFi.begin(ssid, password);  //connect to wifi
  ThingSpeak.begin(client);
    while (WiFi.status() != WL_CONNECTED)
    {
    delay(500);
    Serial.print(".");
    }
  Serial.println("WiFi connected"); 
  server.begin();  // Starts the Server
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.println("/");
}



void loop() {
  // put your main code here, to run repeatedly:
String mems = Serial.readStringUntil('\n');
Serial.println("received");
Serial.println(mems);
 mems.trim();
int x= mems.toInt();
int y = x+50;
int z = x-50;
Serial.println("converted");
Serial.println(x);
if(x>0)
{
 ThingSpeak.writeField(myChannelNumber, 1,x, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2,y, myWriteAPIKey);
   ThingSpeak.writeField(myChannelNumber, 3,z, myWriteAPIKey);
}
}
