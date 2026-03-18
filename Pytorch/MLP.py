from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split 

iris = load_iris()

X = iris['data']
y = iris['target']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=1./3, random_state=1)

import torch
import numpy as np
from torch.utils.data import DataLoader, TensorDataset
X_train_norm = (X_train - np.mean(X_train)) / np.std(X_train) 
X_train_norm = torch.from_numpy(X_train_norm).float()
y_train = torch.from_numpy(y_train)
train_ds = TensorDataset(X_train_norm, y_train)
torch.manual_seed(1)
batch_size = 2
train_dl = DataLoader(train_ds, batch_size, shuffle=True)


######### Define a model with two hidden layers. ##############
""" The first one receives an input of four features and projects them to 16 neurons. 
The second layer receives the output of the previous layer (which has a size of 16) and 
projects them to three output neurons, since we have three class labels"""

import torch.nn as nn

class Model(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super().__init__()
        self.layer1 = nn.Linear(input_size, hidden_size)
        self.layer2 = nn.Linear(hidden_size, output_size)
    def forward(self, x):
        x = self.layer1(x)
        x = nn.Sigmoid()(x)
        x = self.layer2(x)
        return x
    

input_size = X_train_norm.shape[1]
hidden_size = 16
output_size = 3
# Instantiate the model
model = Model(input_size, hidden_size, output_size)
learning_rate = 0.001

# Define the loss function and the optimizer
loss_fn = nn.CrossEntropyLoss()
optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)

# Training loop
num_epochs = 100
loss_hist = [0] * num_epochs
accuracy_hist = [0] * num_epochs 
for epoch in range(num_epochs):
    for x_batch, y_batch in train_dl:
        pred = model(x_batch) # Generate predictions
        loss = loss_fn(pred, y_batch) # Calculate loss
        loss.backward() # Compute gradients
        optimizer.step() # Update parameters using gradients
        optimizer.zero_grad() # Reset gradients to zero for the next iteration
        # Update loss and accuracy history for visualization after training
        loss_hist[epoch] += loss.item()*y_batch.size(0)
        is_correct = (torch.argmax(pred, dim=1) == y_batch).float()
        accuracy_hist[epoch] += is_correct.sum()
    loss_hist[epoch] /= len(train_dl.dataset)
    accuracy_hist[epoch] /= len(train_dl.dataset)

# Visualize the learning curves
import matplotlib.pyplot as plt
fig = plt.figure(figsize=(12, 5)) 
ax = fig.add_subplot(1, 2, 1)
ax.plot(loss_hist, lw=3)
ax.set_title('Training loss', size=15)
ax.set_xlabel('Epoch', size=15)
ax.tick_params(axis='both', which='major', labelsize=15) 
ax = fig.add_subplot(1, 2, 2)
ax.plot(accuracy_hist, lw=3)
ax.set_title('Training accuracy', size=15)
ax.set_xlabel('Epoch', size=15)
ax.tick_params(axis='both', which='major', labelsize=15) 
plt.show()


# Evaluating the trained model on the test dataset
X_test_norm = (X_test - np.mean(X_train)) / np.std(X_train) 
X_test_norm = torch.from_numpy(X_test_norm).float()
y_test = torch.from_numpy(y_test)
pred_test = model(X_test_norm)
correct = (torch.argmax(pred_test, dim=1) == y_test).float() 
accuracy = correct.mean()
print(f'Test Acc.: {accuracy:.4f}')


####### Saving and reloading the trained model ########
path = 'iris_classifier.pt' 
torch.save(model, path) # torch.save() will save both the model architecture and all the learned parameters

# Reload the model
model_new = torch.load(path, weights_only=False)

# Verify the model architecture by calling model_new.eval()
print(model_new.eval()) # This will print the model architecture and confirm that the model was loaded successfully

# Save only the learned parameters (state_dict) of the model
path_weightsonly = 'iris_classifier_state.pt' 
torch.save(model.state_dict(), path_weightsonly)

# To reload the model using the saved state_dict, we first need to instantiate a new model with the same architecture and then load the state_dict into it
model_new2 = Model(input_size, hidden_size, output_size) # Instantiate a new model
model_new2.load_state_dict(torch.load(path_weightsonly)) # Load the saved state_dict
print(model_new2.eval()) # Verify that the model architecture is correct and the weights were loaded