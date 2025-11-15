// You are given an integer array a
//  of length n
// .

// You can perform the following operation: choose a range [l,r]
//  (1≤l≤r≤n
// ) and replace the value of elements al,al+1,…,ar
//  with (l+r)
// .

// Your task is to calculate the maximum possible total array sum if you can perform the aforementioned operation at most once.

// Input
// The first line contains a single integer t
//  (1≤t≤104
// ) — the number of test cases.

// The first line of each test case contains a single integer n
//  (1≤n≤2⋅105
// ).

// The second line contains n
//  integers a1,a2,…,an
//  (0≤ai≤2n
// ).

// Additional constraint on the input: the sum of n
//  over all test cases doesn't exceed 2⋅105
// .

// Output
// For each test case, print a single integer — the maximum possible total array sum if you can perform the aforementioned operation at most once.

// Example
// InputCopy
// 4
// 3
// 2 5 1
// 2
// 4 4
// 4
// 1 3 2 1
// 5
// 3 2 0 9 10
// OutputCopy
// 13
// 8
// 20
// 32
// Note
// In the first example, you can perform the operation on the subarray [3,3]
// , resulting in the array [2,5,6]
//  and the sum 13
// .

// In the second example, you don't need to perform any operation.

// In the third example, you can perform the operation on the subarray [1,4]
// , resulting in the array [5,5,5,5]
//  and the sum 20
// .

// In the fourth example, you can perform the operation on the subarray [2,3]
// , resulting in the array [3,5,5,9,10]
//  and the sum 32
// .
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    if (!(cin >> t)) return 0;

    while (t--) {
        int n; 
        if (!(cin >> n)) break;

        vector<long long> a(n);
        vector<long long> P(n + 1, 0); 
        long long totalSum = 0;

        for (int i = 0; i < n; i++) {
            if (!(cin >> a[i])) break;
            totalSum += a[i];
            P[i + 1] = P[i] + a[i];
        }

        long long maxGain = 0;
        
        long long min_L_term = 0; 
        
        for (int r = 0; r < n; r++) {
            
            long long L_term_current = (long long)r * (r + 1) - P[r]; 
            
            min_L_term = min(min_L_term, L_term_current);
            
            long long R_term = (long long)(r + 2) * (r + 1) - P[r + 1];
            
            maxGain = max(maxGain, R_term - min_L_term);
        }

        cout << totalSum + maxGain << "\n";
    }
    return 0;
}
