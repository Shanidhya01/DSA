#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int len=0;
        int zeropos = -1;
        int maxlen = 0;
        int count = 0;
        while(j<n){
            int prev = zeropos;
            if(nums[j]==0){
                count++;
                zeropos = j;
            }
            if(count<=1) j++;
            else{
                len = j-i;
                maxlen = max(maxlen,len);
                i= prev +1;
                count--;
                j++;
            }
        }
        len = j-i;
        maxlen = max(maxlen,len);
        return maxlen-1;
    }
};