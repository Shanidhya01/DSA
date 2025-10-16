#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reach = 0, cnt = 0, curr = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            max_reach = max(max_reach, i + nums[i]);
            if (i == curr) {
                cnt++;
                curr = max_reach;
            }
        }
        return cnt;
    }
};