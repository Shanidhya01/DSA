// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "(*)"
// Output: true

// Example 3:
// Input: s = "(*))"
// Output: true

#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool checkValidString(string s) {
//         int open = 0;
//         int close = 0;
//         int length = s.length() - 1;
//         for (int i = 0; i <= length; i++) {
//             if (s[i] == '(' || s[i] == '*') {
//                 open++;
//             } else {
//                 open--;
//             }
//             if (s[length - i] == ')' || s[length - i] == '*') {
//                 close++;
//             } else {
//                 close--;
//             }
//             if (open < 0 || close < 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> asterisks;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(') {
                open.push(i);
            } else if (ch == '*') {
                asterisks.push(i);
            } else {
                if (!open.empty()) {
                    open.pop();
                } else if (!asterisks.empty()) {
                    asterisks.pop();
                } else {
                    return false;
                }
            }
        }
        while (!open.empty() && !asterisks.empty()) {
            if (open.top() > asterisks.top()) {
                return false; 
            }
            open.pop();
            asterisks.pop();
        }
        return open.empty();
    }
};