#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;
  
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step1 - Create the deep copy without random pointer
        Node * dummy = new Node(0);
        Node * temp = head;
        Node * tempC = dummy;
        while(temp){
            Node * a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node * b = dummy->next;
        Node * a = head;
        // step 2 make a map of original node and duplicate node
        unordered_map<Node*,Node*> m;
        Node * tempa = a;
        Node * tempb = b;
        while(tempa!=nullptr){
            m[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        for(auto x : m){
            Node * orig = x.first;
            Node * dupl = x.second;
            if(orig->random != nullptr){
                Node * origrandom = orig->random;
                Node * duplrandom = m[origrandom];
                dupl->random = duplrandom;
            }
        }
        return b;
    }
};