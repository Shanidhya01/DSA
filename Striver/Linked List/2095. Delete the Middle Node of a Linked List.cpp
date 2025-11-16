#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        int midIdx = len/2;
        if(midIdx==0)   head = head->next;
        else{
            ListNode * temp = head;
            for(int i=0;i<midIdx-1;i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        return head;
    }
};