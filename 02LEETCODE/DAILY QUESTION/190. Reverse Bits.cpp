#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string numtobit(int num) {
        string binary = "";
        for (int i = 31; i >= 0; i--) {
            binary += ((num >> i) & 1) ? '1' : '0';
        }
        return binary;
    }

    int bittonum(string& binary) {
        int decimal = 0;
        for (char c : binary) {
            decimal = (decimal << 1) + (c - '0');
        }
        return decimal;
    }

    int reverseBits(int n) {
        string s = numtobit(n);  
        reverse(s.begin(), s.end());
        return bittonum(s);      
    }
};
