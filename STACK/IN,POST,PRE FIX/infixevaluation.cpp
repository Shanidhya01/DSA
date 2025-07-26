#include <iostream>
#include <stack>
using namespace std;
int prio(char ch){
    if (ch == '+' || ch == '-')     return 1;
    if (ch == '*' || ch == '/')     return 2;
}
int solve(int val1, int val2, char ch){
    if (ch == '+')    return val1 + val2;
    if (ch == '-')    return val1 - val2;
    if (ch == '*')    return val1 * val2;
    if (ch == '/')    return val1 / val2;
}
int main(){
    string s = "2+6*4/8-3"; // infix Expression
    // We need to stack one for val(int) and one for op(char)
    stack<int> val;
    stack<char> op;
    for (int i = 0; i < s.length(); i++){
        if (isdigit(s[i]))    val.push(s[i] - '0');
        else{
            if (op.empty() || prio(s[i]) > prio(op.top()))    op.push(s[i]);
            else{
                while (!op.empty() && prio(s[i]) <= prio(op.top())){
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    while (!op.empty()){
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, val2, ch);
        val.push(ans);
    }
    cout << val.top();
}