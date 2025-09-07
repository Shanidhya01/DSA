#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;
        // Reverse the first part 
        reverse(arr.begin(), arr.begin() + d);
        // Reverse the second part 
        reverse(arr.begin() + d, arr.end());
        // Reverse the entire array
        reverse(arr.begin(), arr.end());
    }
    void printArray(const vector<int>& arr) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};
