#include<bits/stdc++.h>
using namespace std;
void permutation(string &str,int i){
  if(i==int(str.size()-1)){
    cout<<str<<endl;
    return;
  }
  unordered_set<char> s;
  for(int idx=i;idx<(int)str.size();idx++){
    if(s.count(str[idx]))  continue;
    s.insert(str[idx]);
    swap(str[idx],str[i]);
    permutation(str,i+1);
    swap(str[idx],str[i]);
  }
}
int main(){
  string str;
  cin>>str;
  cout<<"All unique permutations of the string are: "<<endl;
  permutation(str,0);
}