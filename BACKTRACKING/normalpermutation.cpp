#include<bits/stdc++.h>
using namespace std;
void permutation(string input, string output){
  if(input.size() == 0 ){
    cout<<output<<endl;
    return;
  }
  for(int i=0;i<(int)input.size();i++){
    char ch = input[i];
    string left = input.substr(0,i);
    string right = input.substr(i+1);
    string ros = left + right;
    permutation(ros ,output+ch);
  }
}
int main(){
  permutation("abc","");
  return 0;
}