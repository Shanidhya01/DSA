#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){ 
    int arr[] = {5,4,6,5,3,1,2};
    int n=6;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    // bubble sort
    // for(int i = 0;i<n-1;i++){
    //     for (int j=0;j<n-1-i;j++){
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j] ,arr[j+1]);
    //         }
    //     }
    // }
    // bubble sort optimised
    for(int i = 0;i<n-1;i++){
        bool flag = true;
        for (int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] ,arr[j+1]);
                flag = false;
            }
        }
        if(flag == true){
            break;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}