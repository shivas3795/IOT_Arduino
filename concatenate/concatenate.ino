#include <SoftwareSerial.h>


String f;

void setup() {
    Serial.begin(9600);
   
}

void loop() {
    float i = (random(100) + 1);
    float j = (random(100) + 1);

    f = String('H') + String(i) + String('T') + String(j);
    Serial.println(f);
    delay(1000);
}
