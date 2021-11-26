import os
import cv2
import numpy as np
from PIL import Image

recognizer=cv2.face.LBPHFaceRecognizer_create() 
path='database'

def getImageID(path):
    imagePath=[os.path.join(path,f) for f in os.listdir(path)]
    faces=[]
    IDs=[]
    for image in imagePath:
        faceImg=Image.open(image).convert('L')
        faceNP=np.array(faceImg,'uint8')
        ID=int(os.path.split(image)[-1].split('.')[1])
        faces.append(faceNP)
        print (ID)
        IDs.append(ID)
        cv2.imshow("training",faceNP)
        cv2.waitKey(10)
    return IDs,faces

IDs,faces=getImageID(path)
recognizer.train(faces,np.array(IDs))
recognizer.save('recognizer/trainingData.yml')
cv2.destroyAllWindows()
