/*888. Fair Candy Swap

Alice and Bob have a different total number of candies. You are given two integer arrays aliceSizes and bobSizes where aliceSizes[i] is the number of candies of the ith box of candy that Alice has and bobSizes[j] is the number of candies of the jth box of candy that Bob has.
Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy. The total amount of candy a person has is the sum of the number of candies in each box they have.
Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] is the number of candies in the box that Bob must exchange. If there are multiple answers, you may return any one of them. It is guaranteed that at least one answer exists.

Example 1:
Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]

Example 2:
Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]

Example 3:
Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]

Constraints:
1 <= aliceSizes.length, bobSizes.length <= 104
1 <= aliceSizes[i], bobSizes[j] <= 105
Alice and Bob have a different total number of candies.
There will be at least one valid answer for the given input.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0); // total number of candies Alice has
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0); // total number of candies Bob has

        int diff = (sum2 - sum1) / 2; // the difference that needs to be balanced between Alice and Bob
        
        set<int> s; // using a set to keep track of the candies that Bob has
        
        for (auto b : bobSizes) {
            s.insert(b);
        }
        
        for (auto a : aliceSizes) {
            int b = a + diff; // Bob needs to give this many candies to Alice to balance the total candy count
            if (s.count(b)) { // if Bob has this many candies
                return {a, b}; // return the boxes that need to be exchanged
            }
        }
        
        return {}; // this line will not be executed as at least one solution is guaranteed
    }
};