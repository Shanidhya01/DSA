#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<bool> row(n, false), col(m, false);

        // First pass: mark rows and columns
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // Second pass: set zeros
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(row[i] || col[j]){
                    mat[i][j] = 0;
                }
            }
        }
    }
};
