#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        
        // find 1st decreasing number from end
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        
        // if no decreasing element reverse the string
        if(idx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        // find the number just greater the nums[idx]
        for(int j=n-1;j>=0;j--){
            if(nums[j] > nums[idx]){
                swap(nums[j],nums[idx]);
                break;
            }
        }
        
        // reverse after swapped element
        reverse(nums.begin() + idx + 1, nums.end());
    }
};