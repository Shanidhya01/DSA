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
int KthSmallest(int arr[],int st,int end,int k){
    int pivotidx = partition(arr,st,end);
    if(pivotidx+1==k) return arr[pivotidx];
    else if(pivotidx+1<k) return KthSmallest(arr,pivotidx+1,end,k);
    else return KthSmallest(arr,st,pivotidx-1,k);
}
int main(){
    int arr[] = {5,18,82,20,7,6,31,4,-8};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int k = 4;
    cout<<KthSmallest(arr, 0, n - 1, k)<<endl;
}