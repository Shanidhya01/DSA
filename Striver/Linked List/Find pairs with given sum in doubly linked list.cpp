#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        unordered_map<int, Node *> v;
        Node *curr = head;
        while(curr != nullptr){
            int x = target - curr->data;
            if(v.find(x)!=v.end()){
                ans.push_back({x,curr->data});
            }
            v[curr->data]=curr;
            curr = curr->next;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};