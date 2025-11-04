#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
   vector<int>v;
   int rowindex = 0;
   
   int maxcount = 0;
    for(int i = 0 ; i<m ; i++){
        int count = 0 ;
        for(int j = 0;  j<n ; j++){
          
            if(mat[i][j]==1){
                count ++;
                //v.push_back(i);
                if(count>maxcount){
                maxcount = count;
                rowindex = i;
                }
                
            }
        }
    }
    return {rowindex , maxcount};
    }
};