#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[5] = {5,4,3,1,2};
    int n = 5;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    // for(int i=1;i<=n-1;i++){
    //     int j=i;
    //     while(j>=1){
    //         if(arr[j]>=arr[j-1]) break;
    //         else{
    //             swap(arr[j],arr[j-1]);
    //             j--;
    //         }
    //     }
    // }
    for(int i=1;i<n;i++){
        int j=i;
        while(j>1 && arr[j]<arr[j-1]){
             swap(arr[j],arr[j-1]);
             j--;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}