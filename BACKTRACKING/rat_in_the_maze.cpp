#include<bits/stdc++.h>
using namespace std;
int ans;

bool canWeGo(int n,int i,int j,vector<vector<int>> &grid){
  return (i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0);
}
void f(vector<vector<int>> &grid, int n,int i,int j) {
  if( i == n-1 and j==n-1){
    ans += 1;
    return;
  }
  grid[i][j] = 2; // mark as visited
  //left 
  if(canWeGo(n,i,j-1,grid))   f(grid,n,i,j-1);
  //up
  if(canWeGo(n,i-1,j,grid))   f(grid,n,i-1,j);
  //right
  if(canWeGo(n,i,j+1,grid))   f(grid,n,i,j+1);
  //down
  if(canWeGo(n,i+1,j,grid))   f(grid,n,i+1,j);
  grid[i][j] = 0; // backtrack
}

int ratInAMaze(vector<vector<int>> &grid,int n){
    ans = 0;
    f(grid,n,0,0);
    return ans;
}

int main(){
  vector<vector<int>> grid = {
    {0,0,1,0,0,1,0},
    {1,0,1,1,0,0,0},
    {0,0,0,0,1,0,1},
    {1,0,1,0,0,0,0},
    {1,0,1,1,0,1,0},
    {1,0,0,0,0,1,0},
    {1,1,1,1,0,0,0}
  };
  cout << ratInAMaze(grid, 7) << endl;
  return 0;
}