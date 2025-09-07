#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])    v.push_back(nums[i]);
        }
        if (v.size() < 3)    return v[0];
        return v[2];
    }
};