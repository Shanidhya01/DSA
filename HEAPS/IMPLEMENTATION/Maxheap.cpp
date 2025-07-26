#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
public:
    vector<int> arr;
    int idx;
    
    MaxHeap(int x) {
        idx = 1;
        for(int i=1;i<=x;i++) arr.push_back(0);
    }
    
    int top() {
        return arr[1];
    }
    
    void push(int x) {
        arr[idx] = x;
        int i = idx;
        idx++;
        
        // Swapping with parent till it satisfies the max-heap property
        while (i != 1) {
            if (arr[i] > arr[i / 2]) {
                swap(arr[i], arr[i / 2]);
                i = i / 2;
            } else break;
        }
    }
    
    void pop() {
        if (idx == 1) return; // Empty heap
        idx--;
        arr[1] = arr[idx];
        
        // Rearrange the heap
        int i = 1;
        while (true) {
            int left = 2 * i, right = 2 * i + 1;
            if (left >= idx) break;

            int largest = i;
            if (left < idx && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right < idx && arr[right] > arr[largest]) {
                largest = right;
            }
            
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }
    }
    
    int size() {
        return idx - 1;
    }
    
    void display() {
        for (int i = 1; i <= idx - 1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap pq(25);
    pq.push(10);
    pq.push(20);
    cout << pq.top() << " " << pq.size() << endl;
    pq.push(11);
    pq.push(21);
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
    pq.pop();
    cout << pq.top() << " " << pq.size() << endl;
    pq.display();
    return 0;
}
