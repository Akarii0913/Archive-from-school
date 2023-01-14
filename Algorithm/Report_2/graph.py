import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

exec_time = [[0 for i in range(7)]]

for i in range(1, 10):
    exec_num = i*1000
    file_name = (f'result_{exec_num}.csv')
    df = pd.read_csv(file_name, header=None, usecols=[0, 1, 2, 3, 4, 5, 6])
    new_exec_time = df.mean().values
    exec_time =  np.vstack((exec_time, new_exec_time))
    
for i in range(1, 11):
    exec_num = i*10000
    file_name = (f'result_{exec_num}.csv')
    df = pd.read_csv(file_name, header=None, usecols=[0, 1, 2, 3, 4, 5, 6])
    new_exec_time = df.mean().values
    exec_time =  np.vstack((exec_time, new_exec_time))
    
exec_time = np.array(exec_time).T
list = [0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]

plt.style.use('seaborn-dark')
plt.rcParams["font.family"] = "MS Gothic"
plt.plot(list, exec_time[0], label='Bubble')
plt.plot(list, exec_time[1], label='Selection')
plt.plot(list, exec_time[2], label='Insertion')
plt.plot(list, exec_time[3], label='Shell')
plt.plot(list, exec_time[4], label='Quick')
plt.plot(list, exec_time[5], label='Merge')
plt.plot(list, exec_time[6], label='Heap')

plt.xlabel('Amount of elements', fontsize=16)
plt.ylabel('Time required/mS', fontsize=16)
plt.legend(loc='upper left')
plt.xlim(0, list[19])
plt.ylim(0, )
plt.grid()
plt.show()
