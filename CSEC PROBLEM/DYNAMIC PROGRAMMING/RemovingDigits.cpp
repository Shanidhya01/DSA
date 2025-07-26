// // https://cses.fi/problemset/task/1637/
// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
// Input
// The only input line has an integer n.
// Output
// Print one integer: the minimum number of steps.
// Constraints
// 1 \le n \le 10^6
// Example
// Input:
// 27
// Output:
// 5
// Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

vector<int> getdigits(int n) {
    vector<int> v;
    while (n > 0) {
        if (n % 10 != 0) v.push_back(n % 10);
        n /= 10;
    }
    return v;
}

int f(int n) {
    if (n == 0) return 0;
    if (n <= 9) return 1;
    if (dp[n] != -1) return dp[n];
    vector<int> v = getdigits(n);
    int ans = INT_MAX;
    for (int i = 0; i < int(v.size()); i++) {
        ans = min(ans, f(n - v[i]));
    }
    return dp[n] = 1 + ans;
}

int main() {
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    cout << f(n);
    return 0;
}
