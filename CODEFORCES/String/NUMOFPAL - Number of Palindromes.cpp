// Each palindrome can be always created from the other palindromes, if a single character is also a palindrome. For example, the string "malayalam" can be created by some ways:

// malayalam = m + ala + y + ala + m
// malayalam = m + a + l + aya + l + a + m
// We want to take the value of function NumPal(s) which is the number of different palindromes that can be created using the string S by the above method. If the same palindrome occurs more than once then all of them should be counted separately.

// Input
// The string S.

// Output
// The value of function NumPal(s).

// Limitations
// 0 < |s| ≤ 1000

// Example
// Input:
// malayalam

// Output:
// 15


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            total++;
            l--;
            r++;
        }
    }

    for (int i = 0; i + 1 < n; ++i) {
        int l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            total++;
            l--; 
            r++;
        }
    }

    cout << total << "\n";
    return 0;
}