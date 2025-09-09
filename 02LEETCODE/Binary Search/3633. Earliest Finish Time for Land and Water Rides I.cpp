#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int ls = landStartTime[i];
                int le = ls + landDuration[i];
                int ws = max(waterStartTime[j], le);
                int ft1 = ws + waterDuration[j];

                int waters = waterStartTime[j];
                int waterend = waters + waterDuration[j];
                int LS = max(landStartTime[i], waterend);
                int ft2 = LS + landDuration[i];

                ans = min({ans,ft1,ft2});
            }
        }
        return ans;
    }
};