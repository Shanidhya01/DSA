#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int getSecondLargest(vector<int> &arr) {
//         int n = arr.size();
//         if (n < 2) return -1;

//         // Remove duplicates using set
//         set<int> unique(arr.begin(), arr.end());
//         if (unique.size() < 2) return -1;

//         priority_queue<int, vector<int>, greater<int>> pq;
//         int k = 2;
//         for (int val : unique) {
//             pq.push(val);
//             if (pq.size() > k) pq.pop();
//         }
//         return pq.top();
//     }
// };
// User function template for C++
class Solution {
  public:
    // Function to return the second largest element
    int getSecondLargest(vector<int> &nums) {
        int largest = INT_MIN, secondLargest = INT_MIN;

        for (int num : nums) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num < largest) {
                secondLargest = num;
            }
        }

        // If no second largest element exists, return -1
        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};