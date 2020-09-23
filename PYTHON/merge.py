import math  

def merge(arr): 
    if len(arr) >1:
        # Mitad del array y divide en dos
        m = len(arr)//2 
        L = arr[:mid] 
        R = arr[mid:] 

        nL = m - L + 1
        nR = R - m

  
        i = j = k = 0

        for i in range(0, nL):
        L[i] = arr[l + i]

        or j in range(0, nR):
        R[j] = arr[m + 1 + j]

  
        while i < len(L) and j < len(R): 
            if L[i] < R[j]: 
                arr[k] = L[i] 
                i+= 1
            else: 
                arr[k] = R[j] 
                j+= 1
            k+= 1
          
        while i < len(L): 
            arr[k] = L[i] 
            i+= 1
            k+= 1
          
        while j < len(R): 
            arr[k] = R[j] 
            j+= 1
            k+= 1

#
def mergeSort(arr, l, r):
    
    if l < r:
        m = (l + r) // 2

        mergeSort(arr, l, m)
        mergeSort(arr, m + 1, r)
        merge(arr)

#
   
def printList(arr): 
    for i in range(len(arr)):         
        print(arr[i], end =" ") 
    print() 
  
 
if __name__ == '__main__': 
    arr = [12, 11, 13, 5, 6, 7]  
    print ("Given array is", end ="\n")  
    printList(arr) 
    mergeSort(arr,0,len(arr)-1) 
    print("Sorted array is: ", end ="\n") 
    printList(arr) 




