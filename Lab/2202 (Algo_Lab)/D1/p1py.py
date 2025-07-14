import matplotlib.pyplot as plt
import numpy as np
import time
import random

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def measure_time(sort_function, arr):
    start_time = time.time()
    sort_function(arr)
    end_time = time.time()
    return end_time - start_time

def generate_random_array(size):
    return [random.randint(1, 1000) for _ in range(size)]

# Sizes of input arrays
sizes = [1000, 5000, 10000, 15000, 20000]

# Measure time for each sorting algorithm for different input sizes
bubble_sort_times = []
selection_sort_times = []
insertion_sort_times = []

for size in sizes:
    arr = generate_random_array(size)

    bubble_sort_time = measure_time(bubble_sort, arr.copy())
    selection_sort_time = measure_time(selection_sort, arr.copy())
    insertion_sort_time = measure_time(insertion_sort, arr.copy())
    print("Bubble sort: ",bubble_sort_time)
    print("Selection sort: ",selection_sort_time)
    print("Insertion sort: ",insertion_sort_time)
    print()
    bubble_sort_times.append(bubble_sort_time)
    selection_sort_times.append(selection_sort_time)
    insertion_sort_times.append(insertion_sort_time)

# Plotting
plt.plot(sizes, bubble_sort_times, label='Bubble Sort', marker='o')
plt.plot(sizes, selection_sort_times, label='Selection Sort', marker='o')
plt.plot(sizes, insertion_sort_times, label='Insertion Sort', marker='o')

plt.xlabel('Input Size')
plt.ylabel('Time (seconds)')
plt.title('Comparison of Sorting Algorithms')
plt.legend()
plt.grid(True)
plt.show()
