
void setup() {
  Serial.begin(9600);

  String stringOne = "A long integer: ";
  stringOne += 123456789;
  char charBuf[50];
  stringOne.toCharArray(charBuf, 50);  
  Serial.print(stringOne);
  }



void loop() {

  //Example
  
// String str = "This is my string"; 
//
//int str_len = str.length() + 1; 
//Serial.println(str_len);
//
//char char_array[str_len];
//
//str.toCharArray(char_array, str_len); // char_array is divides sentence into parts, str_len will help us to print original character   
//for(int i=0;i<=str_len;i++) {         //upto the required length
//  Serial.print(char_array[i]);
//  delay(200);
//  }
//  Serial.println("");
//  delay(500); 
//

}
