#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double pow(double x , int n){
        if(n==0) return 1.0;
        double half = pow(x,n/2);
        if(n%2==0) return half * half;
        else{
            if(n>0) return x*half*half;
            else return (1/x)*half*half;
        } 
    }
    double myPow(double x, int n) {
        return pow(x,n);
        
    }
};