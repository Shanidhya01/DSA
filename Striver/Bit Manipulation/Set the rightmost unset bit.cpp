#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int setBit(int n) {
        return n | (n + 1);
    }
};
