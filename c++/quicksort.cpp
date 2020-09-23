#include <iostream>
#include <fstream>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
    unsigned t0, t1;

    int tam=100;
    int arr[tam];
    for(int i=0;i<tam;i++)
    {
        arr[i]=rand();
    }

    t0=clock();
    quickSort(arr,0,tam-1);
    printArray(arr, tam);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "\n Execution Time: " << time << endl;
}

