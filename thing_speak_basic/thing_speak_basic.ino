
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
 
const char* ssid = "Pantech Thillainagar"; //Your Network SSID
const char* password = "pantechtry"; //Your Network Password
unsigned long myChannelNumber =  950614; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "AEO6JECVORERMWHD"; //Your Write API Key 
 
//String latitude="10.7881924"; //28.612953,77.231545
//String logitude="78.6530119";
//String inchar="0.07";

WiFiClient client;
 

void setup()
 
{
 Serial.begin(115200);
 delay(10);
 WiFi.begin(ssid, password);
 ThingSpeak.begin(client);
}
 
 
void loop()
 {
 String data = Serial.readStringUntil('\n'); //reads the first line of request
 int distance = data.toInt();
 Serial.println(distance);

//ThingSpeak.writeField(myChannelNumber, 1,latitude, myWriteAPIKey); //Update in ThingSpeak
ThingSpeak.writeField(myChannelNumber, 1,distance, myWriteAPIKey); //Update in ThingSpeak
//ThingSpeak.writeField(myChannelNumber, 3,inchar, myWriteAPIKey); //Update in ThingSpeak
  // logitude
 
 delay(100);
 
}
