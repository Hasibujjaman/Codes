""" We can define simple models using nn.Sequential, which is a container that allows us to stack layers sequentially.
For complex models use nn.Module and define the forward pass explicitly. """

import torch
import torch.nn as nn
import numpy as np
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from torch.utils.data import DataLoader, TensorDataset
import matplotlib.pyplot as plt


########## Prepare binary classification data (Iris: class 0 vs rest) ##########
iris = load_iris()
X = iris['data']
y = (iris['target'] != 0).astype(np.float32)  # binary: class 0 vs rest

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=1./3, random_state=1)

X_train_norm = (X_train - np.mean(X_train, axis=0)) / np.std(X_train, axis=0)
X_test_norm = (X_test - np.mean(X_train, axis=0)) / np.std(X_train, axis=0)

X_train_norm = torch.from_numpy(X_train_norm).float()
y_train = torch.from_numpy(y_train).float().unsqueeze(1)  # shape: (N, 1)
X_test_norm = torch.from_numpy(X_test_norm).float()
y_test = torch.from_numpy(y_test).float().unsqueeze(1)

train_ds = TensorDataset(X_train_norm, y_train)
torch.manual_seed(1)
batch_size = 2
train_dl = DataLoader(train_ds, batch_size, shuffle=True)




########## Define the model with nn.Sequential ##########
# a model with two densely (fully) connected layers + output layer
model = nn.Sequential(
    nn.Linear(4, 16),
    nn.ReLU(),
    nn.Linear(16, 32),
    nn.ReLU(),
    nn.Linear(32, 1),
    nn.Sigmoid()
)

print(model)

# Initialize the weights of the first layer using Xavier initialization
nn.init.xavier_uniform_(model[0].weight)

# L1 regularization weight
l1_weight = 0.01

# Loss function
loss_fn = nn.BCELoss()
# Optimizer
optimizer = torch.optim.SGD(model.parameters(), lr=0.001)


########## Training loop ##########
num_epochs = 100
loss_hist = [0] * num_epochs
accuracy_hist = [0] * num_epochs

for epoch in range(num_epochs):
    for x_batch, y_batch in train_dl:
        pred = model(x_batch)
        # Add L1 regularization penalty to the loss
        l1_penalty = l1_weight * model[2].weight.abs().sum()
        loss = loss_fn(pred, y_batch) + l1_penalty
        loss.backward()
        optimizer.step()
        optimizer.zero_grad()

        loss_hist[epoch] += loss.item() * y_batch.size(0)
        is_correct = ((pred >= 0.5).float() == y_batch).float()
        accuracy_hist[epoch] += is_correct.sum()

    loss_hist[epoch] /= len(train_dl.dataset)
    accuracy_hist[epoch] /= len(train_dl.dataset)


########## Visualize learning curves ##########
fig = plt.figure(figsize=(12, 5))
ax = fig.add_subplot(1, 2, 1)
ax.plot(loss_hist, lw=3)
ax.set_title('Training Loss', size=15)
ax.set_xlabel('Epoch', size=15)
ax.tick_params(axis='both', which='major', labelsize=15)

ax = fig.add_subplot(1, 2, 2)
ax.plot(accuracy_hist, lw=3)
ax.set_title('Training Accuracy', size=15)
ax.set_xlabel('Epoch', size=15)
ax.tick_params(axis='both', which='major', labelsize=15)
plt.tight_layout()
plt.show()


########## Evaluate on test set ##########
pred_test = model(X_test_norm)
correct = ((pred_test >= 0.5).float() == y_test).float()
accuracy = correct.mean()
print(f'Test Acc.: {accuracy:.4f}')