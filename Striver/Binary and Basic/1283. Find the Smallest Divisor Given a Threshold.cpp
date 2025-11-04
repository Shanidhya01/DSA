#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l < r) {
            int mid = (l + r) / 2;
            long sum = 0;
            for(int x : nums)
                sum += (x + mid - 1) / mid;  // ceil(x/mid)

            if(sum > threshold)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
