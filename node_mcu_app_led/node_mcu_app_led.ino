#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>
int COUNT=0;
const int rs = D1, en = D2, d4 = D4, d5 = D5, d6 = D6, d7 = D7,LED=D3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const char* ssid = "Pantech Thillainagar";    //  Your Wi-Fi Name
const char* password = "pantechtry";   // Wi-Fi Password
int inputLength = 0; 
char inputArray[31]; 

WiFiServer server(80); // server 80 used for Input-Output purpose

 void setup()
{
  pinMode(LED,OUTPUT);
  Serial.begin(115200); //Default Baudrate
  lcd.begin(16, 2);
 
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
  
  Serial.println("/");
}

void loop()
{
  String inc = Serial.readStringUntil('\n'); //reads the first line of request
  
  int b=inc.toInt();
  Serial.println(b);
  
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
  Serial.println(request);
   //Serial.println(request.indexOf());
  client.flush(); //erase other lines 
  int value = LOW; 
  if(request.indexOf("/LED=ON") != -1)
  {
    lcd.print("on");
    digitalWrite(LED, HIGH); // Turn LED ON
    value = HIGH;
  }
  if(request.indexOf("/LED=OFF") != -1) 
  {
    lcd.print("off");
    digitalWrite(LED, LOW); // Turn LED OFF
    value = LOW;
       }
}
