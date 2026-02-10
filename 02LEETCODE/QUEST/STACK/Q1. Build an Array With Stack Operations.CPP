#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // int m = target.size();
        // vector<string> ans;
        // int i = 0;
        // for (int num = 1; num <= n; num++) {
        //     if (i == target.size())
        //         break;
        //     if (num == target[i]) {
        //         ans.push_back("Push");
        //         i++;
        //     } else {
        //         ans.push_back("Push");
        //         ans.push_back("Pop");
        //     }
        // }
        // return ans;

        vector<string> res;
        int j = 0;
        for (int i = 1; i <= n && j < target.size(); i++) {
            res.push_back("Push");
            if (i == target[j]) {
                j++;
            } else {
                res.push_back("Pop");
            }
        }
        return res;
    }
};