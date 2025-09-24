#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> freq(26, INT_MAX);  // Global min frequency

        for (auto& word : words) {
            vector<int> count(26, 0);  // Frequency for current word
            for (char c : word) {
                count[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                freq[i] = min(freq[i], count[i]);  // Update global min
            }
        }

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < freq[i]; ++j) {
                ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;
    }
};
