#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m ) return false;
        vector<int> count1(26, 0), count2(26, 0);
        for (int i = 0; i < n; i++) {
            count1[s1[i] - 'a']++;   
            count2[s2[i] - 'a']++;  
        }
        for (int i = n; i < m; i++) {
            if (count1 == count2) return true;
            count2[s2[i] - 'a']++;
            count2[s2[i-n]-'a']--;
        }
        return count1 == count2;
    }
};