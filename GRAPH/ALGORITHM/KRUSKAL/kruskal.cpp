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