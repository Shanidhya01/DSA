#include<bits/stdc++.h>
using namespace std;

int find (int x, vector<int> &parent){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x], parent);
}
void Union(int x, int y, vector<int> &parent, vector<int> &rank){
  int a = find(x, parent);
  int b = find(y, parent);
  if(rank[a] >= rank[b]){
    parent[b] = a;
    rank[a]++;
  }  
  
  else{
    parent[a] = b;
    rank[b]++;
  }
}
int main(){
  int n; // Number of elements
  int m ;// Number of queries
  cin >> n >> m;
  vector<int> parent(n+1);
  vector<int> rank(n+1, 0);
  for(int i = 0; i <= n; i++) parent[i] = i;

  while(m--){
    string str;
    cin>> str;
    if(str == "union"){
      int x, y;
      cin >> x >> y;
      Union(x, y, parent, rank);
    }
    else {
      int x;
      cin >> x;
      cout << "Root of " << x << " is " << find(x, parent) << endl;
    }
  }
  return 0;
}