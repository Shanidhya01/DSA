#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            int at = s.find('@');
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        } else {
            string digit;
            for (char c : s) {
                if (isdigit(c))
                    digit += c;
            }

            string local = "***-***-" + digit.substr(digit.size() - 4);

            if (digit.size() == 10)
                return local;

            string international(digit.size() - 10, '*');
            return "+" + international + "-" + local;
        }
    }
};