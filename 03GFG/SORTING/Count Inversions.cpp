#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;
        int m = (l + r) / 2;
        long long inv = mergeSort(arr, l, m) + mergeSort(arr, m + 1, r);

        vector<int> temp;
        int i = l, j = m + 1;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else {
                temp.push_back(arr[j++]);
                inv += (m - i + 1); // all remaining left elements form inversions
            }
        }
        while (i <= m) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);
        copy(temp.begin(), temp.end(), arr.begin() + l);
        return inv;
    }

    long long inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};
