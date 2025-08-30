#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int count = 0;
        for (int num : arr) {
            if (num == target) {
                count++;
            }
        }
        return count;
    }
};
