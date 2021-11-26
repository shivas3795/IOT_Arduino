#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
unsigned long myChannelNumber =  984714; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "DZ9S4UF0RU725SS0"; //Your Write API Key 
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
const int trig = D6;
const int echo = D7;
const int trig2 = D0;
const int echo2 = D1;
const int buzz = D2;
const int motor = D3;

float duration;
float distance;
float duration2;
float distance2;
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;

 void setup()
{
  Serial.begin(115200); //Default Baudrate
  
  pinMode(motor, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(D5, OUTPUT);
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
  Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  digitalWrite(D5, HIGH);
  
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echo, HIGH);
  distance= duration*340*pow(10,-4)/2;
  Serial.print("distance ");
  Serial.println(distance);

  if(distance<50) {
    digitalWrite(motor,HIGH); //stop
    delay(1000);
    digitalWrite(motor,LOW); //stop
    delay(1000);
    }
}
