// Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

// Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

// Input
// The first line contains a single integer x (1 ≤ x ≤ 1018) — the number that Luke Skywalker gave to Chewbacca.

// Output
// Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

// Examples
// InputCopy
// 27
// OutputCopy
// 22
// InputCopy
// 4545
// OutputCopy
// 4444

// https://codeforces.com/contest/514/problem/A

#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.length();i++){
    int digit=s[i]-'0';
    if(i==0){
      if(digit>4 && digit!=9){
        digit=9-digit;
      }
    }
    else{
      if(digit>4){
        digit=9-digit;
      }
    }
    cout<<digit;
  }
  cout<<endl;
  return 0;
}
