#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll res = 0;
        int n = nums.size();
        
        int lastMin = -1;   // most recent index of minK
        int lastMax = -1;   // most recent index of maxK
        int lastBad = -1;   // most recent index of invalid element
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                lastBad = i;   // reset window
            }
            if (nums[i] == minK) {
                lastMin = i;
            }
            if (nums[i] == maxK) {
                lastMax = i;
            }
            res += max(0, min(lastMin, lastMax) - lastBad);
        }
        
        return res;
    }
};
