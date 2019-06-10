import matplotlib.pyplot as plt
import numpy as np
import os

ordner = "C:/Users/Test/Desktop/plott_txt/"

for root, dirs, files in os.walk(ordner):
    for file in files:
        if file.endswith(".txt"):
            x, y = np.loadtxt(ordner + file, delimiter='\t', unpack=True)
            plt.plot(x, y, label=file)

plt.xlabel('elemente')
plt.ylabel('zeit in sekunden')
plt.legend()
plt.show()