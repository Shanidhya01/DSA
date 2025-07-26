// Roy has N coin boxes numbered from 1 to N.
// Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
// He does this for M number of days.
// After M days, Roy has a query: How many coin boxes have atleast X coins.
// He has Q such queries.

// Input:
// First line contains N - number of coin boxes.
// Second line contains M - number of days.
// Each of the next M lines consists of two space separated integers L and R.
// Followed by integer Q - number of queries.
// Each of next Q lines contain a single integer X.

// Output:
// For each query output the result in a new line.

// Constraints:
// 1 ≤ N ≤ 1000000
// 1 ≤ M ≤ 1000000
// 1 ≤ L ≤ R ≤ N
// 1 ≤ Q ≤ 1000000
// 1 ≤ X ≤ N

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int n;
//     cin >> n;
//     vector<int> f(n+1, 0);
//     int m;
//     cin >> m;
//     vector<int> l(n+2, 0), r(n+2, 0); 
//     for(int i = 0; i < m; i++) {
//         int L, R;
//         cin >> L >> R;
//         l[L]++;
//         r[R]++;
//     }
//     f[1] = l[1];
//     for(int i = 2; i <= n; i++) {
//         f[i] = f[i-1] + l[i] - r[i-1];
//     }
//     vector<int> c(n+2, 0); 
//     for(int i = 1; i <= n; i++) {
//         if (f[i] <= n)
//             c[f[i]]++;
//     }
//     for(int i = n; i >= 0; i--) {
//         c[i] += c[i+1];
//     }
//     int q;
//     cin >> q;
//     while(q--) {
//         int num;
//         cin >> num;
//         if(num > n) cout << 0 << endl;
//         else cout << c[num] << endl;
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> f(n+10, 0);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int L, R;
        cin >> L >> R;
        f[L]++;
        f[R+1]--;
    }
    for(int i = 2; i < f.size(); i++) {
        f[i] += f[i-1];
    }
    vector<int> c(n+2, 0); 
    for(int i = 1; i <= n; i++) {
        if (f[i] <= n)
            c[f[i]]++;
    }
    for(int i = n; i >= 0; i--) {
        c[i] += c[i+1];
    }
    int q;
    cin >> q;
    while(q--) {
        int num;
        cin >> num;
        if(num > n) cout << 0 << endl;
        else cout << c[num] << endl;
    }
    return 0;
}