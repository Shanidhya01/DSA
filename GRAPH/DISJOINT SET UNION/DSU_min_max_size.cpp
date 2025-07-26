#include<bits/stdc++.h>
using namespace std;

int find (int x, vector<int> &parent){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x], parent);
} 
void Union(int x, int y, vector<int> &parent, vector<int> &size, vector<int> &minimal, vector<int> &maximal, vector<int> &rank){
  int a = find(x, parent);
  int b = find(y, parent);
  if(rank[a] >= rank[b]){
    parent[b] = a;
    rank[a]++;
    size[a] += size[b];
    maximal[a] = max(maximal[a], maximal[b]);
    minimal[a] = min(minimal[a], minimal[b]);
  }  
  
  else{
    parent[a] = b;
    rank[b]++;
    size[b] += size[a];
    maximal[b] = max(maximal[a], maximal[b]);
    minimal[b] = min(minimal[a], minimal[b]);
  }
}
int main(){
  int n; // Number of elements
  int m ;// Number of queries
  cin >> n >> m;
  vector<int> parent(n+1);
  vector<int> rank(n+1, 0);
  vector<int> size(n+1, 1);
  vector<int> minimal(n+1);
  vector<int> maximal(n+1);
  for(int i = 0; i <= n; i++) parent[i] = minimal[i] = maximal[i] = i;

  while(m--){
    string str;
    cin>> str;
    if(str == "union"){
      int x, y;
      cin >> x >> y;
      Union(x, y, parent,size, minimal, maximal, rank);
    }
    else {
      int x;
      cin >> x;
      cout << "Root of " << x << " is " << find(x, parent) << endl;
      cout << "Size of component: " << size[find(x, parent)] << endl;
      cout << "Minimal element: " << minimal[find(x, parent)] << endl;
      cout << "Maximal element: " << maximal[find(x, parent)] << endl;
    }
  }
  return 0;
}