#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        unordered_map<int, int> prefixIndex;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == 0) {
                maxLen = i + 1;
            } else if (prefixIndex.count(sum)) {
                maxLen = max(maxLen, i - prefixIndex[sum]);
            } else {
                prefixIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
