// A lazy tourist wants to visit as many interesting locations in a city as possible
// without going one step further than necessary. Starting from his hotel, located in the
// north-west corner of city, he intends to take a walk to the south-east corner of the
// city and then walk back. When walking to the south-east corner, he will only walk east
// or south, and when walking back to the north-west corner, he will only walk north or
// west. After studying the city map he realizes that the task is not so simple because
// some areas are blocked. Therefore he has kindly asked you to write a program to
// solve his problem.

// Given the city map (a 2D grid) where the interesting locations and blocked areas are
//  marked, determine the maximum number of interesting locations he can visit. 
// Locations visited twice are only counted once.

// Input
// The first line in the input contains the number of test cases (at most 20). Then follow the cases. Each case starts with a line containing two integers, W and H (2 ≤ W, H ≤ 100), the width and the height of the city map. Then follow H lines, each containing a string with W characters with the following meaning:

// . Walkable area
// * Interesting location (also walkable area)
// # Blocked area
// You may assume that the upper-left corner (start and end point) and lower-right corner (turning point) are walkable, and that a walkable path of length H + W − 2 exists between them.

// Output
// For each testcase, output a line containing a single integer: the maximum number of interesting locations the lazy tourist can visit.

// Input:
// 2
// 9 7
// *........
// .....**#.
// ..**...#*
// ..####*#.
// .*.#*.*#.
// ...#**...
// *........
// 5 5
// .*.*.
// *###.
// *.*.*
// .###*
// .*.*.

// Output:
// 7
// 8

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;  
char mat[105][105];
ll dp[105][105][105];
ll f(ll i, ll j, ll x, ll y) {
    if (i > n || j > m || x > n || y > m || mat[i][j] == '#' || mat[x][y] == '#')    return LLONG_MIN;
    if (i == n && j == m && x == n && y == m)    return (mat[i][j] == '*') ? 1 : 0;
    if (dp[i][j][x] != -1)    return dp[i][j][x];
    ll res = LLONG_MIN;
    res = max(res, f(i + 1, j, x + 1, y));   
    res = max(res, f(i, j + 1, x, y + 1));   
    res = max(res, f(i + 1, j, x, y + 1));   
    res = max(res, f(i, j + 1, x + 1, y));   
    ll gain = 0;
    if (mat[i][j] == '*') gain++;
    if (i != x || j != y) {
        if (mat[x][y] == '*') gain++;
    }
    return dp[i][j][x] = res + gain;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> m >> n; 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mat[i][j];
            }
        }
        ll ans = f(1, 1, 1, 1);
        cout << ans << endl;
    }
    return 0;
}