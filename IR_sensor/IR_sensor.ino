int Sensor_pin = 6;
int ledpin = 11;
int buzz = 9;
void setup()
{
pinMode(Sensor_pin, INPUT); // Set the human infraredinterface as the input state 
pinMode(ledpin, OUTPUT);
pinMode(buzz, OUTPUT);
Serial.begin(9600);
Serial.flush();
Serial.println("Ready");
}
void loop()
{
int val = digitalRead(Sensor_pin); // Define parameters to store the state read by the human infrared senso
if (val == HIGH) // Buzzer make alarm if someone is detected
{
Serial.println("There is object moving");
digitalWrite(ledpin, HIGH);
digitalWrite(buzz, HIGH);
}
else
{
Serial.println("There isn't object moving");
digitalWrite(ledpin, LOW);
digitalWrite(buzz,LOW);
}
delay(700); // Delay 700 milliseconds }
}
