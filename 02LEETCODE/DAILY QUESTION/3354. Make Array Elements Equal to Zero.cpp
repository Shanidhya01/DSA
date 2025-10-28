#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValid(vector<int> nums, int curr, int dir) {
        int n = nums.size();
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += dir;
            } else {
                nums[curr]--;
                dir *= -1;
                curr += dir;
            }
        }
        for (int x : nums) {
            if (x != 0) return false;
        }
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums, i, -1)) count++;               
                if (isValid(nums, i, 1)) count++;  
            }
        }

        return count;
    }
};
