// 1135. Connecting Cities With Minimum Cost
// There are N cities numbered from 1 to N.
// You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect city1 and city2 together.  (A connection is bidirectional: connecting city1 and city2 is the same as connecting city2 and city1.)
// Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of length 1) that connects those two cities together.  The cost is the sum of the connection costs used. If the task is impossible, return -1.
// Example 1:
// Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
// Output: 6
// Explanation: 
// Choosing any 2 edges will connect all cities so we choose the minimum 2.
// Note:
// 1 <= N <= 10000
// 1 <= connections.length <= 10000
// 1 <= connections[i][0], connections[i][1] <= N
// 0 <= connections[i][2] <= 10^5
// connections[i][0] != connections[i][1]

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find(vector<int> &parent, int x) {
      if (parent[x] == x) return x;
      return parent[x] = find(parent, parent[x]);
    }
    bool Union(vector<int> &parent, vector<int> &rank, int a, int b){
      a = find(parent, a);
      b = find(parent, b);
      if (a == b) return false; // already in the same set
      if (rank[a] >= rank[b]) {
          rank[a]++;
          parent[b] = a;
      } else {
          rank[b]++;
          parent[a] = b;
      }
      return true;
    }
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[2] < b[2];
    }
    int minimumCost(int n, vector<vector<int>> &connections) {
        sort(connections.begin(), connections.end(), cmp);
        vector<int> parent(n + 1), rank(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
        int totalCost = 0, edgesUsed = 0;
        for (const auto& conn : connections) {
            int u = conn[0], v = conn[1], cost = conn[2];
            if (Union(parent, rank, u, v)) {
                totalCost += cost;
                edgesUsed++;
                if (edgesUsed == n - 1) break;
            }
        }
        return (edgesUsed == n - 1) ? totalCost : -1;
    }
};
int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> connections = {
        {1,2,5},{1,3,6},{2,3,1}
    };
    int result = sol.minimumCost(n, connections);
    cout << "Minimum Cost to Connect All Nodes: " << result << endl;
    return 0;
}