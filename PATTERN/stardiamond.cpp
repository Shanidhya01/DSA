#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"ENTER THE NUMBER OF LINES: ";
    cin>>n;
    int nst =1;
    int nsp = n-1;
    for(int i=1;i<=2*n-1;i++){
        for(int j=1;j<=nsp;j++){
            cout<<" ";
        }
        if(i<=n-1)  nsp--;
        else nsp ++;
        for(int k=1;k<=nst;k++){
            cout<<"*";
        }
        if(i<=n-1)  nst+=2;
        else  nst-=2;
        cout<<endl;
    }
    return 0;
}