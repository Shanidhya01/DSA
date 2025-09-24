// https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr) {
        int max_sum = INT_MIN; 
        int current_sum = 0;   
    
        for (int num : arr) {
            current_sum += num;       
            max_sum = max(max_sum, current_sum);
            if (current_sum < 0) {
                current_sum = 0; 
            }
        }
    
        return max_sum;
    }
};
