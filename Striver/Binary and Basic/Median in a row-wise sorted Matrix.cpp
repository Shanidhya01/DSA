#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int> arr;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                arr.push_back(mat[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        int mid = arr.size() / 2;
        return arr[mid];
    }
};


// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1