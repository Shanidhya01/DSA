// Given a number N, find the minimum number of operations required to make N 1. You have following three operations permitted on a number.
// 1. Subtract 1 from it. (N = N - 1)
// 2. Divide by 2 (if N is even). (N = N / 2)
// 3. Divide by 3 (if N is divisible by 3). (N = N / 3)

#include <bits/stdc++.h>
using namespace std;

int minOperation(int n){

    // Gready Approach
    // if(n==1) return 0;
    // if(n%3==0) return 1+minOperation(n/3);
    // if(n%2==0) return 1+minOperation(n/2);
    // return 1+minOperation(n-1);

    // Dynamic Programming
    if(n==1) return 0;
    if(n==2 or n ==3) return 1;

    return min({minOperation(n-1), (n%2==0) ? minOperation(n/2) : INT_MAX, (n%3==0) ? minOperation(n/3) : INT_MAX}) + 1;
}

int main() {    
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Minimum number of operations required : "<<minOperation(n)<<endl;
    return 0;
}