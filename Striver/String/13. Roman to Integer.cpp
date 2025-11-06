#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int value(char r)
  {
    if (r == 'I')
      return 1;
    if (r == 'V')
      return 5;
    if (r == 'X')
      return 10;
    if (r == 'L')
      return 50;
    if (r == 'C')
      return 100;
    if (r == 'D')
      return 500;
    if (r == 'M')
      return 1000;
    return -1;
  }
  int romanToInt(string r)
  {
    int res = 0;
    for (int i = 0; i < r.size(); i++)
    {
      int s1 = value(r[i]);
      if (i + 1 < r.length())
      {
        int s2 = value(r[i + 1]);
        if (s1 >= s2)
        {
          res += s1;
        }
        else
        {
          res += (s2 - s1);
          i++;
        }
      }
      else
      {
        res += s1;
      }
    }
    return res;
  }
};