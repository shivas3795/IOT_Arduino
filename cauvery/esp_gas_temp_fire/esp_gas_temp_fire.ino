#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
int tempPin = A0;
int gasPin = D0;
int firePin = D3;
int fan = D1;

float temperature;
unsigned long myChannelNumber =  982230; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "9Z0GUF8J3C10C31V"; //Your Write API Key 
const char* ssid = "nirmala";    //  Your Wi-Fi Name
const char* password = "nimi3011";   // Wi-Fi Password
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;

 void setup()
{
 pinMode(gasPin,INPUT);
 pinMode(firePin,INPUT);
 pinMode(fan, OUTPUT);
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
 int fireValue = digitalRead(firePin);
 int gasValue = digitalRead(gasPin);
 int tempValue = analogRead(tempPin);
 float voltageOut = (tempValue);
 Serial.print("Fire Value: ");
 Serial.println(fireValue);
 Serial.print("Gas Value: ");
 Serial.println(gasValue);
  
 temperature = voltageOut*0.25;
 Serial.print("Tempertaure: ");
 Serial.println(temperature);
 delay(1000);

 if((gasValue==1)||(temperature>35)||(fireValue==0)) {
  Serial.println("Attention!");
  digitalWrite(fan,HIGH);           
  }
  else                       
  digitalWrite(fan,LOW);     
 
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
  
  if(gasValue==1) {
  client.println(" Attention! Gas detected;"); 
  }
  if(temperature>40) {
  client.println(" Attention! Temperature Rise;"); 
  }
  if(fireValue==0) {
  client.println(" Attention! Fire Detected;"); 
  }
  if((gasValue==1)&&(temperature>40)&&(fireValue==0))                      
  client.print(" No Risk Found!");
   
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
       
