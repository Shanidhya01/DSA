#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0, b = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a')    a += 1;
            if(s[i] == 'b')    b += 1;
        }
        return abs(a - b);
    }
};