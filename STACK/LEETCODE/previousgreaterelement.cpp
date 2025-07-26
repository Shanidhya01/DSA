//GeeksForGeeks question
// Given an array of distinct elements, find previous greater element for every element. If previous greater element does not exist, print -1.
// Input : arr[] = {10, 4, 2, 20, 40, 12, 30}
// Output :         -1, 10, 4, -1, -1, 40, 40
// Input : arr[] = {10, 20, 30, 40}
// Output :        -1, -1, -1, -1
// Input : arr[] = {40, 30, 20, 10}
// Output :        -1, 40, 30, 20
// Expected time complexity : O(n)
#include<iostream>
#include<stack>
using namespace std;
int main() {
    int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int pge[n];
    stack<int> st; 
    pge[0] = -1;
    st.push(arr[0]);
    for (int i = 1; i <= n-1; i++) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (st.empty())    pge[i] = -1;  
        else    pge[i] = st.top();
        st.push(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << pge[i] << " ";
    }
    cout << endl;
    return 0;
}