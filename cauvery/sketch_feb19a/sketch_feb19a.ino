String way;
void setup() {
  
Serial.begin(9600);
}

void loop() {
 
while(Serial.available()) {
    delay(2);  //delay to allow byte to arrive in input buffer
    way = Serial.readString();
    way.trim();
    Serial.println(way);
    }
}
