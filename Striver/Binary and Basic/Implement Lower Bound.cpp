// https://www.geeksforgeeks.org/problems/implement-lower-bound/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
