#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"ENTER THE NUMBER OF LINES: ";
    cin>>n;
    for(int i=1;i<=2*n-1;i++){
        cout<<" "<<i<<" ";
    }
    cout<<endl;
    int nsp =1;
    int m = n-1;
    for(int i=1;i<=m;i++){
        int a=1;
        for(int j=1;j<=m+1-i;j++){
            cout<<" "<<a<<" ";
            a++;
        }
        for(int k=1;k<=nsp;k++){
            cout<<"   ";
            a++;
        }   
        // for(int j=n+i;j<=2*n-1;j++){
        //     cout<<" "<<j<<" ";
            
        // }
        for(int j=1;j<=m+1-i;j++){
            cout<<" "<<a<<" ";
            a++;
        }
        nsp+=2;   
        cout<<endl;
    }
    return 0;
}