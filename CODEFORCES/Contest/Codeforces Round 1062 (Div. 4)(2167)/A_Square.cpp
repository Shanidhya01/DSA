// You are given 4
//  arr of lengths a
// , b
// , c
// , and d
// . You can not break or bend them.

// Determine whether it is possible to form a square∗
//  using the given arr.
// ∗
// A square is defined as a polygon consisting of 4
//  vertices, of which all sides have equal length and all inner angles are equal. No two edges of the polygon may intersect each other.

// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of test cases.

// The only line of each test case contains four integers a
// , b
// , c
// , and d
//  (1≤a,b,c,d≤10
// ) — the lengths of the arr.

// Output
// For each test case, print "YES" if it is possible to form a square using the given arr, and "NO" otherwise.

// You may print each letter in any case (uppercase or lowercase). For example, the strings "yEs", "yes", "Yes", and "YES" will all be recognized as a positive answer.

// Example
// Input
// 7
// 1 2 3 4
// 1 1 1 1
// 2 2 2 2
// 1 2 1 2
// 1 1 5 5
// 5 5 5 5
// 4 10 5 9
// Output
// NO
// YES
// YES
// NO
// NO
// YES
// NO


#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        vector<int> arr(4);
        for (int i = 0; i < 4; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if (arr[0] == arr[1] && arr[2] == arr[3] && arr[0] == arr[2]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}