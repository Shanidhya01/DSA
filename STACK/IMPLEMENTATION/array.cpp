#include<iostream>
using namespace std;
class Stack{  // User defined data structure
public:
    int arr[5];
    int idx = -1;
    void push(int val){
        if(idx==sizeof(arr)/sizeof(arr[0])-1){
            cout<<"Stack is Full"<<endl;
            return;
        }
        idx++;
        arr[idx] = val;
    }
    void pop(){
        if(idx==-1){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        idx--;
    }
    void top(){
        if(idx==-1){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        cout<<arr[idx]<<endl;
    }
    void size(){
        cout<<idx+1<<endl;
    }
    void display(){
        for(int i=0;i<=idx;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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
    st.display();
    st.top();
}