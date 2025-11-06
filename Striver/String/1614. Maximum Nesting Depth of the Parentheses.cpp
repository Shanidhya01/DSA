#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int maxDepth(string s) {
//         int depth = 0; 
//         int count = 0; 
//         for (char ch : s) {
//             if (ch == '(') {
//                 count++;
//                 depth = max(depth, count);
//             }
//             if (ch == ')') {
//                 count--;
//             }
//         }
//         return depth;
//     }
// };
class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int mx = 0;
        for(char c : s){
            if(c == '(')  st.push(c);
            else if(c == ')'){
                int x = st.size();
                mx = max(mx,x);
                st.pop();
            }
        }
        return mx;
    }
};
