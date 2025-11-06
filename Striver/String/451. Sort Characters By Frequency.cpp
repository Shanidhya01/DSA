#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string result;
        unordered_map<char,int> m;
        for(auto x : s) m[x]++;
        priority_queue<pair<int,char>> pq;
        for(auto y : m){
            pq.push({y.second,y.first});
        }
        while(!pq.empty()){
            pair<int,char> top = pq.top();
            int freq = top.first;
            char ch = top.second;
            pq.pop();
            result.append(freq, ch);
        }
        return result;
    }
};