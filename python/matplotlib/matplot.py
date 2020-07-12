import cv2
import matplotlib.pyplot as plt

imgBGR = cv2.imread('cat.png')
imgRGB = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2RGB)
imgGray = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2GRAY)

plt.subplot('121'), plt.axis(False), plt.imshow(imgRGB)
plt.subplot('122'), plt.axis(False), plt.imshow(imgGray, cmap='gray')

plt.show()