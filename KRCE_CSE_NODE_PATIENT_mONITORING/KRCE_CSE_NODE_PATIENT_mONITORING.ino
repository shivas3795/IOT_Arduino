#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#define HB_PIN D1
#define Buzz_PIN D2
#include <ESP8266WiFi.h>
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#define FIREBASE_HOST "https://health-monitoring-f9b78.firebaseio.com/"
#define FIREBASE_AUTH "MH2jvXhwefvaqvOkdGBpnUFQo2WwbBigSzRETZPH"
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password


WiFiServer server(80);

unsigned long myChannelNumber = 1024831; //Your Channel Number (Without Brackets)
 
const char * myWriteAPIKey = "TEART0TOXLHDTTPA"; //Your Write API Key 
 
 String a,b;
   

int count=68;
int val;
WiFiClient client;
void setup() {
  ThingSpeak.begin(client);

 Serial.begin(9600);
 pinMode(HB_PIN,INPUT);

  pinMode(Buzz_PIN,OUTPUT);
 
  digitalWrite(Buzz_PIN,LOW);
   //Serial.print("Connecting to the Newtork");
   
  WiFi.begin(ssid, password);  //connect to wifi
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    while (WiFi.status() != WL_CONNECTED)
    {
    delay(500);
    //Serial.print(".");
  }
  //Serial.println("WiFi connected"); 
  server.begin();  // Starts the Server
  //Serial.println("Server started");
  //Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  //Serial.println(WiFi.localIP());
  //Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format
  //Serial.print(WiFi.localIP());
  //Serial.println("/");
}


void loop() {
   int h = digitalRead(HB_PIN);
 
   val = analogRead(A0);
  float mv = (val/1024.0)*5000;
  float cel = mv/10;
  cel=cel-40;
  
     
   if(h== LOW )
       {
          //Serial.println("Beat Detected");
          count =count+1;
          delay(500);
       }
   if(count>72)
       {
         count =68;
         //Serial.println(" Heartbeat Exceedes");
         digitalWrite(Buzz_PIN,HIGH);
        delay(500);
        digitalWrite(Buzz_PIN,LOW);
        delay(500);
           
       }
      
     
  delay(1000);  
 
  Serial.println(count);   
 
  Serial.println(cel);   

  delay(1000);  
 
 
  WiFiClient client = server.available(); //here client means browser, checks if server available
  if (!client)
  {
    return;
  }
  //Serial.println("Waiting for new client");
  while(!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r'); //reads the first line of request
  
  client.flush(); //erase other lines 

    String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n <!DOCTYPE html> <html> <head> <title>IoT based Health Monitoring</title> <style>";
  s += "a:link {background-color: YELLOW;text-decoration: none;}";
  s += "table, th, td {border: 1px solid black;} </style> </head> <body> <h1  style=";
  s += "font-size:200%;";
  s += " ALIGN=CENTER>Measured Parameters</h1>";
  s += "<p ALIGN=CENTER style=""font-size:150%;""";
 s += "> <b></b></p> <table ALIGN=CENTER style=";
  s += "width:50%";
   s += "> <tr> <th>Temperature</th>";
  s += "<td ALIGN=CENTER >";
  s += cel;
  s += "</td> </tr> <tr> <th>HeartBeat</th> <td ALIGN=CENTER >";
  s +=count ;

  s += "</td>  </tr> </table> ";
 

  s += "</body> </html> \n";

  client.print(s);


}
