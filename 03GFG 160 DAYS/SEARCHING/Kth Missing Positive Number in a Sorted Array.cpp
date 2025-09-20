#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        unordered_set<int>s(arr.begin(),arr.end());
        int cnt = 0, curr = 0;
        while(cnt < k) {
            curr++;
            if(s.find(curr) == s.end())   cnt++;
        }
        return curr;
    }
};