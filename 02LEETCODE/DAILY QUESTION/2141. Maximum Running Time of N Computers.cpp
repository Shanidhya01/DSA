#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& battery) {
        long long time = 0;
        for (auto x : battery)            time += x;
        sort(battery.rbegin(), battery.rend());
        for (int i = 0; i < battery.size(); i++, n--) {
            if (battery[i] <= (time / n))
                break;
            time -= battery[i];
        }

        return time / n;
    }
};