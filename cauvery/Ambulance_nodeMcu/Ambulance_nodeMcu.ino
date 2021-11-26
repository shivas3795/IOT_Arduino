#include <ESP8266WiFi.h>
const char* ssid = "priya";    //  Your Wi-Fi Name
const char* password = "priya jp";   // Wi-Fi Password
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
  client.print(way);
  Serial.println(way);
  client.println("<br><br>");
  if(way == "way1")
  {
   // Serial.println(way);
    client.println("Way 1st: Green");client.println("<br>");
    client.println("Way 2nd: Red");client.println("<br>");
    client.println("Way 3rd: Red");client.println("<br>");
    client.println("Way 4th: Red");client.println("<br>");
  }
  if(way == "way2")
  {
   // Serial.println(way);
    client.println("Way 1st: Red");client.println("<br>");
    client.println("Way 2nd: Green");client.println("<br>");
    client.println("Way 3rd: Red");client.println("<br>");
    client.println("Way 4th: Red");client.println("<br>");
    
  }
  if(way == "way3")
  {
  // Serial.println(way);
    client.println("Way 1st: Red");client.println("<br>");
    client.println("Way 2nd: Red");client.println("<br>");
    client.println("Way 3rd: Green");client.println("<br>");
    client.println("Way 4th: Red");client.println("<br>");
  }
  if(way == "way4")
  {
   // Serial.println(way);
    client.println("Way 1st: Red");client.println("<br>");
    client.println("Way 2nd: Red");client.println("<br>");
    client.println("Way 3rd: Red");client.println("<br>");
    client.println("Way 4th: Green");client.println("<br>");
  }

  client.println("<br><br>");

  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
