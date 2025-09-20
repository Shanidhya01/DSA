#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        if (s1.length() != s2.length()) 
        return false;
    
        // Sort both strings
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
    
        // Compare sorted strings
        return (s1 == s2);
    }
};


// 2nd way
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1; // for s
        if(s.length() != t.length()) return false;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            char ch = t[i];
            if(m1.find(ch)!=m1.end()){
                m1[ch]--;
                if(m1[ch]==0) m1.erase(ch);
            }
            else return false;
        }
        if(m1.size()>0) return false;
        return true;
    }
};