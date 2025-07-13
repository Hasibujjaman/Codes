import matplotlib.pyplot as plt
import numpy as np
import math



def calculate_angle(x, y, reference_x, reference_y):
    dx, dy = x - reference_x, y - reference_y
    return math.atan2(dy, dx)

def sort_points_clockwise(x_values, y_values):
    n = len(x_values)

    # Calculate the centroid as the reference point
    reference_x = sum(x_values) / n
    reference_y = sum(y_values) / n

    # Create a list of tuples (x, y) for each point
    points = [(x_values[i], y_values[i]) for i in range(n)]

    # Sort points based on the angle with respect to the reference point
    sorted_points = sorted(points, key=lambda p: calculate_angle(p[0], p[1], reference_x, reference_y))

    # Separate the sorted x and y values
    sorted_x_values, sorted_y_values = zip(*sorted_points)

    return sorted_x_values, sorted_y_values


file_path = '/Users/emonchowdhury/Library/CloudStorage/GoogleDrive-emonahamed789@gmail.com/My Drive/Codes/ VS Code/Lab/2202/D6/ConvexHull.txt'  # Replace with the path to your file
with open(file_path, 'r') as file:
    # Initialize empty arrays for x and y values
    x_values = []
    y_values = []

    # Read each line in the file
    for line in file:
        # Split the line into x and y values
        x, y = map(float, line.split())

        # Append x and y values to their respective arrays
        x_values.append(x)
        y_values.append(y)

# Print the result
# print("X values:", x_values)
# print("Y values:", y_values)


hull_x = [-10,  10,  9, 2,  -2, -10, -4, 10]
hull_y = [-9,   -4, -9, -10, -10, 7,  10, 10]

# Sort points in clockwise direction
sorted_hull_x_clockwise, sorted_hull_y_clockwise = sort_points_clockwise(hull_x, hull_y)

plt.xlabel('X')
plt.ylabel('Y')
plt.title('2D Points')

plt.scatter(x_values, y_values, color = 'red')
#plt.plot(x_values, y_values, 'ro')

# plt.plot comes with default point connection
#plt.plot(x_values, y_values, color='green', marker = 'o', markerfacecolor = 'red', markersize = 10, linewidth = 0, alpha=.8) 
# use linewidth = 0 to make the plot a scatter plot , use marker = 'o' to make the points visible and use markerfacecolor and markersizepersonalize the points , use alpha specify opacity of the graph


plt.plot(sorted_hull_x_clockwise,sorted_hull_y_clockwise)   
plt.show()