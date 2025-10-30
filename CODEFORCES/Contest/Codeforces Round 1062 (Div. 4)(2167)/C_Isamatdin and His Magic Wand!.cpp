// Isamatdin has n
//  toys arranged in a row. The i
// -th toy has an integer ai
// . He wanted to sort them because otherwise, his mother would scold him.

// However, Isamatdin never liked arranging toys in order, so his friend JahonaliX gave him a magic wand to help. Unfortunately, JahonaliX made a small mistake while creating the wand.

// But Isamatdin couldn't wait any longer and decided to use the broken wand anyway. The wand can only swap two toys if their integers have different parity (one is even, the other is odd). In other words, you can swap toys in positions (i,j)
//  only if aimod2≠ajmod2
// , where mod
//  — is the remainder of integer division.

// Now he wants to know the lexicographically smallest∗
//  arrangement he can achieve using this broken wand.

// ∗
// A sequence p
//  is lexicographically smaller than a sequence q
//  if there exists an index i
//  such that pj=qj
//  for all j<i
// , and pi<qi
// .

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
//  (1≤n≤2⋅105
// ) — the number of toys.

// The second line of each test case contains n
//  integers a1,a2,…,an
//  (1≤ai≤109
// ) — the integers of the toys.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output n
//  integers — the lexicographically smallest sequence that can be obtained using the described operation.

// Example
// Input
// 7
// 4
// 2 3 1 4
// 5
// 3 2 1 3 4
// 4
// 3 7 5 1
// 2
// 1000000000 2
// 3
// 1 3 5
// 5
// 2 5 3 1 7
// 4
// 2 4 8 6
// Output
// 1 2 3 4
// 1 2 3 3 4
// 3 7 5 1
// 1000000000 2
// 1 3 5
// 1 2 3 5 7
// 2 4 8 6

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<long long> a(n);
    bool has_even = false, has_odd = false;
    for (int i = 0; i < n; i++){
      cin >> a[i];
      if (a[i] % 2 == 0)
        has_even = true;
      else
        has_odd = true;
    }
    if (has_even && has_odd){
      sort(a.begin(), a.end());
    }
    cout << a[0];
    for (int i = 1; i < n; i++){
      cout << ' ' << a[i];
    }
    cout << endl;
  }
  return 0;
}
