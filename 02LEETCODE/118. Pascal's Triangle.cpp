#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v;
    int m = numRows;  
    // Initialize the vector
    for (int i = 0; i < m; i++) {
        vector<int> a(i + 1);  
        v.push_back(a);
    }

    // Generate Pascal's triangle
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i){
                v[i][j] = 1;  
            } 
            else
            {
                v[i][j] = v[i - 1][j] + v[i - 1][j - 1];  
            }
        }
    }

    return v;
    }
};