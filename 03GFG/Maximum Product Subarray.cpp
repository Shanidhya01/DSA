#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // Initialize variables
        int max_product = nums[0];
        int min_product = nums[0];
        int result = nums[0];

        // Iterate through the array
        for (int i = 1; i < n; i++) {
            // If the current element is negative, swap max and min
            if (nums[i] < 0) {
                swap(max_product, min_product);
            }

            // Update max_product and min_product
            max_product = max(nums[i], max_product * nums[i]);
            min_product = min(nums[i], min_product * nums[i]);

            // Update the result
            result = max(result, max_product);
        }

        return result;
    }
};


