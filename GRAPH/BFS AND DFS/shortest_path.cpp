// bfs
#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v;
void add_edge(int s,int d,bool bidir=true){
  graph[s].push_back(d);
  if(bidir){
    graph[d].push_back(s);
  }
}

void bfs(int src , vector<int>& dist){
  queue<int> q;
  visited.clear();
  dist.resize(v,INT_MAX);
  dist[src] = 0;
  visited.insert(src);
  q.push(src);
  while(!q.empty()){
    int curr = q.front();
    cout<<curr<<" ";
    q.pop();
    for(auto neighbour : graph[curr]){
      if(not visited.count(neighbour)){
        visited.insert(neighbour);
        dist[neighbour] = dist[curr] + 1;
        q.push(neighbour);
      }
    }
  }
  cout<<endl;
}
int main(){
  cin>>v;
  graph.resize(v,list<int>());
  int e;
  cin>>e;
  while(e--){
    int s,d;
    cin>>s>>d;
    add_edge(s,d);
  }
  int x;
  cin>>x;
  vector<int> dist;
  bfs(x,dist);
  result.push_back(dist);
  for(int i = 0;i<int(dist.size());i++){
    cout<<dist[i]<<" ";
  }
  cout<<"\n";
  return 0;
}