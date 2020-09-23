#include<bits/stdc++.h>
using namespace std;

///--- GENERAR ARRAY

void generateArray(int arr[], int num)
{
    srand(time(NULL));

    for(int a=0; a<num; a++)
    {
        arr[a] = 1 + rand() % (num);
    }
}

//medir tiempo

int getTime_sort(int arr[],int n)
{
    auto start = std::chrono::high_resolution_clock::now();
/*
    sort
*/
    auto finish = std::chrono::high_resolution_clock::now();
    int Ftime=std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    return Ftime;


}

int main()
{
    int num=100;

    int arr[num];

    generateArray(arr,num);
    
    int Time_sort=getTime_sort(arr,num);
    
    cout<<"sort : " <<Tmerge<<" ns ";
}
