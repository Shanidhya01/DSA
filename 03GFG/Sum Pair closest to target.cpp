#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return {}; // not enough elements

        sort(arr.begin(), arr.end()); // sort the array
        
        int left = 0, right = n - 1;
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;
        vector<int> result(2);

        while (left < right) {
            int sum = arr[left] + arr[right];
            int diff = abs(sum - target);

            // update result if this sum is closer
            if (diff < minDiff) {
                minDiff = diff;
                closestSum = sum;
                result = {arr[left], arr[right]};
            }

            // move pointers
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};
