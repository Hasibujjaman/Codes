import matplotlib.pyplot as plt
import numpy as np

# Read data from the file
filename = '/Users/emonchowdhury/Library/CloudStorage/GoogleDrive-emonahamed789@gmail.com/My Drive/Codes/ VS Code/Lab/2204/Assignment/population_data.txt'

with open(filename, 'r') as file:
    lines = file.readlines()

# Extract year and population from each line
years1 = []
populations1 = []

for line in lines:
    year, population = map(float, line.strip().split())
    years1.append(year)
    populations1.append(population)

# Plot the data
plt.plot(years1, populations1, marker='o', linestyle='-', color='r',label = 'Original Data')

# Read data from the file
filename = '/Users/emonchowdhury/Library/CloudStorage/GoogleDrive-emonahamed789@gmail.com/My Drive/Codes/ VS Code/Lab/2204/Assignment/population_prediciton_CF'

with open(filename, 'r') as file:
    lines = file.readlines()

# Extract year and population from each line
years2 = []
populations2 = []

for line in lines:
    year, population = map(float, line.strip().split())
    years2.append(year)
    populations2.append(population)
# Plot the data
plt.plot(years2, populations2, marker='o', linestyle='-', color='b', label = 'Curve Fittng')
plt.title('Population Over Time')
plt.xlabel('Year')
plt.ylabel('Population(in millions)')
plt.grid(True)
plt.legend()








plt.show()


