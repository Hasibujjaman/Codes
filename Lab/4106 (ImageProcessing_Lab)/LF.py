import cv2
import numpy as np
import matplotlib.pyplot as plt


img = cv2.imread("road.bmp", cv2.IMREAD_GRAYSCALE)




img = cv2.imread("road.bmp", cv2.IMREAD_GRAYSCALE)
img_resized = cv2.resize(img, (255,255))
row, cols = img_resized.shape




log_img = np.zeros_like(img_resized)
max_intensity = np.max(img_resized)
C = 255 / np.log(1 + max_intensity)
for i in range(row):
    for j in range(cols):
        log_img[i, j] = C * np.log(1 + img_resized[i, j])



plt.figure(figsize=(12, 6))
# Org img
plt.subplot(1, 2, 1)
plt.imshow(img_resized, cmap='gray')
plt.axis('off')
plt.title('Original Image')
# log img
plt.subplot(1, 2, 2)
plt.imshow(log_img, cmap='gray')
plt.axis('off')
plt.title('Logarithmic Transformation Image')
plt.show()



def manual_median_filter(image, kernel_size):
    pad_size = kernel_size // 2
    padded_image = cv2.copyMakeBorder(image, pad_size, pad_size, pad_size, pad_size, cv2.BORDER_CONSTANT, value=0) # Zero padding
    
    filtered_image = np.zeros_like(image)

    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            region = padded_image[i : i + kernel_size, j : j + kernel_size]
            filtered_image[i, j] = np.median(region)
    
    filtered_image = (1/pad_size**2) * filtered_image
    filtered_image = np.clip(filtered_image, 0, 255).astype(np.uint8)

    return filtered_image

kernel_size = 3
median_filtered_img = manual_median_filter(log_img, kernel_size)


plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 2)
plt.imshow(img_resized, cmap='gray')
plt.axis('off')
plt.title('Original image')
plt.show()

plt.subplot(1, 2, 1)
plt.imshow(median_filtered_img, cmap='gray')
plt.axis('off')
plt.title('Median Filtered Image')

plt.show()