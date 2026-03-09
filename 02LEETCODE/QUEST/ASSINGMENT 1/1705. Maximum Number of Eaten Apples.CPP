#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int ans = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (int i = 0; i < n || !pq.empty(); i++) {
            if (i < n && apples[i] > 0) {
                pq.push({i + days[i], apples[i]});
            }
            while (!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pair<int,int> top = pq.top();
                pq.pop();
                int expire = top.first;
                int cnt = top.second;
                ans++;
                if (cnt > 1) {
                    pq.push({expire, cnt - 1});
                }
            }
        }
        
        return ans;
    }
};
