#include<iostream>
using namespace std;
int gcd(int a, int b){
    int hcf = 1;
    // for(int i=1;i<=min(a,b);i++){
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0){
            hcf = i;
            break;
        }
    }
    return hcf;
}
int main(){
    int a;
    cout<<"enter 1st number: ";
    cin>>a;
    int b;
    cout<<"enter 2nd number: ";
    cin>>b;
    cout<<gcd(a,b);
    return 0;
}