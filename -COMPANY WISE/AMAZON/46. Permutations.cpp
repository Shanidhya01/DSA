#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void permutations(vector<vector<int>>& v, vector<int> ans, vector<int> original) {
        if (original.empty()) {
            v.push_back(ans);
            return;
        }
        int m = original.size();
        for (int i = 0; i < m; i++) {
            int num = original[i];
            vector<int> left(original.begin(), original.begin() + i);
            vector<int> right(original.begin() + i + 1, original.end());
            for (int i = 0; i < right.size(); ++i) {
                left.push_back(right[i]);
            }
            // Now 'left' contains: {1, 2, 3, 4, 5, 6}
            for(int val : left) {
                std::cout << val << " ";
            }
            ans.push_back(num);
            permutations(v, ans, left);
            ans.pop_back(); 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        permutations(v,{},nums);
        return v;
    }
};

// class Solution {
// public:

// void fun(vector<int>& nums, int index, vector<vector<int>>& ans){
//     //base case 
//     if(index == nums.size()){
//         ans.push_back(nums); 
//         return; 
//     }

//     for(int i = index; i < nums.size(); i++){
//         swap(nums[index], nums[i]); 
//         fun(nums, index + 1, ans); 
//         swap(nums[i], nums[index]); 
//     }
    

// }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans; 
//         fun(nums, 0, ans); 
//         return ans; 
//     }
// };