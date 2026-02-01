#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];  
        int first = INT_MAX, second = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < first) {
                second = first;
                first = nums[i];
            } else if (nums[i] < second) {
                second = nums[i];
            }
        }
        
        ans += first + second;
        return ans;
    }
};
