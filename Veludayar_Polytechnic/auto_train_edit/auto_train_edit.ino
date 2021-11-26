#include<LiquidCrystal.h>  //include LCD library
LiquidCrystal LCD(9,8,7,6,5,4);
int gate  = 11;
int IRtrain = 2;
int IRpass = 3;
int red = 12;
int green = 13;
int x,y,count;

void setup() {
  // put your setup code here, to run once:
LCD.begin(16,2);
LCD.setCursor(0,0); 
LCD.print("Limit: 20");
Serial.begin(9600);
pinMode(gate,OUTPUT);
pinMode(IRtrain,INPUT);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
LCD.setCursor(0,1); 
LCD.print("Count: ");
}

void loop() {

//attachInterrupt(digitalPinToInterrupt(2), motor ,CHANGE);
attachInterrupt(digitalPinToInterrupt(3), travel ,RISING);

 IRtrain = digitalRead(2);
 Serial.println(IRtrain);
 IRpass = digitalRead(3);
 //Serial.println(IRpass);
 
 
 
if(IRtrain==0)   {
  x=1;
  LCD.setCursor(7,1); 
  LCD.print("    ");
  count = 0;
  digitalWrite(gate,HIGH);
  delay(1000);
  digitalWrite(gate,LOW);
  digitalWrite(green,LOW);
  digitalWrite(red,HIGH);
  delay(5000);  
 }

if(count>20) {
  x=0; 
  LCD.setCursor(7,1); 
  LCD.print("full");
  digitalWrite(gate,HIGH);
  delay(1000);
  digitalWrite(gate,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  }
}

void motor() {
    if(x==1) {
    digitalWrite(gate,HIGH);
    }
 }

void travel() {
     if(count<=20) {
     count++;
     Serial.print("passenger ");
     Serial.println(count);
     LCD.setCursor(7,1); 
     LCD.print(count);
    } 
  }
//} 



  
/*  LCD.setCursor(9,0);
  LCD.print("lcd print");
  delay(500);
 
  LCD.setCursor(11,1);
//  LCD.print(analogRead(A1));
  delay(500);
  
  LCD.setCursor(9,0);
  LCD.print("   ");
  LCD.setCursor(11,1);
  LCD.print("   ");
  delay(100); 
  
  for(int i=255;i<=0;i--)
  analogWrite(train,i);
  delay(20);
  }
  */
