#include <ESP8266WiFi.h>
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
int pin1 = D0;   // led connected to GPIO2 (D4)
int pin2 = D1;
int pin3 = D2;
int pin4 = D3;
WiFiServer server(80); // server 80 used for Input-Output purpose

 void setup()
{
  Serial.begin(115200); //Default Baudrate
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  digitalWrite(pin1,LOW); 
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW); 
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
  client.flush(); //erase other lines 
  int value = LOW; 
  if(request.indexOf("/forward=ON") != -1)
  {
    digitalWrite(pin1,HIGH); 
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW); 
    delay(3000); 
    value = HIGH;
  }
  if(request.indexOf("/back=ON") != -1)
  {
    digitalWrite(pin1,LOW); 
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);   
    delay(3000); 
    value = LOW;
  }
  if(request.indexOf("/left=ON") != -1)
  {
    digitalWrite(pin1,LOW); 
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW); 
    delay(3000); 
  }
  if(request.indexOf("/right=ON") != -1)
  {
    digitalWrite(pin1,HIGH); 
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW); 
    delay(3000); 
  }
    if(request.indexOf("/stop=ON") != -1)
  {
    digitalWrite(pin1,LOW); 
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW); 
    delay(3000); 
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
    client.print("forward");
  }
  else
  {
    client.print("back");
  }

  client.println("<br><br>");
  client.println("<a href=\"/forward=ON\"\"><button>forward</button></a>");
  client.println("<a href=\"/back=ON\"\"><button>back</button></a>");
  client.println("<a href=\"/left=ON\"\"><button>left</button></a>");
  client.println("<a href=\"/right=ON\"\"><button>right</button></a>");
  client.println("<a href=\"/stop=ON\"\"><button>stop</button></a><br />");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
