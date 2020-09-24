#include <bits/stdc++.h>
using namespace std;

//-----COUNT SORT
void CountSort(vector<int>& arr){
    int maximo = *max_element(arr.begin(), arr.end());
    int minimo = *min_element(arr.begin(), arr.end());
    int rango = maximo - minimo + 1;
    vector<int> count(rango), output(arr.size());
    for(int i = 0; i < arr.size(); i++)
        count[arr[i]-minimo]++;
    for(int i = 1; i < count.size(); i++)
           count[i] += count[i-1];
    for(int i = arr.size()-1; i >= 0; i--){
         output[ count[arr[i]-minimo] -1 ] = arr[i];
              count[arr[i]-minimo]--;
    }

    for(int i=0; i < arr.size(); i++)
            arr[i] = output[i];
}
//-----MERGE SORT
void merges(vector<int>& arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = j= 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merges(arr, l, m, r);
    }
}
void MergeSort(vector<int>& arr){
    mergeSort(arr,0,arr.size());
}
//-----BUBBLE SORT
void BubbleSort(vector<int>& arr) {
    int n=arr.size();
  int x,y,tmp;
  for(x = 1; x < n; x++) {
    for(y = 0; y < n - x; y++) {
      if(arr[y] > arr[y + 1]) {
        tmp = arr[y];
        arr[y] = arr[y + 1];
        arr[y + 1] = tmp;
      }
    }
  }
}
//-----SLECTION SORT
void SelectionSort(vector<int> &arr) {
    int n=arr.size();
  int x, y, min, tmp;
  for(x = 0; x < n; x++) {
    min = x;
    for(y = x + 1; y < n; y++) {
      if(arr[min] > arr[y]) {
        min = y;
      }
    }
    tmp = arr[min];
    arr[min] = arr[x];
    arr[x] = tmp;
  }
}

//-----HEAP SORT
void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void HeapSort(vector<int>&arr){
    int n=arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
//-----INSERT SORT
void InsertSort(vector<int>&arr) {
    int n=arr.size();
  int x,val,y;
  for(x = 1; x < n; x++) {
    val = arr[x];
    y = x - 1;
    while (y >= 0 && arr[y] > val) {
      arr[y + 1] = arr[y];
      y--;
    }
    arr[y + 1] = val;
  }
}

//-----QUICK SORT
void quickSort(vector<int>&arr, int inicio, int final) {
    int i = inicio, f = final, tmp;
    if(final==-100){
        f=arr.size();
    }
  int x = arr[(inicio + final) / 2];
  do {
    while(arr[i] < x && f <= final) {
      i++;
    }
    while(x < arr[f] && f > inicio) {
      f--;
    }
    if(i <= f) {
      tmp = arr[i];
      arr[i] = arr[f];
      arr[f] = tmp;
      i++; f--;
    }
  } while(i <= f);
  if(inicio < f) {
    quickSort(arr,inicio,f);
  }
  if(i < final){
    quickSort(arr,i,final);
  }

}
void QuickSort(vector<int>&arr){
    quickSort(arr,0,arr.size());
}



double timer(void(*f)(vector<int>&),vector<int>&lst){
    double tiempo;
    double promedio=0;

        vector<int> aux=lst;
        tiempo=clock();
        f(lst);
        promedio+=(clock()-tiempo);

    return promedio;

}
void generate_array(int fi,int it,int listMax,string name){
    ofstream of;
    of.open(name.c_str(),ios::out);
    for (int i=it;i<=fi;i+=it){
        cout<<i<<endl;
        vector<int> v0,v1,v2,v3,v4,v5,v6;
        for(int j=0;j<i;j++){
            v0.push_back(rand()%listMax);
        }
        v1=v2=v3=v4=v5=v6=v0;
        of<<i<<";";
        of<<timer(QuickSort,v0)<<";";
        of<<timer(BubbleSort,v1)<<";";
        of<<timer(CountSort,v2)<<";";
        of<<timer(HeapSort,v3)<<";";
        of<<timer(InsertSort,v4)<<";";
        of<<timer(MergeSort,v5)<<";";
        of<<timer(SelectionSort,v6)<<";"<<endl;
    }
    of.close();
}

int main(){
    generate_array(100000,20000,1000000,"csorts.csv");cout<<"listo"<<endl;//de 20 mil datos  a 100 mil datos  
}
