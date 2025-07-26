// There are N rabbits, numbered 1,2,…,N.
// For each i,j (1≤i,j≤N), the compatibility of Rabbit i and Rabbit j is described by an integer a i,j . Here, a i,i =0 for each i (1≤i≤N), and a i,j =a j,i for each i and j (1≤i,j≤N).
// Taro is dividing the N rabbits into some number of groups. Here, each rabbit must belong to exactly one group. After grouping, for each i and j (1≤i<j≤N), Taro earns a i,j points if Rabbit i and Rabbit j belong to the same group.
// Find Taro's maximum possible total score.

// Constraints
// All values in input are integers.
// 1≤N≤16
// ∣a i,j ∣≤10 9
// a i,i =0
// a i,j =a j,i

// Sample Input 1
// 3
// 0 10 20
// 10 0 -100
// 20 -100 0
// Sample Output 1
// 20
// The rabbits should be divided as 
// {1,3},{2}.

#include <bits/stdc++.h>
using namespace std;

vector<int>dp((1<<16),INT_MAX);
vector<int> sums((1<<16),0);

int calc(vector<vector<int>> & compat,int mask){
  int ans = 0;
  for(int i=1;i<=16;i++){
    for(int j=i+1;j<=16;j++){
      if(((mask & (1<<(i-1)))!=0) && ((mask & (1<<(j-1)))!=0)){
        ans += compat[i][j];
      }
    }
  }
  return ans;
}

void precompute(vector<vector<int>> & compat,int n){
  for(int mask = 1;mask<=((1<<n)-1);mask++){
    sums[mask] = calc(compat,mask);
  }
}

int f(int mask,vector<vector<int>> & compat){
  int ans = INT_MIN;
  if(mask == 0)  return 0;
  if(dp[mask] != INT_MAX) return dp[mask];
  for(int g=mask;g!=0;g=(g-1)&mask){
    ans = max(ans, sums[g] + f(mask^g, compat));
  }
  return dp[mask] = ans;
}

int main(){
  int n ;
  cin>>n;
  vector<vector<int>> compat(n+1, vector<int>(n+1, 0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>compat[i][j];
    }
  }
  precompute(compat, n);
  cout<<f((1<<n)-1,compat);
  return 0;
}