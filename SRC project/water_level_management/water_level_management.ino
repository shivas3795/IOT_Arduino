#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <LiquidCrystal.h>
const int rs = D1, en = D2, d4 = D4, d5 = D5, d6 = D6, d7 = D7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int gasPin = D8;
int waterPin = A0;
int turb = D0;
float temperature;
const char* ssid = "Lenovo K8 Plus 3516";    //  Your Wi-Fi Name
const char* password = "11111111";   // Wi-Fi Password
WiFiServer server(80); // server 80 used for Input-Output purpose
WiFiClient client;

 void setup()
{
 pinMode(waterPin,INPUT);
 pinMode(gasPin,INPUT);
 pinMode(turb,INPUT);
 lcd.begin(16, 2);
  Serial.begin(115200);
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
 int waterValue = analogRead(waterPin);
 int gasValue = digitalRead(gasPin);
 int turbidity = digitalRead(turb);
 
 Serial.print("Water Sensor: ");
 Serial.println(waterValue);
 lcd.setCursor(0, 0); 
 lcd.print("Water:"); 
 lcd.setCursor(0, 1); 
 lcd.print("Gas: "); 
 lcd.setCursor(12, 0); 
 lcd.print("Tb:"); 
 
 if(waterValue>500) {
  
  lcd.setCursor(6,0); 
  lcd.print("Full"); 
  delay(1000);

  if(gasValue==1) {
  lcd.setCursor(0,5);   
  lcd.print("Normal");
  delay(1000);
  }
  if(gasValue==0) {
  lcd.setCursor(0,5); 
  lcd.print("Alert"); 
  delay(1000);
  }
  }
 if(waterValue<=500) {
  
  lcd.setCursor(6,0); 
  lcd.print("Empty"); 
  delay(1000);

  if(gasValue==1) {
  lcd.setCursor(5,1);   
  lcd.print("Normal");
  delay(1000);
  }
  if(gasValue==0) {
  lcd.setCursor(5,1); 
  lcd.print("Alert"); 
  delay(1000);
  }
  } 

 if(turbidity==1) {
  Serial.print("turbidity: ");
  Serial.println(turbidity);
  lcd.setCursor(15,0); 
  lcd.print("Y"); 
  delay(1000);
 }
  if(turbidity==0) {
  Serial.print("turbidity: ");
  Serial.println(turbidity);
  lcd.setCursor(15,0);   
  lcd.print("N");
  delay(1000);
  } 
 
 lcd.clear();
 Serial.print("Gas: ");
 Serial.println(gasValue);
 delay(100);
 
 WiFiClient client = server.available(); 
  if (!client)
  {
    return;
  }
  while(!client.available())
  {
    delay(1);
  } 

  String request = client.readStringUntil('\n'); //reads the first line of request
  client.flush(); //erase other lines 
  

  
 
//*------------------HTML Page Code---------------------*//

  client.println("HTTP/1.1 200 OK"); 
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print("Water Level: ");
  if(waterValue>500) {
  client.print("Full");
  }
  if(waterValue<500) {
  client.print("Empty"); 
  }
  client.print("<br>");
  
  client.println("Gas: ");
  if(gasValue==1) {
  client.print("Normal");
  }
  if(gasValue==0) {
  client.print("Attention! Gas detected"); 
  }
  client.print("<br>");
  
  client.println("Turbidity: ");
  if(turbidity==1) {
  client.print("Yes");
  }
  if(turbidity==0) {
  client.print("No"); 
  }
  client.println("<br>");
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
       
