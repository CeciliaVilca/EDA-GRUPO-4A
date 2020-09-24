import matplotlib
import numpy as np
import matplotlib.pyplot as plt
from random import choice
import time
import csv

def algoritmo(name,pos):   
        data=np.loadtxt('cplus.csv',dtype=np.str,delimiter=';',unpack=True)
        x=data[0,:]
        y=data[pos,:]
        y = [float(i) for i in y]
        plt.plot(x, y, "-", color="red", label="C++")

        data=np.loadtxt('python.csv',dtype=np.str,delimiter=';',unpack=True)
        x=data[0,:]
        y=data[pos,:]
        y = [float(i) for i in y]
        plt.plot(x, y, "-", color="green", label="Python")
        
        
        data=np.loadtxt('java.csv',dtype=np.str,delimiter=';',unpack=True)
        x=data[0,:]
        y=data[pos,:]
        y = [float(i) for i in y]
        plt.plot(x, y, "-", color="blue", label="Java")
        plt.legend()
        plt.title(name)
        plt.show()
                      
                
A=["quickSort","bubbleSort","countSort","heapSort","insertionSort","mergeSort","selectionSort"]
for i in range(0,len(A)):
        algoritmo(A[i],i+1)
    

