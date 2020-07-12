import cv2
import sys

print('Hello, OpenCV', cv2.__version__)

img = cv2.imread('cat.png', cv2.IMREAD_GRAYSCALE)

if img is None:
   print('Image load failed')
   sys.exit()

cv2.imwrite('cat_gray.png', img)

cv2.namedWindow('image')
cv2.imshow('image', img)
cv2.waitKey(0)
