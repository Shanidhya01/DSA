#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter the no of rows : ";
    cin>>m;
    int n;
    cout<<"Enter the no of columns : ";
    cin>>n;
    int arr[m][n];
    for(int i=0;i<=m-1;i++){
        for(int j=0;j<=n-1;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"ORIGINAL MATRIX"<<endl;
    cout<<"---------------------------------------------"<<endl;
    for(int i=0;i<=m-1;i++){
        for(int j=0;j<=n-1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"---------------------------------------------"<<endl;
    cout<<"TRANSPOSE MATRIX"<<endl;
    cout<<"---------------------------------------------"<<endl;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}