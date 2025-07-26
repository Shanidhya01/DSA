#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {0, -1, -2, 3, 4, -5, 6, 4, 7, -8};
    vector<int> ans;
    queue<int> q;
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            q.push(i);
        }
    }
    for (int i = 0; i <= n - k; i++) {
        while (!q.empty() && q.front() < i)           q.pop();
        if (q.empty() || q.front() >= i + k)            ans.push_back(0);
        else            ans.push_back(arr[q.front()]);
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
