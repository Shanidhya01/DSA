#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        unordered_map<int, vector<int>> map;
        vector<vector<int>> ans;
        for (int j=0; j<arr.size(); j++) {
            for (int k=j+1; k<arr.size(); k++) {
                int val = -1*(arr[j]+arr[k]);
                if (map.find(val)!=map.end()) {
                    for (auto i: map[val]) {
                        ans.push_back({i, j, k});
                    }
                }
            }
            map[arr[j]].push_back(j);
        }
        return ans;
    }
};