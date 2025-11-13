#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // if(n==1 || n==2 ) return n;
        // return climbStairs(n-1) + climbStairs(n-2);
        vector<int> ans(n+1);
        if(n==1 || n==0 ) return 1;
        ans[0] = 1;  
        ans[1] = 1; 
        for (int i = 2; i <= n; ++i)
            ans[i] = ans[i - 1] + ans[i - 2];
        return ans[n];
    }
};