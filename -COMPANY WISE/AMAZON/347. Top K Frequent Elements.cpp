#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // map pair is <ele,freq>
        unordered_map<int,int> m;
        for(int ele : nums)     m[ele]++;

        // heap pair is <freq,ele>
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(auto x : m){
            int ele = x.first;
            int freq = x.second;
            // pair<int,int> p = {freq,ele};
            // pq.push(p);
            pq.push({freq,ele});
            if(pq.size() > k)  pq.pop();
        }   
        vector<int> ans;
        while(pq.size()>0)     {
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};