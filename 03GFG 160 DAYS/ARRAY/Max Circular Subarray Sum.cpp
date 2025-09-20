#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();

        // Kadane’s algorithm for max subarray sum
        int curMax = arr[0], maxNonWrap = arr[0];
        int curMin = arr[0], minSub = arr[0];
        int totalSum = arr[0];

        for (int i = 1; i < n; i++) {
            curMax = max(arr[i], curMax + arr[i]);
            maxNonWrap = max(maxNonWrap, curMax);

            curMin = min(arr[i], curMin + arr[i]);
            minSub = min(minSub, curMin);

            totalSum += arr[i];
        }

        // Wrapping max = totalSum - minSub
        int maxWrap = totalSum - minSub;

        // If all elements are negative, maxWrap = 0, so use maxNonWrap
        if (maxWrap == 0) return maxNonWrap;

        return max(maxNonWrap, maxWrap);
    }
};
