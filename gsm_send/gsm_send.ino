void setup()
{
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  //Serial.println("ATD +918148394342;\r");
  //delay(10000);
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+918148394342\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("I am SMS from GSM Module");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  //Serial.print("AT+CMGD=1,4\r");  // Deletes all SMS saved in SIM memory
  //delay(100);

}

void loop()
{
 
}
