
#include <SoftwareSerial.h>
#include <dht.h>
dht DHT;

//SoftwareSerial mySerial(8,9);

// what pin we're connected to
#define DHT11_PIN 2

void setup()
{
  Serial.begin(9600);
//  mySerial.begin(9600);
  DHT.begin();
//  Serial.setTimeout(100);
}

//String data;
uint8_t dataRead = 0;

void loop()
{
  if (mySerial.available() > 0) {
    delay(50);
    String readData = "";
    Serial.print("Command from Bolt: ");
    while (mySerial.available() > 0 ) {
      readData = readData + (char)mySerial.read();
    }
    Serial.println(readData);
    if (readData.indexOf("RD") != -1) {
      String data = sensor_data_to_push();
      mySerial.print(data);
      Serial.print("Data sent to Bolt: ");
      Serial.println(data);
    }
  }
}

String sensor_data_to_push() {
  String data;
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  temp = temp * 1.8 + 32;  // convert Celsius to Farenheit
  data = String(temp) + "," + String(hum);
  return data;
}
