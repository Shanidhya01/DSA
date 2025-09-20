#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0; 
        if (n == 2) return (arr[0] > arr[1]) ? 0 : 1; 
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1])) {
                return mid; 
            }
            else if (mid > 0 && arr[mid] < arr[mid - 1])        high = mid - 1;
            else                                                low = mid + 1;
        }
        return -1; 
    }
};
