#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findMajority(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int> Majority;
        int n =  nums.size();
        int threshold = n/3;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        for(auto ele : mp){
            int num = ele.first;
            int cnt = ele.second;
            
            if(cnt > threshold) Majority.push_back(num);
        }
        sort(Majority.begin(),Majority.end());
        return Majority;
    }
};