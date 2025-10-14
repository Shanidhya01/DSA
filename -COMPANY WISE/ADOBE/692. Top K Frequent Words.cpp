#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string s : words)
            mp[s]++;
        priority_queue<pair<int, string>> pq;
        for (auto it : mp) {
            pq.push({-it.second, it.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};