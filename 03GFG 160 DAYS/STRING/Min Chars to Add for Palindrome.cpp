#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChar(string &s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "$" + rev;
        
        int n = combined.size();
        vector<int> lps(n, 0);
        
        // Build KMP prefix function
        for (int i = 1; i < n; i++) {
            int len = lps[i-1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len-1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }
        
        // Minimum characters to add = total length - longest palindromic prefix
        return s.size() - lps.back();
    }
};
