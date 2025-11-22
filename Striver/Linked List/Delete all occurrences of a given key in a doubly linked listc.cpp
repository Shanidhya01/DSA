#include<bits/stdc++.h>
using namespace std;


struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        // Write your code here
        Node *curr=*head;
        while(curr){
            if(curr->data == x){
                Node *toDelete = curr;
                if(curr == *head){
                    *head = curr ->next;
                    if(*head){
                        (*head)->prev = nullptr;
                    }
                }
                else{
                    curr->prev->next = curr->next;
                    if(curr->next){
                        curr->next->prev = curr->prev;
                    }
                }
                curr = curr->next;
                delete toDelete;
                
            }
            else{
                curr = curr->next;
            }
        }
    }
};