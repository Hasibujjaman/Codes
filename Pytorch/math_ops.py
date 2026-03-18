import torch
import numpy as np


torch.manual_seed(1)
t1 = 2 * torch.rand(5, 2) - 1
t2 = torch.normal(mean=0, std=1, size=(5, 2))
print("Tensor t1:\n", t1)
print("Tensor t2:\n", t2)


# Element-wise addition
t_add = t1 + t2
print("Element-wise addition:\n", t_add)

# Element-wise multiplication
t_mul = torch.mul(t1, t2)
print("Element-wise multiplication:\n", t_mul)

# Element-wise division
t_div = torch.div(t1, t2)
print("Element-wise division:\n", t_div)


# Matrix multiplication
t_matmul = torch.matmul(t1, t2.T)
print("Matrix multiplication:\n", t_matmul)

# L2 norm
norm_t1 = torch.linalg.norm(t1, ord=2, dim=1)
print("L2 norm of t1:\n", norm_t1)
print(np.sqrt(np.sum(np.square(t1.numpy()), axis=1))) # verification using numpy