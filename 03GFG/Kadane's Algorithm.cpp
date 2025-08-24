#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int res = arr[0];
        int maxEnd = arr[0];
        
        for(int i=1;i<arr.size();i++){
            maxEnd = max(arr[i],maxEnd+arr[i]);
            
            res = max(res,maxEnd);
        }
        return res;
    }
};