#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

class Solution
{
public:
  struct compare
  {
    bool operator()(Node *a, Node *b)
    {
      return a->data > b->data;
    }
  };

  Node *mergeKLists(vector<Node *> &arr)
  {
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (auto listHead : arr)
    {
      if (listHead)
        pq.push(listHead);
    }

    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (!pq.empty())
    {
      Node *curr = pq.top();
      pq.pop();

      tail->next = curr;
      tail = tail->next;

      if (curr->next)
        pq.push(curr->next);
    }

    return dummy->next;
  }
};
