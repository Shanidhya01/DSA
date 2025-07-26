// Let N be a positive odd number.
// There are N coins, numbered 1,2,…,N. For each i (1≤i≤N), when Coin i is tossed, it comes up heads with probability 
// pi and tails with probability 1−pi.
// Taro has tossed all the N coins. Find the probability of having more heads than tails.

// Constraints
// N is an odd number.
// 1≤N≤2999
// pi  is a real number and has two decimal places.
// 0<pi<1

// Sample Input 
// 3
// 0.30 0.60 0.80
// Sample Output 
// 0.612


#include <bits/stdc++.h>
using namespace std;
double dp[3005][3005];
double f(vector<double> &p, int i,int x){
  if(x == 0)  return 1;
  if(i == -1) return 0;
  if(dp[i][x] > -0.9) return dp[i][x]; 
  return dp[i][x] = f(p,i-1,x-1)*p[i] +  f(p,i-1,x)*(1-p[i]);
}
int main() {
  int n;
  cin>>n;
  vector<double> p(n);
  for(int i=0;i<n;i++) cin>>p[i];
  memset(dp,-1,sizeof(dp));
  cout<<f(p,n-1,(n+1)/2)<<endl;
  return 0;
}