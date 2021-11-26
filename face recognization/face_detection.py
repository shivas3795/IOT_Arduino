import cv2
import numpy as np

faceDetect= cv2.CascadeClassifier("haarcascade_frontalface_default.xml")
cam=cv2.VideoCapture(0)

while True:
    ret,img=cam.read();
    #img=cv2.imread("fan.jpg")
    #print ret
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    cv2.imshow("face",img)
    cv2.namedWindow("detected",cv2.WINDOW_NORMAL)
    cv2.imshow("detected",gray)
    
    faces =faceDetect.detectMultiScale(gray,1.3,5)
    for(x,y,w,h) in faces:
        cv2.rectangle(img,(x,y),(x+w,y+h),(128,128,128),3)
        cv2.imshow("Face",img)
        #cv2.waitKey(1)
        
    if(cv2.waitKey(5)==  ord('q')):
        break
    
cam.release()
cv2.destroyAllWindows()
        
    
