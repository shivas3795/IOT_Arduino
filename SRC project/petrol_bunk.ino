int Level=A1;
int mVperAmp = 66;
int levelc;

int led=13;

char str[15];
void setup()
{
 
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
    pinMode(3, INPUT);
 digitalWrite(led,LOW);
}



void loop()
{
  
         int flag=LOW;
         levelc=analogRead(A1);
         Serial.println(levelc);
         delay(1000);     
       
      
        if(levelc<100)
        {
          flag=HIGH;
          delay(1000);
          
        }

    else
        {
         digitalWrite(led,LOW);
         Serial.println("not needed");
         delay(1000);
        }

if(flag==HIGH)
        {
          if( digitalRead(3)==HIGH)
          {
         digitalWrite(led,HIGH);
         
           Serial.println("finding station");
          delay(2000);
        }
     else
        {
         digitalWrite(led,LOW);
         Serial.println("fuel full");
         delay(1000);
        }
        }

  
}
 

