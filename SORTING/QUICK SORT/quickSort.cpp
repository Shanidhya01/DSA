#include<iostream>
using namespace std;
int partition(int arr[], int st, int end){
    int pivotElement = arr[(st+end)/2];
    int count = 0;
    for(int i=st;i<=end;i++){
        if(i==(st+end)/2) continue;
        if(arr[i]<=pivotElement) count++;
    }
    int pivotidx = count + st;
    swap(arr[(st+end)/2],arr[pivotidx]);
    int i = st;
    int j = end;
    while(i < pivotidx && j > pivotidx){
        if(arr[i]<=pivotElement) i++;
        if(arr[j]>pivotElement) j--;
        else{
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;
}
void quickSort(int arr[],int st,int end){
    if(st>=end) return;
    int pivotidx = partition(arr,st,end);
    quickSort(arr,st,pivotidx-1);
    quickSort(arr,pivotidx+1,end);
}
int main(){
    int arr[] = {5,1,8,2,7,6,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0,n-1);
    cout << "Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
