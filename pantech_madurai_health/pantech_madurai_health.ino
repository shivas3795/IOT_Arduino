#include <ESP8266WiFi.h> //Node MCU library
#include <DHT.h>
#include <ThingSpeak.h>
unsigned long myChannelNumber =  984702; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "LX6U6DGJEJRIN35Z"; //Your Write API Key 
const char* ssid = "Pantech Thillainagar";    //  Your Hotspot Name
const char* password = "pantechtry";   // Wi-Fi Password
int pulse= D0;   // led connected to GPIO2 (D2)
int BP = A0; 
int count =68,pressure;
#define DHTPIN D1     // what pin we're connected to
#define DHTTYPE DHT11  // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); 

WiFiServer server(80); //port number assigned to connect web server to send and receive HTML data
WiFiClient client;

 void setup()
{
  Serial.begin(115200);
  dht.begin();
  ThingSpeak.begin(client);
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
  pressure = analogRead(BP)/15;
  
  
  String data;
  float temp = dht.readTemperature();
  temp = (temp * 1.8 + 32)/2.5;  // convert Celsius to Farenheit
  data = String(temp);
  
  if(digitalRead(pulse)==LOW)
  {
    count =count +1;
  }
  if (count>72)
  {
     count=68;
  }
  

  ThingSpeak.writeField(myChannelNumber, 1,temp, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2,pulse, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 3,pressure, myWriteAPIKey);
  
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
  
//*------------------HTML Page Code---------------------*//

  client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" HEALTH STATUS: ");
  client.println("<br><br>");
  
    client.print("Temperature: ");
    client.print(temp);
    client.println("<br><br>");
  
    client.print("Pulse: ");
    client.print(count);
    client.println("<br><br>");

    client.print("Blood Pressure: ");
    client.print(pressure);
    client.println("<br><br>");
  

  client.println("<br><br>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
