#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        if (arr.empty()) return 0;
        sort(arr.begin(), arr.end());
    
        int res = 1, cnt = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i-1]) 
                continue;
            if (arr[i] == arr[i - 1] + 1) {
                cnt++;
            } 
            else {
                cnt = 1;
            }

            res = max(res, cnt);
        }
        return res;
    }
};