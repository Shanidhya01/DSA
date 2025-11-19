#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }

        ListNode * prev = nullptr;
        ListNode * curr = head;
        ListNode * Next = nullptr;
        int cnt = 0;
        while (cnt < k && curr) {
            Next = curr->next;   
            curr->next = prev;
            prev = curr;
            curr = Next;
            cnt++;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};