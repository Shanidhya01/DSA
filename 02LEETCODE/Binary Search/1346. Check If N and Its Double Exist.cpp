#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int customBinarySearch(vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;
        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] == target)             return mid;
            else if (arr[mid] < target)         lo = mid + 1;
            else                                hi = mid - 1;
        }
        return -1;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int target = 2 * arr[i];
            int index = customBinarySearch(arr,target);
            if(index >= 0 && index != i)  return true;
        }
        return false;
    }
};