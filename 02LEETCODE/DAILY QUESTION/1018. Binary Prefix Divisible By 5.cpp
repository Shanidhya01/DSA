#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int num = 0;
        for(auto & n : nums){
            num = (num << 1) + n;
            num = num%5;
            ans.push_back(num==0);
        }
        return ans;
    }
};