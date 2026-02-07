// While swimming at the beach, Mike has accidentally dropped his cellphone into the water. There was no worry as he bought a cheap replacement phone with an old-fashioned keyboard. The keyboard has only ten digital equal-sized keys, located in the following way:


// Together with his old phone, he lost all his contacts and now he can only remember the way his fingers moved when he put some number in. One can formally consider finger movements as a sequence of vectors connecting centers of keys pressed consecutively to put in a number. For example, the finger movements for number "586" are the same as finger movements for number "253":



// Mike has already put in a number by his "finger memory" and started calling it, so he is now worrying, can he be sure that he is calling the correct number? In other words, is there any other number, that has the same finger movements?

// Input
// The first line of the input contains the only integer n (1 ≤ n ≤ 9) — the number of digits in the phone number that Mike put in.

// The second line contains the string consisting of n digits (characters from '0' to '9') representing the number that Mike put in.

// Output
// If there is no other phone number with the same finger movements and Mike can be sure he is calling the correct number, print "YES" (without quotes) in the only line.

// Otherwise print "NO" (without quotes) in the first line.

// Examples
// InputCopy
// 3
// 586
// OutputCopy
// NO
// InputCopy
// 2
// 09
// OutputCopy
// NO
// InputCopy
// 9
// 123456789
// OutputCopy
// YES
// InputCopy
// 3
// 911
// OutputCopy
// YES
// Note
// You can find the picture clarifying the first sample case in the statement above.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    map<int, pair<int,int>> pos = {
        {1,{0,0}}, {2,{0,1}}, {3,{0,2}},
        {4,{1,0}}, {5,{1,1}}, {6,{1,2}},
        {7,{2,0}}, {8,{2,1}}, {9,{2,2}},
        {0,{3,1}}
    };
    vector<pair<int,int>> moves;
    for (int i = 1; i < n; i++) {
        int a = s[i-1] - '0';
        int b = s[i] - '0';
        moves.push_back({
            pos[b].first - pos[a].first,
            pos[b].second - pos[a].second
        });
    }
    for (int start = 0; start <= 9; start++) {
        if (start == s[0] - '0') continue;
        int x = pos[start].first;
        int y = pos[start].second;
        bool ok = true;
        for (auto move : moves) {
            int dx = move.first;
            int dy = move.second;
            x += dx;
            y += dy;
            bool found = false;
            for (auto &p : pos) {
                if (p.second == make_pair(x,y)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}


