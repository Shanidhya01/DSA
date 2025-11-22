#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    long long Pow(long long base , long long exp){
        long long result = 1;
        base %= mod;
        while(exp > 0){
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n){
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        long long result = (Pow(5, evenPos) * Pow(4, oddPos)) % mod;
        return (int)result;
    }
};
