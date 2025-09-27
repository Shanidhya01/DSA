#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<mat[0].size();j++){
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
    }
};
