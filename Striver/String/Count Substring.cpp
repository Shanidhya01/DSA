#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubstring(string s) {
        int n = s.length();
        int count[3] = {0}; // count[0] = 'a', count[1] = 'b', count[2] = 'c'
        int left = 0, result = 0;

        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += n - right; // all substrings from left to end are valid
                count[s[left] - 'a']--;
                left++;
            }
        }

        return result;
    }
};
