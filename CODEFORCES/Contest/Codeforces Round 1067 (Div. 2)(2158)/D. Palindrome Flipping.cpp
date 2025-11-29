// You are given two binary strings s
//  and t
// , each of the same length n
// . You are allowed to perform the following operation:

// Pick indices l
// , r
//  (1≤l<r≤n
// ) such that substring sl,r
//  is a palindrome and flip all bits in substring sl,r
// .
// The goal is to finally make s
//  equal to t
// , performing any of the above operations at most 2n
//  times (possibly none).

// A substring sl,r
//  of a string s
//  is the contiguous sequence of characters starting from index l
//  and ending at index r
//  (both inclusive), where 1≤l<r≤|s|
// . Here |s|
//  denotes the length of the string s
// .

// A string is a palindrome if it reads the same forwards and backwards. For example, the strings 101 and 00 are palindromes, while 10 is not.

// Flipping all bits in a substring means changing each 0 to 1 and each 1 to 0 in that substring. For example, flipping the substring 101 results in 010.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤5⋅103
// ). The description of the test cases follows.

// The first line of each test case contains an integer n
//  (4≤n≤100
// ) — the length of the strings s
//  and t
// .

// The next two lines of each test case contain the binary strings s
//  and t
// , respectively.

// It is guaranteed that the sum of n2
//  over all test cases does not exceed 5⋅105
// .

// Output
// For each test case, if it is impossible to achieve the goal, print −1
// .

// Otherwise, the first line should contain an integer k
//  (0≤k≤2n
// ) — the number of operations.

// For each of the next k
//  lines, print two integers l,r
//  (1≤l<r≤n
// ) — the indices you choose in each operation. Note that sl,r
//  must be a palindrome at this stage.

// Example
// InputCopy
// 3
// 5
// 01011
// 10000
// 7
// 1010101
// 0101010
// 4
// 0010
// 0010
// OutputCopy
// 2
// 1 3
// 3 5
// 1
// 1 7
// 0
// Note
// For the first test case:

// Initially, s=01011
//  and t=10000
// .
// First, we choose l=1
//  and r=3
// . This is a valid operation since s1,3=010
//  is a palindrome. After flipping s1,3
// , s=10111
// .
// Then, we choose l=3
//  and r=5
// . This is a valid operation since s3,5=111
//  is a palindrome. After flipping s3,5
// , s=10000
// .
// Now, s
//  is equal to t
// .
// For the second test case:

// Initially, s=1010101
//  and t=0101010
// .
// First, we choose l=1
//  and r=7
// . This is a valid operation since s1,7=1010101
//  is a palindrome. After flipping s1,7
// , s=0101010
// .
// Now, s
//  is equal to t
// .
// For the third test case:

// Initially, s
//  is equal to t
// . No operations are needed.


#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<pair<int, int>> ops;

    auto perform_flip = [&](int l, int r) {
        ops.push_back({l + 1, r + 1});
        for (int k = l; k <= r; k++) {
            s[k] = (s[k] == '0' ? '1' : '0');
        }
    };

    auto get_score = [&](const string& curr_s) {
        int score = 0;
        if (t[n - 2] == t[n - 1]) {
            if (curr_s[n - 2] != curr_s[n - 1]) score = 1;
        } else {
            if (curr_s[n - 2] != t[n - 2]) score++;
            if (curr_s[n - 1] != t[n - 1]) score++;
        }
        return score;
    };

    for (int i = 0; i < n - 2; i++) {
        int current_score = get_score(s);
        
        struct Move {
            int type; 
            int param; 
            int new_score;
        };
        
        vector<Move> moves;

        for (int r = i + 1; r < n; r++) {
            if (is_palindrome(s, i, r)) {
                string temp = s;
                if (r >= n - 2) temp[n - 2] = (temp[n - 2] == '0' ? '1' : '0');
                if (r >= n - 1) temp[n - 1] = (temp[n - 1] == '0' ? '1' : '0');
                moves.push_back({0, r, get_score(temp)});
            }
        }

        for (int k = i + 2; k < n; k++) {
            if (is_palindrome(s, i + 1, k)) {
                string temp = s;
                if (k >= n - 2) temp[n - 2] = (temp[n - 2] == '0' ? '1' : '0');
                if (k >= n - 1) temp[n - 1] = (temp[n - 1] == '0' ? '1' : '0');
                moves.push_back({1, k, get_score(temp)});
            }
        }

        if (moves.empty()) {
            if (s[i] != t[i]) {
                cout << -1 << "\n";
                return;
            }
            continue;
        }

        sort(moves.begin(), moves.end(), [](const Move& a, const Move& b) {
            if (a.new_score != b.new_score) return a.new_score < b.new_score;
            return a.type < b.type;
        });

        if (s[i] == t[i]) {
            if (current_score > 0 && moves[0].new_score < current_score) {
                if (moves[0].type == 0) {
                    perform_flip(i, moves[0].param);
                } else {
                    perform_flip(i + 1, moves[0].param);
                    perform_flip(i, i + 1);
                }
                i--; 
            }
        } else {
            if (moves[0].type == 0) {
                perform_flip(i, moves[0].param);
            } else {
                perform_flip(i + 1, moves[0].param);
                perform_flip(i, i + 1);
            }
        }
    }

    if (s[n - 2] != t[n - 2]) {
        if (s[n - 2] == s[n - 1]) {
            perform_flip(n - 2, n - 1);
        } else {
            cout << -1 << "\n";
            return;
        }
    }

    if (s == t) {
        cout << ops.size() << "\n";
        for (auto p : ops) {
            cout << p.first << " " << p.second << "\n";
        }
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
