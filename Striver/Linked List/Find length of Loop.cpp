#include<bits/stdc++.h>
using namespace std;


class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
public:
    int lengthOfLoop(Node* head) {
        if (head == NULL || head->next == NULL) {
            return 0;
        }

        int count = 0;
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                count = 1;
                slow = slow->next;
                while (slow != fast) {
                    slow = slow->next;
                    count++;
                }
                break;
            }
        }
        return count;
    }
};
