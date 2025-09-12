#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool ispalin(string s)
  {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    if (s == s2)
    {
      return true;
    }
    return false;
  }

  void helper(string s, vector<string> &partition, vector<vector<string>> &ans)
  {
    if (s.size() == 0)
    {
      ans.push_back(partition);
      return;
    }

    for (int i = 0; i < s.size(); i++)
    {

      string part = s.substr(0, i + 1);

      if (ispalin(part))
      {
        partition.push_back(part);
        helper(s.substr(i + 1), partition, ans);
        partition.pop_back(); // Backtraking
      }
    }
  }
  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> ans;
    vector<string> partition;
    helper(s, partition, ans);
    return ans;
  }
};