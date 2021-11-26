# Importing modules
import spidev # To communicate with SPI devices
from time import sleep  # To add delay
# Start SPI connection
spi = spidev.SpiDev() # Created an object
spi.open(0,0)
import RPi.GPIO as GPIO,time
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(26,GPIO.IN,pull_up_down = GPIO.PUD_UP)
GPIO.setup(19,GPIO.OUT)
# Read MCP3008 data
def analogInput(channel):
  spi.max_speed_hz = 1350000
  adc = spi.xfer2([1,(8+channel)<<4,0])
  data = ((adc[1]&3) << 8) + adc[2]
  return data
# Below function will convert data to voltage
def Volts(data):
  volts = (data * 3.3) / float(1023)
  volts = round(volts, 2) # Round off to 2 decimal places
  return volts
 
# Below function will convert data to temperature.
def Temp(data):
  temp = ((data * 330)/float(1023))-50
  temp = round(temp)
  return temp
count=68
while True:
  if(GPIO.input(26)== 0):
    count +=1
    print('Heart Beat Detected')
  else:      
   
    print('off')
  
  temp_output=analogInput(0)
 
  temp_volts = Volts(temp_output)
  temp       = (Temp(temp_output)+2)
  temp=(temp-20)*(-1)
  X = analogInput(1) # Reading from CH0
  Y = analogInput(2)
  Z = analogInput(3)
 
  print("Heart Beat=: {} ".format(count))
  print("Temp : {} ({}V) {} deg C".format(temp_output,temp_volts,(temp)))
  print("X=: {} , Y= {} , Z={}".format(X,Y,Z))
  f=open("log.txt","w")
  f.write("\n")
  f.write("Temperature: {} deg C".format(temp))
  f.write("<br/><br/></p>")
  f.write("\n")
  f.write("Heart Beat=: {} ".format(count))
  f.write("<br/><br/></p>")
  f.write("\n")
  f.write("Position: X=: {} , Y= {} , Z={}".format(X,Y,Z))
  f.write("<br/><br/></p>")
  f.write("\n")
  if count>72 or (temp < 35) or (400<X>500):
    count=68
    print('Alert')
    GPIO.output(19,True)
    sleep(2)
    GPIO.output(19,False)
    sleep(1)
  sleep(2)
  
    
        
