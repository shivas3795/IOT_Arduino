//MIT AI2Companion

#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>
int COUNT=0;
const int rs = D0, en = D1, d4 = D2, d5 = D3, d6 = D4, d7 = D5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const char* ssid = "gokulraj";    //  Your Wi-Fi Name
const char* password = "gokulraj";   // Wi-Fi Password
int inputLength = 0; 
char inputArray[31]; 

WiFiServer server(80); // server 80 used for Input-Output purpose

 void setup()
{
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
  String request = client.readStringUntil('\r'); //reads the first line of request
 
 
  int x=request.length()-8;
  request.remove(x);
  request.remove(0,5);
 
  Serial.println(request);
  Serial.println(request.length());
  
  
  if(request.length()<=32)
  {
      lcd.clear();
      lcd.setCursor(0,0); 
      request.toCharArray(inputArray,31); 
      for (int i = 0; i <= 15; i++) 
      {
        lcd.write(inputArray[i]);
      }
      
      lcd.setCursor(0,1);
      for (int j = 16; j <=31; j++) 
      { 
        lcd.write(inputArray[j]); 
      }
    }
    if(request.length()>=32)
  {
  lcd.print("character exceeds");
  }
  client.flush(); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
  delay(10000);
  
}
