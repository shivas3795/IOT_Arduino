int count1=0;
int count2=0;
int flag4=LOW;
int flag3=LOW;
int i=HIGH;
String id;
int item = 0;
void setup()
{ 

Serial.begin(9600);
}

void loop() 
{
 int flag1=LOW;
 int flag2=LOW;
 
  if(Serial.available()>0) 
  {
  id= Serial.readString();
  id.trim();
  Serial.println(id);
  delay(1000);
   }
if(id=="07000FFFEC1B") {
  count1++;
  flag1=HIGH;
  }
if(id=="070011CF27FE") {
  count2++;
  flag2=HIGH;
  }


if(flag1==HIGH) {
    if (count1==1) {
    Serial.println("Arrival1 side");
    }
if (count1==2){
    Serial.println("Departure1 side");
    flag3=HIGH;
    }
    //flag3=HIGH;
    }
    

 if(flag2==HIGH) {
    if (count2==1){
    Serial.println("Arrival2 side");
    }
 if (count2==2){
    Serial.println("Deparature2 side");    
    flag4=HIGH;
    }
    //flag4=HIGH;
   }
 
 if ((flag3)&&(flag4)&&(i)==HIGH)
 {
   count2=0;
   count1=0;
  Serial.println("All Bags are collected"); 
  i=LOW; 
  }
id="";
}
