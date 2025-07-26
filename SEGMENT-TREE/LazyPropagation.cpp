#include<bits/stdc++.h>
using namespace std;
vector<int> st;
vector<int> lazy;
void buildTree(int arr[], int i, int lo, int hi) {
    if (lo == hi) {  
        st[i] = arr[lo];
        lazy[i] = 0; // Initialize lazy value
        return;
    }
    int mid = lo + (hi - lo) / 2;
    buildTree(arr, 2 * i + 1, lo, mid);
    buildTree(arr, 2 * i + 2, mid + 1, hi);
    st[i] = st[2 * i + 1] + st[2 * i + 2]; // Sum of children
}
int getSum(int i, int lo, int hi, int l, int r) {
    if (lazy[i] != 0) { // If there are pending updates
        st[i] += lazy[i] * (hi - lo + 1); // Apply the update
        if (lo != hi) { // Not a leaf node
            lazy[2 * i + 1] += lazy[i]; // Propagate to left child
            lazy[2 * i + 2] += lazy[i]; // Propagate to right child
        }
        lazy[i] = 0; // Clear the lazy value
    }
    if (l > hi || r < lo) return 0; // No overlap
    if (l <= lo && r >= hi) return st[i]; // Total overlap
    int mid = lo + (hi - lo) / 2;
    return getSum(2 * i + 1, lo, mid, l, r) + getSum(2 * i + 2, mid + 1, hi, l, r); // Partial overlap
}
void updateRange(int i, int lo, int hi, int l, int r, int val) {
    if (l > hi || r < lo) return; // No overlap
    if (l <= lo && r >= hi) { // Total overlap
        st[i] += val * (hi - lo + 1); // Update the current node
        if (lo != hi) { // Not a leaf node
            lazy[2 * i + 1] += val; // Propagate to left child
            lazy[2 * i + 2] += val; // Propagate to right child
        }
        return;
    }
    int mid = lo + (hi - lo) / 2;
    updateRange(2 * i + 1, lo, mid, l, r, val); // Update left child
    updateRange(2 * i + 2, mid + 1, hi, l, r, val); // Update right child
    st[i] = st[2 * i + 1] + st[2 * i + 2]; // Update the current node
}
int main(){
  int arr[] = {1,4,2,8,6,4,9,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  st.resize(4 * n);
  lazy.resize(4 * n,0);
  buildTree(arr, 0, 0, n - 1);
  cout << getSum(0, 0, n - 1, 1, 3) << endl; // Output the maximum in the range
  updateRange(0, 0, n - 1, 2, 5, 10); // Example update
  cout << getSum(0, 0, n - 1, 1, 3) << endl; // Output the maximum in the range
  return 0;
}