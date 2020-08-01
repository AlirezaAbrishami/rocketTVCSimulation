import numpy as np
import matplotlib.pyplot as plt
import os

times = np.array([])
rocketAngles = np.array([])
f = open("rocketAngleData.txt", "r")
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
        rocketAngles = np.append(rocketAngles, float(temp))
        temp = ""
        times = np.append(times, timer)
        timer += 1

graph(times, rocketAngles)
os.system(" > rocketAngleData.txt")

