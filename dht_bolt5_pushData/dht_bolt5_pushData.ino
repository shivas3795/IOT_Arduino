#include <SoftwareSerial.h>
#include <BoltIoT-Arduino-Helper.h>
#include <dht.h>
dht DHT;
#include <BoltIoT-Arduino-Helper.h>

/*
 * This code monitors the status of pin 2, 
 * and sends the status fo the same to the cloud,
 * when the Bolt sends the RD\r command
 */

#ifndef API_KEY
#define API_KEY   "17c63b48-8cbb-4509-a874-800557df372d"
#endif
#ifndef DEVICE_ID
#define DEVICE_ID "BOLT290676"
#endif
#define DHT11_PIN 2

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup(){
	boltiot.begin(Serial);
  Serial.begin(9600);
  boltiot.begin(3,4); //Initialize the bolt interface over software serial uart.
  //In this example Tx pin of bolt is connected to pin 3 of arduino
  //and rx pin of bolt is connected to pin 4 of arduino
  pinMode(2,INPUT);
}

void loop() 
{
temp();
}


void temp()
{
//unsigned long currentMillis = millis();  
//float tim = currentMillis - previousMillis;
//Serial.println(tim);
//if ( tim >= interval) {
    // save the last time you blinked the LED
//    previousMillis = currentMillis;

    int chk = DHT.read11(DHT11_PIN);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    boltiot.processPushDataCommand(analogRead(A0),DHT.humidity);
//    delay(970);
//}
}	
