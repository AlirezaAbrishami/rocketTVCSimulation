import numpy as np
import matplotlib.pyplot as plt
import os

times = np.array([])
thrustAngles = np.array([])
f = open("thrustAngleData.txt", "r")
content = ""

if f.mode == 'r':
    content = f.read()

def graph(x, y):
    plt.plot(x, y)
    plt.show()

temp = ""
timer = 0
for i in content:
    if i != ',':
        temp += i
    elif i == ',':
        thrustAngles = np.append(thrustAngles, float(temp))
        temp = ""
        times = np.append(times, timer)
        timer += 1

graph(times, thrustAngles)
os.system(" > thrustAngleData.txt")

