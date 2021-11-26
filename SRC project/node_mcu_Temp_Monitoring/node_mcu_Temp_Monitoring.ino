#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(D5,D4,D3,D2,D1,D0);
int tempPin = A0;
unsigned long myChannelNumber =  1024805; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "ULTGSMQIU9416Q5D "; //Your Write API Key 
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;

 void setup()
{
 
  pinMode(D6,OUTPUT);
  LCD.begin(16,2);
  
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
 
 int sensorValue = analogRead(tempPin);
 float voltageOut = (sensorValue * 0.48828125);
  
 float temperature = voltageOut*0.5;
 if(temperature>30) {
  digitalWrite(D6,HIGH);
  delay(1000);
  digitalWrite(D6,LOW);
  delay(1000);
  }
 Serial.print("Temperature(ºC): ");
 Serial.println(temperature); 
 LCD.setCursor(0,0); 
  LCD.print("Temp:");
  LCD.setCursor(6,0); 
  LCD.print(temperature);
  LCD.setCursor(12,0);
  LCD.print("*C");
  delay(1000);
  //LCD.clear();
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
  client.print(" Temperature(ºC): ");
  client.print(temperature);
  client.println("<br><br>");
  
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
       
