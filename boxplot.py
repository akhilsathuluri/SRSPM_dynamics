import numpy as np
import matplotlib.pyplot as plt
from numpy import genfromtxt

config = genfromtxt('config_exectime.csv', delimiter=',')
act = genfromtxt('act_exectime.csv', delimiter=',')
task = genfromtxt('task_exectime.csv', delimiter=',')
etask = genfromtxt('extended_task_exectime.csv', delimiter=',')
eact = genfromtxt('extended_act_exectime.csv', delimiter=',')

#Print data stats also
alldata = np.transpose([config, act, task, etask, eact])
#print(type(alldata))
print("The average computation time is: ", alldata.mean(0))
print("The variance in computation time is: ", alldata.var(0))

#print("The mean of the data is: ", config.mean())
#print("The variance of the data is: ", config.var(0))

fig1, ax1 = plt.subplots()
ax1.set_title('Execution times of dynamics models simulated in C++')
ax1.boxplot(alldata, showfliers=False)
plt.show()
#time.sleep(100)

