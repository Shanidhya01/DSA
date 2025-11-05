#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans="";
        stack<string> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch == ' '){
                if(temp!=""){
                    st.push(temp);
                }
                temp = "";
            }
            else{
                temp += ch;
            }
        }
        if(temp!=""){
            st.push(temp);
        }
        while(!st.empty()){
            ans += (st.top() + " ");
            st.pop();
        }    
        ans.pop_back();
        return ans;   
    }
};