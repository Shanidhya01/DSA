#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll kadane(vector<ll>& arr) {
    ll best = arr[0], curr = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        curr = max(arr[i], curr + arr[i]);
        best = max(best, curr);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        ll ans = kadane(a);

        if (k == 1) {
            for (int i = 0; i < n; i++) {
                a[i] += b[i];
            }
            ans = max(ans, kadane(a));
        }

        cout << ans << "\n";
    }
}
