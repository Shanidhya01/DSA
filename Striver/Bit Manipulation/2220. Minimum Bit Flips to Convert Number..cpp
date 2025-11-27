#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s = bitset<32>(start).to_string();
        string g = bitset<32>(goal).to_string();
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (s[i] != g[i]) count++;   
        }
        return count;
    }
};