#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& strs) {
        // code here
        unordered_map<string,vector<string>> m;
        for(auto x : strs){
            string word = x;
            sort(word.begin(),word.end());
            m[word].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x: m){
            ans.push_back(x.second);
        }
        return ans;
    }
};