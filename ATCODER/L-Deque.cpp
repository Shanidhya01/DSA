// Taro and Jiro will play the following game against each other.
// Initially, they are given a sequence  a=(a1,a2,…,aN). Until a becomes empty, the two players perform the following operation alternately, starting from Taro:
// Remove the element at the beginning or the end of a. The player earns x points, where 
// x is the removed element.Let X and Y be Taro's and Jiro's total score at the end of the game, respectively. Taro tries to maximize X−Y, while Jiro tries to minimize  X−Y.
// Assuming that the two players play optimally, find the resulting value of  X−Y.

// Input is given from Standard Input in the following format:
// N
// a1,a2,...,aN 
// Output
// Print the resulting value of  X−Y, assuming that the two players play optimally.

// 4
// 10 80 90 30
// 10

// The game proceeds as follows when the two players play optimally (the element being removed is written bold):
// Taro: (10, 80, 90, 30) → (10, 80, 90)
// Jiro: (10, 80, 90) → (10, 80)
// Taro: (10, 80) → (10)
// Jiro: (10) → ()
// Here, 
// X=30+80=110 and 
// Y=90+10=100.


#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<vector<ll>> dp;
vector<ll> arr;
ll f(int i,int j){
    if(i==j)  return arr[i];
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(arr[i]-f(i+1,j),arr[j]-f(i,j-1));
}

ll fbu(int n){
    for(int i=0;i<n;i++){
        dp[i][i] = arr[i];
    }
    
    for (int len = 2; len <= n; len++){
        for (int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];    
}

int main() {
    int n;
    cin>>n;
    dp.assign(n+1,vector<ll>(n+1,-1));
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    // cout<<f(0,n-1)<<endl;
    cout<<fbu(n)<<endl;
    return 0;
}