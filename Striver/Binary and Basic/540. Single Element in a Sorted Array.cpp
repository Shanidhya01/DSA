# include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for (int num : nums) {
//             freq[num]++;
//         }
//         for (auto& [key, val] : freq) {
//             if (val == 1) return key;
//         }
//         return -1; 
//     }
// };


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 2;
            }
        }
        return nums[left];
    }
};
