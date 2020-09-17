package heap;

public class Heap {

    public void heapsort(int arr[]) 
    { 
        int n = arr.length; 
  
        // Crea el heap
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify(arr, n, i); 
  
        // Quita 1x1 elementos del heap
        for (int i=n-1; i>0; i--) 
        { 
            //Colaca la raiz al final del arreglo
            int temp = arr[0]; 
            arr[0] = arr[i]; 
            arr[i] = temp; 
  
            // Heapify en el heap reducido 
            heapify(arr, i, 0); 
        } 
    } 
  
    void heapify(int arr[], int n, int i) 
    { 
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2; 
  
        if (l < n && arr[l] > arr[largest]) 
            largest = l; 
  
        if (r < n && arr[r] > arr[largest]) 
            largest = r; 
  
        if (largest != i) 
        { 
            int swap = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = swap; 
  
            heapify(arr, n, largest); 
        } 
    } 

    static void printArray(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(arr[i]+" "); 
        System.out.println(); 
    } 
  
    public static void main(String args[]) 
    { 
        int arr[] = {12, 11, 20, 5, 6, 7}; 
        int n = arr.length; 
  
        Heap ob = new Heap(); 
        ob.heapsort(arr); 
  
        System.out.println("Sorted array is"); 
        printArray(arr); 
    } 

}
