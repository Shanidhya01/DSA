// You are given an integer n
//  and an array a
//  of length n
// .

// Find the smallest integer x
//  (2≤x≤1018
// ) such that there exists an index i
//  (1≤i≤n
// ) with gcd
// ∗
// (ai,x)=1
// . If no such x
//  exists within the range [2,1018]
// , output −1
// .

// ∗
// gcd(x,y)
//  denotes the greatest common divisor (GCD) of integers x
//  and y
// .

// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of test cases.

// Each of the following t
//  test cases consists of two lines:

// The first line contains a single integer n
//  (1≤n≤105
// ) — the length of the array.

// The second line contains n
//  space-separated integers a1,a2,…,an
//  (1≤ai≤1018
// ).

// It is guaranteed that the total sum of n
//  across all test cases does not exceed 105
// .

// Output
// For each test case, output a single integer: the smallest x
//  (2≤x≤1018
// ) such that there exists an index i
//  with gcd(ai,x)=1
// . If there is no such x
//  in the range [2,1018]
// , print −1
// .

// Example
// Input
// 4
// 1
// 1
// 4
// 6 6 12 12
// 3
// 24 120 210
// 4
// 2 4 6 10
// Output
// 2
// 5
// 5
// 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long g = a[0];
        for (int i = 1; i < n; i++)
            g = __gcd(g, a[i]);

        long long ans = -1;
        for (long long x = 2; x <= 1000; x++) {
            if (__gcd(x, g) == 1) {
                ans = x;
                break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
