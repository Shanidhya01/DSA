// You are given an array of n integer numbers a0, a1, ..., an - 1. Find the distance between two closest (nearest) minimums in it. It is guaranteed that in the array a minimum occurs at least two times.

// Input
// The first line contains positive integer n (2 ≤ n ≤ 105) — size of the given array. The second line contains n integers a0, a1, ..., an - 1 (1 ≤ ai ≤ 109) — elements of the array. It is guaranteed that in the array a minimum occurs at least two times.

// Output
// Print the only number — distance between two nearest minimums in the array.

// Examples
// InputCopy
// 2
// 3 3
// OutputCopy
// 1
// InputCopy
// 3
// 5 6 5
// OutputCopy
// 2
// InputCopy
// 9
// 2 1 3 5 4 1 2 3 1
// OutputCopy
// 3

#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int mn=*min_element(a.begin(),a.end());
  int prev=-1;
  int ans=n;
  for(int i=0;i<n;i++){
    if(a[i]==mn){
      if(prev!=-1){
        ans=min(ans,i-prev);
      }
      prev=i;
    }
  }
  cout<<ans<<endl;
  return 0;
}