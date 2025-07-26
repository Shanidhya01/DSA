// leetcode 90  subset 2
class Solution {
public:
    // Helper function to store subsets
    void storeSubset(vector<int> ans, int* original, int n, int idx, vector<vector<int>>& v, bool flag) {
        if (idx == n) {
            v.push_back(ans);
            return;
        }
        int ch = original[idx];
        if (idx == n - 1) {
            if (flag) {
                vector<int> ANS = ans;
                ANS.push_back(ch);
                storeSubset(ANS, original, n, idx + 1, v, true);
            }
            storeSubset(ans, original, n, idx + 1, v, true);
            return;
        }
        int dh = original[idx + 1];
        if (ch == dh) {
            if (flag) {
                vector<int> ANS = ans;
                ANS.push_back(ch);
                storeSubset(ANS, original, n, idx + 1, v, true);
            }
            storeSubset(ans, original, n, idx + 1, v, false);
        } else {
            if (flag) {
                vector<int> ANS = ans;
                ANS.push_back(ch);
                storeSubset(ANS, original, n, idx + 1, v, true);
            }
            storeSubset(ans, original, n, idx + 1, v, true);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        storeSubset(arr, nums.data(), nums.size(), 0, v, true);
        return v;
    }
};