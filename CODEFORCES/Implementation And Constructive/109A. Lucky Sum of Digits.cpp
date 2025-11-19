// Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

// Petya wonders eagerly what minimum lucky number has the sum of digits equal to n. Help him cope with the task.

// Input
// The single line contains an integer n (1 ≤ n ≤ 106) — the sum of digits of the required lucky number.

// Output
// Print on the single line the result — the minimum lucky number, whose sum of digits equals n. If such number does not exist, print -1.

// Examples
// Input
// 11
// Output
// 47
// Input
// 10
// Output
// -1

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int bestA = -1, bestB = -1, bestLen = INT_MAX;

    for (int b = 0; b <= n / 7; ++b) {
        int rem = n - b * 7;
        if (rem % 4 == 0) {
            int a = rem / 4;
            int len = a + b;
            if (len < bestLen || (len == bestLen && a > bestA)) {
                bestLen = len;
                bestA = a;
                bestB = b;
            }
        }
    }

    if (bestA == -1) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < bestA; ++i) cout << '4';
        for (int i = 0; i < bestB; ++i) cout << '7';
        cout << '\n';
    }
}
