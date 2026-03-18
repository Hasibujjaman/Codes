import torch.nn as nn
import torch

loss_func = nn.BCELoss()
loss = loss_func(torch.tensor([0.9]), torch.tensor([1.0])) # loss_func(y_hat, y_true)


conv_layer = nn.Conv2d(in_channels=3, out_channels=5, kernel_size=5)
linear_layer = nn.Linear(10, 16)

l2_lambda = 0.001
# add the L2 penalty for both the convolutional layer and the linear layer
l2_penalty = l2_lambda * sum(
    [(p**2).sum() for p in conv_layer.parameters()] +
    [(p**2).sum() for p in linear_layer.parameters()]
)
loss_with_penalty = loss + l2_penalty



print(loss)
print(l2_penalty)
print(loss_with_penalty)



## Alternative way : Weight decay in the optimizer
optimizer = torch.optim.SGD(conv_layer.parameters(), lr=0.01, weight_decay=l2_lambda)