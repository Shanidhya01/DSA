// Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
// The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the i-th day:
// A: Swim in the sea. Gain a i points of happiness.
// B: Catch bugs in the mountains. Gain b i  points of happiness.
// C: Do homework at home. Gain c i  points of happiness.
// As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.
// Find the maximum possible total points of happiness that Taro gains.
// Sample Input
// 3 n
// A B C
// 10 40 70
// 20 50 80
// 30 60 90
// Sample Output
// 210

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(3,0));
    int a,b,c;
    cin>>a>>b>>c;
    dp[0][0] = a;
    dp[0][1] = b;
    dp[0][2] = c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a;
        dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b;
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + c;
    }
    cout<<endl<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
    return 0;
}