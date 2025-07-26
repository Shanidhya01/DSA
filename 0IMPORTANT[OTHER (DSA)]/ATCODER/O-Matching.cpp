// There are N men and N women, both numbered 1,2,…,N.
// For each i,j (1≤i,j≤N), the compatibility of Man i and Woman j is given as an integer a i,j . If a i,j =1, Man i and Woman j are compatible; if a i,j =0, they are not.

// Taro is trying to make N pairs, each consisting of a man and a woman who are compatible. Here, each man and each woman must belong to exactly one pair.

// Find the number of ways in which Taro can make N pairs, modulo 10^9 +7.

// Constraints
// All values in input are integers.
// 1≤N≤21
// a i,j is 0 or 1.

// Sample Input 1
// 3
// 0 1 1
// 1 0 1
// 1 1 1
// Sample Output 1
// 3

// There are three ways to make pairs, as follows (
// (i,j) denotes a pair of Man i and Woman j):
// (1,2),(2,1),(3,3)
// (1,2),(2,3),(3,1)
// (1,3),(2,1),(3,2)


#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dp[22][1 << 22]; // dp[i][mask] = number of ways to match first
int f(int i , int mask,int n, vector<vector<int>>& c) {
  if(i == n+1){
    if( mask == 0) {
      return 1; // All pairs are matched
    } else {
      return 0; // Not all pairs are matched
    }
  }
  if(dp[i][mask] != -1) {
    return dp[i][mask]; // Return cached result
  }
  int ans = 0;
  for (int w = 1; w <= n; w++) {
    if(c[i][w] == 1 && (mask & (1 << (w - 1))) != 0) {
      ans = (ans + f(i + 1, mask ^ (1 << (w - 1)), n, c)) % mod;
    }
  }
  return dp[i][mask] = ans;
}
int main(){
  int n;
  cin >> n;
  vector<vector<int>> c(n+1, vector<int>(n+1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
    }
  }
  memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
  cout << f(1, (1 << n) - 1, n, c) << endl; // Start with all men and all women unmatched
  return 0;
}