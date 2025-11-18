#include<bits/stdc++.h>
using namespace std;

  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    Node* segregate(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        
        int zc=0;
        int oc=0;
        int tc=0;

        Node* temp=head;
        while(temp!=NULL) {
            if(temp->data==0) zc++;
            else if(temp->data==1) oc++;
            else tc++;
            temp=temp->next;
        }
        
        temp=head;
        while(zc) {
            temp->data=0;
            temp=temp->next;
            zc--;
        }
        while(oc) {
            temp->data=1;
            temp=temp->next;
            oc--;
        }
        while(tc) {
            temp->data=2;
            temp=temp->next;
            tc--;
        }
        return head;
    }
};