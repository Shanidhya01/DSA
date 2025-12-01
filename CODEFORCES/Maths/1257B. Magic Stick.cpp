// Recently Petya walked in the forest and found a magic stick.

// Since Petya really likes numbers, the first thing he learned was spells for changing numbers. So far, he knows only two spells that can be applied to a positive integer:

// If the chosen number a
//  is even, then the spell will turn it into 3a2
// ;
// If the chosen number a
//  is greater than one, then the spell will turn it into a−1
// .
// Note that if the number is even and greater than one, then Petya can choose which spell to apply.

// Petya now has only one number x
// . He wants to know if his favorite number y
//  can be obtained from x
//  using the spells he knows. The spells can be used any number of times in any order. It is not required to use spells, Petya can leave x
//  as it is.

// Input
// The first line contains single integer T
//  (1≤T≤104
// ) — the number of test cases. Each test case consists of two lines.

// The first line of each test case contains two integers x
//  and y
//  (1≤x,y≤109
// ) — the current number and the number that Petya wants to get.

// Output
// For the i
// -th test case print the answer on it — YES if Petya can get the number y
//  from the number x
//  using known spells, and NO otherwise.

// You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES will all be recognized as positive answer).

// Example
// Input
// 7
// 2 3
// 1 1
// 3 6
// 6 8
// 1 2
// 4 1
// 31235 6578234
// Output
// YES
// YES
// NO
// YES
// NO
// YES
// YES


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        long long x, y;
        cin >> x >> y;
        if (x >= y) {
            cout << "YES\n";
        } else if (x == 1) {
            cout << "NO\n";
        } else if (x == 2 || x == 3) {
            cout << (y <= 3 ? "YES\n" : "NO\n");
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}