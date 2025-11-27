#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     long long maxSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         long long ans = LLONG_MIN;
//         long long prefix = 0;
//         unordered_map<int, long long> minPrefix;
//         minPrefix[0] = 0; 
        
//         for (int j = 0; j < n; j++) {
//             prefix += nums[j];
//             int mod = (j+1) % k;
            
//             if (minPrefix.count(mod)) {
//                 ans = max(ans, prefix - minPrefix[mod]);
//             }
//             if (!minPrefix.count(mod)) {
//                 minPrefix[mod] = prefix;
//             } else {
//                 minPrefix[mod] = min(minPrefix[mod], prefix);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0, maxSum = LONG_LONG_MIN;
        vector<long long> kSum(k, LONG_LONG_MAX / 2);
        kSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = max(maxSum, prefixSum - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
};