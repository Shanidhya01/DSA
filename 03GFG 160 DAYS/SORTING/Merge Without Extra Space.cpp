#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int gap = (n + m + 1) / 2;  // initial gap (ceil)

        while (gap > 0) {
            int i = 0, j = gap;

            while (j < n + m) {
                // Get values at i and j
                int &val1 = (i < n) ? a[i] : b[i - n];
                int &val2 = (j < n) ? a[j] : b[j - n];

                if (val1 > val2)
                    swap(val1, val2);

                i++; j++;
            }

            if (gap == 1) break;
            gap = (gap + 1) / 2; // ceil(gap/2)
        }
    }
};
