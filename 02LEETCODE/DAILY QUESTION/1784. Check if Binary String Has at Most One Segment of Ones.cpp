#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        // return s.find("01") == string::npos;
        bool seen0 = false;
        for(char c : s){
            if(c=='0') seen0 = true;
            if(seen0 && c == '1') return false;
        }
        return true;
    }
};