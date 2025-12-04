// You are given three positive (i.e. strictly greater than zero) integers x
// , y
//  and z
// .

// Your task is to find positive integers a
// , b
//  and c
//  such that x=max(a,b)
// , y=max(a,c)
//  and z=max(b,c)
// , or determine that it is impossible to find such a
// , b
//  and c
// .

// You have to answer t
//  independent test cases. Print required a
// , b
//  and c
//  in any (arbitrary) order.

// Input
// The first line of the input contains one integer t
//  (1≤t≤2⋅104
// ) — the number of test cases. Then t
//  test cases follow.

// The only line of the test case contains three integers x
// , y
// , and z
//  (1≤x,y,z≤109
// ).

// Output
// For each test case, print the answer:

// "NO" in the only line of the output if a solution doesn't exist;
// or "YES" in the first line and any valid triple of positive integers a
// , b
//  and c
//  (1≤a,b,c≤109
// ) in the second line. You can print a
// , b
//  and c
//  in any order.
// Example
// InputCopy
// 5
// 3 2 3
// 100 100 100
// 50 49 49
// 10 30 20
// 1 1000000000 1000000000
// OutputCopy
// YES
// 3 2 1
// YES
// 100 100 100
// NO
// NO
// YES
// 1 1 1000000000

#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    int x,y,z;
    cin>>x>>y>>z;
    int mx=max({x,y,z});
    int cnt=0;
    if(x==mx)cnt++;
    if(y==mx)cnt++;
    if(z==mx)cnt++;
    if(cnt<2){
      cout<<"NO\n";
    }else{
      cout<<"YES\n";
      if(x==mx && y==mx){
        cout<<mx<<" "<<z<<" "<<z<<"\n";
      }else if(x==mx && z==mx){
        cout<<y<<" "<<mx<<" "<<y<<"\n";
      }else{
        cout<<x<<" "<<x<<" "<<mx<<"\n";
      }
    }
  }
}