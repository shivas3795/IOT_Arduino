#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
unsigned long myChannelNumber =  950614; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "AEO6JECVORERMWHD"; //Your Write API Key 
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
const int trig = D0;
const int echo = D2;
const int trig2 = D7;
const int echo2 = D8;
const int buzz = D5;
const int ir = D1;

float duration;
float distance;
float duration2;
float distance2;
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;

 void setup()
{
  Serial.begin(115200); //Default Baudrate
  
  pinMode(ir, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
 
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
  int IR= digitalRead(ir);
  int soil= analogRead(A0);
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echo, HIGH);
  distance= duration*340*pow(10,-4)/2;
  Serial.print("distance ");
  Serial.println(distance);

  digitalWrite(trig2,LOW);
  delayMicroseconds(10);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  
  duration2 = pulseIn(echo2, HIGH);
  distance2= duration2*340*pow(10,-4)/2;
  Serial.print("distance2 ");
  Serial.println(distance2);
ThingSpeak.writeField(myChannelNumber, 1,distance, myWriteAPIKey);
ThingSpeak.writeField(myChannelNumber, 2,distance2, myWriteAPIKey);
ThingSpeak.writeField(myChannelNumber, 3,soil, myWriteAPIKey);

  if(IR==HIGH) {
    digitalWrite(buzz,HIGH); //stop
    delay(1000);
    digitalWrite(buzz,LOW); //stop
    delay(1000);
    }
 else{
  digitalWrite(buzz,LOW); //stop
  }

      WiFiClient client = server.available(); //checking if client(browser) is available, server sends request to web server listening on port 80
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())  //wait until client send some data
  {
    delay(1);
  }
  String request = client.readStringUntil('\r'); //receives message from the client and read first line of request
  Serial.println(request); 
  client.flush(); //Discard any bytes that have been written to the client but not yet read

//*------------------HTML Page Code---------------------*//

  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" Distance 1: ");
  client.print(distance);
  client.println("<br>");
  client.print(" Distance 2: ");
  client.print(distance2);
  client.println("<br>");
  client.print(" Soil Condition: ");
  client.print(soil);
  client.println("<br><br>");
  
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
