import cv2
import numpy as np



image_gray = cv2.imread('lenna.png',cv2.IMREAD_GRAYSCALE)
# image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)


print("Image shape:", image_gray.shape)




import matplotlib.pyplot as plt
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







################################# 1. Perwitt Operator ###############################
kernelH_perwitt = np.array([[-1, -1, -1],
                    [0, 0, 0],
                    [1, 1, 1]], dtype=np.float32)
kernelV_perwitt = np.array([[-1, 0, 1],
                    [-1, 0, 1],
                    [-1, 0, 1]], dtype=np.float32)
    
    
perwitt_hori = manual_weighted_average_filter(image_gray, kernelH_perwitt)
perwitt__verti = manual_weighted_average_filter(image_gray, kernelV_perwitt)
    

# Plotting
plt.figure(figsize=(12, 6))
plt.subplot(1, 3, 1)
plt.imshow(image_gray, cmap='gray')
plt.title('Original Image')
plt.axis('off')
plt.subplot(1, 3, 2)
plt.imshow(perwitt_hori, cmap='gray')
plt.title('Perwitt operator (Horizontal)')
plt.axis('off')
plt.subplot(1, 3, 3)
plt.imshow(perwitt__verti, cmap='gray')
plt.title('Perwitt operator (Vertical)')
plt.axis('off')
plt.show()














################################# 2. Sobel Operator ###############################
kernelH_sobel = np.array([[-1, -2, -1],
                    [0, 0, 0],
                    [1, 2, 1]], dtype=np.float32)
kernelV_sobel = np.array([[-1, 0, 1],
                    [-2, 0, 2],
                    [-1, 0, 1]], dtype=np.float32)

    
    
sobel_hori = manual_weighted_average_filter(image_gray, kernelH_sobel)
sobel_verti = manual_weighted_average_filter(image_gray, kernelV_sobel)
    

# Plotting
plt.figure(figsize=(12, 6))
plt.subplot(1, 3, 1)
plt.imshow(image_gray, cmap='gray')
plt.title('Original Image')
plt.axis('off')
plt.subplot(1, 3, 2)
plt.imshow(sobel_hori, cmap='gray')
plt.title('Sobel operator (Horizontal)')
plt.axis('off')
plt.subplot(1, 3, 3)
plt.imshow(sobel_verti, cmap='gray')
plt.title('Sobel operator (Vertical)')
plt.axis('off')
plt.show()


############# 3.1 Canny Algorithm (Built-in) ###############################
# blurred_img = cv2.GaussianBlur(image_gray, (5, 5), 0)
canny_edges = cv2.Canny(image_gray, 150, 240)

# Plotting
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1)
plt.imshow(image_gray, cmap='gray')
plt.title('Blurred Image')
plt.axis('off')
plt.subplot(1, 2, 2)
plt.imshow(canny_edges, cmap='gray')
plt.title('Canny Edges (Built-in)')
plt.axis('off')
plt.show()












# ################################# 3.2 Canny Algorithm (manual) ###############################
# #1. smoothing (Gaussian low pass filter using cv2)
# blurred_img = cv2.GaussianBlur(image_gray, (5, 5), 0)
# #plot
# plt.figure(figsize=(6, 6))
# plt.subplot(1, 2, 1)
# plt.imshow(image_gray, cmap='gray')
# plt.title('Original Image')
# plt.axis('off')
# plt.subplot(1, 2, 2)
# plt.imshow(blurred_img, cmap='gray')
# plt.title('Blurred Image (Gaussian)')
# plt.axis('off')

# #2. gradient calculation (Sobel operator)
# grad_x = manual_weighted_average_filter(blurred_img, kernelV_sobel)
# grad_y = manual_weighted_average_filter(blurred_img, kernelH_sobel)
# magnitude = np.sqrt(grad_x**2 + grad_y**2)
# angle = np.arctan2(grad_y, grad_x) * (180.0 / np.pi)
# angle[angle < 0] += 180

# print(magnitude)

# #3. non-maximum suppression
# def non_maximum_suppression(magnitude, angle):
#     nms = np.zeros_like(magnitude, dtype=np.float32)
#     angle = angle % 180  # Ensure angles are within [0, 180)

#     for i in range(1, magnitude.shape[0] - 1):
#         for j in range(1, magnitude.shape[1] - 1):
#             q = 255
#             r = 255

#             # Angle 0
#             if (0 <= angle[i, j] < 22.5) or (157.5 <= angle[i, j] <= 180):
#                 q = magnitude[i, j + 1]
#                 r = magnitude[i, j - 1]
#             # Angle 45
#             elif (22.5 <= angle[i, j] < 67.5):
#                 q = magnitude[i + 1, j - 1]
#                 r = magnitude[i - 1, j + 1]
#             # Angle 90
#             elif (67.5 <= angle[i, j] < 112.5):
#                 q = magnitude[i + 1, j]
#                 r = magnitude[i - 1, j]
#             # Angle 135
#             elif (112.5 <= angle[i, j] < 157.5):
#                 q = magnitude[i - 1, j - 1]
#                 r = magnitude[i + 1, j + 1]

#             if (magnitude[i, j] >= q) and (magnitude[i, j] >= r):
#                 nms[i, j] = magnitude[i, j]
#             else:
#                 nms[i, j] = 0

#     return nms

# nms_image = non_maximum_suppression(magnitude, angle)
# nms_image = np.clip(nms_image, 0, 255).astype(np.uint8)

# print("\n\n")
# print(nms_image)

# #plot
# plt.figure(figsize=(12, 6))
# plt.subplot(1, 2, 1)
# plt.imshow(image_gray, cmap='gray')
# plt.title('Original Image')
# plt.axis('off')
# plt.subplot(1, 2, 2)
# plt.imshow(nms_image, cmap='gray')
# plt.title('Non-Maximum Suppression')
# plt.axis('off')
# plt.show()



# # Debug: Plot histogram and print min/max of nms_image
# print('nms_image min:', np.min(nms_image), 'max:', np.max(nms_image))


# #4. double thresholding
# def double_thresholding(image, low_threshold, high_threshold):
#     strong = 255
#     weak = 75

#     result = np.zeros_like(image, dtype=np.uint8)

#     strong_i, strong_j = np.where(image >= high_threshold)
#     zeros_i, zeros_j = np.where(image < low_threshold)

#     weak_i, weak_j = np.where((image <= high_threshold) & (image >= low_threshold))

#     result[strong_i, strong_j] = strong
#     result[weak_i, weak_j] = weak

#     return result 

# dt_image = double_thresholding(nms_image, 30, 90)
# #plot
# plt.figure(figsize=(12, 6))
# plt.subplot(1, 2, 1)
# plt.imshow(image_gray, cmap='gray') 
# plt.title('Original Image')
# plt.axis('off') 
# plt.subplot(1, 2, 2)
# plt.imshow(dt_image, cmap='gray')
# plt.title('Double Thresholding')
# plt.axis('off')
# plt.show()








