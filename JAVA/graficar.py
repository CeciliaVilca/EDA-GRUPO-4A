import numpy as np
from matplotlib import pyplot as plt

a,b = np.loadtxt('C:/Users/51931/Documents/EDA-GRUPO-4A/JAVA/TiemposJava/valores_Java_b.txt',delimiter = ',',unpack = True)
c,d = np.loadtxt('C:/Users/51931/Documents/EDA-GRUPO-4A/JAVA/TiemposJava/valores_Java_c.txt',delimiter = ',',unpack = True)
e,f = np.loadtxt('C:/Users/51931/Documents/EDA-GRUPO-4A/JAVA/TiemposJava/valores_Java_h.txt',delimiter = ',',unpack = True)
g,h = np.loadtxt('C:/Users/51931/Documents/EDA-GRUPO-4A/JAVA/TiemposJava/valores_Java_i.txt',delimiter = ',',unpack = True)
i,j = np.loadtxt('C:/Users/51931/Documents/EDA-GRUPO-4A/JAVA/TiemposJava/valores_Java_m.txt',delimiter = ',',unpack = True)
k,l = np.loadtxt('C:/Users/51931/Documents/EDA-GRUPO-4A/JAVA/TiemposJava/valores_Java_q.txt',delimiter = ',',unpack = True)
m,n = np.loadtxt('C:/Users/51931/Documents/EDA-GRUPO-4A/JAVA/TiemposJava/valores_Java_s.txt',delimiter = ',',unpack = True)
plt.plot(a,b, color = "blue",label = "BubbleSort")
plt.plot(c,d, color = "red",label = "CountingSort")
plt.plot(e,f, color = "green",label = "HeapSort")
plt.plot(g,h, color = "cyan",label = "InsertionSort")
plt.plot(i,j, color = "yellow",label = "MergeSort")
plt.plot(k,l, color = "black",label = "Quicksort")
plt.plot(m,n, color = "magenta",label = "SelectionSort")
plt.title('Algoritmos Ordenamiento Java')
plt.xlabel('# elementos')
plt.ylabel('tiempo-segundos')
plt.legend()
plt.show();