#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/Unique-Morse-Code-Words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCode = {
            ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
            "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
            "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
            "...-", ".--",  "-..-", "-.--", "--.."
        };
        unordered_set<string>Unique;
        for(const string word : words){
            string morse = "";
            for(char c : word){
                morse += morseCode[c-'a'];
            }
            Unique.insert(morse);
        }
        return Unique.size();
    }
};