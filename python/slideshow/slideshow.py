import cv2
import glob

image_paths = glob.glob('./images/*.jpg')
cnt = len(image_paths)
idx = 0

while True:
    img = cv2.imread(image_paths[idx])
    idx = (idx + 1) % cnt

    if img is None:
        print('Image load failed!')
        continue

    cv2.imshow('image', img)

    if cv2.waitKey(1000) == 27:
        break