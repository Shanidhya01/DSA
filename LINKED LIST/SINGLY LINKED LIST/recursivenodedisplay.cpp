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
void reversedisplay(Node * head) {
    if(head==NULL) return;
    reversedisplay(head->next);
    cout << head->val << " ";
}
void displayrec(Node * head) {
    if(head==NULL) return;
    cout << head->val << " ";
    displayrec(head->next);
}
int size(Node * head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    displayrec(a);
    cout<<endl;
    reversedisplay(a);
    // cout << size(a);
}