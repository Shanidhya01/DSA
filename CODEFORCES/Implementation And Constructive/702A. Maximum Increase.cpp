// You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array.

// A subarray is the sequence of consecutive elements of the array. Subarray is called increasing if each element of this subarray strictly greater than previous.

// Input
// The first line contains single positive integer n (1 ≤ n ≤ 105) — the number of integers.

// The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).

// Output
// Print the maximum length of an increasing subarray of the given array.

// Examples
// Input
// 5
// 1 7 2 11 15
// Output
// 3
// Input
// 6
// 100 100 100 100 100 100
// Output
// 1
// Input
// 3
// 1 2 3
// Output
// 3

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxLen=1;
    int currLen=1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            currLen++;
            maxLen=max(maxLen,currLen);
        }
        else{
            currLen=1;
        }
    }
    cout<<maxLen<<endl;
    return 0;
}