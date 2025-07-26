#include<bits/stdc++.h>
using namespace std;

int find (int x, vector<int> &parent){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x], parent);
}
bool Union(int x, int y, vector<int> &parent, vector<int> &rank){
  int a = find(x, parent);
  int b = find(y, parent);
  if(a == b) return true; 
  if(rank[a] >= rank[b]){
    parent[b] = a;
    rank[a]++;
  }  
  else{
    parent[a] = b;
    rank[b]++;
  }
  return false; 
}
int main(){
  int n; // Number of elements
  int m ;// Number of queries
  cin >> n >> m;
  vector<int> parent(n+1);
  vector<int> rank(n+1, 0);
  for(int i = 0; i <= n; i++) parent[i] = i;

  while(m--){
    int x, y;
    cin >> x >> y;
    bool b = Union(x, y, parent, rank);
    if(b==true)  cout<<"Cycle detected"<<endl;
    // else cout<<"No cycle detected"<<endl;
  }
  return 0;
}