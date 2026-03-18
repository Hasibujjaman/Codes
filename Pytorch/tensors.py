import torch
import numpy as np

a = [1,2,3]
b = np.array([4,5,6])

# Convert list to tensor
t_a = torch.tensor(a)
t_b = torch.from_numpy(b)
t_ones = torch.ones(2,3)
t_rand = torch.rand(2,3)

print("Tensor a:", t_a)
print("Tensor b:", t_b)
print("Tensor of ones:", t_ones)
print("Tensor of random values:", t_rand)

# change data type of tensor
t_a_float = t_a.float()
print("Tensor a as float:", t_a_float,"Data type:", t_a_float.dtype)

# Transpose tensor
t = torch.rand(3,5)
t_transposed = torch.transpose(t, 0, 1)
print("Original tensor shape:", t.shape)
print("Transposed tensor shape:", t_transposed.shape)

# Reshape tensor
t = torch.zeros(30)
t_reshape = t.reshape(5, 6)
print("Reshaped tensor shape:", t_reshape.shape)

# Remove dimensions
t = torch.zeros(1, 2, 1, 4, 1)
t_sqz = torch.squeeze(t, 2)
print(t.shape, ' --> ', t_sqz.shape)
print("Original tensor:", t)
print("Squeezed tensor:", t_sqz)