int flag1=HIGH;
int flag2=HIGH;
int flag3=HIGH;
int flag4=HIGH;
int Flag7=HIGH;
int Flag6=HIGH;
int Flag8=HIGH;
int Flag9=HIGH; 

String way;
//int way2=LOW;
//int way3=LOW;
//int way4=LOW;
   
int FLAGEND = LOW;

void setup() {
Serial.begin(9600);
  pinMode(31,INPUT);
   pinMode(33,INPUT);
    pinMode(35,INPUT);
     pinMode(37,INPUT);
      pinMode(39,INPUT);
        pinMode(41,INPUT);
   pinMode(43,INPUT);
    pinMode(45,INPUT);
    
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
     pinMode(7,OUTPUT);
      pinMode(11,OUTPUT);
       pinMode(12,OUTPUT);
        pinMode(13,OUTPUT);
         pinMode(51,OUTPUT);
          pinMode(49,OUTPUT);
           pinMode(53,OUTPUT);
            digitalWrite(4,LOW);
             digitalWrite(3,LOW);
              digitalWrite(2,LOW);
               digitalWrite(51,LOW);
                digitalWrite(49,LOW);
                 digitalWrite(53,LOW);
                  digitalWrite(11,LOW);
                   digitalWrite(12,LOW);
                    digitalWrite(13,LOW);
                     digitalWrite(5,LOW);
                      digitalWrite(6,LOW);
                       digitalWrite(7,LOW);
                       digitalWrite(18,HIGH);
                       digitalWrite(16,HIGH);
                       digitalWrite(14,HIGH);

                       
                       
}

void loop() { 

  attachInterrupt(digitalPinToInterrupt(18),buttonPressed1,RISING);
  attachInterrupt(digitalPinToInterrupt(19),buttonPressed2,RISING);
  attachInterrupt(digitalPinToInterrupt(20),buttonPressed3,RISING);
  attachInterrupt(digitalPinToInterrupt(21),buttonPressed4,RISING);

  if(FLAGEND == HIGH)
  {
      delay(10000);
      FLAGEND = LOW;
      Flag6 = HIGH;
      Flag7 = LOW;
      Flag8 = LOW;
      Flag9 = LOW;
  }
  
  if(Flag6 == HIGH)  {
  way="way1"; 
  Serial.println(way);  
  digitalWrite(49,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(11,HIGH);     
  digitalWrite(2,LOW); 
  //GREEN LED OFF
  digitalWrite(7,LOW);
  digitalWrite(13,LOW);
  digitalWrite(53,LOW);
   digitalWrite(51,LOW);
   digitalWrite(12,LOW);
  digitalWrite(3,HIGH);
  delay(500);   
  digitalWrite(3,LOW); 
  digitalWrite(4,HIGH);
  delay(2000);
  digitalWrite(4,LOW);
  Flag6 = LOW;
  Flag7 = HIGH;
  Flag8 = LOW;
  Flag9 = LOW;
  }
  
  else if(Flag7 == HIGH) 
  {
  way="way2"; 
  Serial.println(way); 
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
   digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
   
 //GREEN LED OFF
  digitalWrite(7,LOW);
  digitalWrite(11,HIGH); 
  digitalWrite(12,LOW);
  digitalWrite(13,LOW); 
  digitalWrite(49,LOW);
  digitalWrite(51,HIGH); 
  delay(500);  
  digitalWrite(51,LOW);  
  digitalWrite(53,HIGH);
  delay(2000);
  digitalWrite(53,LOW);
  Flag8 = HIGH;
  Flag7 = LOW;
  Flag6 = LOW;
  Flag9 = LOW;
  }
  
  else if(Flag8 == HIGH) 
  {
  way="way3"; 
  Serial.println(way); 
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(49,HIGH);
  digitalWrite(51,LOW);
  digitalWrite(53,LOW);  
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);  
  digitalWrite(11,LOW);
  delay(2000);

  //GREEN LED OFF
  digitalWrite(12,HIGH);
  delay(500);    
  digitalWrite(12,LOW);  
  digitalWrite(13,HIGH);
  delay(2000);
  digitalWrite(13,LOW);
  Flag9 = HIGH;
  Flag8 = LOW;
  Flag7 = LOW;
  Flag6 = LOW;
   
  }
 
  else if(Flag9 == HIGH) 
  {
  way="way4"; 
  Serial.println(way); 
  digitalWrite(49,HIGH);
  digitalWrite(51,LOW);
  digitalWrite(53,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(11,HIGH);  
  digitalWrite(12,LOW); 
  digitalWrite(13,LOW); 
  digitalWrite(5,LOW);
  delay(2000);
  digitalWrite(6,HIGH); 
  delay(500);   
  digitalWrite(6,LOW);   
  digitalWrite(7,HIGH);
  delay(2000);
  digitalWrite(7,LOW);
  Flag6 = HIGH;
  Flag9 = LOW;
  Flag7 = LOW;
  Flag8 = LOW;
  }
 }

void buttonPressed1()          

{                    
   flag1 = LOW;
   Flag6 = LOW; 
   Flag7 = LOW; 
   Flag8 = LOW; 
   Flag9 = LOW;  

   if((flag1 == LOW)&&(digitalRead(37)==HIGH))
   {
    way="way1"; 
    Serial.println(way); 
      digitalWrite(3,LOW);
      digitalWrite(2,LOW);
      digitalWrite(51,LOW);
      digitalWrite(49,HIGH);
      digitalWrite(53,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);     
    
         flag1 = HIGH;                        
         FLAGEND = HIGH;
                            
     }
  }


void buttonPressed2()          

{                    
   flag2 = LOW;
   Flag6 = LOW; 
   Flag7 = LOW; 
   Flag8 = LOW; 
   Flag9 = LOW;  

   if((flag2 == LOW)&&(digitalRead(35)==HIGH))
   {
    way="way2"; 
    Serial.println(way); 
      digitalWrite(3,LOW);
      digitalWrite(2,HIGH);
      digitalWrite(51,LOW);
      digitalWrite(49,LOW);
      digitalWrite(53,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);     
    
       flag2 = HIGH;                        
       FLAGEND = HIGH;     
   }
   }

void buttonPressed3()          

{                    
   flag3 = LOW;
   Flag6 = LOW; 
   Flag7 = LOW; 
   Flag8 = LOW; 
   Flag9 = LOW;  

   if((flag3 == LOW)&&(digitalRead(33)==HIGH))
   {
      way="way3"; 
      Serial.println(way); 
        digitalWrite(3,LOW);
        digitalWrite(2,HIGH);
        digitalWrite(51,LOW);
        digitalWrite(49,HIGH);
        digitalWrite(53,LOW);
        digitalWrite(4,LOW);
        digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        digitalWrite(13,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);     
    
         flag3 = HIGH;                        
         FLAGEND = HIGH;     
   }
   }   


 void buttonPressed4()          

{                    
   flag4 = LOW;
   Flag6 = LOW; 
   Flag7 = LOW; 
   Flag8 = LOW; 
   Flag9 = LOW;  

   if((flag4 == LOW)&&(digitalRead(31)==HIGH))
   {
     way="way4"; 
     Serial.println(way);  
      digitalWrite(2,HIGH);
      digitalWrite(51,LOW);
      digitalWrite(49,HIGH);
      digitalWrite(53,LOW);
      digitalWrite(4,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);       
      
      flag4 = HIGH;                        
      FLAGEND = HIGH;     
   }
}   

   
