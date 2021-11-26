#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
int gasPin = D0;

unsigned long myChannelNumber =  958417; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "S777Y636BRZFUS9M"; //Your Write API Key 
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;

 void setup()
{
 pinMode(gasPin,INPUT);
 
  Serial.begin(115200);
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

void loop()
{
 int gasValue = analogRead(gasPin);

 
 Serial.print("Gas Value: ");
 Serial.println(gasValue);
  
 
 ThingSpeak.writeField(myChannelNumber, 1,gasValue, myWriteAPIKey);
 
 WiFiClient client = server.available(); 
  if (!client)
  {
    return;
  }
 // Serial.println("Waiting for new client");
  while(!client.available())
  {
    delay(1);
  } 


  String request = client.readStringUntil('\n'); //reads the first line of request
  //Serial.println(request);
  client.flush(); //erase other lines 
  

  
 
//*------------------HTML Page Code---------------------*//

  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("Status: ");
  client.print("<br><br>");
  client.println(gasValue);
  
  if(gasValue>500) {
  client.print(" Attention!");
  Serial.println("Attention!");
  }
  else                       {
  client.print(" No Risk Found!");
  Serial.println("No Risk Found!");
  }
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
       
