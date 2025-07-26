// Given an undirected weighted connected graph, find the Really Special SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and:

// There is only one exclusive path from a node to every other node.
// The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
// No cycles are formed
// To create the Really Special SubTree, always pick the edge with smallest weight. Determine if including it will create a cycle. If so, ignore the edge. If there are edges of equal weight available:

// Choose the edge that minimizes the sum u+w+t where u and v are vertices and wt is the edge weight.
// If there is still a collision, choose any of them.
// Print the overall weight of the tree formed using the rules.

// For example, given the following edges:
// u	v	wt
// 1	2	2
// 2	3	3
// 3	1	5
// First choose 1->2 at weight 2. Next choose 2->3 at weight 3. All nodes are connected without cycles for a total weight of 3+2 = 5.

// Function Description

// Complete the kruskals function in the editor below. It should return an integer that represents the total weight of the subtree formed.

// kruskals has the following parameters:
// g_nodes: an integer that represents the number of nodes in the tree
// g_from: an array of integers that represent beginning edge node numbers
// g_to: an array of integers that represent ending edge node numbers
// g_weight: an array of integers that represent the weights of each edge

// Input Format

// The first line has two space-separated integers g_nodes and g_edges, the number of nodes and edges in the graph.

// The next g_edges lines each consist of three space-separated integers g_from, g_to and g_weight, where g_from and g_to denote the two nodes between which the undirected edge exists and g_weight denotes the weight of that edge.

// Constraints
// 2 <= g_nodes <= 3000
// 1 <= g_edges <= N*(N-1)/2
// 1 <= g_from[i], g_to[i] <= N
// 1 <= g_weight[i] <= 10^5
// **Note: ** If there are edges between the same pair of nodes with different weights, they are to be considered as is, like multiple edges.

// Output Format

// Print a single integer denoting the total weight of the Really Special SubTree.

// Sample Input 1
// 4 6
// 1 2 5
// 1 3 3
// 4 1 6
// 2 4 7
// 3 2 4
// 3 4 5
// Sample Output 1
// 12

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int find(vector<int> &parent, int x) {
    if (parent[x] == x)     return x;
    return parent[x] = find(parent, parent[x]);
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a == b) return; // already in the same set
    if (rank[a] >= rank[b]) {
      rank[a]++;
      parent[b] = a;
    } else {
      rank[b]++;
      parent[a] = b;
    }
}
struct Edge {
    int src, dest, wt;
};

bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

ll kruskals(vector<Edge> &input,int n){
  sort(input.begin(), input.end(), cmp);
  vector<int> parent(n + 1), rank(n + 1, 1);
  for(int i=0; i <= n; i++)     parent[i] = i;
  int edgeCount = 0;  //n-1
  int i = 0;
  ll totalWeight = 0;
  while(edgeCount < n - 1 and i<int(input.size())) {
    Edge curr = input[i];
    int srcParent = find(parent, curr.src);
    int destParent = find(parent, curr.dest);
    if(srcParent != destParent) {
      Union(parent, rank, srcParent, destParent);
      edgeCount++;
      totalWeight += curr.wt;
    }
    i++;
  }
  return totalWeight;
}
int main(){
  int n, e;
  cin >> n >> e;
  vector<Edge> v(e);
  for(int i = 0; i < e; i++) {
    cin>> v[i].src >> v[i].dest >> v[i].wt;
  }
  cout<<kruskals(v, n)<<"\n";
  return 0;
}
