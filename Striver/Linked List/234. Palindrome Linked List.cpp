#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode *head) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* Next = head;
//         while (curr){
//             Next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = Next;
//         }
//         return prev;
//     }
//     bool isPalindrome(ListNode* head) {
//         ListNode * c = new ListNode(10);
//         // deep copy of head
//         ListNode * temp = head;
//         ListNode * tempC = c;
//         while(temp){
//             ListNode * node = new ListNode(temp->val);
//             tempC->next = node;
//             temp = temp->next;
//             tempC = tempC->next;
//         }
//         c = c->next;
//         c = reverseList(c);
//         ListNode * a = head;
//         ListNode * b = c;
//         while(a){
//             if(a->val != b->val) return false;
//             a = a->next;
//             b = b->next;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL && head->next==NULL) return true;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * second = slow -> next;
        slow -> next = NULL;
        ListNode * curr = second;
        ListNode * prev = NULL;
        while(curr){
            ListNode * temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode * start = head;
        ListNode * end = prev;
        while(start && end){
            if(start -> val != end -> val)
            return false;
            start = start -> next;
            end = end -> next;
        }
        return true;
    }
};