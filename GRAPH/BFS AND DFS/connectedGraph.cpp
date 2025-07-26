#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
int v;
void add_edge(int src,int dest,bool bi_dir = true){
  graph[src].push_back(dest);
  if(bi_dir){
    graph[dest].push_back(src);
  }
}

void dfs(int node,unordered_set<int> &visited){
  visited.insert(node);
  for(auto child:graph[node]){
    if(visited.find(child) == visited.end()){
      dfs(child,visited);
    }
  }
}

int connected_components(){
  int result = 0;
  unordered_set<int> visited;
  for(int i=0;i<v;i++){
    if(visited.find(i) == visited.end()){
      result++;
      dfs(i,visited);
    }
  }
  return result;
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
  cout<<"Number of connected components: " << connected_components() << endl;
  return 0;
}