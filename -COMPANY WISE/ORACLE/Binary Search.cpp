#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/binary-search-1587115620/1

// User function template for C++

class Solution
{
public:
  int binarysearch(vector<int> &arr, int k)
  {
    int low = 0, high = arr.size() - 1;
    int result = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (arr[mid] == k)
      {
        result = mid;   // Update result to the current index
        high = mid - 1; // Move to the left part to find the first occurrence
      }
      else if (arr[mid] < k)
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    return result;
  }
};
