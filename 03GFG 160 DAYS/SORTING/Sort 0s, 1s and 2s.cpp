#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0;
        int mid = 0;
        int high = arr.size()-1;
        while(mid<=high){
            if(arr[mid] == 2){
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
            }
            else if(arr[mid] == 0){
                int tmp = arr[mid];
                arr[mid] = arr[low];
                arr[low] = tmp;
                mid++;
                low++;
            }
            else if(arr[mid] == 1)  mid++;
        }
    }
};
