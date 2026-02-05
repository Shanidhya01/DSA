#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size(), p = n - 1, q = 0;

        for (int i = 0; i < n - 1; i++) {
            if (p == n - 1 && nums[i] >= nums[i + 1])
                p = i;
            if (q == 0 && nums[n - 1 - i] <= nums[n - 2 - i])
                q = n - 1 - i;
            if (p < q)
                return isDecreasing(nums, p, q);
        }

        return false;
    }

    bool isDecreasing(vector<int>& A, int a, int b) {
        if (a == 0 || b == A.size() - 1) return false;
        for (int i = a; i < b; i++)
            if (A[i] <= A[i + 1]) return false;
        
        return true;
    }
};
