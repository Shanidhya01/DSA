#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void display(queue<int> & q){
    int n = q.size();
    for(int i=1;i<=n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
void reverse(queue<int> & q){
    stack<int> st;
    while (q.size()>0){
        int x = q.front();
        q.pop();
        st.push(x);
    }
    while (st.size()>0){
        int x = st.top();
        // cout<<x<<" ";
        st.pop();
        q.push(x);
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);  
    display(q);
    reverse(q);  
    display(q);
}