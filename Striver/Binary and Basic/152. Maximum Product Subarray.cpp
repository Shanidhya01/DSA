#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int MAX = nums[0];
        int MIN = nums[0];
        int result = nums[0];
        for(int i=1;i<nums.size();i++){
            int curr = nums[i];
            int temp_max = max({curr, MAX * curr, MIN * curr});
            int temp_min = min({curr, MAX * curr, MIN * curr});
            MAX = temp_max;
            MIN = temp_min;
            result = max(result, MAX);
        }
        return result;
    }
};