#include<bits/stdc++.h>
using namespace std;  
vector<list<int>> graph;
int v;
void add_edge(int a,int b,bool bidir = true){
  graph[a].push_back(b);
  if(bidir){
    graph[b].push_back(a);
  }
}
void topoBFS(){
  // KAHN'S ALGORITHM
  vector<int> indegree(v,0);
  for(int i=0;i<v;i++){
    for(auto j:graph[i]){
      // i ---> j
      // j has an incoming edge from i
      indegree[j]++;
    }
  }
  queue<int> q;
  unordered_set<int> vis;
  for(int i=0;i<v;i++){
    if(indegree[i] == 0){
      q.push(i);
      vis.insert(i);
    }
  }
  while(!q.empty()){
    int node = q.front();
    cout << node << " ";
    q.pop();
    for(auto j:graph[node]){
      if(not vis.count(j) ){
        indegree[j]--;
        if(indegree[j] == 0){
          q.push(j);
          vis.insert(j);
        }
      }
    }
  }
}
int main(){
  cin >> v;
  graph.resize(v,list<int>());
  int e;
  cin >> e;
  while(e--){
    int a,b;
    cin >> a >> b;
    add_edge(a,b,false);
  }
  cout << "Topological Sort using Kahn's Algorithm: ";
  topoBFS();
  return 0;
}