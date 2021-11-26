#include <SoftwareSerial.h>
#include <DHT.h>

SoftwareSerial mySerial(8,9);

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

void setup()
{
  Serial.begin(9600);
 
  dht.begin();
  Serial.setTimeout(100);
}

String data;
uint8_t dataRead = 0;

void loop()
{
 
   
  
 
  
   
      //String data = sensor_data_to_push();
     // mySerial.print(data);
      //Serial.print("data sent to bolt:");
     int hum = dht.readHumidity();
  int temp = dht.readTemperature();
      Serial.println(hum);
      Serial.println(temp);
    
  
}

/*String sensor_data_to_push() {
  String data;
 
  data = String(hum) + "," + String(temp);
  return data;
}*/



 
