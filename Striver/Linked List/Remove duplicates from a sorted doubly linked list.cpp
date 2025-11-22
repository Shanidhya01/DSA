#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node *prev=head;
        Node *curr=head->next;
        while(curr){
            if(prev->data == curr->data){
                prev->next = curr->next;
                if(curr->next){
                    curr->next->prev = prev;
                }
                delete curr;
                curr = prev ->next;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
        return head;
    }
};