#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        int j = n-1;
        int i = 0 ;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }
};