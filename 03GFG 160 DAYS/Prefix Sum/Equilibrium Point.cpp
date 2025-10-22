#include<bits/stdc++.h>
using namespace std;  

// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/equilibrium-point-1587115620

class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        int prefSum = 0, total = 0;
        for (int ele: arr) {
            total += ele;
        }
        for (int pivot = 0; pivot < arr.size(); pivot++) {
          	int suffSum = total - prefSum - arr[pivot];
          	if (prefSum == suffSum) {
              	return pivot;
            }
          	prefSum += arr[pivot];
        }
        return -1;
    }
};