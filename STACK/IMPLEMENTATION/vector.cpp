#include<iostream>
#include<vector>
using namespace std;
class Stack{  // User defined data structure
public:
    vector<int> v;  // No overflow condition
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        if(v.size()==0){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        v.pop_back();
    }
    void top(){
        if(v.size()==0){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        cout<<v[v.size()-1]<<endl;
    }
    void size(){
        cout<<v.size()<<endl;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.top();
}