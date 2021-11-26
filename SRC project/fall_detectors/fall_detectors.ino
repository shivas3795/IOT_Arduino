#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
float ax=0, ay=0, az=0, gx=0, gy=0, gz=0, Raw_AM;

boolean fall = false; //stores if a fall has occurred
int buzz=11;
int AM;

void setup(){
 Wire.begin();
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x6B);  // PWR_MGMT_1 register
 Wire.write(0);     // set to zero (wakes up the MPU-6050)
 Wire.endTransmission(true);
 Serial.begin(9600);

 pinMode(buzz, OUTPUT);
}


void loop(){

 mpu_read();
 Serial.print("Acceleration magnitude: ");
 Serial.println(AM);
     
     
 if (AM>25){           //in event of a fall detection
   Serial.println("FALL DETECTED");
   for(int i=1;i<=10;i++) {
   analogWrite(buzz,5);
   delay(100);
   analogWrite(buzz,0);
   delay(300);
   }
   fall = true;
 }
 
 if ((AM<15)&&(fall==false)) {
 Serial.println("Normal");
 }

if ((AM<15)&&(fall==true)) {
 for(int j=1;j<=15;j++) {
 mpu_read();
 if (AM<15) {
    Serial.println("Person Fallen");
    analogWrite(buzz,100);
    delay(500);    
    analogWrite(buzz,0);
    delay(100);
   }
 } 
  fall=false;   
}
}

void mpu_read(){
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
 Wire.endTransmission(false);
 Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
 AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
 AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
 AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
 Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
 GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
 GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
 GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

 //2050, 77, 1947 are values for calibration of accelerometer
 // values may be different for you
 ax = (AcX-2050)/16384.00;
 ay = (AcY-77)/16384.00;
 az = (AcZ-1947)/16384.00;

 //270, 351, 136 for gyroscope
 gx = (GyX+270)/131.07;
 gy = (GyY-351)/131.07;
 gz = (GyZ+136)/131.07;

 // calculating Amplitute vactor for 3 axis
 Raw_AM = pow(pow(ax,2)+pow(ay,2)+pow(az,2),0.5);
 AM = Raw_AM * 10;  // as values are within 0 to 1, I multiplied 
                        // it by for using if else conditions 
 }
