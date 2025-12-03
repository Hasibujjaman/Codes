import cv2
import numpy as np



image_rgb = cv2.imread('road.bmp',cv2.IMREAD_GRAYSCALE)
# image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)


print("Image shape:", image_rgb.shape)


################################# 1. Average Filter ###############################
## MANUAL IMPLEMENTATION
def manual_average_filter(image, kernel_size):
    pad_size = kernel_size // 2
    padded_image = cv2.copyMakeBorder(image, pad_size, pad_size, pad_size, pad_size, cv2.BORDER_CONSTANT, value=0) # Zero padding
    
    filtered_image = np.zeros_like(image)

    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            region = padded_image[i : i + kernel_size, j : j + kernel_size]
            filtered_image[i, j] = np.mean(region)
    
    filtered_image = (1/pad_size**2) * filtered_image
    filtered_image = np.clip(filtered_image, 0, 255).astype(np.uint8)

    return filtered_image


kernel_size = 3
kernel = np.ones((kernel_size, kernel_size), np.float32) / (kernel_size ** 2)
# using library function
average_filtered = cv2.filter2D(image_rgb, -1, kernel) # Zero padding
# using manual function
manual_average_filtered = manual_average_filter(image_rgb, kernel_size)



# Plotting 
import matplotlib.pyplot as plt

plt.figure(figsize=(12, 6))
plt.subplot(1, 3, 1)
plt.imshow(image_rgb, cmap='gray')
plt.title('Original Image')
plt.axis('off')
plt.subplot(1, 3, 2)
plt.imshow(average_filtered, cmap='gray')
plt.title('Average Filter (Library)')
plt.axis('off')
plt.subplot(1, 3, 3)
plt.imshow(manual_average_filtered, cmap='gray')
plt.title('Average Filter (Manual)')
plt.axis('off')
plt.show()




################################# 2. Weighted Average Filter ###############################
## MANUAL IMPLEMENTATION
def manual_weighted_average_filter(image, kernel):
    kernel_size = kernel.shape[0]
    pad_size = kernel_size // 2
    padded_image = cv2.copyMakeBorder(image, pad_size, pad_size, pad_size, pad_size, cv2.BORDER_CONSTANT, value=0) # Zero padding

    filtered_image = np.zeros_like(image, dtype=np.float32)

    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            region = padded_image[i : i + kernel_size, j : j + kernel_size]
            filtered_image[i, j] = np.sum(region * kernel)

    kernel_sum = np.sum(kernel)
    if kernel_sum != 0:
        filtered_image = filtered_image / kernel_sum

    filtered_image = np.clip(filtered_image, 0, 255).astype(np.uint8)

    return filtered_image


# weights = np.array([[1,2,1],[2,4,2],[1,2,1]])
weights = np.array([[1,1,1],[1,1,1],[1,1,1]])
manual_weighted_average_filtered = manual_weighted_average_filter(image_rgb, weights)
print(manual_average_filtered)

## Plotting
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
plt.imshow(image_rgb, cmap='gray')
plt.title('Original Image')
plt.axis('off')
plt.subplot(1, 2, 2)
plt.imshow(manual_weighted_average_filtered, cmap='gray')
plt.title('Weighted Average Filter (Manual)')
plt.axis('off')
plt.show()  




################################# 3. Median Filter ###############################

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
manual_median_filtered = manual_median_filter(image_rgb, kernel_size)

## Plotting
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
plt.imshow(image_rgb, cmap='gray')
plt.title('Original Image')
plt.axis('off')
plt.subplot(1, 2, 2)
plt.imshow(manual_median_filtered, cmap='gray')
plt.title('Median Filter (Manual)')
plt.axis('off')
plt.show()





################################# 4. (Image Sharpening) Laplacian ###############################
def manual_laplacian_filter(image):
    kernel = np.array([[0, 1, 0],
                       [1, -4, 1],
                       [0, 1, 0]], dtype=np.float32)
    
    img_filtered = image + 1 * manual_weighted_average_filter(image, kernel)
    return img_filtered

manual_laplacian_filtered = manual_laplacian_filter(image_rgb)

# Plotting
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
plt.imshow(image_rgb, cmap='gray')
plt.title('Original Image')
plt.axis('off')
plt.subplot(1, 2, 2)
plt.imshow(manual_laplacian_filtered, cmap='gray')
plt.title('Laplacian Filter (Manual)')
plt.axis('off')
plt.show()





################################# 5. High Boost Filtering ###############################
def manual_highboost_filter(image, k):
    blurred_img = manual_average_filter(image, kernel_size=3)
    mask = image - blurred_img
    filtered_img = image + k * mask
    return filtered_img


# Plotting
plt.figure(figsize=(12, 6))
plt.subplot(1, 3, 1)
plt.imshow(image_rgb, cmap='gray')
plt.title('Original Image')
plt.axis('off')
plt.subplot(1, 3, 2)
plt.imshow(manual_highboost_filter(image_rgb, k = 5), cmap='gray')
plt.title('HighBoost Filter (k = 10)')
plt.axis('off')
plt.subplot(1, 3, 3)
plt.imshow(manual_highboost_filter(image_rgb, k = 0.5), cmap='gray')
plt.title('HighBoost Filter (k = 0.5)')
plt.axis('off')
plt.show()