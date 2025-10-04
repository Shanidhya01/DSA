#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& currentPath, int node) {
        currentPath.push_back(node);
        if (node == graph.size() - 1) {
            paths.push_back(currentPath);
        } else {
            for (int neighbor : graph[node]) { 
                dfs(graph, paths, currentPath, neighbor);
            }
        }
        currentPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> currentPath;
        dfs(graph, paths, currentPath, 0);
        return paths;
    }
};