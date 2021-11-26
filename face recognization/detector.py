import cv2
import numpy as np

faceDetect= cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
cam=cv2.VideoCapture(0)
rec=cv2.face.LBPHFaceRecognizer_create(); 
rec.read("recognizer/trainingData.yml")
id=0

font = cv2.FONT_HERSHEY_SIMPLEX
import serial
import time
a=""
ser = serial.Serial('COM3', 9600)
while True:
    ret,img=cam.read();
   
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
 
    
    faces =faceDetect.detectMultiScale(gray,1.3,5)
    for(x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(128,128,128),3)
        id,conf=rec.predict(gray[y:y+h,x:x+w])
        print (rec.predict(gray[y:y+h,x:x+w]))
        if (id==1 and conf<70):
            id="ABITHA"
            cv2.namedWindow("ABITHA",cv2.WINDOW_NORMAL)
            cv2.imshow("ABITHA",gray)
            ser.write(str.encode("ABITHA"))
            time.sleep(1)
        elif (id==2 and conf<70):
            id="RAGA SRI"
            cv2.namedWindow("HARINI",cv2.WINDOW_NORMAL)
            cv2.imshow("HARINI",gray)
            ser.write(str.encode("HARINI"))
            time.sleep(1)
           
            break

        a=''
        cv2.putText(img,id,(x,y-10),font,0.55,(0,255,0),1)
    cv2.imshow("Face",img);
    if(cv2.waitKey(5)==  ord('q')):
        break
    
cam.release()
cv2.destroyAllWindows()
        
    
