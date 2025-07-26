/*Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints
1 \le n \le 10^6
Example
Input:
3
Output:
4
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long int
vector<ll> dp(1000001, -1);

ll f(int n){
    if(n == 0) return 1;
    if(dp[n]!=-1)  return dp[n];
    ll sum = 0;
    for(int i = 1; i <= 6; i++){
        if(n-i<0) break;
        sum = (sum % mod + f(n - i) % mod) % mod;
    }
    return dp[n] = sum;
}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}