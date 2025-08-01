// Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).
// He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.
// When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.
// Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.
// Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

// Input
// There will be a number of test cases in the input.
// The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.
// The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

// Output
// For each test case, output the minimum amount of smoke.
// Example
// Input:
// 2
// 18 19
// 3
// 40 60 20
// Output:
// 342
// 2400
// In the second test case, there are two possibilities:
// first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400
// first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400

#include<bits/stdc++.h>
#define ll long long   
using namespace std; 
ll dp[105][105]; 
ll g(int i, int j, vector<int> & colors) {
    int result = 0;
    for(int m = i; m <= j; m++) {
        result = (result + colors[m]) % 100;
    }
    return result;
}
// ll f(int i, int j, vector<int> & colors) {
//     if(i == j) return 0;
//     if(dp[i][j] != -1) return dp[i][j]; 
//     ll result = LLONG_MAX;
//     for(int k = i; k < j; k++) { 
//         result = min(result, f(i, k, colors) + f(k + 1, j, colors) + g(i, k, colors) * g(k + 1, j, colors));
//     }
//     return dp[i][j] = result;
// }
ll fbu(vector<int> & colors) {
    int n = colors.size();
    memset(dp, 0, sizeof(dp));
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            ll result = LLONG_MAX;
            for(int k = i; k < j; k++) {
                result = min(result, dp[i][k] + dp[k + 1][j] + g(i, k, colors) * g(k + 1, j, colors));
            }
            dp[i][j] = result;
        }
    }
    return dp[0][n - 1];
}
int main() {
    int x;
    cin >> x;
    vector<int> color(x);
    for(int i = 0; i < x; i++) cin >> color[i];
    memset(dp, -1, sizeof(dp)); 
    // cout << f(0, n - 1, color) << endl;
    cout<<fbu(color)<<endl;
    return 0;
}
