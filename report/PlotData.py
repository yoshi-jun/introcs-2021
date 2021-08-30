import numpy as np 
import matplotlib.pyplot as plt 

data = np.loadtxt('data.csv',delimiter=',')

print(len(data))

edep=np.zeros(7)

for j in range(7):
    for i in range(len(data)):    
        if data[i,0] == j :
            edep[j] += data[i,1]
        else :
            continue

plt.plot(range(7),edep)
plt.xlabel("Number of layer")
plt.ylabel("Energy Deposit(MeV)")
plt.show()
