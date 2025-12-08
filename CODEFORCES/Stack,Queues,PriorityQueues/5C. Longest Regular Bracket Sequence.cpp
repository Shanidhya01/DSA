// This is yet another problem dealing with regular bracket sequences.

// We should remind you that a bracket sequence is called regular, if by inserting «+» and «1» into it we can get a correct mathematical expression. For example, sequences «(())()», «()» and «(()(()))» are regular, while «)(», «(()» and «(()))(» are not.

// You are given a string of «(» and «)» characters. You are to find its longest substring that is a regular bracket sequence. You are to find the number of such substrings as well.

// Input
// The first line of the input file contains a non-empty string, consisting of «(» and «)» characters. Its length does not exceed 106.

// Output
// Print the length of the longest substring that is a regular bracket sequence, and the number of such substrings. If there are no such substrings, write the only line containing "0 1".

// Examples
// InputCopy
// )((())))(()())
// OutputCopy
// 6 2
// InputCopy
// ))(
// OutputCopy
// 0 1


#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin>>s;
  stack<int>st;
  st.push(-1);
  int maxlen = 0;
  int count = 0;
  for(int i=0;i<int(s.size());i++){
    if(s[i]=='('){
      st.push(i);
    }
    else{
      st.pop();
      if(st.empty()){
        st.push(i);
      }
      else{
        int len = i - st.top();
        if(len > maxlen){
          maxlen = len;
          count = 1;
        }
        else if(len == maxlen){
          count++;
        }
      }
    }
  }
  
    if(maxlen == 0) cout<<"0 1\n";
    else    cout<<maxlen<<" "<<count<<"\n";
}