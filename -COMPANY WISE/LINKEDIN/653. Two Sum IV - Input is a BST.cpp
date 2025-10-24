#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(TreeNode * root,vector<int> & v){
        if(root == nullptr) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);         
        int left = 0, right = v.size() - 1;  
        while (left < right) {
            int sum = v[left] + v[right];
            if (sum == k) return true;  
            else if (sum < k) left++;  
            else right--;  
        }
        return false; 
    }
};