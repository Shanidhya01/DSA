#include<iostream>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}
int main(){
    int a = 8,b=4;
    swap(&a,&b);
    cout<<a<< " "<<b; 
}