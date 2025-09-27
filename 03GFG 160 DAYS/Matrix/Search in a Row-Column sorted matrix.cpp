#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool matSearch(vector<vector<int>> &arr, int x) {
        int n = arr.size(), m = arr[0].size();
        int r = 0, c = m - 1;
        while (r < n and c >= 0) {
            if (arr[r][c] == x)                return 1;
            if (arr[r][c] > x)                c--;
            else                r++;
        }
        return 0;
    }
};


// // User function template for C++
// class Solution {
//   public:
//     bool matSearch(vector<vector<int>> &mat, int x) {
//         // your code here
//         int n = mat.size();
//         int m = mat[0].size();
//         for(int i =0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(mat[i][j] == x )  return true;
//             }
//         }
//         return false;
//     }
// };