#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<int> pq;
        for (int n : target) {
            sum += n;
            pq.push(n);
        }
        while (true) {
            int x = pq.top();
            pq.pop();
            long long rest = sum - x;
            if (x == 1 || rest == 1)
                return true;
            if (rest == 0 || x < rest)
                return false;
            long long prev = x % rest;
            if (prev == 0)
                return false;
            sum = rest + prev;
            pq.push(prev);
        }
    }
};