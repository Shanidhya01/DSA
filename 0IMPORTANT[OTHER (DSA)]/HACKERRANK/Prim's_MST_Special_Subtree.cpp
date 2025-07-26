/*
Given a graph which consists of several edges connecting its nodes, find a subgraph of the given graph with the following properties:
The subgraph contains all the nodes present in the original graph.
The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
It is also required that there is exactly one, exclusive path between any two nodes of the subgraph.
One specific node S is fixed as the starting point of finding the subgraph using Prim's Algorithm.
Find the total weight or the sum of all edges in the subgraph.

Example
n = 3
edges = [[1,2,2],[2,3,2],[1,3,3]]
start = 1

Starting from node 1, select the lower weight edge, i.e. 1<->2, weight 2.
Choose between the remaining edges, 2<->3, weight 2, and 1<->3, weight 3.
The lower weight edge is 2<->3, weight 2.
All nodes are connected at a cost of 2+2=4 . The edge 1<->3 is not included in the subgraph.

Function Description
Complete the prims function in the editor below.
prims has the following parameter(s):
1) int n: the number of nodes in the graph
2) int edges[m][3]: each element contains three integers, two nodes numbers that are connected and the weight of that edge
3) int start: the number of the starting node

Returns
int: the minimum weight to connect all nodes in the graph

Input Format
The first line has two space-separated integers m and n, the number of nodes and edges in the graph.

Each of the next m lines contains three space-separated integers u, v and w, the end nodes of e, and the edge's weight.
The last line has an integer start, the starting node.

Constraints
2 <= n <=3000
1 <= m <= (n*(n-1))/2
1 <= u,v <= n
0 <= w <= 10^5
There may be multiple edges between two nodes.


// Sample Input 0

// 5 6
// 1 2 3
// 1 3 4
// 4 2 6
// 5 2 2
// 2 3 5
// 3 5 7
// 1
// Sample Output 0
// 15
*/

#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int, int>
using namespace std;

vector<list<pp > > gr;
void add_edge(int u, int v, int wt, bool bidir=true) {
    gr[u].push_back({v, wt});
    if(bidir) {
        gr[v].push_back({u, wt});
    }
}

ll prims(int src, int n) {
    priority_queue<pp, vector<pp> , greater<pp> > pq; // {wt, node}
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = 0;
    int total_count = 0; // 0 -> n-1 edges
    int result = 0; // sum of wts
    while(total_count < n && !pq.empty()) {
        pp curr = pq.top();
        if(vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        total_count++;
        result += curr.first;
        pq.pop();

        for(auto neighbour : gr[curr.second]) {
            if(!vis.count(neighbour.first) and mp[neighbour.first] > neighbour.second) {
                pq.push({neighbour.second, neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }

    }
    return result;

}

int main() {
    int n, m;
    cin>>n>>m;
    gr.resize(n+1, list<pp > ());
    while(m--) {
        int u, v, wt;
        cin>>u>>v>>wt;
        add_edge(u, v, wt);
    }

    int src;
    cin>>src;
    cout<<prims(src, n)<<"\n";
    return 0;
}