#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string curr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');  // build number
            }
            else if (ch == '[') {
                numStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            }
            else if (ch == ']') {
                string temp = curr;
                curr = strStack.top(); strStack.pop();
                int repeat = numStack.top(); numStack.pop();
                while (repeat--) curr += temp;
            }
            else {
                curr += ch;  // add normal characters
            }
        }
        return curr;
    }
};
