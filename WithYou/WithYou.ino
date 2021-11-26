#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String readvoice;
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  Serial.setTimeout(50);
   lcd.begin(16, 2);
   pinMode (6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   // when characters arrive over the serial port...
 if (Serial.available()) {
    // wait a bit for the entire message to arrive
  delay(100);
  lcd.clear();
  }
  while (Serial.available()){  //Check if there is an available byte to read
    
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  readvoice += c; //build the string- "lightson", "lightsoff"
       
  }  
  if(readvoice == "Smile") //lights on
  {
    digitalWrite(6, HIGH);   
        digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(13,LOW); 
  } 
  
 
     if(readvoice == "Angry")
   {
    digitalWrite(7,HIGH);
        digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
    digitalWrite(13,LOW);
    }
     if(readvoice == "Netural")
   {
    digitalWrite(8,HIGH);
        digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(13,LOW);
    }
     if(readvoice == "Disappointed")
   {
    digitalWrite(9,HIGH);
        digitalWrite(8,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(13,LOW);
    }
     if(readvoice == "Shocked")
   {
    digitalWrite(10,HIGH);
        digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(13,LOW);
    }
     if(readvoice == "Crazy")
   {
    digitalWrite(13,HIGH);
        digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
    }
      if(readvoice == "TakeCare")
   {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(13,LOW);
    digitalWrite(6,LOW);
    
    }
     if (readvoice.length() > 0) {
    Serial.println(readvoice); 
      lcd.print(readvoice);
 readvoice="";}}

