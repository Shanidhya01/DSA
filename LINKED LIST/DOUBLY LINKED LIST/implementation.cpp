#include<iostream>
using namespace std;
class Node{ // user defined data type
public:
    int val;
    Node * next;
    Node * prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void display(Node * head){  //0(1) space
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}
void displayrec(Node * head) {  //0(n)  space
    if(head==NULL) return;
    cout << head->val << " ";
    displayrec(head->next);
}
void displayrev(Node * tail){  //0(1) space
    while(tail){
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}
void reversedisplayrec(Node * head) {   //0(n)  space
    if(head==NULL) return;
    reversedisplayrec(head->next);
    cout << head->val << " ";
}
int main(){
    // 10 20 30 40 50 
    Node * a = new Node(10);
    Node * b = new Node(20);
    Node * c = new Node(30);
    Node * d = new Node(40);
    Node * e = new Node(50);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;
    display(a);
    displayrev(e);
}