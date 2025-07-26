#include<iostream>
#include<vector>
using namespace std;
class Queue {  // User defined data structure
public:
    vector<int> arr;
    int f;  // front
    int b;  // rear
    int s;
    vector<int> arr;
    Queue(int val) {
        f = 0;
        b = 0;
        s = 0;
        vector<int> v(val);
        arr = v;
    }
    void push(int val) {
        int n = arr.size();
        if (b == n) {
            cout << "Queue is Full" << endl;
            return;
        }
        arr[b] = val;
        b++;
        s++;
    }
    void pop() {
        if (s==0) {
            cout << "Queue is Empty" << endl;
            return;
        }
        f++;
        s--;
    }
    void front() {
        if (s==0) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[f] << endl;
    }
    void back() {
        if (s==0) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[b - 1] << endl;
    }
    int size() {
        return s;
    }
    bool empty() {
        if(s==0) return true;
        else return false;
    }
    void display() {
        if (f == b) {
            cout << "Queue is Empty" << endl;
            return;
        }
        for (int i = f; i < b; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q(5); // Create a queue with a capacity of 5
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();  
    q.push(50);   
    q.push(60);   
    q.display();  
    q.pop();      // Pop one element
    q.display();  // Display remaining elements
    return 0;
}