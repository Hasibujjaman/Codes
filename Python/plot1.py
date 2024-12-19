import time
import matplotlib.pyplot as plt
import random

x = []
y = []

n = [10000, 250000, 500000, 750000, 1000000, 1250000, 1500000, 1750000, 2000000]
# n = [10000, 250000, 500000]
for i in range(len(n)):
    try:

        # Append x and y values
        y.append(i)
        x.append(n[i])

    except:
        break

# Plot the curve

plt.plot(x, y, 'ro', color='red', alpha=0.2)
plt.xlabel('Input Size')
plt.ylabel('Execution Time (s)')
plt.title('Merge Sort')
print(x)
print(y)
plt.plot(x, y)
plt.show()


