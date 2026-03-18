def DDA(x0, y0, x1, y1):
    points = []
    dx = x1 - x0
    dy = y1 - y0

    steps = int(max(abs(dx), abs(dy)))

    x_incr = dx / steps
    y_incr = dy / steps

    x = x0
    y = y0
    for i in range(steps):
        points.append((round(x), round(y)))
        x += x_incr
        y += y_incr

    return points

# coordinates of 1st point
x0, y0 = 180, 160

    # coordinates of 2nd point
x1, y1 = 200, 180

    # Function call
points = DDA(x0, y0, x1, y1)


print(points)
from matplotlib import pyplot as plt
    # plot the line with coordinates list
plt.plot([x for x,y in points], [y for x,y in points], marker="o",
             markersize=1, markerfacecolor="green")
plt.show()

