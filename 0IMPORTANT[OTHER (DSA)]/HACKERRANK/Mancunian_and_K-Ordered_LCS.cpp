// Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.
// In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change at most k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

// Input:
// The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively.
// The second line contains N integers denoting the elements of the first sequence.
// The third line contains M integers denoting the elements of the second sequence.

// Output:
// Print the answer in a new line.

// Sample Input
// 5 5 1
// 1 2 3 4 5
// 5 3 1 4 2
// Sample Output
// 3
// Explanation
// You can change the first element of the first sequence to 5 to get the LCS comprising of the sequence (5, 3, 4).

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[2005][2005][8]; 
ll kOrderedLCS(int *a, int *b, int n, int m, int i, int j, int k) {
    if (i == n || j == m) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    ll res = 0;
    if (a[i] == b[j]) {
        res = 1 + kOrderedLCS(a, b, n, m, i + 1, j + 1, k);
    } else {
        if (k > 0)
            res = 1 + kOrderedLCS(a, b, n, m, i + 1, j + 1, k - 1); 
        res = max(res, kOrderedLCS(a, b, n, m, i + 1, j, k));
        res = max(res, kOrderedLCS(a, b, n, m, i, j + 1, k));
    }

    return dp[i][j][k] = res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];
    memset(dp, -1, sizeof(dp));
    cout << kOrderedLCS(a, b, n, m, 0, 0, k) << endl;
    return 0;
}
