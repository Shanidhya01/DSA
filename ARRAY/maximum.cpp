#include<iostream>
using namespace std ;
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    int max = a[0];
    for(int i=0;i<=n-1;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    cout<<" Largest number : "<<max<<endl;
    return 0;
}