#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};



class Solution {
  public:
    // Function to reverse a linked list.
    Node* reverseList(struct Node* head) {
        Node * curr = head;
        Node * prev = NULL;
        Node * Next = NULL;
        while(curr!=NULL){
            Next = curr->next;
            curr-> next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
};

