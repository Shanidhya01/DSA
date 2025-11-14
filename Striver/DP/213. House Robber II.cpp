#include<bits/stdc++.h>
using namespace std;

// bottom up approach
class Solution {
public:
    int robLinear(vector<int>& nums,int start,int end){
        int len = end - start + 1;
        if(len ==1 ) return nums[start];
        vector<int> dp(len, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i-1], nums[start+i] + dp[i-2]);
        }
        return dp[len-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        //case 1
        int case1 = robLinear(nums,0,n-2);
        //case 2
        int case2 = robLinear(nums,1,n-1);
        return max(case1,case2);
    }
};


// top down approach
class Solution {
public:
    vector<int>dp;
    int robLinear(vector<int>& nums,int start,int end){
        dp.assign(nums.size(),-1);
        return helper(nums,start,end);
    }
    int helper(vector<int>& nums,int i,int end){
        if(i>end) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i] + helper(nums, i+2, end),helper(nums, i+1, end));

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        //case 1
        int case1 = robLinear(nums,0,n-2);
        //case 2
        int case2 = robLinear(nums,1,n-1);
        return max(case1,case2);
    }
};