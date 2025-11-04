#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
       unordered_map<int, int> m;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
                m[arr[i]]++;
        }
        int repeated = -1, missing = -1;
        for (int i = 1; i <= n; i++) {
            if (m[i] == 0)            missing = i;
            else if (m[i] == 2)       repeated = i; 
        }
        return {repeated,missing};
        
    }
};