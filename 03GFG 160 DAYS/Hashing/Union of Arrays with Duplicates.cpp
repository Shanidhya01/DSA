#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        unordered_set<int> m1;
        vector<int> res;
        for(int i=0;i<n;i++)   m1.insert(a[i]);
        for(int i=0;i<m;i++)   m1.insert(b[i]);
        for(int num : m1)   res.push_back(num);
        return res;
    }
};