#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  typedef pair<int,vector<int>> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        // Your code here
        priority_queue<pi> pq;
        for(auto v : arr){
            int x = v[0],y = v[1];
            int dist = x*x + y*y;
            pq.push({dist,v});
            if(pq.size() > k)  pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            auto v = pq.top().second;
            ans.push_back(v);
            pq.pop();
        }
        return ans;
    }
};