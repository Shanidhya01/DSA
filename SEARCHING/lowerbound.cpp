//leetcode 704  binary search
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[9]= {1,2,4,5,9,15,18,21,24};
//     int n = 9;
//     int x = 20;
//     for(int i=0;i<n;i++){
//         if(arr[i]>x){
//             cout<<arr[i-1];
//             break;
//         }
//     }
// }
#include<iostream>
using namespace std;
int main(){
    int arr[9]= {1,2,4,5,9,15,18,21,24};
    int n = 9;
    int x = 20;
    int low = 0;
    int high = n-1;
    bool flag = false;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == x){
            flag = true;
            cout<<arr[mid-1];
            break;
        }
        else if(arr[mid]<x) low = mid + 1;
        else high = mid -1;
    }
    if(flag == false ) cout<<arr[low];  //upper bound
    if(flag == false ) cout<<arr[high]; // lower bound 
}