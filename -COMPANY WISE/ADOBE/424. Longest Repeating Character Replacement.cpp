#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();
    unordered_map<char,int> m;
    int maxlen =0 , start =0 , maxf =0;
    for(int i=0;i<n;i++){
        m[s[i]]++;
        maxf = max(maxf,m[s[i]]);
        while((i - start +1) - maxf > k){
            m[s[start]]--;
            start++;
        }
        maxlen = max(maxlen,i - start +1);
    }
    return maxlen;
  }
};