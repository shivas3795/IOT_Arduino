#include <ESP8266WiFi.h> //Node MCU library
const char* ssid = "Redmi_12";    //  Your Hotspot Name
const char* password = "asdfg4321";   // Wi-Fi Password
int LED = D3;   // led connected to GPIO2 (D2)
int trig = D1;
int echo = D2;
float distance;
float Time;
WiFiServer server(80); //port number assigned to connect web server to send and receive HTML data

 void setup()
{
  Serial.begin(115200); //Default Baudrate
  pinMode(LED, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(LED, LOW);
  Serial.print("Connecting to the Newtork");
  WiFi.begin(ssid, password);  //connects to wifi
  
    while (WiFi.status() != WL_CONNECTED) //if wifi is not connected it prints ....
    {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  server.begin();  // Starts the Server when wifi connected
  Serial.println("Server started");
  Serial.print("IP Address of network: "); // will IP address on Serial Monitor
  Serial.println(WiFi.localIP());
  Serial.print("Copy and paste the following URL: https://"); // Will print IP address in URL format
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  Time = pulseIn(echo, HIGH);
  distance = (Time/2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
  
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
  int value = LOW; //declare value as Low
  if(request.indexOf("/LED=ON") != -1) //if ON button pressed then LED is ON
  {
    if (distance < 15)

  {
    digitalWrite(LED,HIGH);
  }
  else {
    digitalWrite(LED,LOW);
  }
    value = HIGH;
  }
  if(request.indexOf("/LED=OFF") != -1) 
  {
    digitalWrite(LED,LOW); // Turn LED OFF
    value = LOW;
  }
  
//*------------------HTML Page Code---------------------*//

  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" CONTROL LED: ");
  if(value == HIGH)
  {
    client.print("Turn On");
    client.println("<br><br>");
    client.print(distance);
    client.print(" cm");
  }
  else
  {
    client.print("Turn Off");
  }

  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>"); //creating ON button
  client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br />"); //Creating OFF button
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
