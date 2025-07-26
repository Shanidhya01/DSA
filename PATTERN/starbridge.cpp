#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"ENTER THE NUMBER OF LINES: ";
    cin>>n;
    for(int i=1;i<=2*n-1;i++){
        cout<<"*";
    }
    cout<<endl;
    int nsp =1;
    int m = n-1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m+1-i;j++){
            cout<<"*";
        }
        for(int k=1;k<=nsp;k++){
            cout<<" ";
        }   
        for(int j=1;j<=m+1-i;j++){
            cout<<"*";
        }
        nsp+=2;   
        cout<<endl;
    }
    return 0;
}