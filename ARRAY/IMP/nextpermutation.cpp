// leetcode - 31
#include<iostream>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the first decreasing element from the end
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If no decreasing element is found, reverse the entire array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the element just larger than nums[idx] in the suffix
        for(int j = n - 1; j > idx; j--) {
            if(nums[j] > nums[idx]) {
                swap(nums[j], nums[idx]);
                break;
            }
        }

        // Step 4: Reverse the elements after the swapped element to get the next permutation
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
int main(){
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(8);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    vector<int>v = merge(v1,v2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}