#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> st,gt;
    MyQueue() {
    }
    
    void push(int x) {
        while(!st.empty()){
            gt.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!gt.empty()){
            st.push(gt.top());
            gt.pop();
        }
    }
    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */