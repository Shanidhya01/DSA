
#include <iostream>
using namespace std;
int main() {
    int m, n;
    cout << "Enter the number of rows for the matrix: ";
    cin >> m;
    cout << "Enter the number of columns for the matrix: ";
    cin >> n;
    int arr[m][n];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    // // wave print
    // for(int i =0;i<m;i++){
    //     if(i%2==0){
    //         for(int j=0;j<n;j++){
    //            cout<<arr[i][j]<<" ";
    //         }
    //     }
    //     else{
    //         for(int j=n-1;j>=0;j--){
    //            cout<<arr[i][j]<<" ";
    //         }        
    //     }
    // }
    // column wise print
    // for(int i=0;i<=n-1;i++){
    //     for(int j=0;j<=m-1;j++){
    //         cout<<arr[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int j=0;j<n;j++){
        if(j%2==0){
            for(int i=0;i<m;i++){
               cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int i=n-1;i>=0;i--){
               cout<<arr[i][j]<<" ";
            }        
        }
    }  
    return 0;
}
