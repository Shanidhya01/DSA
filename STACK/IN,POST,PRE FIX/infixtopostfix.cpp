#include <iostream>
#include <stack>
using namespace std;
int prio(char ch){
    if (ch == '+' || ch == '-')     return 1;
    if (ch == '*' || ch == '/')     return 2;
    return 0;
}
string solve(string val1, string val2, char ch){
    // Store prefix to answer
    // prefix is ->  v1 v2 op
    string s = "";
    s += val1;
    s += val2;
    s.push_back(ch);
    return s;
}
int main(){
    string s = "2+6*4/8-3"; // infix Expression
    // We need to stack one for val(int) and one for op(char)
    stack<string> val;
    stack<char> op;
    int n = s.length();
    for (int i = 0; i < n; i++){
        if (isdigit(s[i]))    val.push(to_string(s[i] - '0'));
        else{
            if (op.empty())           op.push(s[i]);
            else if(s[i] == '(')      op.push(s[i]);
            else if(op.top() == '(')  op.push(s[i]);
            else if(s[i] == ')'){
                while(op.top() != '('){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop();
            }
            else if(prio(s[i]) > prio(op.top()))   op.push(s[i]);
            else{
                while (!op.empty() && prio(s[i]) <= prio(op.top())){
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while (!op.empty()){
        char ch = op.top();
        op.pop();
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1, val2, ch);
        val.push(ans);
    }
    cout << val.top()<<endl;
}