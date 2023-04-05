import matplotlib.pyplot as plt
import pandas as pd
import sys


data = pd.read_csv(sys.argv[1])

fig, ax = plt.subplots()

print(data.info())

x = data['n'].values
y = data['time[ms]'].values

ax.plot(x, y)

ax.set_xlabel('n')
ax.set_ylabel('time[ms]')

ax.set_title('Line Plot for Matrix Multiplication')

plt.show()
