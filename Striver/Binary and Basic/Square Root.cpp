#include<bits/stdc++.h>
using namespace std;


//  https://www.geeksforgeeks.org/problems/square-root/1

class Solution {
  public:
    int floorSqrt(int n) {
        // return sqrt(n);
        int res = exp(0.5 * log(n)) ;
        if((res+1) * (res+1) <= n){
            res++;
        }
        return res;
    }
};