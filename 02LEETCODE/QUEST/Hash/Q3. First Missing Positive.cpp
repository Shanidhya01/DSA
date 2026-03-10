#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int n = nums.size();
        for (int num : nums) {
            if (num > 0) {
                mp[num] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (mp.find(i) == mp.end()) {
                return i;
            }
        }
        return n + 1;
    }
};
