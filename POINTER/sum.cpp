#include<iostream>
using namespace std;
int main(){
    int x,y;
    int* p1 = &x;
    int* p2 = &y;
    cout<<"enter 1st number : ";
    cin>>*p1;
    cout<<"enter 2nd number : ";
    cin>>*p2;
    cout<<x+y;
    return 0;
}