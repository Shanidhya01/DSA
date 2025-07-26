#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the elements you want to serach : ";
    cin>>x;
    bool flag = false;
    for(int i=0;i<=n-1;i++){
        if(arr[i]==x) flag = true;
    }
    if(flag==true) cout<<"present"<<endl;
    else cout<<"not present"<<endl;
    return 0;
}