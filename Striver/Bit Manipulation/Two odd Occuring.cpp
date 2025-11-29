#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans;
        unordered_map<int,int> m;
        for (int i=0; i<n; i++) {
            m[arr[i]]++;
        }
        for (auto p: m) {
            if (p.second%2==1) {
                ans.push_back(p.first);
            }
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};