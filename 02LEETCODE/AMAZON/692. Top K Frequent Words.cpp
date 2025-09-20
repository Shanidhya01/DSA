#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;
    for (auto &word : words) {
      mp[word]++;
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minHeap;

    for (auto &it : mp) {
      minHeap.push({it.second, it.first});
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    vector<string> result;
    while (!minHeap.empty()) {
      result.push_back(minHeap.top().second);
      minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};