#include <iostream>
#include <stack>
using namespace std;
int solve(int val1, int val2, char ch){
    if (ch == '+')    return val1 + val2;
    if (ch == '-')    return val1 - val2;
    if (ch == '*')    return val1 * val2;
    if (ch == '/')    return val1 / val2;
    return 0;
}
int main(){
    string s = "79+4*8/3-"; // postfix Expression
    // We need to stack one for val(int) 
    stack<int> val;
    int n = s.length();
    for (int i = 0; i < n; i++){
        if (isdigit(s[i]))    val.push(s[i] - '0');
        else{
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = solve(val1, val2, s[i]);
            val.push(ans);
        }
    }
    cout << val.top()<<endl;
}