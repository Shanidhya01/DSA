#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> m1,m2;
        vector<int>res;
        int n = a.size();
        int m = b.size();
        for(int i=0;i<n;i++){
            m1[a[i]]++;
        }
        for(int i=0;i<m;i++){
            m2[b[i]]++;
        }
        for(auto it = m1.begin(); it != m1.end(); ++it){
            int key = it->first;
            if(m2.find(key) != m2.end()){
                res.push_back(key);
            }
        }
        return res;
    }
};