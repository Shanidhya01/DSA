#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        vector<int>ans;
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            int rem = target - arr[i];
            if(m.find(rem)!=m.end()){
                ans.push_back(m[rem]);
                ans.push_back(i);
            }
            else{
                m[arr[i]] = i;
            }
        }
        if(!ans.empty())  return true;
        return false;
    }
};