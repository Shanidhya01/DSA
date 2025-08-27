#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        // frequency array for lowercase letters
        vector<int> freq(26, 0);

        // count frequency of each character
        for(char c : s) {
            freq[c - 'a']++;
        }

        // find first non-repeating character
        for(char c : s) {
            if(freq[c - 'a'] == 1) {
                return c;
            }
        }

        // if none found
        return '$';
    }
};