#include<iostream>
using namespace std;
class Node{ // user defined data type
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList{  // user defined data structure
public:
    Node * head;
    Node * tail;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int val){
        Node * temp = new Node(val);
        if(size==0)  head=tail=temp;           
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val){
        Node * temp = new Node(val);
        if(size==0)  head=tail=temp;           
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtIdx(int idx,int val){
        if(idx <0 || idx>size)    cout<<"Ivalid Index"<<endl;
        else if(idx==0)    insertAtHead(val);
        else if(idx==size)    insertAtTail(val);
        else{
            Node * t = new Node(val);
            Node * temp = head;
            for(int i=1;i<idx-1;i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next= t;
            size++;
        }
    }
    int getAtIdx(int idx){
        if(idx <0 || idx>size){
            cout<<"Invalid Index";
            return -1;
        }
        else if(idx==0)    return head->val;
        else if(idx==size)    return tail->val;
        else{
            Node * temp = head;
            for(int i=0;i<idx;i++){
                temp = temp->next;
            }
            return temp->val; 
        }
    }
    void deleteAtHead(){
        if(size==0){
            cout<<"List is Empty"<<endl;
            return;
        }
        head = head->next;
        size--;
    }
    void deleteAtTail(){
        if(size==0) {
            cout<<"List is Empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        temp->next=NULL;
        tail = temp;
        size--;
    }
    void deleteAtIdx(int idx){
        if(idx <0 || idx>size){
            cout<<"Invalid Index";
            return;
        }
        else if(idx==0)    return deleteAtHead();
        else if(idx==size)    return deleteAtTail();
        else{
            Node * temp = head;
            for(int i=0;i<idx-1;i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }
    void display(){
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    LinkedList ll;
    ll.insertAtTail(10);
    ll.display(); 
    ll.insertAtTail(20);
    ll.display();
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    ll.display();
    ll.insertAtHead(50);
    ll.display();
    ll.insertAtHead(24);
    ll.display();
    ll.insertAtIdx(4,80);
    ll.display();
    ll.insertAtIdx(0,76);
    ll.display();
    cout<<ll.getAtIdx(3)<<endl;
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIdx(3);
    ll.display();
}