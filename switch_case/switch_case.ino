// #include <SoftwareSerial.h>

//SoftwareSerial Serial(9, 10);

void setup()
{
  //Serial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    //case 'r':
    //  RecieveMessage();
    //  break;
  }

 if (Serial.available()>0)
   Serial.write(Serial.read());
}


 void SendMessage()
{
  Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  Serial.println("AT+CMGS=\"+917845829919\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("I am SMS from GSM Module");// The SMS text you want to send
  delay(100);
  Serial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}
