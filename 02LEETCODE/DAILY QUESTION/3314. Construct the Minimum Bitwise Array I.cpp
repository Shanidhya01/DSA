#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            int temp = arr[i];
            for (int j = 1; j < arr[i]; j++) {
                if ((j | (j + 1)) == arr[i]) {
                    arr[i] = j;
                    break;
                }
            }
            if (arr[i] == temp) {
                arr[i] = -1;
            }
        }
        return arr;
    }
};