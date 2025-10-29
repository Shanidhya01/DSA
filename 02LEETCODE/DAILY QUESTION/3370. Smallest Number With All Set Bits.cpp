#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int smallestNumber(int n)
  {
    int ans = 0;
    while (ans < n)
    {
      ans = (ans * 2) + 1;
    }
    return ans;
  }
};