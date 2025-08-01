#include<iostream>
using namespace std;
class Node {  // linked list nodes
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
int main() {
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    // Forming linked list
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Node temp = a;
    while (1) { 
        cout << temp.val << " ";
        if(temp.next==NULL) break;
        temp = *(temp.next); 
    }
    return 0;
}
