#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int csum = nums[0];
        int mx = nums[0];
        if(n==1)   return mx;
        for(int i=1;i<nums.size();i++){
            csum = max(nums[i], csum + nums[i]); // Update cumulative sum
            mx = max(mx, csum);
        }
        return mx;
    }
};