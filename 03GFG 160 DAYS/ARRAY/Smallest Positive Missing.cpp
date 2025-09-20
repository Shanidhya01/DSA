#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n= arr.size();
        for(int i=0;i<n;i++){
            if(arr[i] <= 0) arr[i] = 0;
        }
        sort(arr.begin(),arr.end());
        int missing = 1;
        for(int i=0;i<n;i++){
            if(arr[i] == missing){
                missing++;
            }
        }
        return missing;
    }
};