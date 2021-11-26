#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
int tempPin = A0;
int gasPin = D0;
int led = D2;
float temperature;
unsigned long myChannelNumber =  957377; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "76TSU3N4MWDKTACJ"; //Your Write API Key 
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;

 void setup()
{
 pinMode(gasPin,INPUT);
 pinMode(led,OUTPUT);
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
 int gasValue = digitalRead(gasPin);
 int tempValue = analogRead(tempPin);
 float voltageOut = (tempValue * 0.488281100);
 Serial.print("Gas Value: ");
 Serial.println(gasValue);
  
 temperature = voltageOut*0.18*3;
 Serial.print("Tempertaure: ");
 Serial.println(temperature);
 delay(100);

 if((gasValue==0)||(temperature>40)) {
  Serial.println("Attention!");
  digitalWrite(led,HIGH);           }
  else                       {
  Serial.println("No Risk Found!");
  digitalWrite(led,LOW);     }
 
 ThingSpeak.writeField(myChannelNumber, 1,temperature, myWriteAPIKey);
 
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
  client.println(temperature);
  
  if((gasValue==0)||(temperature>40)) {
  client.print(" Attention!");
  Serial.println("Attention!");
  digitalWrite(led,HIGH);           }
  else                       {
  client.print(" No Risk Found!");
  Serial.println("No Risk Found!");
  digitalWrite(led,LOW);     }
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
       
