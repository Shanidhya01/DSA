// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
#include <bits/stdc++.h>
using namespace std;

// class Solution {
//   public:
//     int power(int base, int exp) {
//         long long result = 1;
//         for (int i = 0; i < exp; ++i) {
//             result *= base;
//             if (result > 1e9) return 1e9 + 1; }
//         return result;
//     }
//     int nthRoot(int n, int m) {
//         int low = 1, high = m;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             int midPower = power(mid, n);
//             if (midPower == m)
//                 return mid;
//             else if (midPower < m)
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }
//         return -1;
//     }
// };

class Solution
{
public:
  int nthRoot(int n, int m)
  {

    for (int i = 0; i <= m; i++)
    {
      if (pow(i, n) == m)
      {
        return i;
      }
      else if (pow(i, n) > m)
      {
        break;
      }
    }
    return -1;
  }
};