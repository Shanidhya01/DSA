#include<iostream>
using namespace std;
int main(){
    int arr[] = {4,2,6,1,7};
    int* ptr = arr;
    for(int i=0;i<=4;i++){
        cout<<*ptr<<" ";
        ptr++;
    }
    ptr =arr;
    *ptr = 8;
    ptr++;
    *ptr = 9;
    ptr--;
    cout<<endl;
    for(int i=0;i<=4;i++){
        cout<<*ptr<<" ";
        ptr++;
    }
    ptr =arr;
    // ptr[0]= 7;
    // for(int i=0;i<=4;i++){
    //     cout<<ptr[i]<<" ";
    // }
    // cout<<endl;
    // *ptr = 9;
    // for(int i=0;i<=4;i++){
    //     cout<<ptr[i]<<" ";
    // }

    return 0;
}