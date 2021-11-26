#include <ESP8266WiFi.h>
#include <Servo.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <LiquidCrystal.h>

const int rs = D5, en = D4, d4 = D3, d5 = D2, d6 = D1, d7 = D0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pos;
Servo myservo;
long duration;
long distance, dist;
String data;
const int trigPin = D6;
const int echoPin = D7;
unsigned long myChannelNumber =  873880; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "DG286EAQ0JS6QGPE"; //Your Write API Key 
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;

 void setup()
{
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); 
  myservo.attach(D8);
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

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  //data += distance; 
  //data = String(distance);
  if(distance!=0){
  dist = distance;
  Serial.print(dist);
  Serial.println(" cm");
  delay(100);
  }
  lcd.clear();
  delay(100);
  if(distance>20)
  {
    lcd.print("EMPTY");
  }
  if(distance<=20&&distance>15)
  {
    lcd.print("LOW");
  }
  if(distance<=15&&distance>5)
  {
    lcd.print("MIDDLE");
  }
  if(distance<=5)
  {
    lcd.print("FULL");
  }
   
  ThingSpeak.writeField(myChannelNumber, 1,22, myWriteAPIKey);
   
  
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
  if(request.indexOf("/Dustbin=Close") != -1)
  {
    for (pos = 0; pos <= 100; pos += 100) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100); 
    Serial.println("close");
   }
  }
  if(request.indexOf("/Dustbin=Open") != -1) 
  {
    for (pos = 90; pos >= 0; pos -= 90) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println("open");// waits 15ms for the servo to reach the position
   }
  }
       

//*------------------HTML Page Code---------------------*//

  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" Dustbin Level: ");

  if(distance>20)
  {
    client.print("EMPTY");
    lcd.print("EMPTY");
  }
  if(distance<=20&&distance>15)
  {
    client.print("LOW");
    lcd.print("LOW");
  }
  if(distance<=10&&distance>5)
  {
    client.print("MIDDLE");
    lcd.print("MIDDLE");
  }
  if(distance<=5)
  {
    client.print("FULL");
    lcd.print("FULL");
  }
  client.println("<br><br>");
  client.println("<a href=\"/Dustbin=Close\"\"><button>CLOSE</button></a>");
  client.println("<a href=\"/Dustbin=Open\"\"><button>OPEN</button></a><br />");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
       
