#include <iostream>
using namespace std;
int main() {
    int x = 5;
    int *ptr = &x;
    int **p = &ptr;
    cout<<x;
    cout<<"\n"<<*ptr<<endl;
    cout<<**p<<endl;
    return 0;
}