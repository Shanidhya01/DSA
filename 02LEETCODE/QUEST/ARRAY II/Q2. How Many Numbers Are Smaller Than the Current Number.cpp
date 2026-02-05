#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size(),cnt=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i] > nums[j] && j!=i) cnt++;
            }
            ans.push_back(cnt);
            cnt = 0;
        }
        return ans;
    }
};