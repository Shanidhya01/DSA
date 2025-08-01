#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
int v;
void add_edge(int s,int d,bool bidir=true){
  graph[s].push_back(d);
  if(bidir){
    graph[d].push_back(s);
  }
}
bool dfs(int curr,int end){
  if(curr == end)  return true;
  visited.insert(curr);
  for(auto neighbour : graph[curr]){
    if(not visited.count(neighbour)){
      bool result = dfs(neighbour,end);
      if(result)  return true;
    }
  }
  return false;
}
bool anyPath(int src,int dest){
  return dfs(src,dest);
}
int main(){
  cin>>v;
  graph.resize(v,list<int>());
  int e;
  cin>>e;
  while(e--){
    int s,d;
    cin>>s>>d;
    add_edge(s,d,false);
  }
  int x,y;
  cin>>x>>y;
  cout<<anyPath(x,y)<<"\n";
  return 0;
}