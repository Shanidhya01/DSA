#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<int> majorityElements;
        int threshold = nums.size() / 3;
        for(auto elementCountPair : mp) {
            int element = elementCountPair.first;
            int count = elementCountPair.second;
            
            if(count > threshold) {
                majorityElements.push_back(element);
            }
        }
        return majorityElements; 
    }
};