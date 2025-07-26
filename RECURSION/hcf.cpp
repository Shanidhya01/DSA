#include<iostream>
using namespace std;
int hcf(int a,int b){
    if(a==0) return b;
    else return  hcf(b%a,a);
}
int main(){
    int a =24;
    int b = 60;
    cout<<hcf(a,b);
}