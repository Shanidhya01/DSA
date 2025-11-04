#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result{intervals[0]};
        for (auto& i : intervals) {
            if (result.back()[1] >= i[1])
                continue;
            if (result.back()[1] >= i[0])
                result.back()[1] = i[1];
            else
                result.push_back(i);
        }
        return result;
    }
};