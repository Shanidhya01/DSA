#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"ENTER THE NUMBERS OF LINES : ";
    cin>>n;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n-i;j++){
    //        cout<<" ";
    //     }
    //     for(int j=1;j<=2*i-1;j++){
    //        cout<<"*";
    //     }
    //     cout<<endl;
    // }
    int nst = 1;
    int nsp = n-1;
    for(int i = 0;i<=n;i++){
        for(int j=0;j<=nsp;j++){
           cout<<" ";
        }
        nsp--;
        for(int k=1;k<=nst;k++){
            cout<<"*";
        }
        nst+=2;
        cout<<endl;
    }
    return 0;
}