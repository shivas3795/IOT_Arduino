#include <ESP8266WiFi.h> //Node MCU library
const char* ssid = "Pantech Thillainagar";    //  Your Hotspot Name
const char* password = "pantechtry";   // Wi-Fi Password
int count1=0;
int count2=0;
int flag3=LOW;
int flag4=LOW;
String id;

WiFiServer server(80); //port number assigned to connect web server to send and receive HTML data

void setup()
{
  Serial.begin(9600); //Default Baudrate
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
 int flag1=LOW;
 int flag2=LOW; 
 int value1=LOW;
 int value2=LOW;
 int value3=LOW;
 int value4=LOW;
 int result=LOW;
  if(Serial.available()>0) 
  {
  id = Serial.readString();
  Serial.println(id);
  delay(100);
  }
if(id=="07000FFFEC1B") {
  count1++;
  flag1=HIGH;
  }
if(id=="070011CF27FE") {
  count2++;
  flag2=HIGH;
  }

if(flag1==HIGH)   {
    if (count1==1){
    Serial.println("Arrival side:1");
    value1=HIGH;
    }
  if (count1==2){
    Serial.println("Departure side:1");
    flag3=HIGH;
    value2=HIGH;
    }
   } 

  if(flag2==HIGH) {
    if (count2==1){
    Serial.println("Arrival side:2");
    value3=HIGH;
    }
    if (count2==2){
    Serial.println("Departure side:2");
    flag4=HIGH;
    value4=HIGH;
    }
  }
 if ((flag3)&&(flag4)==HIGH)
 {
   count2=0;
   count1=0;
   result=HIGH;
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
  client.println(" STATUS: ");
  client.print("<br><br>");
  
  if(value1=HIGH) {
   // Serial.println("Arrival side:1");
    client.println("Arrival side:1");
    client.print(" ");
    }
  if(value2=HIGH) {
    //Serial.println("Departure side:1");
    client.println("Departure side:1");
    client.println("<br><br>");
    }
  if(value3=HIGH) {
    //Serial.println("Arrival side:2");
    client.println("Arrival side:2");
    client.print(" ");
    }
  if(value4=HIGH) {
    //Serial.println("Departure side:2");
    client.println("Departure side:2");
    client.println("<br><br>");
    }
  if(result=HIGH) {
    client.println("Collected"); 
   // break;
    }
    
id="";

  client.println("<br><br>");
  client.println("</html>");
  delay(1);
}
