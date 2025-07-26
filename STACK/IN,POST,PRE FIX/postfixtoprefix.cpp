#include <iostream>
#include <stack>
using namespace std;
string solve(string val1, string val2, char ch){
    // Store prefix to answer
    // prefix is ->  op v1 v2
    string s = "";
    s.push_back(ch);
    s += val1;
    s += val2;
    return s;
}
int main(){
    string s = "79+4*8/3-"; // postfix Expression
    // We need to stack one for val(int) 
    stack<string> val;
    int n = s.length();
    for (int i = 0; i < n; i++){
        if (isdigit(s[i]))    val.push(to_string(s[i] - '0'));
        else{
            string val2 = val.top();
            val.pop();
            string val1 = val.top();
            val.pop();
            string ans = solve(val1, val2, s[i]);
            val.push(ans);
        }
    }
    cout << val.top()<<endl;
}