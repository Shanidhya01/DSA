#include<iostream>
#include<vector>
using namespace std;
class Queue {  // User defined data structure
public:
    vector<int> arr;
    int front;
    int rear;
    Queue(int size) {
        arr.resize(size);
        front = 0;
        rear = 0;
    }
    void push(int val) {
        int n = arr.size();
        if (rear == n) {
            cout << "Queue is Full" << endl;
            return;
        }
        arr[rear] = val;
        rear++;
    }
    void pop() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        front++;
    }
    void display_front() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[front] << endl;
    }
    void display_rear() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[rear - 1] << endl;
    }
    void size() {
        cout << rear - front << endl;
    }
    bool empty() {
        return front == rear;
    }
    void display() {
        if (front == rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        for (int i = front; i < rear; i++) {
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