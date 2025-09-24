// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = nullptr;
  }
};

class Solution
{
public:
  void removeLoop(Node *head)
  {
    // code here
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == NULL)
        break;
      if (slow == fast)
        break;
    }
    Node *newp = head;
    Node *pointer = fast;
    if (slow == fast)
    {
      while (slow != newp)
      {
        slow = slow->next;
        newp = newp->next;
      }
      while (pointer->next != slow)
      {
        pointer = pointer->next;
      }
      pointer->next = NULL;
    }
  }
};