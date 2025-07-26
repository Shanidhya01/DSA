#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v;
void add_edge(int src,int dest,bool bi_dir = true){
  graph[src].push_back(dest);
  if(bi_dir){
    graph[dest].push_back(src);
  }
}
void display(){
  for(int i=0;i<int(graph.size());i++){
    cout<<i<<" -> ";
    for(auto node:graph[i]){
      cout<<node<<" , ";
    }
    cout<<endl;
  }
}

bool dfs(int src ,int parent, unordered_set<int> &vis){
  vis.insert(src);
  for(auto node:graph[src]){
    if(vis.find(node) == vis.end()){
      if(dfs(node,src,vis)){
        return true;
      }
    }else if(node != parent){
      return true; // Cycle detected
    }
  }
  return false;
}

bool has_cycle(){
  unordered_set<int> vis;
  bool result = false;
  for(int i=0;i<v;i++){
    if(!vis.count(i)){
      result = dfs(i,-1,vis);
      if(result) return true; 
    }
  }
  return false;
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
  // display();
  bool b = has_cycle();
  if(b){
    cout<<"Cycle detected"<<endl;
  }
  return 0;
}