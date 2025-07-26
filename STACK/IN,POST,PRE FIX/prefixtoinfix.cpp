#include <iostream>
#include <stack>
using namespace std;
string solve(string val1, string val2, char ch){
    // infix is ->   v1 op v2
    string s = "";
    s += val1;
    s.push_back(ch);
    s += val2;
    return s;
}
int main() {
    string s = "-/*+79483"; // Prefix Expression
    stack<string> val; 
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        if (isdigit(s[i]))        val.push(to_string(s[i] - '0')); 
        else {
            string val1 = val.top();
            val.pop();
            string val2 = val.top();
            val.pop(); 
            string ans = solve(val1, val2, s[i]);
            val.push(ans);
        }
    }
    cout << val.top() << endl;
    return 0;
}