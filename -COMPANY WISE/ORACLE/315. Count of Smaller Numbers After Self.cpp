#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void mergeSort(vector<pair<int, int>> &nums, int left, int right,
                 vector<int> &result)
  {
    if (left >= right)
      return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid, result);
    mergeSort(nums, mid + 1, right, result);
    vector<pair<int, int>> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0, count = 0;
    while (i <= mid && j <= right)
    {
      if (nums[i].first <= nums[j].first)
      {
        result[nums[i].second] += count;
        temp[k++] = nums[i++];
      }
      else
      {
        count++;
        temp[k++] = nums[j++];
      }
    }
    while (i <= mid)
    {
      result[nums[i].second] += count;
      temp[k++] = nums[i++];
    }
    while (j <= right)
    {
      temp[k++] = nums[j++];
    }
    for (int p = 0; p < temp.size(); ++p)
    {
      nums[left + p] = temp[p];
    }
  }
  vector<int> countSmaller(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> result(n, 0);
    vector<pair<int, int>> copy;
    for (int i = 0; i < n; ++i)
    {
      copy.push_back({nums[i], i});
    }
    mergeSort(copy, 0, n - 1, result);
    return result;
  }
};
