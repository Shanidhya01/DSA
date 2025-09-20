#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int ans = INT_MAX;
        for(int i=0;i<arr.size();i++){
            ans = min(arr[i],ans);
            
        }
        return ans;
    }
};