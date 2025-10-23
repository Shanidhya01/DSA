#include<bits/stdc++.h> 
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// class Solution{
//     public:
//     ListNode* reverseList(ListNode *head)        {
//         ListNode *temp = NULL;
//         while (head != NULL){
//             ListNode *next = head->next;
//             head->next = temp;
//             temp = head;
//             head = next;
//         }
//         return temp;
//     }
// };
class Solution{
    public:
    ListNode* reverseList(ListNode *head)        {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while (curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
};