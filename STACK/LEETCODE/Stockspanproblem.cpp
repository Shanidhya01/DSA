#include<iostream>
#include<stack>
using namespace std;
int main() {
    int arr[] = {100,80,60,81,70,60,75,85};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Previous greater element index array
    int pgi[n];
    // Using a stack pop ans push and forward transverse
    // TC = 0(n)    SC = 0(n)
    stack<int> st; 
    pgi[0] = 1;
    st.push(0);
    for (int i = 1; i <= n-1; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (st.empty())    pgi[i] = -1;  
        else    pgi[i] = st.top();
        pgi[i] = i - pgi[i];
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << pgi[i] << " ";
    }
    cout << endl;
    return 0;
}