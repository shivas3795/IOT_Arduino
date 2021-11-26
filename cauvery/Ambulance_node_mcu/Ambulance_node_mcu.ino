#include <ESP8266WiFi.h>
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
WiFiServer server(80);
String readString;
String way;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
    {
    delay(500);
    Serial.print(".");
    }
server.begin(); 
Serial.println(WiFi.localIP());
}

void loop() {


while(Serial.available()) {
    delay(2);  //delay to allow byte to arrive in input buffer
    way = Serial.readStringUntil('\n');
    way.trim();
    Serial.println(way);
    }
    WiFiClient client = server.available(); //here client means browser, checks if server available
  if (!client)
  {
    return;
  }
  while(!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r'); //reads the first line of request
  client.flush(); //erase other lines 

  
  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" Traffic Signal Status (Green): ");
  if(way == "way1")
  {
   // Serial.println(way);
    client.print("Way 1st");
  }
  if(way == "way2")
  {
   // Serial.println(way);
    client.print("Way 2nd");
  }
  if(way == "way3")
  {
  // Serial.println(way);
   client.print("Way 3rd");
  }
  if(way == "way4")
  {
   // Serial.println(way);
    client.print("Way 4th");
  }

  client.println("<br><br>");

  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
