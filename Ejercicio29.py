import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits.mplot3d import Axes3D
data= np.loadtxt('data.dat')
t= data[:,0]; x=data[:,1]; y=data[:,2]
fig=plt.figure(figsize=(15,15))
plt.suptitle('Solución a la ecuación de difusión')
plt.subplot(3,3,1)
plt.plot(data[:,0],data[:,2])
plt.xlabel('$t$')
plt.ylabel('$\psi$(x,t)')
plt.grid()
plt.axhline(c='k',lw=0.8)
plt.axvline(c='k',lw=0.8)
plt.subplot(3,3,2)
icrit=0
for i in range(len(x)):
    if(x[i]<(1*10**-10)): icrit=i
a=[]
t=y[:icrit+1]
for i in range(len(t)):
    a.append(t[i])
a.reverse()
plt.grid()
plt.axhline(c='k',lw=0.8)
plt.axvline(c='k',lw=0.8)
plt.plot(x[:icrit+1],y[:icrit+1],c='b')
plt.plot(x[icrit:],a,c='b')
plt.xlabel('$x$')
plt.ylabel('$\psi$(x,t)')
plt.subplot(3,3,3)
plt.savefig('PuntoA.png')
