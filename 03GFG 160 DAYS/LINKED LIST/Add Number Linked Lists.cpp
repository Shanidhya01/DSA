#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverseList(Node *head)        {
        Node* prev = NULL;
        Node* curr = head;
        Node* Next = head;
        while (curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        Node * sum = NULL;
        int carry = 0;
        while (head1 != NULL || head2 != NULL || carry != 0) {
            int newVal = carry;
            if (head1) {
                newVal += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                newVal += head2->data;
                head2 = head2->next;
            }
            carry = newVal / 10;
            newVal %= 10;
            Node* newNode = new Node(newVal);
            newNode->next = sum;
            sum = newNode;
        }
        while (sum != NULL && sum->data == 0) {
            Node* temp = sum;
            sum = sum->next;
            delete temp;
        }
        if (sum == NULL) {
            return new Node(0);
        }
        return sum;
    }
};