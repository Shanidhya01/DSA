#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans="",clean = "";
        for(char c : s){
            if(c != '-') clean +=toupper(c);
        }
        int cnt = 0;
        for(int i= clean.size() - 1;i>=0;i--){
            ans.push_back(clean[i]);
            cnt++;
            if(cnt == k && i!= 0){
                ans.push_back('-');
                cnt = 0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;
            if (cnt == k) {
                ans.push_back('-');
                cnt = 0;
            }
            ans.push_back(toupper(s[i]));
            cnt++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};