#include <ESP8266WiFi.h>
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
WiFiServer server(80); // server 80 used for Input-Output purpose

 void setup()
{
  Serial.begin(115200); //Default Baudrate
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  
  Serial.print("Connecting to the Newtork");
  WiFi.begin(ssid, password);  //connect to wifi
  
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
  WiFiClient client = server.available(); //here client means browser, checks if server available
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r'); //reads the first line of request
  Serial.println(request);
   //Serial.println(request.indexOf());
  client.flush(); //erase other lines 
  int value = LOW; 
  if(request.indexOf("/LED=Forward") != -1)
  {
    digitalWrite(D0,HIGH); //fwd
    digitalWrite(D1,LOW);
    digitalWrite(D2,HIGH);
    digitalWrite(D3,LOW);
  }
  if(request.indexOf("/LED=Back") != -1)
  {
    digitalWrite(D0,LOW); //back
    digitalWrite(D1,HIGH);
    digitalWrite(D2,LOW);
    digitalWrite(D3,HIGH);
  }
  if(request.indexOf("/LED=Left") != -1)
  {
    digitalWrite(D0,HIGH); //left
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
  }
  if(request.indexOf("/LED=Right") != -1)
  {
    digitalWrite(D0,LOW); //right
    digitalWrite(D1,LOW);
    digitalWrite(D2,HIGH);
    digitalWrite(D3,LOW);
  }
  if(request.indexOf("/LED=Stop") != -1)
  {
    digitalWrite(D0,LOW);
    digitalWrite(D1,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D3,LOW);
  }
  
  
//*------------------HTML Page Code---------------------*//

  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" CONTROL LED: ");
  if(value == HIGH)
  {
    client.print("ON");
  }
  else
  {
    client.print("OFF");
  }

  client.println("<br><br>");
  client.println("<a href=\"/LED=Forward\"\"><button>Forward</button></a>");
  client.println("<a href=\"/LED=Back\"\"><button>Back</button></a><br />");
  client.println("<a href=\"/LED=Left\"\"><button>Left</button></a><br />");
  client.println("<a href=\"/LED=Right\"\"><button>Right</button></a><br />");
  client.println("<a href=\"/LED=Stop\"\"><button>Stop</button></a><br />");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
