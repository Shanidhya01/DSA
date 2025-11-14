#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int ftd(vector<int> arr, int i){
        if(i== arr.size()-1)  return arr[i];
        if( i== arr.size()-2) return max(arr[i],arr[i+1]);

        if(dp[i]!= -1)  return dp[i];
        return dp[i] = max(arr[i]+ftd(arr,i+2),0 + ftd(arr,i+1));
    }

    int rob(vector<int>& nums) {
        // bottom up
        // int n = nums.size();
        // if (n == 1)     return nums[0];
        // vector<int> dp(n,0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0],nums[1]);
        // for(int i=2;i<n;i++){
        //     dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        // }
        // return dp[n-1];


        // top down 
        dp.clear();
        dp.resize(nums.size(),-1);
        return ftd(nums,0);
    }
};