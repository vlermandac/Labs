import matplotlib.pyplot as plt
import pandas as pd
import sys


data1 = pd.read_csv(sys.argv[1])
data2 = pd.read_csv(sys.argv[2])

label1 = sys.argv[1].split('_')[0]
label2 = sys.argv[2].split('_')[0]

x1 = data1['n'].values
y1 = data1['time[ms]'].values

x2 = data2['n'].values
y2 = data2['time[ms]'].values

plt.plot(x1, y1, label=label1)
plt.plot(x2, y2, label=label2)

plt.xlabel('n')
plt.ylabel('time[ms]')

plt.title('Line Plot for Matrix Multiplication')

plt.show()
