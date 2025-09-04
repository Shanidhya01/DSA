#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int m = pat.size();
        int n = txt.size();
        vector<int> lps(m, 0);
        vector<int> res;

        // Preprocess pattern to create LPS (Longest Prefix Suffix) array
        int len = 0;
        for (int i = 1; i < m; ) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // KMP Search
        int i = 0, j = 0;
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            if (j == m) {
                // Pattern found at index (i - j)
                res.push_back(i - j );  // 0-based indexing
                j = lps[j - 1];
            } else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return res;
    }
};
