// Maximum sum Subarray of size k
// #include<iostream>
// #include <climits>
// using namespace std;
// int main(){
//     int arr[] = {7,1,2,5,8,4,9,3,6};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int k =3;
//     int maxsum = INT_MIN;
//     int maxidx = -1;
//     for(int i=0;i<=n-k;i++){
//         int sum = 0;
//         for(int j=i;j<i+k;j++){
//             sum += arr[j];
//         }
//         if(maxsum<sum){
//             maxsum = sum ;
//             maxidx = i;
//         }
//     }
//     cout<<maxsum<<endl<<maxidx;
// }


// using sliding windows
#include<iostream>
#include <climits>
using namespace std;
int main(){
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int maxsum = INT_MIN;
    int maxidx = -1;
    int prevSum = 0;
    for(int i=0;i<k;i++){
        prevSum += arr[i];
    }
    maxsum = prevSum;
    int i=1;
    int j=k;
    while(j<n){
        int currSum = prevSum + arr[j] - arr[i-1];
        if(maxsum<currSum){
            maxsum = currSum;
            maxidx = i;
        }
        prevSum = currSum;
        i++;
        j++;
    }
    cout<<maxsum<<endl<<maxidx;
}