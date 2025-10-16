#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a,ListNode* b){
        ListNode* c = new ListNode(0);
        ListNode* temp = c;
        while(a && b ){
            if(a->val <= b->val){
                temp->next = a;
                a = a->next;
                temp= temp->next;
            }
            else{
                temp->next = b;
                b = b->next;
                temp= temp->next;
            }
        }
        if(a==NULL) temp->next=b;
        else temp->next=a;
        return c->next;
    }
    // ListNode* mergeKLists(vector<ListNode*>& arr) {
    //     if(arr.size()==0) return NULL;
    //     while(arr.size()>1){
    //         ListNode* a = arr[arr.size()-1];
    //         arr.pop_back();
    //         ListNode* b = arr[arr.size()-1];
    //         arr.pop_back();
    //         ListNode* c = mergeTwoLists(a,b);
    //         arr.push_back(c);
    //     }
    //     return arr[0];
    // }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1){
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = mergeTwoLists(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};