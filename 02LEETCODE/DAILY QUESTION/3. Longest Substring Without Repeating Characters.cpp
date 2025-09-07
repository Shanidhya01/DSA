#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        int length = 0,left=0;
        for(int right=0;right<n;right++){
            char c = s[right];
            m[c]++;
            while (m[c] > 1){
                m[s[left]]--;
                left++;
            }
            length = max(length,right-left+1);
        }   
        return length;
    }
};