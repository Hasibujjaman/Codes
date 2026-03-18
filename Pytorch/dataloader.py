import torch
from torch.utils.data import DataLoader

t = torch.arange(6, dtype=torch.float32) 
data_loader = DataLoader(t)

print("DataLoader with batch_size=1:")
for item in data_loader:
    print(item)


data_loader_batch = DataLoader(t, batch_size=2, drop_last=False, shuffle=False)
print("\nDataLoader with batch_size=2:")
for i, batch in enumerate(data_loader_batch, 1):
    print(f"Batch {i}:\n{batch}")


### Combining two tensors into a joint dataset ########
from torch.utils.data import TensorDataset 

torch.manual_seed(1)
t_x = torch.rand([4, 3], dtype=torch.float32) 
t_y = torch.arange(4)


from torch.utils.data import Dataset 
class JointDataset(Dataset):   # A custom Dataset class must contain the following methods: __init__ and __getitem__
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __len__(self):
        return len(self.x)

    def __getitem__(self, idx):
        return self.x[idx], self.y[idx]
    
joint_dataset = JointDataset(t_x, t_y) # method 1: using custom Dataset class    
# joint_dataset = TensorDataset(t_x, t_y) # method 2: using TensorDataset
print("\nJoint dataset (t_x, t_y):")
for example in joint_dataset:
    print(' x: ', example[0], ' y: ', example[1])



########## Shuffle, batch, and repeat #########
torch.manual_seed(1)
data_loader = DataLoader(dataset=joint_dataset, batch_size=2, shuffle=True)

print("\nShuffled and batched dataset:")
for epoch in range(2):
    print(f'epoch {epoch+1}')
    for i, batch in enumerate(data_loader, 1):
        print(f'batch {i}:', 'x:', batch[0],
                  '\n         y:', batch[1])


