import numpy as np
import matplotlib.pyplot as plt
import os

times = np.array([])
rocketVelocity = np.array([])
f = open("rocketVelocityData.txt", "r")
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
        rocketVelocity = np.append(rocketVelocity, float(temp))
        temp = ""
        times = np.append(times, timer)
        timer += 1

graph(times, rocketVelocity)
os.system(" > rocketVelocityData.txt")

