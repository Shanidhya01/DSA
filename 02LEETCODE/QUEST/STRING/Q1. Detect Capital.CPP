#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        // all upper
        string upperWord = word;
        for (char& c : upperWord)          c = toupper(c);
        if (word == upperWord)          return true;

        // all lower
        string lowerWord = word;
        for (char& c : lowerWord)    c = tolower(c);
        if (word == lowerWord)     return true;

        // first upper
        if (isupper(word[0])) {
            bool restLower = true;
            for (int i = 1; i < word.size(); i++) {
                if (!islower(word[i])) {
                    restLower = false;
                    break;
                }
            }
            if (restLower)
                return true;
        }

        return false;
    }
};
