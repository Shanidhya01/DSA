#include<iostream>
using namespace std;
int main(){
    int m,n;
    cout<<"enter the number of rows and column :  ";
    cin>>n>>m;
    for(int i =0;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}