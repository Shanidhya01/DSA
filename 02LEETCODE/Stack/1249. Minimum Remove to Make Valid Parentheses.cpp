#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        for (char& c : s) {  
            if (c == '(') {
                open++;
            } else if (c == ')') {
                if (open == 0) {
                    c = '*'; 
                } else {
                    open--;
                }
            }
        }
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (open > 0 && *it == '(') {
                *it = '*'; 
                open--;
            }
        }
        string result;
        for (char c : s) {
            if (c != '*') result += c;
        }

        return result;
    }
};
