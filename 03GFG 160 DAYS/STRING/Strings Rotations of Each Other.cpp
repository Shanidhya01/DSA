#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areRotations(string &a, string &b) {
        // code here
        string temp = a+a;
        // for(int i=0;i<n;i++){
        //     if(a==b) return true;
        //     char last = a.back();
        //     a.pop_back();
        //     a = last + a;
        // }
        return (temp.find(b) != string::npos);
    }
};