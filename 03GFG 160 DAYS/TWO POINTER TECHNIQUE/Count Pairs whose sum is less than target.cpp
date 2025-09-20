#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int l = 0, r = n - 1;
        int ans = 0;

        while (l < r) {
            if (arr[l] + arr[r] < target) {
                ans += (r - l);  // all pairs with arr[l]
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
