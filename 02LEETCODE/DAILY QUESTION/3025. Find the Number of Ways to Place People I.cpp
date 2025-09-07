#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Step 1: Sort by x ascending, then y descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // y descending
            return a[0] < b[0];                   // x ascending
        });

        int n = points.size();
        int pair_count = 0;

        // Step 2: Iterate through all points as potential "upper-left" points
        for (int i = 0; i < n; i++) {
            int upper_y = points[i][1];
            int lower_y_limit = INT_MIN;

            // Step 3: Check subsequent points as potential "bottom-right" points
            for (int j = i + 1; j < n; j++) {
                int current_y = points[j][1];
                if (current_y <= upper_y && current_y > lower_y_limit) {
                    pair_count++;
                    lower_y_limit = current_y;
                    if (current_y == upper_y) {
                        break;
                    }
                }
            }
        }
        return pair_count;
    }
};
