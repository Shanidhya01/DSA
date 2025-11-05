#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        // If s1 is longer than s2, it's impossible for s2 to contain its permutation
        if (n > m) return false;
        
        // Frequency arrays for 26 lowercase letters
        vector<int> count1(26, 0), count2(26, 0);
        // Count frequencies of characters in s1
        // and in the first 'n' characters of s2 (initial window)
        for (int i = 0; i < n; i++) {

            count1[s1[i] - 'a']++;   // frequency of s1
            count2[s2[i] - 'a']++;   // frequency of first window in s2
        }   
        // Slide the window over s2
        for (int i = n; i < m; i++) {
            // If the current window matches s1's frequency, we found a permutation
            if (count1 == count2) return true;
            // Add the new character entering the window
            count2[s2[i] - 'a']++;            
            // Remove the character that is sliding out of the window
            count2[s2[i - n] - 'a']--;
        }
        return count1 == count2;
    }
};