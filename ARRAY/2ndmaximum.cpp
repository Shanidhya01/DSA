#include<iostream>
#include<climits>
using namespace std ;
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    int max = INT_MIN;
    for(int i=0;i<=n-1;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    int Smax = INT_MIN;
    for(int i=0;i<=n-1;i++){
        if(a[i]!= max && a[i]>Smax){
            Smax = a[i];
        }
    }
    cout<<" Largest number : "<<max<<endl;
    cout<<" 2nd Largest number : "<<Smax<<endl;
    return 0;
}