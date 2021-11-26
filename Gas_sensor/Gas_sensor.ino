int sensor1=D0;
int sensor2=A0;
int gas_value1,gas_value2;

void setup()
{

pinMode(sensor1,INPUT);
Serial.begin(115200);

}

void loop()
{
gas_value1=analogRead(sensor2);
gas_value2=digitalRead(sensor1);
Serial.println(gas_value1);
Serial.println(gas_value2);
delay(500);
}
