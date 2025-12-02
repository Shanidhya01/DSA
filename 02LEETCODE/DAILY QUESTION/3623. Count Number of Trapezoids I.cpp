#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> m;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            m[points[i][1]]++;
        }
        long long ans = 0, sum = 0;
        int mod = 1e9 + 7;
        for(auto &entry : m) {
            long long count = entry.second;
            long long pairs = (count) * (count - 1) / 2;
            ans = (ans + (pairs * sum) % mod) % mod;
            sum = (sum + pairs) % mod;
        }
        return ans;
    }
};