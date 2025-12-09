#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod = 1000000007;
        long long cnt = 0;
        unordered_map<int, int> freqPrev, freqNext;
        for (int x : nums) {
            freqNext[x]++;
        }
        for (int j = 0; j < nums.size(); j++) {
            freqNext[nums[j]]--;
            long long left = freqPrev[nums[j] * 2];
            long long right = freqNext[nums[j] * 2];
            cnt = (cnt + (left * right) % mod) % mod;
            freqPrev[nums[j]]++;
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    int result = obj.specialTriplets(nums);
    cout << "Number of special triplets: " << result << "\n";
    return 0;
}
