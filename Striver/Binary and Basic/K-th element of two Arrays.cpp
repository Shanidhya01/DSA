#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i : a)  pq.push(i);
        for(int i : b)  pq.push(i);
        
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
    
};