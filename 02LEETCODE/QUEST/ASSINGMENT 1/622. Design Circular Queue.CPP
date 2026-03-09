#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    queue<int> q;
    int capacity;
    int count;

    MyCircularQueue(int k) {
        capacity = k;
        count = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q.push(value);
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        q.pop();
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q.front();
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
};
