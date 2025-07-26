// leetcode 47
class Solution {
public:
    void permutations(vector<vector<int>>& v, vector<int> ans, vector<int> original) {
        if (original.empty()) {
            v.push_back(ans);
            return;
        }
        int m = original.size();
        for (int i = 0; i < m; i++) {
            if (i > 0 && original[i] == original[i - 1]) continue;
            int num = original[i];
            vector<int> left(original.begin(), original.begin() + i);
            vector<int> right(original.begin() + i + 1, original.end());
            for (int i = 0; i < right.size(); ++i) {
                left.push_back(right[i]);
            }
            for(int val : left) {
                std::cout << val << " ";
            }
            ans.push_back(num);
            permutations(v, ans, left);
            ans.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        permutations(v, {}, nums);
        return v;
    }
};
