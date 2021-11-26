#include <BoltIoT-Arduino-Helper.h>
#include <dht.h>

dht DHT;
int b,c;
#define DHT11_PIN 2

void setup(){
  Serial.begin(9600);
  boltiot.begin(Serial);
}

void loop()
{
  String data;
  int chk = DHT.read11(DHT11_PIN);
 // Serial.print("Temperature = ");
 //
  b= DHT.temperature;
  data +=b;
  //Serial.println(DHT.temperature);
 // Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  c=DHT.humidity;
   data +=c;
 // boltiot.CheckPoll(DHT.temperature,DHT.humidity);
   Serial.println(DHT.humidity);
  boltiot.CheckPoll(digitalRead(2));
  delay(500);
}
/*
#include <BoltIot-Arduino-Helper.h>
  void setup() {
    boltiot.Begin(Serial); //Initialize the Bolt interface over serial uart. Serial could be replaced with Serial0 or Serial1 on Arduino mega boards.
         //In this example Tx pin of Bolt is connected to Rx pin of Arduino Serial Port
         //and Rx pin of Bolt is connected to tx pin of arduino Serial Port
    pinMode(2,INPUT); //Set pin 2 as input. We will send this pin's state as the data to the Bolt Cloud
  }
  void loop() {
    boltiot.CheckPoll(digitalRead(2)); //Send data to the Bolt Cloud, when the Bolt polls the Arduino for data.
  //This function needs to be called regularly. Calling the CheckPoll function once every seconds is required
  }
  
var lineGraph1 = new boltGraph();
lineGraph1.setChartType("lineGraph");
lineGraph1.setAxisName('time','Temperature');
lineGraph1.plotChart('time_stamp','temp');
dataDownload('True');

var lineGraph2 = new boltGraph();
lineGraph2.setChartType("lineGraph");
lineGraph2.setAxisName('time','Humidity');
lineGraph2.plotChart('time_stamp','humidity');
dataDownload('True');
  */
