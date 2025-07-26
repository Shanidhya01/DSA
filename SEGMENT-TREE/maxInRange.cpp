#include<bits/stdc++.h>
using namespace std;
vector<int> st;
void buildTree(int arr[], int i, int lo, int hi) {
    if (lo == hi) {  
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi - lo) / 2;
    buildTree(arr, 2 * i + 1, lo, mid);
    buildTree(arr, 2 * i + 2, mid + 1, hi);
    st[i] = max(st[2 * i + 1], st[2 * i + 2]);
}
int getMax(int i, int lo, int hi, int &l, int &r) {
    if (l > hi || r < lo) return INT_MIN; // No overlap
    if (l <= lo && r >= hi) return st[i]; // Total overlap
    int mid = lo + (hi - lo) / 2;
    return max(getMax(2 * i + 1, lo, mid, l, r), getMax(2 * i + 2, mid + 1, hi, l, r)); // Partial overlap
}
int main(){
  int arr[] = {1,4,2,8,6,4,9,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  st.resize(4*n);
  buildTree(arr,0,0,n-1);
  int q;
  cin>>q; // Number of queries
  while(q--) {
    int l, r;
    cout << "Enter range (l r): ";
    cin >> l >> r; // Range for max query
    cout << getMax(0, 0, n - 1, l, r) << endl; // Output the maximum in the range
  }
}