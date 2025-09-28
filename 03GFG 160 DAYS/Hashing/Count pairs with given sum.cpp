#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int,int> freq;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            int rem = target - arr[i];
            if (freq.find(rem) != freq.end()) {
                count += freq[rem];
            }
            freq[arr[i]]++;
        }

        return count;
    }
};
