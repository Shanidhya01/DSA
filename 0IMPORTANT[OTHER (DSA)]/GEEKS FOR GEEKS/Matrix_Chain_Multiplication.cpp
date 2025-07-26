// Given the dimension of a sequence of matrices in an array arr[], where the dimension of 
// the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply
//  these matrices together such that the total number of element multiplications is minimum.

// Input: arr[] = [2, 1, 3, 4]
// Output: 20
// Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, 
// Let this 3 input matrices be M1, M2, and M3. There are two ways to multiply:
//  ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) 
// is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix. 
// ((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30 
// (M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20. 
// The minimum of these two is 20.

// top down approach
/*#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int f(int i,int j,vector<int> &arr){
    if(i==j or i+1 == j) return 0;
    if(dp[i][j] != 0) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i+1;k<j;k++){
        ans = min(ans,f(i,k,arr) + f(k, j,arr) + arr[i] * arr[k] * arr[j]);
    }
    return dp[i][j] = ans;
}
int main(){ 
    int n;
    cin>>n;
    vector<int> v(n);
    dp.resize(n,vector<int>(n,0));
    for(int i=0;i<n;i++)  cin>>v[i];
    cout<<f(0,n-1,v)<<"\n";
    return 0;
}*/

//bottom up approach
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)      cin >> v[i];
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;  
    return 0;
}
