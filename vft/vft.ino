#include <BoltIoT-Arduino-Helper.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>


#ifndef API_KEY
#define API_KEY   "17c63b48-8cbb-4509-a874-800557df372d"
#endif
#ifndef DEVICE_ID
#define DEVICE_ID "BOLT290676"
#endif

#define DHTPIN            2


#define DHTTYPE           DHT11     // DHT 11 



DHT_Unified dht(DHTPIN, DHTTYPE);

float Temperature,Humidity;
bool TemperatureValueIsValid=false;
bool HumidityValueIsValid=false;

long NextMeasurementTime;

uint32_t delayMS;
String pushData(String *data){
  return String(Temperature)+","
  +String(Humidity)+","
  +String(TemperatureValueIsValid)+","
  +String(HumidityValueIsValid);
}

String getSensorDetail(String *data){
  String retval="",units="";
  sensor_t sensor;
  if(data[0].equals("Temperature")){
    dht.temperature().getSensor(&sensor);
    units="*C";
  }else if(data[0].equals("Humidity")){
    dht.humidity().getSensor(&sensor);
    units="%";
  }else{
    return "Invalid Sensor Type";
  }
  if(data[1].equals("Sensor")){
    retval=String(sensor.name);
  }else if(data[1].equals("Driver Ver")){
    retval=String(sensor.version);
  }else if(data[1].equals("Unique ID")){
    retval=String(sensor.sensor_id);
  }else if(data[1].equals("Max Value")){
    retval=String(sensor.max_value)+units;
  }else if(data[1].equals("Min Value")){
    retval=String(sensor.min_value)+units;
  }else if(data[1].equals("Resolution")){
    retval=String(sensor.resolution)+units;
  }else{
    retval="Unknown parameter";
  }
  return retval;
}

void setup(){
  boltiot.begin(Serial);
  dht.begin();
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  dht.humidity().getEvent(&event);
  NextMeasurementTime=millis()+delayMS;
  boltiot.setCommandString("RD\r",pushData);
  boltiot.setCommandString("GetData",pushData);
  boltiot.setCommandString("GetSensorDetails",getSensorDetail,2,'.'); //2 arguments are required. The command and argument should be seperted by a '.' character.
}

void loop(){
  boltiot.handleCommand();
  if(NextMeasurementTime>millis()){
    return;
  }
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if(isnan(event.temperature)){
    TemperatureValueIsValid=false;
  }else{
    TemperatureValueIsValid=true;
    Temperature=event.temperature;
  }
  dht.humidity().getEvent(&event);
  if(isnan(event.relative_humidity)){
    HumidityValueIsValid=false;
  }else{
    HumidityValueIsValid=true;
    Humidity=event.relative_humidity;
  }
}
