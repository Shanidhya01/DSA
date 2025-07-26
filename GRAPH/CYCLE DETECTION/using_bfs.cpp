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

bool bfs(int src ){
  unordered_set<int> vis;
  queue<int> q;
  vector<int>parent(v,-1);
  q.push(src);
  vis.insert(src);
  parent[src] = -1;
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(auto node:graph[curr]){
      if(vis.count(node) and parent[curr]!= node)  return true;
      if(!vis.count(node)){
        vis.insert(node);
        parent[node] = curr;
        q.push(node);
      }
    }
  }
}

bool has_cycle(){
  unordered_set<int> vis;
  bool result = false;
  for(int i=0;i<v;i++){
    if(!vis.count(i)){
      result = bfs(i);
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