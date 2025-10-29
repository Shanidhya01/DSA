#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);  
        return parent[x];
    }
    void unionSets(int a, int b, vector<int>& parent) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA != rootB)
            parent[rootA] = rootB; 
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1)
                    unionSets(i, j, parent);
            }
        }
        unordered_set<int> provinces;
        for (int i = 0; i < n; ++i)
            provinces.insert(find(i, parent));

        return provinces.size();
    }
};
